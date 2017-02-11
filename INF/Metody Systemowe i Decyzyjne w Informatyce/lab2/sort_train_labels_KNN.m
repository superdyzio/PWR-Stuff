%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

function [ y_sorted ] = sort_train_labels_KNN(Dist,y)
% Funkcja sortuj¹ca etykiety klas danych treningowych y wzglêdem 
% podobieñstw zawartych w macierzy Dist. Funkcja zwróci macierz o wymiarach
% N1xN2, w ka¿dym wierszu maj¹ byæ posortowane etykiety klas z y wzglêdem
% wartoœci podobieñstw odowiadaj¹cego wiersza macierzy Dist. 

% Dist - macierz odleg³osci pomiêdzy obiektami z X i Xtrain N1xN2
% y - wektor etykiet klas o d³ugoœci N2
% N1 - liczoœæ zbioru X
% N2 - liczoœæ zbioru Xtrain
% y_sorted - macierz etykiet klas posortowana wzglêdem podobieñstw 
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

