clear all;

% ustalone granice przedzial�w
a = -10;
b = 10;
 
l = 24;     % wybrana liczba w�z��w -1
 
% x = a : (b-a)/l : b;   % w�z�y r�wnoodleg�e

for i = 1 : 1 : l+1;
    x(i) = (a-b) * cos((2*i-1)*pi/(2*l+2)) / 2 + (a+b) / 2;   % w�z�y Czebyszewa
end;

y1 = exp(x);
y2 = 1 ./ (1+x.^2);

% [xi yi] = Lagrange(x,y2);
[xi yi] = Newton(x,y2);
% [xi yi] = Vandermonde(x,y2);

figure;
hold on; 
grid on;
plot(xi,yi);
plot(x,y2,' bo');
title('Lagrange, 16 wezlow');