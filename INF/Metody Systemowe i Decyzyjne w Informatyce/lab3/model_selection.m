%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

function [lambda_best theta_best w F] = model_selection(xTrain,yTrain,xVal,yVal,w0,...
    epochs,eta,mini_batch,lambdas,thetas)
% Funkcja wykonuje selekcje modelu, ustalaj¹c najlepszy parametr regularyzacji 
% lambda_best oraz prog klasyfikacji theta_best, a takze najlepszy wektor parametrow w. 
% Dodatkowo funkcja zwraca wartoœci miary F dla wszystkich par (lambda, theta). 
% Do uczenia modelu nale¿y korzystaæ z
% algorytmu SGD oraz krterium uczenia z regularyzacja l2.
%
% WskaŸnik na funkcjê celu dla pewnej wartoœci lambda definiujemy
% nastêpuj¹co:
% obj_fun = @(X,Y,w)(regularized_logistic_cost_function(X,Y,w,lambda));
%
% xTrain - ciag treningowy wejsciowy NxD
% yTrain - ciag treningowy zero-jedynkowy klas Nx1
% xVal - ciag walidacyjny wejsciowy NvalxD
% yVal - ciag walidacyjny zero-jedynkowy klas Nvalx1
% w0 - wektor pocz¹tkowych wartoœci parametrów
% eta - krok uczenia
% mini_batch - wielkosc mini_batcha dla SGD
% epochs - liczba epok dla SGD
% lambdas - wektor wartosci lambda, ktore maja byc sprawdzone
% thetas - wektor wartosci theta, ktore maja byc sprawdzone
 
Nlambda = length(lambdas);
Ntheta = length(thetas);
F = zeros(Nlambda,Ntheta);
w = zeros(size(w0));
lambda_best = 0;
theta_best = 0;

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

fBest = -inf;

for i = 1 : Nlambda;
   [wtemp ~] = stochastic_gradient_descent(@(X,Y,w)(regularized_logistic_cost_function(X,Y,w,lambdas(i))),xTrain,yTrain,w0,epochs,eta,mini_batch);
    for j = 1 : Ntheta;
        F(i,j) = f_measure(prediction(xVal,wtemp,thetas(j)),yVal);     
        if F(i,j) > fBest;
            fBest = F(i,j);
            lambda_best = lambdas(i);
            theta_best = thetas(j);
            w = wtemp;       
        end;
    end;
end;

%--------------------------------------------------------------------------

end