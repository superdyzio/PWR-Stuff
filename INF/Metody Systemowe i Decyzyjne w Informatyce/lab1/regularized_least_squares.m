%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: A. Gonczarek, J.M. Tomczak
% 2013
%--------------------------------------------------------------------------

function [w err] = regularized_least_squares( xTrain, yTrain, M, lambda )
% Funkcja dopasowuje wielomian rzedu M do danych zgodnie z kryterium
% najmniejszych kwadratow z regularyzacja Tichonowa, 
% zwraca blad dopasowania

% xTrain - ciag treningowy wejscia Nx1
% yTrain - ciag treningowy wyjscia Nx1
% M - rzad wielomianu
% lambda - parametr regularyzacji

w = zeros(M+1,1); 
err = 0;

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

matrixFI = design_matrix(xTrain,M); % tworzymy macierz FI
w = (matrixFI' * matrixFI + lambda * eye(M+1))^-1 * matrixFI' * yTrain;  % wzor (4), eye - macierz jednostkowa
err = mean_squared_error(xTrain, yTrain, w);


%--------------------------------------------------------------------------

end