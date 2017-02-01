% filtr IIR kreowany metoda zer i biegunow


clear all;	clf;	subplot(1,1,1);

f_choice = 1;		% 1 - dolnoprzepustowy, 2 - pasmowoprzepustowy

fs = 1000;		% czestotliwosc probkowania



if (f_choice == 1)
	
	fz = [50];	% czestotliwosc zera
	
	fp = [10];	% czestotliwosc bieguna
	
	Rz = [1];	% promien zera
	
	Rp = [0.96];	% promien bieguna
	
	fmax = 100; df = 0.1;	% parametry do transformaty Fouriera

endif



if (f_choice == 2)
	
	fz = [50 100 150 350 400 450];		% czestotliwosci zer
	
	fp = [200 220 240 260 280 300];		% czestotliwosci biegunow
	
	Rz = [1 1 1 1 1 1];			% promienie zer
	
	Rp = [0.9 0.65 0.9 0.65 0.9 0.65];	% promienie biegunow
	
	fmax = 500; df =1;		% parametry do transformaty Fouriera

endif



% obliczamy wartosci zespolone zer i biegunow

fi_z = 2*pi*fz/fs;			% katy zer

fi_p = 2*pi*fp/fs;			% katy biegunow

z = Rz .* exp(j*fi_z);			% zera w gornej polowie plaszczyzny

p = Rp .* exp(j*fi_p);			% bieguny w gornej polowie plaszczyzny

z = [z conj(z)];			% zera w parach ze sprzezeniami

p = [p conj(p)];			% bieguny w parach ze sprzezeniami



% wykres polozenia zer i biegunow na plaszczyznie z

NP = 1000;

fi = 2*pi*(0:NP-1)/NP;

s = sin(fi);	
c = cos(fi);


subplot(3,2,1);

plot(s,c,'-k',real(z),imag(z),'or',real(p),imag(p),'xb');	
grid on; 
xlabel('Re(z)'); 	ylabel('Im(z)');	
title('Zera i bieguny odpowiedzi czestotliwosciowej');



% obliczanie wspolczynnikow filtra

wzm = 1;

[b,a] = zp2tf(z',p',wzm);

b	

a			% wypisanie wyliczonych wspolczynnikow filtru



% obliczanie odpowiedzi czestotliwosciowej (transmitancji)

f = 0 : df : fmax;

w = 2*pi*f;

wn = 2*pi*f/fs;		% pulsacja unormowana


H = freqz(b,a,wn);

Habs = abs(H);

HdB = 20*log10(Habs);

Hfa = unwrap(angle(H));


subplot(3,2,3);

plot(f,Habs);	grid on;	title('|H(f)|');	xlabel('f[Hz]');



% subplot(3,2,5);

% plot(w/pi,Hdb);	grid on;	title ('abs(H) [dB]');



% tworzenie sygnalu testowego

Nx = 1024;

n = 0:Nx-1;

dt = 1/fs;

t = n*dt;

f1 = 10;	f2 = 50;	f3 = 250;

x1 = sin(2*pi*f1*t);

x2 = sin(2*pi*f2*t);

x3 = sin(2*pi*f3*t);


if (f_choice == 1)
	
		x = x1+x2;
	else
	
		x = x1+x2+x3;

endif



subplot(3,2,2);

plot(t,x); grid on; title('sygnal wejsciowy');



% filtracja sygnalu testowego

y = filter(b,a,x);


n = Nx/2+1:Nx;

X = freqz(x(n),1,wn)/(Nx/4);

Y = freqz(y(n),1,wn)/(Nx/4)
;
X = abs(X);

Y = abs(Y);


subplot(3,2,4);

plot(X);


subplot(3,2,6);

plot(Y);