clear all;

[t,y] = ode45(@funkcja, [0 3], [50 100]);

plot(t,y)

sim('model',3);

figure(2);
subplot(2,1,1);
plot(time,x1out);
subplot(2,1,2);
plot(time,x2out);