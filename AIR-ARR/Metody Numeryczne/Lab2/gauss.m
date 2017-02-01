% MACIERZ = zmienna przechowuj¹ca informacjê o wybranej do dalszych dzia³añ macierzy
%   1 - macierz 2x2 z punktu a)
%   2 - macierz Vandermonde'a o rozmiarze 20x20
%   3 - macierz trójprzek¹tniowa z przek¹tn¹ dominuj¹c¹
%   4 - macierz trójprzek¹tniowa bez przek¹tnej dominuj¹cej
%   5 - dowolna wprowadzona macierz
 
clear all;
format longeng;

MACIERZ = 4;

%%%%%%%%%%%%%%%%%%%% DEFINIOWANIE MACIERZY

if MACIERZ == 1;
    rozmiar = 2;
    A = [ 10^-10 1 ; 3 10^-12 ];
    wyznacznik = det(A);
end;

if MACIERZ == 2;
    rozmiar = 20;
    for i = 1 : 1 : rozmiar;
        for j = 1 : 1 : rozmiar;
            A(i,j) = i^(j-1);
        end;
    end;
    wyznacznik = det(A);
end;
    
if MACIERZ == 3;
    rozmiar = 15;
    for i = 1 : 1 : rozmiar;
        for j = 3 : 1 : rozmiar;
            A(i,j) = 0;
            A(j,i) = 0;
        end;
    end;
    for i = 1 : 1 : rozmiar;
        A(i,i) = rand()+2;
    end;
    for i = 1 : 1 : rozmiar-1;
        A(i+1,i) = rand();
        A(i,i+1) = rand();
    end;
    wyznacznik = det(A);
end;

if MACIERZ == 4;
    rozmiar = 15;
    for i = 1 : 1 : rozmiar;
        for j = 3 : 1 : rozmiar;
            A(i,j) = 0;
            A(j,i) = 0;
        end;
    end;
    for i = 1 : 1 : rozmiar;
        A(i,i) = rand();
    end;
    for i = 1 : 1 : rozmiar-1;
        A(i+1,i) = rand()+0.5;
        A(i,i+1) = rand()+0.5;
    end;
    wyznacznik = det(A);
end;

if MACIERZ == 5;
    rozmiar = 5;
    A = [ 1 1 0 1 -3 ; 2 0 -1 0 -2 ; 1 -1 -2 1 -2 ; 2 0 1 0 1 ; -3 -1 1 2 2 ];
    wyznacznik = det(A);
end;

%%%%%%%%%%%%%%%%%%%% ALGORYTM GAUSSA

wolne = rand(rozmiar,1);        % wektor wyrazów wolnych
x = zeros(rozmiar,1);           % wektor wartoœci x
koniec = false;                 % zmienna pomocnicza mówi¹ca o b³êdzie w algorytmie
e = 10^-24;                     % b³¹d przybli¿enia
mnoznik = 0;        % wartoœæ przez jak¹ przemna¿amy dodawany do innego wiersz
suma = 0;           % zmienna na podstawie której wyznaczamy koñcow¹ wartoœæ danego x
M = [ A wolne ];    % macierz A z do³¹czon¹ kolumn¹ wyrazów wolnych
i = 1;
j = 1;
k = 1;

while koniec == false && i <= rozmiar;
    j = i+1;
    while koniec == false && j <= rozmiar;
        if abs(M(i,i)) < e;
            koniec = true;
        end;
        if koniec == false;
            mnoznik = -M(j,i)/M(i,i);       % wyznaczanie wartoœci wspó³czynnika
        end;
        k = 1;
        while koniec == false && k <= rozmiar+1;
            M(j,k) = M(j,k) + mnoznik * M(i,k);     % sumowanie wierszy
            k = k+1;
        end;
        j = j+1;
    end;
    i = i+1;
end;
i = rozmiar;
while koniec == false && i > 0;
    suma = M(i,rozmiar+1);      % pobranie odpowiedniego wyrazu wolnego
    j = rozmiar;
    while koniec == false && j > i;
        suma = suma - M(i,j) * x(j);        % pomniejszanie wyrazu wolnego o odpowiednie iloczyny
        j = j-1;
    end;
    if abs(M(i,i)) < e;
        koniec = true;
    end;
    if koniec == false;
        x(i) = suma / M(i,i);           % wyznaczanie koñcowej wartoœci x
    end;
    i = i-1;
end;
                 
% b³¹d bezwzglêdny
blad = norm(A*x-wolne);

% obliczanie wyznacznika macierzy
if MACIERZ == 1;
    q = 0;
    while q <= rozmiar;
        wyliczonywyznacznik = A(1,1)*A(2,2) - A(1,2)*A(2,1);
        q = q+1;
    end;
end;
if MACIERZ == 2;
    wyliczonywyznacznik = 1;
    for i = 1 : 1 : rozmiar;
        for j = i+1 : 1 : rozmiar;
            wyliczonywyznacznik = wyliczonywyznacznik * ( A(j) - A(i) );
        end;
    end;
end;
if MACIERZ == 3 || MACIERZ == 4;
    wyliczonywyznacznik = 1;
    for i = 1 : 1 : rozmiar;
        wyliczonywyznacznik = wyliczonywyznacznik * A(i,i);
    end;
end;
if  MACIERZ == 5;
    wyliczonywyznacznik = det(A);
end;

% obliczanie b³êdu wyznaczenia wyznacznika macierzy
bladwyznacznik = ( (wyliczonywyznacznik-wyznacznik) / wyznacznik) * 100;