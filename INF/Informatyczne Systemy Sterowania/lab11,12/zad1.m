clear all;

% parametry obiektu
% N = 550;
% C = 8000;
% d = 10;
% B = C*C/(2*N);
% alfa = 2*N/(d*d*C);
% beta = 1 / d;
d = 3;
B = 2;
alfa = 12;
beta = 3;
zadana = 5;    % wartoœæ zadana

% regulator P
% wiêksze wzmocnienie -> mocniejsze oscylacje i wy¿sze wartoœci
Ki = 0;
Ti = 1;
Td = 0;

figure(1);
for K = [0.1 0.5 1 1.8 2.5];
    sim('model', 30);
    plot(t,y);
    hold on;
    grid on;
end;
title('P - ró¿ne wzmocnienia');
legend('K=0.1', 'K=0.5', 'K=1', 'K=1.8', 'K=2.5');


% regulator PI
% lepsza sta³a czasowa -> lepsze t³umienie oscylacji
K = 1.8;
Ki = 1;
Td = 0;

figure(2);
for Ti = [1 1.3 1.8 2.5 3.3];
    sim('model', 200);
    plot(t,y);
    hold on;
    grid on;
end;
title('PI - ró¿ne Ti');
legend('Ti=1', 'Ti=1.3', 'Ti=1.8', 'Ti=2.5', 'Ti=3.3');


% regulator PID
% lepsza sta³a czasowa -> lepsze wyg³adzanie i stabilizacja
K = 1.8;
Ki = 1;
Ti = 3.3;

figure(3);
for Td = [1 1.5 2 3 5];
    sim('model', 200);
    plot(t,y);
    hold on;
    grid on;
end;
title('PID - ró¿ne Td');
legend('Td=1', 'Td=1.5', 'Td=2', 'Td=3', 'Td=5');


% porónanie PD
K = 1.8;
Ki = 0;

figure(4);
for Td = [1 1.5 2 3 5];
    sim('model', 30);
    plot(t,y);
    hold on;
    grid on;
end;
title('PD - ró¿ne Td');
legend('Td=1', 'Td=1.5', 'Td=2', 'Td=3', 'Td=5');
