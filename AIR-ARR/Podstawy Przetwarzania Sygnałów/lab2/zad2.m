figure;
czas = 2;
N = 1000;
dt = czas/N;
t = 0:dt:czas-dt;
f = 10;
a = 20;
C = 1;
A = 1;

x1 = C*exp(-a*t);
x2 = A*sin(2*pi*f*t);
x3 = x1 .* x2;

subplot(3,1,1);
plot(t,x1);
grid on;
subplot(3,1,2);
plot(t,x2);
grid on;
subplot(3,1,3);
plot(t,x3);
grid on;
