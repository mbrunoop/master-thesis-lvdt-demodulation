clear all; clc;
run('parameters.m');

nTest = 9;
t = 0:(1/sampleFrequency):((samplesPerCycle - 1)/sampleFrequency);
sineSignal = sin(2 * pi * lvdtFrequency * t);

% LVDT range = 0.875 VRMS to 2.625 VRMS
lvdtMaxRMS = 2.625; % VRMS
lvdtMinRMS = 0.875; % VRMS
lvdtMaxAmp = lvdtMaxRMS*sqrt(2); % V
lvdtMinAmp = lvdtMinRMS*sqrt(2); % V
VaVec = linspace(lvdtMinAmp, lvdtMaxAmp, nTest);
VbVec = linspace(lvdtMaxAmp, lvdtMinAmp, nTest);

% Parâmetros do Condicionamento de Sinal (Atenuação + Offset DC)
G = 0.4;                % Fator de escala / atenuação
V_bias = 1.65;          % Deslocamento DC (metade de Vref = 3.3V)
lvdtOffsetDig = uint16(adc_kl25z(V_bias));

realPosition = linspace(-5, 5, nTest);
simulPosition_all = zeros(nTest, 3);
error = zeros(nTest, 3);
error_FS = zeros(nTest, 3);
adcSignalA_all = zeros(nTest, samplesPerCycle, 'uint16');
adcSignalB_all = zeros(nTest, samplesPerCycle, 'uint16');

for i = 1:nTest
    signalA = VaVec(i) * sineSignal;
    signalB = VbVec(i) * sineSignal;
    
    signalACond = (signalA * G) + V_bias;
    signalBCond = (signalB * G) + V_bias;
    
    adcSignalA = uint16(adc_kl25z(signalACond, 12, 3.3, 0.0));
    adcSignalB = uint16(adc_kl25z(signalBCond, 12, 3.3, 0.0));
    adcSignalA_all(i, :) = adcSignalA;
    adcSignalB_all(i, :) = adcSignalB;

    simout = sim('modelVerification');
    simulPosition = [simout.position_average(end) simout.position_peak(end) simout.position_RMS(end)];
    simulPosition_all(i, :) = simulPosition;
end

%% WHITE NOISE INSERTION
noise_std = 0.060; % Desvio padrão do ruído em Volts

simulPosition_all_noisy = zeros(nTest, 3);
error_noisy = zeros(nTest, 3);
adcSignalA_all_noisy = zeros(nTest, samplesPerCycle, 'uint16');
adcSignalB_all_noisy = zeros(nTest, samplesPerCycle, 'uint16');

for i = 1:nTest
    signalA = VaVec(i) * sineSignal;
    signalB = VbVec(i) * sineSignal;

    signalA_noisy = signalA + noise_std * randn(size(t));
    signalB_noisy = signalB + noise_std * randn(size(t));

    signalACond = (signalA_noisy * G) + V_bias;
    signalBCond = (signalB_noisy * G) + V_bias;

    adcSignalA = uint16(adc_kl25z(signalACond, 12, 3.3, 0.0));
    adcSignalB = uint16(adc_kl25z(signalBCond, 12, 3.3, 0.0));
    adcSignalA_all_noisy(i, :) = adcSignalA;
    adcSignalB_all_noisy(i, :) = adcSignalB;

    simout = sim('modelVerification');    
    simulPosition = [simout.position_average(end) simout.position_peak(end) simout.position_RMS(end)];
    simulPosition_all_noisy(i, :) = simulPosition;
end

%% RESULTS
T_verification = table(realPosition(:), simulPosition_all(:,1), simulPosition_all(:,2), simulPosition_all(:,3), ...
                     'VariableNames', {'Posicao_Real', 'Simulacao_Average', 'Simulacao_Peak', 'Simulacao_RMS'});

disp('Simulation Results (without noise):');
disp(T_verification);

nomeArquivo = 'verification_results.xlsx';
writetable(T_verification, nomeArquivo);
disp(['Results saved on: ', nomeArquivo]);

T_verification_noisy = table(realPosition(:), simulPosition_all_noisy(:,1), simulPosition_all_noisy(:,2), simulPosition_all_noisy(:,3), ...
                     'VariableNames', {'Posicao_Real', 'Simulacao_Average', 'Simulacao_Peak', 'Simulacao_RMS'});

disp('Simulation Results (with noise):');
disp(T_verification_noisy);

nomeArquivo = 'verification_noisy_results.xlsx';
writetable(T_verification_noisy, nomeArquivo);
disp(['Results saved on: ', nomeArquivo]);

%% ERROR PLOTS
error_all = (realPosition(:)-simulPosition_all)*1000; %10^-3 inches
figure('Name', 'Measurement Error - Without Noise', 'NumberTitle', 'off');
hold on; grid on;
plot(realPosition, error_all(:, 1), 'r', 'LineWidth', 1.5, 'DisplayName', 'Average');
plot(realPosition, error_all(:, 2), 'b', 'LineWidth', 1.5, 'DisplayName', 'Peak');
plot(realPosition, error_all(:, 3), 'g', 'LineWidth', 1.5, 'DisplayName', 'RMS');
xlabel('Real LVDT position [in]');
ylabel('Error [10^{-3} in]');
% title('Measure Error x Real Position');
legend('Location', 'best');

error_all_noisy = (realPosition(:)-simulPosition_all_noisy); % inches
figure('Name', 'Measurement Error - With Noise', 'NumberTitle', 'off');
hold on; grid on;
plot(realPosition, error_all_noisy(:, 1), 'r', 'LineWidth', 1.5, 'DisplayName', 'Average');
plot(realPosition, error_all_noisy(:, 2), 'b', 'LineWidth', 1.5, 'DisplayName', 'Peak');
plot(realPosition, error_all_noisy(:, 3), 'g', 'LineWidth', 1.5, 'DisplayName', 'RMS');
xlabel('Real LVDT position [in]');
ylabel('Error [in]');
% title('Measure Error x Real Position (with noise)');
legend('Location', 'best');

%% MEAN ABSOLUT ERROR (MAE)
mae_avg = mean(abs(error_all(:,1)));
mae_peak = mean(abs(error_all(:,2)));
mae_rms = mean(abs(error_all(:,3)));

mae_avg_noisy = mean(abs(error_all_noisy(:,1)));
mae_peak_noisy = mean(abs(error_all_noisy(:,2)));
mae_rms_noisy = mean(abs(error_all_noisy(:,3)));

fprintf('\n======================================================\n');
fprintf(' MEAN ABSOLUT ERROR (MAE)\n');
fprintf('======================================================\n');
fprintf('[WITHOUT NOISE]\n');
fprintf(' - Average : %.6f 10^{-3} in\n', mae_avg);
fprintf(' - Peak    : %.6f 10^{-3} in\n', mae_peak);
fprintf(' - RMS     : %.6f 10^{-3} in\n\n', mae_rms);

fprintf('[WITH NOISE (std = %.3f V)]\n', noise_std);
fprintf(' - Average : %.6f in\n', mae_avg_noisy);
fprintf(' - Peak    : %.6f in\n', mae_peak_noisy);
fprintf(' - RMS     : %.6f in\n', mae_rms_noisy);
fprintf('======================================================\n\n');

%% INPUT VECTORS
T_adc_A = array2table(adcSignalA_all);
T_adc_B = array2table(adcSignalB_all);
nomeArquivo = 'testVectors.xlsx';
writetable(T_adc_A, nomeArquivo, 'Sheet', 'Channel_A');
writetable(T_adc_B, nomeArquivo, 'Sheet', 'Channel_B');

T_adc_A_noisy = array2table(adcSignalA_all_noisy);
T_adc_B_noisy = array2table(adcSignalB_all_noisy);
nomeArquivo = 'testVectorsNoisy.xlsx';
writetable(T_adc_A_noisy, nomeArquivo, 'Sheet', 'Noisy_Channel_A');
writetable(T_adc_B_noisy, nomeArquivo, 'Sheet', 'Noisy_Channel_B');