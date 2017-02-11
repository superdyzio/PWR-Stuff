%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: A. Gonczarek, J.M. Tomczak
% 2013
%--------------------------------------------------------------------------

function err = mean_squared_error( x, y, w )
% Funkcja blad pomiedzy rzeczywistymi wyjsciami y oraz wyjsciami uzyskanymi
% z wielomianu o parametrach w dla wejsc x
% x - ciag wejsciowy Nx1
% y - ciag wyjsciowy Nx1
% w - parametry modelu (M+1)x1

err = 0; 

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

% Skorzystac z funkcji polynoial(x,w)

y2 = polynomial(x,w); % wylicza y z kresk¹
N = length(y); % N
suma = 0;
for i = 1 : N % zgodnie ze wzorem (5) suma od 1 do N
    suma = suma + (y(i) - y2(i))^2;
end
err = suma/N; % realizacja 1/N*suma


%--------------------------------------------------------------------------

end