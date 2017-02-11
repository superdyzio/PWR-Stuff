%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

function [w func_values] = stochastic_gradient_descent( obj_fun, xTrain, yTrain,...
    w0, epochs, eta, mini_batch )
% Funkcja wykonuje optymalizacje metoda stochastycznego gradientu prostego dla funkcji
% obj_fun z krokiem uczenia eta, liczba epok epochs oraz 
% wielokoscia mini batcha. Zwraca rozwiazane w, ktore
% minimalizuje funkcje celu oraz wartosci funkcji celu dla calego zbioru 
% treningowego na koniec ka¿dej epoki algorytmu - func_values.

% obj_fun - wskaznik na funkcje celu, wywolanie: obj_fun(X,Y,w),  gdzie X,Y
% oznaczaj¹ podane podzbiory zbioru treningowego (mini-batche)
% xTrain - dane treningowe NxD
% yTrain - dane treningowe Nx1 (etykiety klas)
% w0 - punkt startowy (poczatkowe parametry)
% epochs - liczba epok
% eta - krok uczenia
% mini_batch - wielkoœæ mini-batcha

func_values = [];
w = zeros(size(w0));

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

w = w0;

% reshape - dzieli wektor na mini_batch wierszy, drugi wymiar [] czyli "jak
% wyjdzie"
% permute - zamienia miejscami kolumny macierzy

y_batches = permute(reshape(yTrain,mini_batch,[]),[1 3 2]);
x_batches = permute(reshape(xTrain',size(xTrain,2),mini_batch,[]),[2 1 3]);
M = size(x_batches,3);

for e = 1 : epochs;
    for m = 1 : M;
        [~,grad] = obj_fun(x_batches(:,:,m),y_batches(:,:,m),w);
        w = w - grad * eta;
    end;
    func_values(e,1) = obj_fun(xTrain,yTrain,w);
end;

%--------------------------------------------------------------------------

end