% projektowanie filtra pasmowoprzepustowego o czêst. próbkowania 4000 Hz
% przy u¿yciu funkcji FIR2 - czêst. graniczne 210 i 350 Hz (unormowane)

clear all;  clf;    subplot(1,1,1);

fs = 4000;      fg1 = 210;      fg2 = 350;                                  % zalozenia do tworzenia filtru
fN = fs/2;

fHz = [ 0 fg1 fg1 fg2 fg2 fN ];                                             % wektor czestotliwosci
fHz = fHz/fN;                                                               % unormowany wektor czestotliwosci
amp = [ 0 0 1 1 0 0 ];                                                      % wektor amplitud
N = 33;     M = (N-1)/2;                                                    % rzad filtru i jego polowa
filtr = fir2(N,fHz,amp);                                                    % tworzenie filtru za pomoca funkcji fir2(..)


n = 0:N;
h = ifft(filtr);                                                            % odwrotna transformacja filtru
h = real(h)/N;
subplot(3,2,1); 
stem(n-M,h);        grid on;                                                % wykres odpowiedzi impulsowej filtru
title(['Odpowiedz impulsowa filtru FIR - h(n) - rzad filtru = ',num2str(N)]);

[H,w] = freqz(filtr,1,128);
subplot(3,2,3);
plot(fHz,amp,'-r',w/pi,abs(H),'-b');
grid on;
title('Charakterystyki filtru: idealna i faktyczna');
legend('idealna','faktyczna |H|');

subplot(3,2,5);
hold on;
plot(w/pi,20*log10(abs(H)));                                                % wykres tlumienia
grid on;	title('abs(H) w [dB]');


% tworzenie sygnalu testowego i jego charakterystyk
deltaT = 1/fs;                                                              % okres probkowania
t = 0:deltaT:1-deltaT;                                                      % wektor czasu dla 1 sekundy
f1 = 120; f2 = 390;                                                         % czestotliwosci sygnalu testowego w [Hz]
s1 = sin(2*pi*f1*t);    s2 = sin(2*pi*f2*t);
syg = s1+s2;                                                                % sygnal testowy
syg = syg+randn(1,length(syg));                                             % zaszumienie sygnalu

subplot(3,2,2);
plot(t,syg);    grid on;    title('Sygnal testowy');
xlabel('Czas[s]');

F = fft(syg);   FM = abs(F);                                                % widmo sygnalu testowego
subplot(3,2,4);
plot(FM);   grid on;    title('Widmo amplitudowe sygnalu testowego');

% filtracja - splot sygnalu (syg) z odpowiedzia impulsowa (filtr)
y = conv(syg,filtr);                                                        % y - sygnal przefiltrowany
FF = abs(fft(y));                                                           % widmo amplitudowe (modul) sygnalu po filtrac1ii
subplot(3,2,6);
plot(FF);   grid on;    title('Widmo sygnalu testowego po filtracji');
axis([0,4000,0,2000]);