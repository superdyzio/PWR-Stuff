clear all;

options = optimset('MaxFunEvals', 1000);

optymalne = fminsearch(@fzad2, [1.8 3.3 5], options);

% parametry obiektu
% N = 2;
% C = 1000;
% d = 3;
% B = C*C/(2*N);
% alfa = 2*N/(d*d*C);
% beta = 1 / d;
d = 3;
B = 2;
alfa = 12;
beta = 3;
zadana = 5;    % wartoœæ zadana


Ki = 1;
K = optymalne(1);
Ti = optymalne(2);
Td = optymalne(3);

sim('model', 60);

figure(1);
plot(t,y);
grid on;
title('regulacja przy optymalnych parametrach (fminsearch)');