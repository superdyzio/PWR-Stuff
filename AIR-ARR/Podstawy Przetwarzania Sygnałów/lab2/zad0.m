figure;
t = 0:0.002:2;
szum = randn(size(t));

subplot(2,2,1);
y1 = sin(3*t);
plot(t,y1);
grid on;
axis([0,2,(-2),2]);
xlabel('t');
ylabel('y');
title('y = sin(3t)');

subplot(2,2,3);
y2 = 0.3 * sin(10*t);
plot(t,y2);
grid on;
axis([0,2,(-2),2]);
xlabel('t');
ylabel('y');
title('y = 0.3sin(10t)');

subplot(2,2,2);
plot(t,y1+y2);
grid on;
axis([0,2,(-2),2]);
xlabel('t');
ylabel('y');
title('y = sin(3t) + 0.3sin(10t)');

subplot(2,2,4);
plot(t,y1+y2+szum);
grid on;
axis([0,2,(-4),4]);
xlabel('t');
ylabel('y');
title('szum bialy');
