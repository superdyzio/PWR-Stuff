close all;
clear all;

for Kp = [50 300]
    Kd = Kp/5;
    sim('linearyzacja_EDDA.slx',60);
    figure();
    subplot(2,1,1);
    plot(t,e1);
    title('B��d po�o�enia pierwszego przegubu (e1)');
    xlabel('czas [s]');
    ylabel('b��d');
    hold on;
    grid on;
    subplot(2,1,2);
    plot(t,e2);
    title('B��d po�o�enia drugiego przegubu (e2)');
    xlabel('czas [s]');
    ylabel('b��d');
    hold on;
    grid on;
end;