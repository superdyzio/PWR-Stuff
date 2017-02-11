%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

function [ p_y_x ] = p_y_x_NB(p_y,p_x_1_y, X )
% Funkcja wyznacza rozk³ad prawdopodbieñstwa p(y|x) dla ka¿dej z klas z
% wykorzystaniem klasyfikatora Naiwnego Bayesa

% X - dane dla których bêd¹ wyznaczone prawdopodbieñstwa NxD
% p_x_1_y - rozk³ad prawdopobieñstw p(x=1|y) - macierz MxD
% p_y_x - macierz NxM prawdopobieñstw dla obiektów z X
% ka¿dy wiersz macierzy reprezentuje rozk³ad p(y|x)) 

N = size(X,1);

% M - liczba klas
M = length(p_y);

% Dope³nienia p_x_y
p_x_0_y = 1 - p_x_1_y;

%Inicjalizacja prawdopodobieñstw
p_y_x = zeros(N,M);

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

for n = 1 : N;
    kProbability = zeros(1,M);
    for k = 1 : M;
        kProbability(k) = p_y(k) * prod((p_x_1_y(k,:) .^ X(n,:)) .* (p_x_0_y(k,:) .^ (1-X(n,:))));
    end;
    p_y_x(n,:) = kProbability / sum(kProbability);
end;

%-------------------------------------------------------------------------
end