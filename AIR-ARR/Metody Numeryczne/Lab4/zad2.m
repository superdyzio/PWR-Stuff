clear all;

load('dane.mat');
w = A(:,1);
y = A(:,2);

l = size(w);     % liczba w�z��w - 1

% w = a : (b-a)/l : b;       % w�z�y r�wnoodleg�e

% for i = 1 : 1 : l+1;
%    w(i) = (a-b) * cos((2*i-1)*pi/(2*l+2)) / 2 + (a+b) / 2;   % w�z�y Czebyszewa
% end;

[xi yi] = Lagrange(w,y);

figure();
hold on;
grid on;
plot(xi,yi);
plot(w,y,'bo');
title('Lagrange, 50 wezlow');

[xi yi] = Newton(w,y);

figure();
hold on;
grid on;
plot(xi,yi);
plot(w,y,'bo');
title('Newton, 50 wezlow');

[xi yi] = Vandermonde(w,y);

figure();
hold on;
grid on;
plot(xi,yi);
plot(w,y,'bo');
title('Vandermonde, 50 wezlow');