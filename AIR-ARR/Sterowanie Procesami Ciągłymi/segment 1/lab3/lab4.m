%dane
czas_symulacji=10;
stan=0;
Kr=4;
Td=3;
Ti=2;
tau=0.7;

%symulacja
sim('regulator_pid', czas_symulacji);

%identyfikacja czlonu dynamiki
x1=5;
y1=odp_skokowa(500);
x2=5.01;
y2=odp_skokowa(501);
m=(y2-y1)/(x2-x1);
c=y1-m*x1;
styczna=m*t+c;

%rysowanie wykresu
figure(1);
hold on all;
grid on;
axis([0 10 0 25]);
plot(t, odp_skokowa);
plot(t, styczna, 'r');



% %linie pierwiastkowe
% k1=1;
% sys1=tf([k1], [1 3 3 1+k1]);
% k2=8;
% sys2=tf([k2], [1 3 3 1+k2]);
% figure(2);
% grid on;
% hold on;
% subplot(1,2,1);
% rlocus(sys1);
% subplot(1,2,2);
% rlocus(sys2);



