%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Zi�ba, A. Gonczarek, J.M. Tomczak, S. Zar�ba
% 2016
%--------------------------------------------------------------------------

function [ error_best, best_K, errors ] = model_selection_KNN( Xtrain,Xval,ytrain,yval,K_values)
% Funkcja wykonuje selekcj� modelu KNN - wybiera K, dla kt�rego b��d na 
% zbiorze walidacyjnym jest najni�szy

% Xval- zbi�r danych walidacyjnych N1xD
% Xtrain - zbi�r danych treningowych N2xD
% yval- etykiety klas dla danych walidacyjnych 1xN1
% ytrain- etykiety klas dla danych treningowych 1xN2
% K_values - wektor warto�ci K, kt�re maj� by� sprawdzone w selekcji modelu

Dist = hamming_distance( Xval,Xtrain );
y_sorted = sort_train_labels_KNN(Dist,ytrain);

% Aby nie przeprowadza� selekcji dla pe�nego y_sorted
y_sorted = y_sorted(:,1:max(K_values));

% Warto�ci b��d�w odpowiadaj�ce parametrom z K_vlues
errors = zeros(1,length(K_values));


%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

for i = 1 : size(K_values,2);
    errors(i) = error_fun(p_y_x_KNN(y_sorted,K_values(i)),yval);
end;

[error_best,indeks] = min(errors);
best_K = K_values(indeks);

%-------------------------------------------------------------------------
end

