clear all;

% parametry obiektu
a0 = 6;
a1 = 4;
a2 = 3;
a3 = 1;
b = 3;
zadana = 1;    % odpowiedü skokowa

% parametry regulatora - strojenie
K = 2;
Ki = 0;
Ti = 1;
Td = 0;
sim('model', 10);
Kg = 2;
Tg = 3.18;

figure(1);
plot(t, y);
grid on;
title('metoda zieglera-nicholsa; strojenie');


% parametry regulatora P - wyznaczone
K = 0.5 * Kg;
Ki = 0;
Ti = 1;
Td = 0;
sim('model', 40);

figure(2);
plot(t, y);
grid on;
title('metoda zieglera-nicholsa; regulator P');


% parametry regulatora PI - wyznaczone
K = 0.45 * Kg;
Ki = 1;
Ti = 0.85 * Tg;
Td = 0;
sim('model', 40);

figure(3);
plot(t, y);
grid on;
title('metoda zieglera-nicholsa; regulator PI');


% parametry regulatora PID - wyznaczone
K = 0.6 * Kg;
Ki = 1;
Ti = 0.5 * Tg;
Td = 0.125 * Tg;
sim('model', 40);

figure(4);
plot(t, y);
grid on;
title('metoda zieglera-nicholsa; regulator PID');