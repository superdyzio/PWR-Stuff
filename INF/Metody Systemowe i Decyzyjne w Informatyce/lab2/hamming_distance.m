%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

function [ Dist ] = hamming_distance( X,Xtrain )
% Funkcja wyznacza odleg³oœci Hamminga obiektów ze zbioru
% X od obiektów Xtrain. Odleg³oœci obiektów z jednego i drugiego zbioru
% zwrócone zostan¹ w postaci macierzy Dist

%UWAGA! Obiekty X i Xtrain s¹ typu sparse i logial natomiast Dist jest typu
%full i double

% X - zbiór porównywanych obiektów N1xD
% Xtrain - zbiór obiektów do których porównujemy N2xD
% Dist - macierz odleg³osci pomiêdzy obiektami z X i Xtrain N1xN2
% N1 - licznoœæ zbioru X
% N2 - liczoœæ zbioru Xtrain
% D - liczba cech (s³ów kluczowych)

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
    fprintf('\nCoœ tu nie gra!\n\n');
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

