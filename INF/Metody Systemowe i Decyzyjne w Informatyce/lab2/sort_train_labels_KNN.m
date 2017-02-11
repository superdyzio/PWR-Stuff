%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Zi�ba, A. Gonczarek, J.M. Tomczak, S. Zar�ba
% 2016
%--------------------------------------------------------------------------

function [ y_sorted ] = sort_train_labels_KNN(Dist,y)
% Funkcja sortuj�ca etykiety klas danych treningowych y wzgl�dem 
% podobie�stw zawartych w macierzy Dist. Funkcja zwr�ci macierz o wymiarach
% N1xN2, w ka�dym wierszu maj� by� posortowane etykiety klas z y wzgl�dem
% warto�ci podobie�stw odowiadaj�cego wiersza macierzy Dist. 

% Dist - macierz odleg�osci pomi�dzy obiektami z X i Xtrain N1xN2
% y - wektor etykiet klas o d�ugo�ci N2
% N1 - liczo�� zbioru X
% N2 - liczo�� zbioru Xtrain
% y_sorted - macierz etykiet klas posortowana wzgl�dem podobie�stw 
% zawartych w macierzy Dist N1xN2

y_sorted = zeros(size(Dist));

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

N1 = size(Dist,1);
N2 = size(Dist,2);

for i = 1 : N1;
    wiersz = Dist(i,1:N2);
    [~,I] = sort(wiersz);
    for j = 1 : N2;
        y_sorted(i,j) = y(I(j));
    end;
end;

%-------------------------------------------------------------------------
end

