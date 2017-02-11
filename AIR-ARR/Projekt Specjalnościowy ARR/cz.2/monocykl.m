clear all;
close all;

k = 1;
p2 = -7;
p3 = 12;

teta0 = 3;
x0 = 4;
y0 = 2;
v0 = 1;
w0 = 10;

sim('model_monocykl.slx',30);

figure();
plot(t,x);
title('x, y, teta, x1, x2, x3 -> 0');
grid on;
hold all on;
plot(t,y);
plot(t,teta);
plot(t,x1);
plot(t,x2);
plot(t,x3);


Mp = 97;
Mk = 5;
Mc = Mp + 2*Mk;
L = 0.3;
d = 0.0000000001;   % 10 miejsce
Rk = 0.075;
Iz = 6.609;

Izz = (Mk * d*d)/12 + (Mk*Rk*Rk)/4;
Ip = Iz + 2*Izz + 2*Mk*L*L;

M11 = Mc+2*Mk*L*L;
M22 = Ip/(L*L);

K = 100;
k1 = 1;
k2 = 1;

figure();
hold on;
grid on;
kolor = [ 'r' 'g' 'c' 'm' 'y' ];
i = 1;
for k = [100 1000 10000]
    sim('model_monocykl',30);
    plot(x,y,kolor(i));
    i = i+1;
end;