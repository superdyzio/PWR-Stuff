% definiujemy pierwszy z zadanych przedzia³ów
a = -3;
b = -1;

%%%%%%%%%% METODA SIECZNYCH 

xa = -2.1;
xb = -1;
fa = xa^3 + xa^2 - 3*xa - 2;
fb = xb^3 + xb^2 - 3*xb - 2;
x0 = xa - fa * (xb - xa) / (fb - fa);
f0 = x0^3 + x0^2 - 3*x0 - 2;

iteracje = 0; 

while abs(f0) > 10^-6;
    p1 = fa * f0;
    p2 = f0 * fb;
    if p1 < 0;
        xb = x0;
    end;
    if p2 < 0;
        xa = x0;
    end;
    fa = xa^3 + xa^2 - 3*xa - 2;
    fb = xb^3 + xb^2 - 3*xb - 2;
    x0 = xa - fa * (xb - xa) / (fb - fa);
    f0 = x0^3 + x0^2 - 3*x0 - 2;
    iteracje = iteracje + 1;
end;

disp('Wynik dla przedzialu [-3,-1]:');
x0
iteracje

% definiujemy drugi z zadanych przedzia³ów
a = -1;
b = 1;

x = (a+b)/2;    % œrodek zadanego przedzia³u
f = x^3 + x^2 - 3*x - 2;

%%%%%%%%%% METODA SIECZNYCH 

xa = -1;
xb = 1;
fa = xa^3 + xa^2 - 3*xa - 2;
fb = xb^3 + xb^2 - 3*xb - 2;
x0 = xa - fa * (xb - xa) / (fb - fa);
f0 = x0^3 + x0^2 - 3*x0 - 2;

iteracje = 0;

while abs(f0) > 10^-6;
    p1 = fa * f0;
    p2 = f0 * fb;
    if p1 < 0;
        xb = x0;
    end;
    if p2 < 0;
        xa = x0;
    end;
    fa = xa^3 + xa^2 - 3*xa - 2;
    fb = xb^3 + xb^2 - 3*xb - 2;
    x0 = xa - fa * (xb - xa) / (fb - fa);
    f0 = x0^3 + x0^2 - 3*x0 - 2;
    iteracje = iteracje + 1;
end;

disp('Wynik dla przedzialu [-1,1]:');
x0
iteracje