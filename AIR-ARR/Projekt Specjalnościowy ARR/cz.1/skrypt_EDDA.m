close all;
clear all;

P = 1;              % nastawa regulatora PD (D = P/10)

for P = [20 200 2000 20000];
    sim('PD_EDDA.slx',20);
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
    ylabel('b��d')
    hold on;
    grid on;
end;