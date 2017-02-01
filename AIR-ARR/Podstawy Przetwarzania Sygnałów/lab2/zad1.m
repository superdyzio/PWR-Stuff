figure;
N = 2000;
czas = 4;
t1 = 250;
t2 = 125;

dt = czas/N;
t = 0:dt:czas-dt;
f = 1;

x1 = 3.5*sin(2*pi*f*t);
x1 = (x1+abs(x1))/2;

z = [zeros(1,t1),ones(1,t2),-ones(1,t2)];
x2 = [z,z,z,z];

x3 = x1+x2;

wsr = sum(x3)/length(x3);
x4 = x3 - wsr;

subplot(4,1,1);
plot(t,x1);
grid on;
subplot(4,1,2);
plot(t,x2);
grid on;
subplot(4,1,3);
plot(t,x3);
grid on;
subplot(4,1,4);
plot(t,x4);
grid on;
