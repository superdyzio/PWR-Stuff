%wprowadzamy zmienne
x=5; %opoznienie
k=1; %wzmocnienie
T=2; %czas rozniczkowania

%symulacja
sim('rozniczkujacy', 30);

%rysowanie wykresu odpowiedzi skokowej
figure(1);
title('Odpowiedz skokowa');
xlabel('t');
ylabel('A');
hold all;
grid on;
plot(t, odp_skokowa, 'b');

%charakterystyka amplitudowo-fazowa (XY Graph)
sim('XYGraph');

%charakterystyka amplitudowo-fazowa (tradycyjnie)
sys=tf([k 0], [T 1]);
w=0:0.01:20;
r=freqresp(sys,w);
for i=1:1001
    rr(i)=r(1,1,i);
end;
figure(2);
grid on;
hold on;
title('Charakterystyka amplitudowo-fazowa');
axis([-0.1 0.6 -0.1 0.3]);
xlabel('ReK(jw)');
ylabel('ImK(jw)');
plot(rr, 'bo');


