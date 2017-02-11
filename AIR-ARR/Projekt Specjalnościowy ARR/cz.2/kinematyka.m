clear all;
close all;

R = 5;
w = 1;
k1 = 1;
k2 = 1;

x0 = 0;
y0 = 0;
teta0 = 0;

sim('model_kinematyka',100);

figure();
plot(xd,yd);
grid on;
hold on;
plot(x,y,'-r');
title('Œledzenie trajektorii');
xlabel('x');
ylabel('y');

figure();
subplot(3,1,1);
plot(t,xe);
grid on;
xlabel('t');
ylabel('xe');
subplot(3,1,2);
plot(t,ye);
grid on;
xlabel('t');
ylabel('ye');
subplot(3,1,3);
plot(t,tetae);
grid on;
xlabel('t');
ylabel('tetae');