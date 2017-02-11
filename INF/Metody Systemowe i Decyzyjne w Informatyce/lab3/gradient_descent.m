%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

function [w func_values] = gradient_descent( obj_fun, w0, epochs, eta )
% Funkcja wykonuje optymalizacje metoda gradientu prostego dla funkcji
% obj_fun. Zwraca rozwiazane w, ktore minimalizuje funkcje celu oraz wartosci 
% funkcji celu we wszystkich krokach algorytmu po aktualizacji 
% parametrow w - func_values.

% obj_fun - wskaŸnik na funkcjê celu, wywo³anie: obj_fun(w)
% w0 - punkt startowy (poczatkowe parametry)
% epochs - liczba epok / liczba iteracji algorytmu
% eta - krok uczenia

func_values = [];
w = zeros(size(w0));

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

w = w0;
for k = 1 : epochs;
    [L grad] = obj_fun(w);
    w = w - eta * grad;
    if (k > 1)
        func_values = [func_values L];
    end;
end;

[L grad] = obj_fun(w);
func_values = [func_values L];
func_values = func_values';

%--------------------------------------------------------------------------

end