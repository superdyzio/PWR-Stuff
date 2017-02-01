figure;
x = (-5)*pi : pi/100 : 5*pi;
szum = randn(size(x));

subplot(2,2,1);
y1 = sin(3*x);
plot(x,y1);
grid on;
axis([(-8),8,(-2),2]);
xlabel('x');
ylabel('y');
title('y = sin(3x)');

subplot(2,2,3);
y2 = 0.3 * sin(10*x);
plot(x,y2);
grid on;
axis([(-8),8,(-0.5),0.5]);
xlabel('x');
ylabel('y');
title('y = 0.3sin(10x)');

subplot(2,2,2);
plot(x,y1+y2);
grid on;
axis([(-8),8,(-2),2]);
xlabel('x');
ylabel('y');
title('y = sin(3x) + 0.3sin(10x)');

subplot(2,2,4);
plot(x,y1+y2+szum);
grid on;
axis([(-8),8,(-4),4]);
xlabel('x');
ylabel('y');
title('szum bia³y');