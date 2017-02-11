%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Zi�ba, A. Gonczarek, J.M. Tomczak, S. Zar�ba
% 2016
%--------------------------------------------------------------------------

function [ p_y_x ] = p_y_x_NB(p_y,p_x_1_y, X )
% Funkcja wyznacza rozk�ad prawdopodbie�stwa p(y|x) dla ka�dej z klas z
% wykorzystaniem klasyfikatora Naiwnego Bayesa

% X - dane dla kt�rych b�d� wyznaczone prawdopodbie�stwa NxD
% p_x_1_y - rozk�ad prawdopobie�stw p(x=1|y) - macierz MxD
% p_y_x - macierz NxM prawdopobie�stw dla obiekt�w z X
% ka�dy wiersz macierzy reprezentuje rozk�ad p(y|x)) 

N = size(X,1);

% M - liczba klas
M = length(p_y);

% Dope�nienia p_x_y
p_x_0_y = 1 - p_x_1_y;

%Inicjalizacja prawdopodobie�stw
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