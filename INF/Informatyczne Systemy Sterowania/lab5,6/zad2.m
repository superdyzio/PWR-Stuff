clear all;

options = optimset('MaxFunEvals', 1000);

optymalne = fminsearch(@fzad2, [1.8 3.3 5], options);

% parametry obiektu
a0 = 6;
a1 = 4;
a2 = 3;
a3 = 1;
b = 3;
zadana = 25;    % wartoœæ zadana

Ki = 1;
K = optymalne(1);
Ti = optymalne(2);
Td = optymalne(3);

sim('model', 30);

figure(1);
plot(t,y);
grid on;
title('regulacja przy optymalnych parametrach (fminsearch)');