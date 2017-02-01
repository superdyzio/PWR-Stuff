clear all;

x = 0;
czas = 10;
tau = 0.01;

min = 10^24;
kmin = 11;
Timin = 11;
Tdmin = 11;


for k = 2;
    for Ti = 4.5;
        i = 1;
        for Td = 0.5;
            d = 1;
            sim('model', czas);
            if (uchyb(size(uchyb,1)) < min)
                kmin = k;
                Timin = Ti;
                Tdmin = Td;
                min = uchyb(size(uchyb,1));
                emin = e;
                uchybmin = uchyb;
                odpmin = odp;
            end;
        end;
    end;
end;

figure(1);
title('Odpowiedz skokowa');
xlabel('czas');
hold all;
grid on;
plot(t, odpmin);

figure(2);
title('ISE');
xlabel('czas');
hold all;
grid on;
plot(t, uchybmin-0.1);

figure(3);
title('Uchyb');
xlabel('czas');
hold all;
grid on;
plot(t, emin);