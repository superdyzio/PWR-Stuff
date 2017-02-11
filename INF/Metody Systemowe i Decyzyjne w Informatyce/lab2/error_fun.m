%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

function [ error_val ] = error_fun( p_y_x,y_true )
% Funkcja wyznacza b³¹d klasyfikacji

% y_true - zbiór rzeczywistych etykiet klas 1xN
% p_y_x - macierz przewidywanych prawdopobieñstw 
% ka¿dy wiersz macierzy reprezentuje rozk³ad p(y|x)) NxM
% N - liczba przyk³adów
% M - liczba klas
% error_val - b³¹d klasyfikacji

error_val = 0;

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

N = size(p_y_x,1);
M = size(p_y_x,2);
etykiety = zeros(1,N);

for i = 1 : N;
    [~,etykiety(i)] = max(p_y_x(i,1:M));
    pom = etykiety(i);
    for j = pom+1 : M;
        if p_y_x(i,pom) == p_y_x(i,j);
            etykiety(i) = j;
        end;
    end;
end;

for i = 1 : N;
    if etykiety(i) ~= y_true(i);
        error_val = error_val + 1;
    end;
end;

error_val = error_val / N;

%-------------------------------------------------------------------------
end
