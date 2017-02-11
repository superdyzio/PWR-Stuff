%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

function [L, grad] = logistic_cost_function( xTrain, yTrain, w )
% Funkcja wylicza wartosc funkcji celu L i jej gradient grad
% xTrain - ciag treningowy wejsciowy NxD
% yTrain - ciag zero-jedynkowy klas Nx1
% w - parametry modelu

N = size(xTrain,1);
D = size(w,1);

L = 0;
grad = zeros(D,1);

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

pD_w = 1;

for i = 1 : N;
    sigma_n = sigmoid(w' * xTrain(i,:)');
    pD_w = pD_w * (sigma_n^yTrain(i) * (1-sigma_n)^(1-yTrain(i)));
    grad = grad + ((sigma_n - yTrain(i)) * xTrain(i,:)');
end;

L = -log(pD_w)/N;
grad = grad/N;

%--------------------------------------------------------------------------

end