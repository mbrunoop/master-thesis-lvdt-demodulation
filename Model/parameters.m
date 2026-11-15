%% SAMPLING PARAMETERS
samplesPerCycle = 332;
sampleFrequency = 1000; % Hz
samplePeriod = 1/sampleFrequency; % seconds

%% LVDT OUTPUT PARAMETERS
lvdtFrequency = sampleFrequency/samplesPerCycle; % Hz
lvdtPeriod = 1/lvdtFrequency; % seconds
maxRatio = 0.5;
maxStroke = 5; % inches (127 mm)
K = maxStroke/maxRatio;

%% SIMULATION PARAMETERS
MST = 1e-3; % seconds;
stopTime = 10*lvdtPeriod; % seconds;
