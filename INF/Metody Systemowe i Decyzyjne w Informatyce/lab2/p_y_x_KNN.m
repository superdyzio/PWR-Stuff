%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

function [ p_y_x ] = p_y_x_KNN(y, K )
% Funkcja wyznacza rozk³ad prawdopodbieñstwa p(y|x) dla ka¿dej z klas dla
% obiektów ze zbioru testowego wykorzystuj¹c klasyfikator KNN wyuczony na 
% danych treningowych

% y - macierz posortowanych etykiet dla danych treningowych N1xN2
% K - liczba najbli¿szych s¹siadów dla KNN
% p_y_x - macierz prawdopobieñstw dla obiektów z X
% ka¿dy wiersz macierzy reprezentuje rozk³ad p(y|x)) N1xM

% N1 - licznoœæ zbioru poddawanego testowaniu
% N2 - licznoœæ zbioru treningowego
% M - liczba klas

% N1 - licznoœæ zbioru poddawanego testowaniu
N1 = size(y,1);

% M - liczba klas
M = length(unique(y));

%Inicjalizacja prawdopodobieñstw
p_y_x = zeros(N1,M);

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

N2 = size(y,2);

for i = 1 : N1;
    for j = 1 : M;
        for k = 1 : K;
            if y(i,k) == j;
                p_y_x(i,j) = p_y_x(i,j) + 1;
            end;
        end;
        p_y_x(i,j) = p_y_x(i,j) / K;
    end;
end;

%-------------------------------------------------------------------------
end

