%Dane:

a=2;
omega=10;
czas=10;

u=[0,1,2,3,4,5,6,7,8,9;1,0,0,0,0,0,0,0,0,0]';


sim('model', czas);

figure(1);
hold on;
title('Z(1)');
xlabel('x');
ylabel('odp');
stem(odp1);

figure(2);
hold on;
title('Z(a^n)');
xlabel('x');
ylabel('odp');
stem(odp2);

figure(3);
hold on;
title('Z(n)');
xlabel('x');
ylabel('odp');
stem(odp3);

figure(4);
hold on;
title('Z(n^2)');
xlabel('x');
ylabel('odp');
stem(odp4);

figure(5);
hold on;
title('Z(coswn)');
xlabel('x');
ylabel('odp');
stem(odp5);