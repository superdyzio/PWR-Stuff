k1 = 10;
k2 = 6;
Td = 5;
Tp = 0.2;
x = 0;

sim('model_pid',5);

plot(t,odp_skok,'b');
grid on;