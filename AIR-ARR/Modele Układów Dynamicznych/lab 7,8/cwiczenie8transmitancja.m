clear all;
a1 = 4; %powierzchnia Z1
a2 = 5; %powierzchnia Z2
A1 = 2; %wspolczynnik przy h1 
A2 = 4; %wspolczynnik przy h2
g = 10;
u0max = 3;
tabu0 = [0 0.5*u0max 0.9*u0max];
du = 0.1*u0max;
czas_skoku = 2;

for i = 1:3;
    figure;
    u0 = tabu0(i);
    h10 = u0/a1;
    h20 = u0/a2;
    sim('sim8transmitancja');
    subplot(2,1,1);
    plot(t,y1);
    title('h1(t)');
    grid on;
    subplot(2,1,2);
    plot(t,y2);
    title('h2(t)');
    grid on;
end;