clf; clear

N = 1600;
Tobs = 1;
dt = Tobs/N;
fs = 1/dt
df = fs/N

t = 0:dt:Tobs-dt;
f = 0:df:fs-df;

z = [ones(1,200),-ones(1,200)];
x1 = [z,z,z,z];

fsin = 45;
A = 1;

x2 = A*sin(2*pi*fsin*t);

syg = x1+x2;

subplot(2,1,1);
hold on;
plot(t,syg,'-b');
plot(t,x1,'-r');
plot(t,x2,'-g');
grid on;

X = fft(syg);
XM = abs(X);
XM = XM/max(XM);

subplot(2,1,2);
stem(f,XM);
grid on;
