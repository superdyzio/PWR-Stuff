%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Zi�ba, A. Gonczarek, J.M. Tomczak, S. Zar�ba
% 2016
%--------------------------------------------------------------------------

function [ Dist ] = hamming_distance( X,Xtrain )
% Funkcja wyznacza odleg�o�ci Hamminga obiekt�w ze zbioru
% X od obiekt�w Xtrain. Odleg�o�ci obiekt�w z jednego i drugiego zbioru
% zwr�cone zostan� w postaci macierzy Dist

%UWAGA! Obiekty X i Xtrain s� typu sparse i logial natomiast Dist jest typu
%full i double

% X - zbi�r por�wnywanych obiekt�w N1xD
% Xtrain - zbi�r obiekt�w do kt�rych por�wnujemy N2xD
% Dist - macierz odleg�osci pomi�dzy obiektami z X i Xtrain N1xN2
% N1 - liczno�� zbioru X
% N2 - liczo�� zbioru Xtrain
% D - liczba cech (s��w kluczowych)

N1 = size(X,1);
N2 = size(Xtrain,1);

Dist = zeros(N1,N2);

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

x = full(X);
xtrain = full(Xtrain);

D1 = size(x,2);
D2 = size(xtrain,2);
if D1 ~= D2;
    fprintf('\nCo� tu nie gra!\n\n');
end;

for i = 1 : N1;
     for j = 1 : N2;
         for k = 1 : D1;
            if x(i,k) ~= xtrain(j,k);
               Dist(i,j) = Dist(i,j) + 1;
            end;
         end;
     end;
end;

%-------------------------------------------------------------------------
end

