figure;
t1 = 0:0.002:1;
t2 = 1:0.002:2;
t3 = 2:0.002:3;
t4 = 3:0.002:4;
A = 3.5;

for i = 1:1:250;
	y1(i) = 3.5*sin(2*pi*t1(i));
end;
for i = 250:1:501;
	y1(i) = 0;
end;
for i = 1:1:250;
	y2(i) = 0;
end;
for i = 250:1:375;
	y2(i) = 1;
end;
for i = 375:1:501;
	y2(i) = (-1);
end;

suma = 0;
for i = 1:1:501;
	suma += y1(i)+y2(i);
end;
wsr = suma/500;

subplot(4,1,1);
plot(t1,y1);
hold on;
plot(t2,y1);
plot(t3,y1);
plot(t4,y1);
grid on;
subplot(4,1,2)
plot(t1,y2);
hold on;
plot(t2,y2);
plot(t3,y2);
plot(t4,y2);
grid on;
subplot(4,1,3);
plot(t1,y1+y2);
hold on;
plot(t2,y1+y2);
plot(t3,y1+y2);
plot(t4,y1+y2);
grid on;
subplot(4,1,4);
plot(t1,y1+y2-wsr);
hold on;
plot(t2,y1+y2-wsr);
plot(t3,y1+y2-wsr);
plot(t4,y1+y2-wsr);
grid on;
