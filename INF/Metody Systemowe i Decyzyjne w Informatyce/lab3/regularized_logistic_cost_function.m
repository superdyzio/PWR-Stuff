%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

function [L, grad] = regularized_logistic_cost_function( xTrain, yTrain, w, lambda )
% Funkcja wylicza wartosc funkcji celu z regularycja l2 L i jej gradient grad
% xTrain - ciag treningowy wejsciowy NxD
% yTrain - ciag zero-jedynkowy klas Nx1
% w - parametry modelu
% lambda - parametr regularyzacji

N = size(xTrain,1);
M = size(w,1);

L = 0;
grad = zeros(M,1);

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

for i = 1 : N;
    temp = sigmoid(w' * xTrain(i,:)');
    L = L - (yTrain(i) * log(temp) + (1-yTrain(i)) * log(1-temp))/N;
    grad = grad - (yTrain(i)*xTrain(i,:)'-xTrain(i,:)'*temp)/N;    
end;

L2 = 0;

for i = 2 : M;
    L2 = L2 + w(i)*w(i)*lambda/2;   
end;

for i = 2 : M;
    grad(i) = grad(i)+lambda*w(i);
end;

L = L + L2;

%--------------------------------------------------------------------------

end