function [wynik, blad] = liczby(a)
    blad = false;
    if (a == 1)
        blad = true;
        wynik = 0;
    elseif mod(a,2) == 0
        wynik = a/2;
    else
        wynik = a*3+1;
    end;
end