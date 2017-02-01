clear all;

% ustalone granice przedzialów
a = -10;
b = 10;
 
l = 24;     % wybrana liczba wêz³ów -1
 
% x = a : (b-a)/l : b;   % wêz³y równoodleg³e

for i = 1 : 1 : l+1;
    x(i) = (a-b) * cos((2*i-1)*pi/(2*l+2)) / 2 + (a+b) / 2;   % wêz³y Czebyszewa
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