%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: KNN i Naiwny Bayes
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

function [ error_best, best_K, errors ] = model_selection_KNN( Xtrain,Xval,ytrain,yval,K_values)
% Funkcja wykonuje selekcjê modelu KNN - wybiera K, dla którego b³¹d na 
% zbiorze walidacyjnym jest najni¿szy

% Xval- zbiór danych walidacyjnych N1xD
% Xtrain - zbiór danych treningowych N2xD
% yval- etykiety klas dla danych walidacyjnych 1xN1
% ytrain- etykiety klas dla danych treningowych 1xN2
% K_values - wektor wartoœci K, które maj¹ byæ sprawdzone w selekcji modelu

Dist = hamming_distance( Xval,Xtrain );
y_sorted = sort_train_labels_KNN(Dist,ytrain);

% Aby nie przeprowadzaæ selekcji dla pe³nego y_sorted
y_sorted = y_sorted(:,1:max(K_values));

% Wartoœci b³êdów odpowiadaj¹ce parametrom z K_vlues
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

