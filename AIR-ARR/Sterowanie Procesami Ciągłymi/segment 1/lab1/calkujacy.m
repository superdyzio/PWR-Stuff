d = 0;          % opoznienie skoku
k = 3;
T = 2;

% symulacja
sim('model', 20);

% rysowanie wykresu odpowiedzi skokowej
figure(1);
title('Odpowiedz skokowa');
xlabel('t');
plot(t, odp_skok, 'b');
grid on;
hold on;
x1 = 10;
x2 = 10.01;
y1 = k * ( x1 - T * ( 1 - exp(-x1/T)));
y2 = k * ( x2 - T * ( 1 - exp(-x2/T)));
m = (y2-y1)/(x2-x1);
c = y1 - m * x1;
s = m * t + c;
styczna = s - s(1);
plot(t,styczna, 'r',t,s,'g');
(styczna(1002) - odp_skok(1002))/2

% charakterystyka amplitudowo-fazowa (tradycyjnie)
sys = tf( [ k ] , [ T 1 0 ] );
w = 0:0.01:20;
r = freqresp(sys,w);
for i = 1 : 1001
    rr(i) = r(1,1,i);
end;
figure(2);
title('Charakterystyka amplitudowo-fazowa');
xlabel('ReK(jw)');
ylabel('ImK(jw)');
plot(rr, 'bo');
grid on;
hold on;
bode(sys);
grid on;
        
% charakterystyka amplitudowo-fazowa (XY Graph)
sim('XYGraph');
      