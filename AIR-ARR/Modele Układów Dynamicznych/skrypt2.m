figure;
subplot (2,1,1);
hold all on;
grid on;
xlabel('Tzew [C]');
ylabel('Twew [C]');
title('Zaleznosc Twew od Tzew, qg parametrem, Tp = 10');

qgn = 1000;
Tzewn = -20;
Twewn = 20;
Tpn = 10;

x = [0; 0];
b = [4*qgn; 0];
a = [ (5*Twewn - 4*Tzewn - Tpn), 0; (Twewn - Tpn), (-4)*(Tpn-Tzewn)];

x = a\b;
Kcw = x(1);
Kcp = x(2);
Kcwp = Kcw / 4;

Tzew = -40 : 1 : 60;
qg = 0 : 500 : 6000;

for i = 1 : 1 : 12;
    Twew = (qg(i) + Kcw*Tzew + Kcwp*Tpn) / (Kcw + Kcwp);
    plot(Tzew,Twew);
end;

subplot(2,1,2);
hold all on;
grid on;
xlabel('Tzew [C]');
ylabel('Tp [C]');
title('Zaleznosc Tp od Tzew, qg parametrem, Twew = 20');

for i = 1 : 1 : 12;
    Tp = (Twewn*(Kcw+Kcwp) - qg(i) - Kcw*Tzew) / Kcwp;
    plot(Tzew,Tp);
end;