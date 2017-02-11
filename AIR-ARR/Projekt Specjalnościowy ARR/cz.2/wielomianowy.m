clear all;
close all;

x10 = 1;
x20 = 2;
x30 = 0;
x1T = 2;
x2T = 3;
x3T = 1;
T = 10;
x0 = x10;
y0 = x20;
teta0 = x30;

xz = [x30;
      -x10*cos(x30)-x20*sin(x30);
      -x10*sin(x30)+x20*cos(x30)];
xT = [x3T;
      -x1T*cos(x3T)-x2T*sin(x3T);
      -x1T*sin(x3T)+x2T*cos(x3T)];

b0 = (x1T-x10)/T;

c = [b0*T^3/6, -T^2/2; -b0*T^2/2, T]*[xT(2)-xz(2); xT(3)-xz(3)-b0*xz(2)*T]*-12/(b0*T^4);

b0
c

sim('model_wielomianowy.slx',T);

figure;
hold all on;
grid on;
plot(tout,XX1);
plot(tout,XX2);
plot(tout,XX3);
legend('X1','X2','X3');

figure;
hold all on;
grid on;
plot(x,y);

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

v0 = 0;
w0 = 0;

for K = [10 100 1000 10000 100000]
    sim('model_wielomianowy_dynamika',T);
    plot(x1,y1);
    legend('kin','10','100','1000','10000','100000');
end;