function [wynik] = funkcja(t, x)
    a = 2;
    b = 0.2;
    c = 1;
    d = 0.1;

    wynik = [ a*x(1) - b*x(1)*x(2); c*x(1)*x(2) - d*x(2)];
end

