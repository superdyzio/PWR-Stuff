k1 = 3;
k2 = 2;
Td = 1.5;
Tp = 0.1;
x = 0;

sim('regulator_pid',5);

plot(t,odp_skokowa);
grid on;
hold all;

x1 = 3;
x2 = 3.01;
y1 = odp_skokowa(300);
y2 = odp_skokowa(301);
m = (y2-y1) / (x2-x1);
c = y1 - m * x1;
styczna = m * t + c;
plot(t,styczna,'r');

max(odp_skokowa)