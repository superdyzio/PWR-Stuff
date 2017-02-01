% MACIERZ = zmienna przechowuj¹ca informacjê o wybranej do dalszych dzia³añ macierzy
%   1 - macierz 2x2 z punktu a)
%   2 - macierz Vandermonde'a o rozmiarze 20x20
%   3 - macierz trójprzek¹tniowa z przek¹tn¹ dominuj¹c¹
%   4 - macierz trójprzek¹tniowa bez przek¹tnej dominuj¹cej
%   5 - dowolna macierz wprowadzana w kodzie skryptu
 
clear all;
format longeng;

MACIERZ = 5;

%%%%%%%%%%%%%%%%%%%% DEFINIOWANIE MACIERZY

if MACIERZ == 1;
    rozmiar = 2;
    A = [ 10^-10 1 ; 3 10^-12 ];
    det(A);
end;

if MACIERZ == 2;
    rozmiar = 20;
    for i = 1 : 1 : rozmiar;
        for j = 1 : 1 : rozmiar;
            A(i,j) = i^(j-1);
        end;
    end;
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
end;

% if MACIERZ == 5;
%     rozmiar = 5;
%     A = [ 0 1 0 1 -3 ; 2 0 -1 0 -2 ; 1 -1 -2 1 -2 ; 2 0 1 0 1 ; -3 -1 1 2 2 ];
%     wyznacznik = det(A);
% end;

if MACIERZ == 5;
    rozmiar = 5;
    A = [ 0 5 7 1 2 ; 6 0 4 3 4 ; 5 -2 -3 5 6 ; 3 4 5 5 7 ; 1 2 3 4 5];
end;

%%%%%%%%%%%%%%%%%%%% ALGORYTM ODWRACANIA MACIERZY

C = A;          % przepisanie umo¿liwiaj¹ce sprawdzenie poprawnoœci na koñcu

% sprawdzenie wymiarów macierzy wejœciowej
[m,n] = size(A);
if m ~= n;
    disp('Macierz nie jest kwadratowa')
    B = [];
    return;
end;

B = eye(m);

for i = 1 : 1 : rozmiar;
    x = A(i,1:rozmiar);
    wolne = B(i,1:rozmiar)';
    wynik = pom(C,x,wolne);
    A(1:rozmiar,i) = wynik;
end;