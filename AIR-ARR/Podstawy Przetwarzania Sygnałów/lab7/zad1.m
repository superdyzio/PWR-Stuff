% analiza harmoniczna sygnalu rzeczywistego

[y, fs, bits] = wavread('bizon.wav');	% wczytanie pliku wav do programu

% wyswietlanie fs i bits
disp(['Czestotliwosc probkowania, fs = ',num2str(fs)]);
disp(['bitrate = ',num2str(bits)]);

[rozmiar, kanaly] = size(y);		% liczba probek
disp(['Liczba probek = ',num2str(rozmiar)]);
disp(['Liczba kanalow = ',num2str(kanaly)]);

yfft = abs(fft(y));		% modul fft
yn = yfft(1:round(rozmiar/2));	% polowa charakterystyki
dt = 1/fs;
disp(['Delta t = ',num2str(dt)]);
tobs = rozmiar/fs;		% czas trwania sygnalu dzwiekowego
df = fs/rozmiar;		% rozdzielczosc widma
disp(['Rozdzielczosc widma = Delta_f = ',num2str(df)]);

t = 0:dt:tobs-dt;
f = 0:df:(round(rozmiar/2-1))*df;

subplot(2,1,1);
plot(t,y);	grid on;	
title('Wykres sygnalu rzeczywistego'); xlabel('czas');

subplot(2,1,2);			% wykres charakterystyki amplitudowej
plot(f,yn);	grid on;	
title('wykres charakterystyki amplitudowej'); xlabel('Hz');
