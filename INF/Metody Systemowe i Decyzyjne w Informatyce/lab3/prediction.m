%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

function y = prediction(X, w, theta)
% Funkcja wylicza wartosci etykiet y dla macierzy cech X na podstawie
% modelu regresji logistycznej o wektorze parametrow w oraz progu
% klasyfikacji theta

% X - macierz obserwacji NxD
% w - wektor parametrow modelu Dx1
% theta - prog klasyfikacji

N = size(X,1);
y = zeros(N,1);

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

for i = 1 : N;
    temp = sigmoid(X(i,:)*w); 
        if (temp > theta);
            y(i) = true;
        else
            y(i) = false;
        end;
end;

%--------------------------------------------------------------------------

end