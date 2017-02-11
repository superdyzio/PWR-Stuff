%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Zi�ba, A. Gonczarek, J.M. Tomczak, S. Zar�ba
% 2016
%--------------------------------------------------------------------------

function [ error_best, best_a, best_b,errors] = model_selection_NB( Xtrain,Xval,ytrain,yval,a_values,b_values )
% Funkcja wykonuje selekcj� modelu Naive Bayes- wybiera najlepsze warto�ci
% parametru a i b rozk�adu Beta (a priori na parametry theta)

% Xval- zbi�r danych walidacyjnych N1xD
% Xtrain - zbi�r danych treningowych N2xD
% yval- etykiety klas dla danych walidacyjnych 1xN1
% ytrain- etykiety klas dla danych treningowych 1xN2
% a_values - warto�ci a, kt�re maj� by� sprawdzone
% b_values - warto�ci b, kt�re maj� by� sprawdzone

% error_best - najmniejszy b��d na ci�gu walidacyjnym
% best_a - najlepszy a
% best_b - najlepszy b
% errors - macierz b��d�w na ci�gu walidacyjnym dla poszczeg�lnych par (a,b)

errors = zeros(length(a_values),length(b_values));
%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

error_best = Inf;
best_a = Inf;
best_b = Inf;
p_y = estimate_a_priori_NB(ytrain);
p_yval = estimate_a_priori_NB(yval);

for a = 1 : size(a_values,2);
    for b = 1 : size(b_values,2);
        p_x_y = estimate_p_x_y_NB(Xtrain,ytrain,a_values(a),b_values(b));
        p_y_x = p_y_x_NB(p_y, p_x_y, Xval);
        pom = error_fun(p_y_x, yval);
        errors(a,b) = pom;
        if pom < error_best;
            error_best = pom;
            best_a = a_values(a);
            best_b = b_values(b);
        end;
    end;
end;

%-------------------------------------------------------------------------

end

% Por�wnanie 