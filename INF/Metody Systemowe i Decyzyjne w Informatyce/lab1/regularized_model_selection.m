%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: A. Gonczarek, J.M. Tomczak
% 2013
%--------------------------------------------------------------------------

function [w train_err val_err lambda] = regularized_model_selection( xTrain, yTrain, xVal, yVal, M )
% Funkcja wybiera dla wielomianu rzedu M wybiera parametr regularyzacji 
% i zwraca parametry w, dla ktorych model najlepiej
% generalizuje dane, tj. daje najmniejszy blad na ciagu walidacyjnym,
% zwraca blad na ciagu treningowym i walidacyjnym i wartosc lambda.

% xTrain - ciag treningowy wejscia 
% yTrain - ciag treningowy wyjscia 
% xVal - ciag walidacyjny wejscia 
% yVal - ciag walidacyjny wyjscia
% M - rzad wielomianu

w = [];
train_err = inf;
val_err = inf;
lambda = 0;

for temp_lambda = [0.001 0.003 0.01 0.03 0.1 0.3 1 3 10 30 100 300]
    
%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

% Dla kazdej wartosci wspó³czynnika regularyzacji  2  wyznacz wartosci parametrów wkorzystajac z (4) w oparciu o dane X i y.
[temp_w temp_train_err] = regularized_least_squares(xTrain,yTrain,M,temp_lambda);
% Dla kazdego wielomianu o parametrach w wyznacz wartosc funkcji b³edu E o postaci (5) w oparciu o dane Xval i yval.
temp_val_err = mean_squared_error(xVal,yVal,temp_w);
% Wybierz te wartosci parametrów w, dla których wartosc funkcji b³edu E jest najmniejsza
if temp_val_err < val_err
    w = temp_w;
    train_err = temp_train_err;
    val_err = temp_val_err;
    lambda = temp_lambda;
end

%--------------------------------------------------------------------------

end
end