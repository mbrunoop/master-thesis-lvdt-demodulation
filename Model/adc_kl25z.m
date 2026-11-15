function [D_out] = adc_kl25z(Vin, bits, Vrefh, Vrefl)
    % ADC_KL25Z Modela a conversão A/D do FRDM-KL25Z (modo single-ended).
    %
    % Entradas:
    %   Vin   - Tensão ou vetor de tensões de entrada (V)
    %   bits  - Resolução: 8, 10, 12 ou 16 (padrão: 12)
    %   Vrefh - Tensão de referência superior (padrão: 3.3 V)
    %   Vrefl - Tensão de referência inferior (padrão: 0.0 V)
    %
    % Saídas:
    %   D_out   - Código digital inteiro correspondente
    %   V_quant - Tensão reconstruída após a quantização (V)

    % Valores padrão caso não sejam informados
    if nargin < 4, Vrefl = 0.0; end
    if nargin < 3, Vrefh = 3.3; end
    if nargin < 2, bits = 12;   end

    % Validação da resolução suportada pelo KL25Z
    if ~ismember(bits, [8, 10, 12, 16])
        error('A resolução do KL25Z deve ser 8, 10, 12 ou 16 bits.');
    end

    % Saturação física da entrada (o ADC satura nos limites das referências)
    Vin_clamped = min(max(Vin, Vrefl), Vrefh);

    % Número total de níveis de quantização
    n_levels = 2^bits - 1;

    % Cálculo do código digital (arredondamento para o nível mais próximo)
    D_out = round(((Vin_clamped - Vrefl) / (Vrefh - Vrefl)) * n_levels);

    % Tensão quantizada (reconstrução analógica)
    % V_quant = Vrefl + (D_out / n_levels) * (Vrefh - Vrefl);
end