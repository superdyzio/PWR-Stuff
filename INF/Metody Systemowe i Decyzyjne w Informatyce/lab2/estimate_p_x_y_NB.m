%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Zi�ba, A. Gonczarek, J.M. Tomczak, S. Zar�ba
% 2016
%--------------------------------------------------------------------------

function [ p_x_y ] = estimate_p_x_y_NB(Xtrain,ytrain,a,b )

% Funkcja wyznacza rozk�ad prawdopodbie�stwa p(x|y) zak�adaj�c �e x
% przyjmuje warto�ci binarne i �e elementy x s� niezale�ne od siebie

% Xtrain - dane treningowe NxD
% ytrain - etykiety klas dla danych treningowych 1xN
% p_x_y - estymatory rozk�ad�w dwupunktowych - element na pozycji (m,d)
% oznacza estymator prawdopodbie�stwa  p(x_d=1|y=m) MxD
% N - liczno�� zbioru treningowego
% D - liczba cech

D = size(Xtrain,2);

% M - liczba klas
M = length(unique(ytrain));

%Inicjalizacja prawdopodobie�stw
p_x_y = zeros(M,D);

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

X = full(Xtrain);
N = size(X,1);

apriori = estimate_a_priori_NB(ytrain) .* 50;
mianownik = apriori + a + b - 2;

for i = 1 : M;
    for j = 1 : N;
        for k = 1 : D;
            if ytrain(j) == i && X(j,k) == 1;
                p_x_y(i,k) = p_x_y(i,k) + 1;
            end;
        end;
    end;
end;

for i = 1 : M;
    for j = 1 : D;
        p_x_y(i,j) = p_x_y(i,j) + a - 1;
    end;
    p_x_y(i,:) = p_x_y(i,:) ./ mianownik(i);
end;

%-------------------------------------------------------------------------

end
