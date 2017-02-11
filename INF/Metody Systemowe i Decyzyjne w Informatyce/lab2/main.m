%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%----------------- TA FUNKCJA MA POZOSTAC NIEZMODYFIKOWANA ----------------
%--------------------------------------------------------------------------

function main()

load data.mat
load test.mat

eps = 0.000001;

try
    test_h = test.hamming_distance;
    fprintf('\nWALIDACJA hamming_distance.m...\n\n');
    Dist = hamming_distance( test_h.X,test_h.Xtrain );
    if sum(sum(abs(Dist - test_h.Dist))) < eps
        fprintf('GRATULACJE! Funkcja hamming_distance.m jest poprawna\n\n');
    else
        fprintf('Funkcja hamming_distance.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja hamming_distance.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;

try
    test_sort = test.sort_train_labels_KNN;
    fprintf('\nWALIDACJA sort_train_labels_KNN.m...\n\n');
    y_sorted = sort_train_labels_KNN( test_sort.Dist,test_sort.y );
    if sum(sum(abs(y_sorted - test_sort.y_sorted))) < eps
        fprintf('GRATULACJE! Funkcja sort_train_labels_KNN.m jest poprawna\n\n');
    else
        fprintf('Funkcja sort_train_labels_KNN.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja sort_train_labels_KNN.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    
try
    test_p_y_x = test.p_y_x_KNN;
    fprintf('\nWALIDACJA p_y_x_KNN.m...\n\n');
    p_y_x = p_y_x_KNN( test_p_y_x.y,test_p_y_x.K);
    if sum(sum(abs(p_y_x - test_p_y_x.p_y_x))) < eps
        fprintf('GRATULACJE! Funkcja p_y_x_KNN.m jest poprawna\n\n');
    else
        fprintf('Funkcja p_y_x_KNN.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja p_y_x_KNN.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
    
 try
    test_error = test.error_fun;
    fprintf('\nWALIDACJA error_fun.m...\n\n');
    error_val = error_fun( test_error.p_y_x,test_error.y_true);
    if abs(error_val - test_error.error_val) < eps
        fprintf('GRATULACJE! Funkcja error_fun.m jest poprawna\n\n');
    else
        fprintf('Funkcja error_fun.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja error_fun.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 

try
    test_ms = test.model_selection_KNN;
    fprintf('\nWALIDACJA model_selection_KNN.m...\n\n');
    [ error_best, best_K, errors]  = model_selection_KNN( test_ms.Xtrain,test_ms.Xval,test_ms.ytrain,test_ms.yval,test_ms.K_values);
    if (sum(abs(errors - test_ms.errors)) < eps) && (abs(error_best - test_ms.error_best) < eps) && (abs(best_K - test_ms.best_K) < eps) 
        fprintf('GRATULACJE! Funkcja model_selection_KNN.m jest poprawna\n\n');
    else
        fprintf('Funkcja model_selection_KNN.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja model_selection_KNN.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
 
fprintf('Przystêpujemy do analizy Naiwnego Bayesa \n\n\n');


try
    test_p_y = test.estimate_a_priori_NB;
    fprintf('\nWALIDACJA estimate_a_priori_NB.m ...\n\n');
    p_y = estimate_a_priori_NB( test_p_y.ytrain );
    if (sum(abs(p_y - test_p_y.p_y)) < eps)
        fprintf('GRATULACJE! Funkcja estimate_a_priori_NB.m jest poprawna\n\n');
    else
        fprintf('Funkcja estimate_a_priori_NB.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja estimate_a_priori_NB.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
    
try
    test_p_x_y = test.estimate_p_x_y_NB;
    fprintf('\nWALIDACJA estimate_p_x_y_NB.m ...\n\n');
    p_x_y = estimate_p_x_y_NB(test_p_x_y.Xtrain,test_p_x_y.ytrain,test_p_x_y.a,test_p_x_y.b );
    if (sum(sum(abs(p_x_y - test_p_x_y.p_x_y ))) < eps)
        fprintf('GRATULACJE! Funkcja estimate_p_x_y_NB.m jest poprawna\n\n');
    else
        fprintf('Funkcja estimate_p_x_y_NB.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja estimate_p_x_y_NB.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
    
    
try
    test_p_y_x = test.p_y_x_NB;
    fprintf('\nWALIDACJA p_y_x_NB.m ...\n\n');
    p_y_x = p_y_x_NB(test_p_y_x.p_y,test_p_y_x.p_x_1_y, test_p_y_x.X );
    if (sum(sum(abs(p_y_x - test_p_y_x.p_y_x ))) < eps)
        fprintf('GRATULACJE! Funkcja p_y_x_NB.m jest poprawna\n\n');
    else
        fprintf('Funkcja p_y_x_NB.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja p_y_x_NB.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
   
try
    test_ms = test.model_selection_NB;
    fprintf('\nWALIDACJA model_selection_NB.m...\n\n');
    [ error_best, best_a, best_b,errors]  = model_selection_NB( test_ms.Xtrain,test_ms.Xval,test_ms.ytrain,test_ms.yval,test_ms.a_values,test_ms.b_values);
    if (sum(sum(abs(errors - test_ms.errors))) < eps) && (abs(best_b - test_ms.best_b) < eps) && (abs(error_best - test_ms.error_best) < eps) && (abs(best_a - test_ms.best_a) < eps) 
        fprintf('GRATULACJE! Funkcja model_selection_NB.m jest poprawna\n\n');
    else
        fprintf('Funkcja model_selection_NB.m NIE JEST poprawna !!!\n\n');
    end
catch
    fprintf('Funkcja model_selection_NB.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
    
%%%%%
% Zakres wartoœci K dla seleckji modelu
K_values = 1:2:201;

fprintf('*** UCZENIE ALGORYTMU KNN ***\n\n');  
fprintf('Wczytujê dane ... \n');    

load data.mat

fprintf('Przystêpujê do selekcji modelu KNN \n');
fprintf('Mo¿e to potrwaæ parê minut... \n\n');
[ error_best, best_K, errors ] = model_selection_KNN( Xtrain,Xval,ytrain,yval,K_values);

figure
plot(K_values,errors,'Color',[0,0.7,0.9])

title('Wyniki selekcji modelu KNN')
xlabel('Liczba s¹siadów (K)')
ylabel('B³¹d klasyfikacji')
xlim([min(K_values) max(K_values)])

fprintf('Najni¿szy b³¹d klasyfikacji na zbiorze walidacyjym: %f \n',error_best);
fprintf('Oœ¹gniêto go dla %i s¹siadów \n',best_K);


fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
pause; 

fprintf('Dla %i s¹siadów liczê b³¹d na zbiorze testowym ... \n',best_K);
Dist = hamming_distance( Xtest,Xtrain );
y_sorted = sort_train_labels_KNN(Dist,ytrain);
p_y_x = p_y_x_KNN(y_sorted, best_K); 
error_KNN = error_fun( p_y_x,ytest);

fprintf('B³¹d na zbiorze testowym wynosi %f\n',error_KNN);

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
pause; 

fprintf('*** UCZENIE ALGORYTMU NAIWNEGO BAYESA ***\n\n');  

% Zakres wartoœci a i b dla seleckji modelu
a_values = [1 3 10 30 100 300 1000];
b_values = [1 3 10 30 100 300 1000];

fprintf('Przystêpujê do selekcji modelu Naiwnego Bayesa \n');
[ error_best, best_a,best_b,errors] = model_selection_NB( Xtrain,Xval,ytrain,yval,a_values,b_values);

figure;

colormap('hot');

imagesc(errors);

colorbar;

xlabel('Parametr b');

ylabel('Parametr a');

title('Wartoœci b³êdu klasyfikacji na ci¹gu walidacyjnym');

set(gca, 'XTick',1:7, 'XTickLabel',{'1' '3', '10' '30' '100' '300' '1000'},'YTick',1:7, 'YTickLabel',{'1' '3', '10' '30' '100' '300' '1000'})

fprintf('Najni¿szy b³¹d klasyfikacji na zbiorze walidacyjym: %f \n',error_best);
fprintf('Oœ¹gniêto go dla a równego %i i b równego %i \n',best_a,best_b);
fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
pause; 
p_y = estimate_a_priori_NB(ytrain);

p_x_y = estimate_p_x_y_NB(Xtrain,ytrain,best_a,best_b);

fprintf('Wyszukujê najpopularniejsze s³owa w ka¿dej z klas ...\n');

print_words_category( p_x_y,wordlist,groupnames )

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
pause;

p_y_x = p_y_x_NB(p_y,p_x_y, Xtest );
error_NB = error_fun( p_y_x,ytest);

fprintf('Dla najlepszego modelu liczê b³¹d na zbiorze testowym ... \n');
fprintf('B³¹d na zbiorze testowym wynosi %f \n',error_NB);

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
pause;

figure
bar([error_KNN,error_NB],'BarWidth', 0.8)
title('Porównanie jakoœci modeli KNN i NB na zbiorze testowym')
xlabel('Klasyfikator')
ylabel('B³¹d klasyfikacji')
   Labels = {'KNN', 'NB'};
   set(gca, 'XTick',1:3,'XTickLabel', Labels);




end
