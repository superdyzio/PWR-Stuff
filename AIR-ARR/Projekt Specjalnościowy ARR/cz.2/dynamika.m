clear all;
kinematyka;

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
R = 5;
w = 1;
k1 = 1;
k2 = 1;

x0 = 0;
y0 = 0;
teta0 = 0;

figure();
plot(xd,yd);
hold on;
grid on;
kolor = [ 'r' 'g' 'c' 'm' 'y' ];
i = 1;
for K = [100 1000 10000]
    sim('model_dynamika',20);
    plot(x,y,kolor(i));
    i = i+1;
end;

figure();
i = 1;
for K = [100 1000 10000]
    sim('model_dynamika',20);
    subplot(3,1,1);
    plot(t,xe);
    grid on;
    hold all on;
    xlabel('t');
    ylabel('xe');
    subplot(3,1,2);
    plot(t,ye);
    grid on;
    hold all on;
    xlabel('t');
    ylabel('ye');
    subplot(3,1,3);
    plot(t,tetae);
    grid on;
    hold all on;
    xlabel('t');
    ylabel('tetae');
    i = i+1;
end;