%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: A. Gonczarek, J.M. Tomczak
% 2013
%--------------------------------------------------------------------------

function [w train_err val_err] = model_selection( xTrain, yTrain, xVal, yVal )
% Funkcja wybiera rzad modelu M i zwraca parametry w, dla ktorych model 
% najlepiej generalizuje dane, tj. daje najmniejszy blad na ciagu 
% walidacyjnym, zwraca blad na ciagu treningowym i walidacyjnym.

% xTrain - ciag treningowy wejscia 
% yTrain - ciag treningowy wyjscia 
% xVal - ciag walidacyjny wejscia 
% yVal - ciag walidacyjny wyjscia

w = [];
train_err = inf;
val_err = inf;

for m=0:7
    
%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

% Dla kazdego wielomianu stopnia M 2 M wyznacz wartosci parametrów wM korzystajac z (2) w oparciu o dane X i y.
[cckiw cckitrain_err] = least_squares(xTrain,yTrain,m);
% Dla kazdego wielomianu stopnia M 2M o parametrach wM wyznacz wartosc funkcji b³edu EM o postaci (5) w oparciu o dane Xval i yval.
cckival_err = mean_squared_error(xVal,yVal,cckiw);
%Wybierz ten stopien wielomianu M, dla którego wartosc funkcji b³edu EM jest najmniejsza
if cckival_err < val_err
    w = cckiw;
    train_err = cckitrain_err;
    val_err = cckival_err;
end

%--------------------------------------------------------------------------

end
end