figure;
T = 2;
N = 800;
f = 1/2;
A = 1;
dt = T/N;
a = 1;
C = 1;
t1 = 0:dt:(T/2)-dt;
t2 = T/2:dt:T-dt;

y1 = 1 - A*sin(2*pi*f*t1);
y2 = C * exp(-a*t1);

plot(t1,y1); hold on; plot(t2,y2);
