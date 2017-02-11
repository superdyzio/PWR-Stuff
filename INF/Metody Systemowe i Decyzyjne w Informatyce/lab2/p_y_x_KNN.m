%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Zi�ba, A. Gonczarek, J.M. Tomczak, S. Zar�ba
% 2016
%--------------------------------------------------------------------------

function [ p_y_x ] = p_y_x_KNN(y, K )
% Funkcja wyznacza rozk�ad prawdopodbie�stwa p(y|x) dla ka�dej z klas dla
% obiekt�w ze zbioru testowego wykorzystuj�c klasyfikator KNN wyuczony na 
% danych treningowych

% y - macierz posortowanych etykiet dla danych treningowych N1xN2
% K - liczba najbli�szych s�siad�w dla KNN
% p_y_x - macierz prawdopobie�stw dla obiekt�w z X
% ka�dy wiersz macierzy reprezentuje rozk�ad p(y|x)) N1xM

% N1 - liczno�� zbioru poddawanego testowaniu
% N2 - liczno�� zbioru treningowego
% M - liczba klas

% N1 - liczno�� zbioru poddawanego testowaniu
N1 = size(y,1);

% M - liczba klas
M = length(unique(y));

%Inicjalizacja prawdopodobie�stw
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

