%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

function [ p_y ] = estimate_a_priori_NB(ytrain )

% Funkcja wyznacza rozk³ad apriori p(y) 

% ytrain - etykiety klas dla danych treningowych 1xN
% p_y - estymator a priori 1xM
% N - licznoœæ zbioru treningowego

% M - liczba klas
M = length(unique(ytrain));

%Inicjalizacja prawdopodobieñstw
p_y = zeros(M,1);


%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

N = size(ytrain,2);

for i = 1 : N;
    if ytrain(i) == 1;
        p_y(1) = p_y(1) + 1;
    elseif ytrain(i) == 2;
        p_y(2) = p_y(2) + 1;
    elseif ytrain(i) == 3;
        p_y(3) = p_y(3) + 1;
    elseif ytrain(i) == 4;
        p_y(4) = p_y(4) + 1;
    end;
end;

p_y = p_y ./ N;

%-------------------------------------------------------------------------

end
