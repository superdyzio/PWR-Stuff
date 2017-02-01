a = 2;
u = [0,1,2,3,4,5,6,7,8,9;1,0,0,0,0,0,0,0,0,0]';
omega = 10;

sim('model',5);

figure(1);
stem(odp1);

figure(2);
stem(odp2);

figure(3);
stem(odp3);

figure(4);
stem(odp4);

figure(5);
stem(odp5);

figure(6);
stem(odp6);