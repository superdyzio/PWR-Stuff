%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: A. Gonczarek, J.M. Tomczak
% 2013
%--------------------------------------------------------------------------

function [w err] = least_squares( xTrain, yTrain, M )
% Funkcja dopasowuje wielomian rzedu M do danych zgodnie z kryterium
% najmniejszych kwadratow, zwraca blad dopasowania

% xTrain - ciag treningowy wejscia Nx1
% yTrain - ciag treningowy wyjscia Nx1
% M - rzad wielomianu

w = zeros(M+1,1); 
err = 0;

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

matrixFI = design_matrix(xTrain,M); % tworzymy macierz FI
w = (matrixFI' * matrixFI)^-1 * matrixFI' * yTrain; % zgodnie ze wzorkiem (2)
err = mean_squared_error(xTrain, yTrain, w);


%--------------------------------------------------------------------------

end