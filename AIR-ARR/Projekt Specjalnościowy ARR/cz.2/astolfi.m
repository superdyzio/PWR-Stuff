clear all;
close all;

k = 1;
p2 = -7;
p3 = 12;
sim('model_astolfi.slx');

figure;
hold all on;
plot(t,x1);
title('p2 = -7, p3 = 12');
plot(t,x2);
plot(t,x3);
legend('x1','x2','x3');