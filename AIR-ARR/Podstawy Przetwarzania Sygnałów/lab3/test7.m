% DFT 3 sygnalow sinusoidalnych

clf; clear
N = 1000;	% ilosc probek
Tobs = 1;	% czas obserwacji
f1 = 22.2;	
f2 = 35.5;	% czestotliwosci
f3 = 487.8;
A1 = 4;
A2 = 3;		% amplitudy
A3 = 2;
dt = Tobs / N;	% odstep probkowania

t = 0:dt:Tobs-dt;		% wektor czasu
s1 = A1*sin(2*pi*f1*t);
s2 = A2*sin(2*pi*f2*t);		% wektory sinusoid
s3 = A3*sin(2*pi*f3*t);

syg = s1+s2+s3;		% suma sygnalow
% syg = syg+4*randn(1,length(syg));	% sygnal+szum

subplot(2,1,1);
plot(t,syg);
grid on;
xlabel('Czas[s]');

fs = 1/dt		% czestotliwosc probkowania
df = fs/N		% rozdzielczosc widma
f = 0:df:fs-df;		% wektor czestotliwosci
X = fft(syg);		% obliczenie DFT
XM = abs(X);		% modul DFT (charakterystyka amplitudowa)
XM = XM/max(XM);	% normowanie widma do wartosci maksymalnej

subplot(2,1,2);
% stem(f(1:150),XM(1:150));
% grid on;
% axis([0,75,0,max(XM)]);
stem(f,XM);
grid on;
xlabel('Czestotliwosc [Hz]');
