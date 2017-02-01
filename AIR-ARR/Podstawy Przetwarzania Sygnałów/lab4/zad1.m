% pro1iektowanie filtra cyfrowego FIR typu I
% metoda probkowanie w dziedzinie czestotliwosci
% typ 1 - odpowiedz impulsowa symetryczna (zerowa czesc uro1iona transmitanc1ii)
% dlugosc odpowiedz impulsowe1i N=2L+1

clear all;	clf;	subplot(1,1,1);
% okno = 0;	% bez okna, czyli okno prostokatne
okno = 1;	% z oknem Blackmana

% N = 33;		% dlugosc odpowiedzi impulsowe1i (rzad filtru)
N = 129;
disp(['Rzad filtru',num2str(N)]);

% M musi byc podzielne przez 8
M = (N-1)/2;
M2 = M/2;	M4 = M/4;
z2 = zeros(1,M2);	j2 = ones(1,M2);
z4 = zeros(1,M4);	j4 = ones(1,M4);

% tworzenie charakterystyki czestotliwosciowe1i
Ar = [1 j2 z2 z2 j2];	% czesc rzeczywista charakterystyki czestotliwosciowe1i
Ai = zeros(1,N);	% czesc uro1iona
A = Ar+1i*Ai;		% zespolona charakterytyka czestotliwosciowa

% obliczanie idft czyli rzeczywiste1i h(n)
n = 0:N-1;	% indeksy odpowiedzi impulsowe1i
f = n/N;	% czestotliwosc unormowana
h = zeros(1,N);
for k=0:N-1;
	h = h + A(k+1)*exp(1i*2*pi*k/N*(n-M));	% (n-M) przesuwa kolowo h(n) o M probek w prawo
end;
h = real(h)/N;		% unormowanie idft
if (okno == 1)		% przypadek gdy jest okno
	h = h.*blackman(N)';	% zmienic funkcje okna
end;
subplot(3,2,1);
stem(n-(N-1)/2,h);
grid on;
title(['Odp. impulsowa filtru FIR - h(n). Rzad filtru N = ',num2str(N)]);
% disp('Pause 1 - Dowolny klaiwsz...'); pause

% obliczanie transmitanc1ii filtru - H(m)
NF = 1000;	% liczba probek transmitanc1ii filtru
k = 0:NF-1;	% indeksy dla kole1inych wartosci czestotliwosci
fn = k/NF;	% czestotliwosc unormowana
for k=0:NF-1;
	H(k+1) = exp(-1i*2*pi*k/NF*(n-N))*h';
end;

% to samo mozna wykonac funkc1ia freqz
% wn = 2*pi*fn;		% pulsac1ia unormowana dla funkc1ii freqz
% H = freqz(h,1,wn);	H = H.*exp(1i*wn*N);

subplot(3,2,3);
plot(f,Ar,'-r',fn,abs(H),'-b');	grid on;
title('Charakterystyki filtru: idealna i faktczyna');
legend('idealna','faktyczna |H|');
% disp('Puase 2 - Dowolny klaiwsz...'); pause

subplot(3,2,5)		% wykresy Ar i H w skali logarytmiczne1i
plot(f,20*log10(Ar),'-r',fn,20*log10(abs(H)),'-b');
grid on;	title('abs(H) w [dB]');
% disp('Pause 3 - Dowolny klawisz...'); pause


% tworzenie sygnalu testowego i jego charakterystyk
fs = 1000;		% czetotliwosc probkowania w [Hz]
deltaT = 1/fs;		% okres probkowania
t = 0:deltaT:1-deltaT;	% wektor czasu dla 1 sekundy
f1 = 120; f2 = 390;	% czestotliwosci sygnalu testowego w [Hz]
s1 = sin(2*pi*f1*t);
s2 = sin(2*pi*f2*t);
syg = s1+s2;		% sygnal testowy
syg = syg+randn(1,length(syg));		% zaszumienie sygnalu

subplot(3,2,2);
plot(t,syg); grid on; title('Sygnal testowy');
xlabel('Czas[s]');
% disp('Pause 4 - Dowolny klaiwsz...'); pause

F = fft(syg); FM = abs(F);	% widmo sygnalu testowego
subplot(3,2,4);
plot(FM); grid on; title('Widmo amplitudowe sygnalu testowego');

% filtrac1ia - splot sygnalu (syg) z odpowiedzia impulsowa (h)
y = conv(syg,h);	% y - sygnal przefiltrowany
FF = abs(fft(y));	% widmo amplitudowe (modul) sygnalu po filtrac1ii
% FF = F.*H;		% zespolone widmo sygnalu testowego po filtrac1ii
% FF = abs(FF);
subplot(3,2,6);
plot(FF); grid on; title('Widmo sygnalu testowego po filtracji');
