% definiujemy pierwszy z zadanych przedzia��w
a = -2.1;
b = -1;

x = (a+b)/2;    % �rodek zadanego przedzia�u
f = x^3 + x^2 - 3*x - 2;

%%%%%%%%%% METODA BISEKCJI

iteracje = 0;

while abs(f) > 10^-6;
    p1 = (a^3 + a^2 - 3*a - 2) * f;
    p2 = (b^3 + b^2 - 3*b - 2) * f;
    if p1 < 0;
        b = x;
    end;
    if p2 < 0;
        a = x;
    end;
    x = (a+b)/2;
    f = x^3 + x^2 - 3*x - 2;
    iteracje = iteracje+1;
end;


 disp('Wynik dla przedzialu [-3,-1]:');
 x
 iteracje


% definiujemy drugi z zadanych przedzia��w
a = -1;
b = 1;

x = (a+b)/2;    % �rodek zadanego przedzia�u
f = x^3 + x^2 - 3*x - 2;

%%%%%%%%%% METODA BISEKCJI

iteracje = 0;

while abs(f) > 10^-6;
    p1 = (a^3 + a^2 - 3*a - 2) * f;
    p2 = (b^3 + b^2 - 3*b - 2) * f;
    if p1 < 0;
        b = x;
    end;
    if p2 < 0;
        a = x;
    end;
    x = (a+b)/2;
    f = x^3 + x^2 - 3*x - 2;
    iteracje = iteracje + 1;
end;


disp('Wynik dla przedzialu [-1,1]:');
x
iteracje
