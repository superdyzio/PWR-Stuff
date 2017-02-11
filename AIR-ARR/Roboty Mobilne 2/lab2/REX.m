clear all;

stala=0.1;
q0=0.1;

omega=0.15;
vd=1.5;
R=10;
g=9.81;

mi=0.9;
fr=0.1;

I=4.4; %bylo 4,45
Ik=0.15; %moment bezwladnosci kol
Ip=I;
mp=45;
mk=2.38;
r=0.127;

a=0.365;
b=0.365;
c=0.387;
d=0.387;
tt=0.387;

Kd=300;
k1=1;
k2=1;
lambda=10;

x0=-5;
y0=2;
th0=0;

wzm=0;
enk=0;


a200W_silnik_370355_36V_przekl_100
silnik_136211
przekladnia_223095
sim('platforma3',10);
ys = I_start;
while length(t) > length(ys)
    ys = [ys I_start];
end;
yc = I_cont;
while length(t) > length(yc)
    yc = [yc I_cont];
end;
figure(1);
subplot(2,1,1);
plot(t,I1);
grid on;
hold all on;
plot(t,ys,'-r');
plot(t,yc,'-g');
plot(t,-ys,'-r');
plot(t,-yc,'-g');
subplot(2,1,2);
plot(t,I2);
grid on;
hold all on;
plot(t,ys,'-r');
plot(t,yc,'-g');
plot(t,-ys,'-r');
plot(t,-yc,'-g');