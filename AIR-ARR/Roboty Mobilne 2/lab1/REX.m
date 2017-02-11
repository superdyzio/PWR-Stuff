stala=0.1;
q0=0.1;

omega=0.1;
R=10;
g=9.81;

% mi=0.9;
% fr=0.1;
mi = 0;
fr = 0;

I=6; %bylo 4,45
Ik=0.15; %moment bezwladnosci kol
Ip=I;
mp=40;
mk=2.38;
r=0.127;

a=0.365;
b=0.365;
c=0.387;
d=0.387;
tt=0.387;

Kd=500;
k1=1;
k2=1;
lambda=10;

x0=-5;
y0=2;
th0=0;

wzm=0;
enk=0;

mkdir('sym');
sciezka = pwd;
for Kd = 100 : 100 : 1000
    for k1 = 0.1 : 0.1 : 2
        for k2 = 0.1 : 0.1 : 2
            sim('platforma3a');
            cd('sym');
            nazwa = sprintf('Kd_%d_k1_%d,k2_%d',Kd,k1,k2)
            mkdir(nazwa);
            cd(nazwa);
            figure(1);
            plot(x,y);
            hold on;
            grid on;
            plot(xd,yd,'-.r');
            xlabel('x [m]');
            ylabel('y [m]');
            title('trajektoria');
            print('trajektorie','-dpng');
            close;
            figure(2);
            subplot(2,1,1);
            plot(t,ex);
            grid on;
            subplot(2,1,2);
            plot(t,ey);
            grid on;
            print('bledy','-dpng');
            close;
            figure(3);
            subplot(3,1,1);
            plot(t,tau1);
            grid on
            subplot(3,1,2);
            plot(t,tau2);
            grid on;
            subplot(3,1,3);
            plot(t,tau3);
            grid on;
            print('sterowania','-dpng');
            cd(sciezka);
            close;
        end;
    end;
end;