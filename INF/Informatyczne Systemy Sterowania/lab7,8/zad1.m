clear all;

% parametry obiektu
k0 = 2;
T1 = 3;
T2 = 4;
zadana = 5;    % warto�� zadana

% parametry regulator�w
dwu_on_tab = [1 0.5 0.1];
dwu_off_tab = [-1 -0.5 -0.1];
troj1_on_tab = [1 0.5 0.1];
troj1_off_tab = [0.5 0.3 0.1];
troj2_on_tab = [-0.5 -0.3 -0.1];
troj2_off_tab = [-1 -0.5 -0.1];

% regulator dwupo�o�eniowy bez histerezy
figure(1);
dwu_on = 0;
dwu_off = 0;
sim('model_dwu', 30);
subplot(3,1,1);
plot(t,y);
hold on;
grid on;
title('regulator 2po� bez histerezy');
subplot(3,1,2);
plot(e,ster);
title('zale�no�� sterowania od b��du');
grid on;
subplot(3,1,3);
plot(t,e);
title('przebieg b��du');
grid on;

% regulator dwupo�o�eniowy z histerez�
figure(2);
for i = 1 : 3;
    dwu_on = dwu_on_tab(i);
    dwu_off = dwu_off_tab(i);
    sim('model_dwu', 30);
    subplot(3,1,1);
    plot(t,y);
    hold on;
    grid on;
    subplot(3,1,2);
    plot(e,ster);
    hold on;
    grid on;
    subplot(3,1,3);
    plot(t,e);
    grid on;
    hold on;
end;
subplot(3,1,1);
title('regulator 2po� z histerez�');
legend('+-1', '+-0.5', '+-0.1');
subplot(3,1,2);
title('zale�no�� sterowania od b��du');
legend('+-1', '+-0.5', '+-0.1');
subplot(3,1,3);
title('przebieg b��du');
legend('+-1', '+-0.5', '+-0.1');

% regulator tr�jpo�o�eniowy bez histerezy
figure(3);
troj1_on = 0;
troj1_off = 0;
troj2_on = 0;
troj2_off = 0;
sim('model_troj', 30);
subplot(3,1,1);
plot(t,y);
hold on;
grid on;
title('regulator 3po� bez histerezy');
subplot(3,1,2);
plot(e,ster);
grid on;
title('zale�no�� sterowania od b��du');
subplot(3,1,3);
plot(t,e);
grid on;
title('przebieg b��du');

% regulator tr�jpo�o�eniowy z histerez�
figure(4);
for i = 1 : 3;
    troj1_on = troj1_on_tab(i);
    troj1_off = troj1_off_tab(i);
    troj2_on = troj2_on_tab(i);
    troj2_off = troj2_off_tab(i);
    subplot(3,1,1);
    sim('model_troj', 30);
    plot(t,y);
    hold on;
    grid on;
    subplot(3,1,2);
    plot(e,ster);
    hold on;
    grid on;
    subplot(3,1,3);
    plot(t,e);
    grid on;
    hold on;
end;
subplot(3,1,1);
title('regulator 3po� z histerez�');
legend('+-1', '+-0.5', '+-0.1');
subplot(3,1,2);
title('zale�no�� sterowania od b��du');
legend('+-1', '+-0.5', '+-0.1');
subplot(3,1,3);
title('przebieg b��du');
legend('+-1', '+-0.5', '+-0.1');

% zadanie lab
figure(5);
for T1 = [5 10 15];
    dwu_on = dwu_on_tab(3);
    dwu_off = dwu_off_tab(3);
    sim('model_dwu', 30);
    subplot(3,1,1);
    plot(t,y);
    hold on;
    grid on;
    subplot(3,1,2);
    plot(e,ster);
    hold on;
    grid on;
    subplot(3,1,3);
    plot(t,e);
    grid on;
    hold on;
end;
subplot(3,1,1);
title('regulator 2po� z histerez�');
legend('T1 = 5', 'T1 = 10', 'T1 = 15');
subplot(3,1,2);
title('zale�no�� sterowania od b��du');
legend('T1 = 5', 'T1 = 10', 'T1 = 15');
subplot(3,1,3);
title('przebieg b��du');
legend('T1 = 5', 'T1 = 10', 'T1 = 15');