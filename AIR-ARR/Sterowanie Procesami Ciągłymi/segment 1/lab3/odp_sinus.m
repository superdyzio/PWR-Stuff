czas=10*pi;

sim('sinus', czas);

x=0:pi/36:10*pi;
y=sin(x);

figure(1);
hold on;
grid on;
%axis([0 18.84 -1 1]);
plot(t, odpowiedz, 'r');
plot(x, y, 'b');