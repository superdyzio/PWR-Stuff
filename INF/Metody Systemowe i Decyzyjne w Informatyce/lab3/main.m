%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%----------------- TA FUNKCJA MA POZOSTAC NIEZMODYFIKOWANA ----------------
%--------------------------------------------------------------------------

function main()


eps = 0.0000001;
test = load('test.mat');
test = test.test;

try
    fprintf('\nWALIDACJA sigmoid.m...\n\n');
    val = sigmoid(test.sigm.arg);
    diff = max( abs(val - test.sigm.val) );
    assert( diff < eps );
    fprintf('GRATULACJE! Funkcja sigmoid.m jest poprawna\n\n');
catch
    fprintf('Funkcja sigmoid.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    
    
try
    fprintf('\nWALIDACJA logistic_cost_function.m...\n\n');
    [L grad] = logistic_cost_function(test.cost.xTrain,test.cost.yTrain,test.cost.w);
    diff_L = max( abs(L - test.cost.L) );
    diff_grad = max( abs(grad - test.cost.grad) );
    assert( diff_L < eps && diff_grad < eps );
    fprintf('GRATULACJE! Funkcja logistic_cost_function.m jest poprawna\n\n');
catch
    fprintf('Funkcja logistic_cost_function.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;  
    
try
    fprintf('\nWALIDACJA gradient_descent.m...\n\n');
    [w f_values] = gradient_descent(test.opt.func,test.opt.w0,test.opt.epochs,test.opt.step);
    diff_w = max( abs(w - test.opt.w) );
    diff_values = max( abs(f_values - test.opt.func_values) );
    assert( diff_w < eps && diff_values < eps );
    fprintf('GRATULACJE! Funkcja gradient_descent.m jest poprawna\n\n');
catch
    fprintf('Funkcja gradient_descent.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;

try
    fprintf('\nWALIDACJA stochastic_gradient_descent.m...\n\n');
    [w f_values] = stochastic_gradient_descent(test.sopt.func,test.sopt.xTrain,...
        test.sopt.yTrain,test.sopt.w0,test.sopt.epochs,test.sopt.step, test.sopt.mini_batch);
    diff_w = max( abs(w - test.sopt.w) );
    diff_values = max( abs(f_values - test.sopt.func_values) );
    assert( diff_w < eps && diff_values < eps );
    fprintf('GRATULACJE! Funkcja stochastic_gradient_descent.m jest poprawna\n\n');
catch
    fprintf('Funkcja stochastic_gradient_descent.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    
try
    fprintf('\nWALIDACJA regularized_logistic_cost_function.m...\n\n');
    [L grad] = regularized_logistic_cost_function(test.rcost.xTrain,test.rcost.yTrain,test.rcost.w,test.rcost.lambda);
    diff_L = max( abs(L - test.rcost.L) );
    diff_grad = max( abs(grad - test.rcost.grad) );
    assert( diff_L < eps && diff_grad < eps );
    fprintf('GRATULACJE! Funkcja regularized_logistic_cost_function.m jest poprawna\n\n');
catch
    fprintf('Funkcja regularized_logistic_cost_function.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
    
try
    fprintf('\nWALIDACJA prediction.m...\n\n');
    yPred = prediction(test.pred.X,test.pred.w, test.pred.theta);
    diff_y = max( abs(yPred - test.pred.y) );
    assert( diff_y < eps );
    fprintf('GRATULACJE! Funkcja prediction.m jest poprawna\n\n');
catch
    fprintf('Funkcja prediction.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
    
try
    fprintf('\nWALIDACJA f_measure.m...\n\n');
    fm = f_measure(test.fm.y,test.fm.yPred);
    diff_f = max( abs(fm - test.fm.f) );
    assert( diff_f < eps );
    fprintf('GRATULACJE! Funkcja f_measure.m jest poprawna\n\n');
catch
    fprintf('Funkcja f_measure.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 
       
try
    fprintf('\nWALIDACJA model_selection.m...\n\n');
    [lambda theta w F] = model_selection(test.ms.xTrain,test.ms.yTrain,test.ms.xVal,...
        test.ms.yVal,test.ms.w0,test.ms.epochs,test.ms.step,test.ms.mini_batch,...
        test.ms.lambdas,test.ms.thetas);
    
    diff_lam = abs(lambda - test.ms.lambda);
    diff_theta =  abs(theta - test.ms.theta);
    diff_w = sum(abs(w - test.ms.w));
    diff_F = sum(sum(abs(F - test.ms.F)));
    
    assert( diff_lam < eps && diff_theta < eps && diff_w < eps  && diff_F < eps  );
    fprintf('GRATULACJE! Funkcja model_selection.m jest poprawna\n\n');
catch
    fprintf('Funkcja model_selection.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause; 

    

%--------------------------------------------------------------------------
data = load('data.mat');
data = data.data;
image = imread('image2016.jpg');
eta = 0.1;
mini_batch = 50;
theta = 0.65;
epochs = 100;
lambda = 0.01;
w0 = zeros(size(data.xTrain,2),1);

fprintf('\n***UCZENIE REGRESJI LOGISTYCZNEJ***\n');
fprintf('METODA GRADIENTU PROSTEGO\n');
fprintf('To moze potrwac ok. 1 min.\n\n');
fprintf('Krok uczenia: %f\n',eta);
fprintf('Wielkoœæ mini-batcha: %i\n',mini_batch);
fprintf('Liczba epok: %i\n',epochs);

obj_fun = @(arg)(logistic_cost_function(data.xTrain,data.yTrain,arg));
[w f_values1] = gradient_descent(obj_fun,w0,epochs,eta);

fprintf('\nUczenie zakonczone!!!\n');
fprintf('Wartosc koncowa funkcji celu: %f\n\n',f_values1(end));

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n');
pause;

fprintf('\n***UCZENIE REGRESJI LOGISTYCZNEJ***\n');
fprintf('METODA STOCHASTYCZNEGO GRADIENTU PROSTEGO\n');
fprintf('To moze potrwac ok. 1 min.\n\n');
fprintf('Krok uczenia: %f\n',eta);
fprintf('Wielkoœæ mini-batcha: %i\n',mini_batch);
fprintf('Liczba epok: %i\n',epochs);

epochs = size(f_values1);
obj_fun = @(X,Y,arg)(logistic_cost_function(X,Y,arg));
[w f_values2] = stochastic_gradient_descent(obj_fun,data.xTrain,data.yTrain,w0,epochs,eta,mini_batch);

fprintf('\nUczenie zakonczone!!!\n');
fprintf('Wartosc koncowa funkcji celu: %f\n\n',f_values2(end));

figure;
plot(1:length(f_values1),f_values1,'-',1:length(f_values2),f_values2,'r-');
legend('GD','SGD')
xlabel('Numer iteracji');
ylabel('Wartosc funkcji celu');
title('Przebieg wartosci funkcji celu');
xlim([1 length(f_values1)]);

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n');
pause;

fprintf('\n***DETEKCJA TWARZY***\n');
fprintf('Model nauczony algorytmem SGD\n');
fprintf('Prog klasyfikacji: %f\n',theta);

face_detect(image,w,20,theta);

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n');
pause;

fprintf('\n***UCZENIE REGRESJI LOGISTYCZNEJ z REGULARYZACJA L2***\n');
fprintf('METODA STOCHASTYCZNEGO GRADIENTU PROSTEGO\n');
fprintf('To moze potrwac ok. 1 min.\n\n');
fprintf('Krok uczenia: %f\n',eta);
fprintf('Wielkoœæ mini-batcha: %i\n',mini_batch);
fprintf('Liczba epok: %i\n',epochs);
fprintf('Parametr regularyzacji: %f\n',lambda);

epochs = size(f_values1);
obj_fun = @(X,Y,arg)(regularized_logistic_cost_function(X,Y,arg,lambda));
[w f_values2] = stochastic_gradient_descent(obj_fun,data.xTrain,data.yTrain,w0,epochs,eta,mini_batch);

fprintf('\nUczenie zakonczone!!!\n');
fprintf('Wartosc koncowa funkcji celu: %f\n\n',f_values2(end));

figure;
plot(1:length(f_values2),f_values2,'r-');
legend('SGD')
xlabel('Numer iteracji');
ylabel('Wartosc funkcji celu');
title('Przebieg wartosci funkcji celu z regularyzacja');
xlim([1 length(f_values1)]);

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n');
pause;

fprintf('\n***DETEKCJA TWARZY***\n');
fprintf('Model z regularyzacja l2 nauczony algorytmem SGD\n');
fprintf('Prog klasyfikacji: %f\n',theta);

face_detect(image,w,20,theta);

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n');
pause;


%model selection
lambdas = [0 0.00001 0.0001 0.001 0.01 0.1];
thetas = 0.1:0.05:0.9;
mini_batch = 50;
epochs = 100;
eta = 0.1;

fprintf('\n***SELEKCJA MODELU***\n');
fprintf('Strojenie parametru regularyzacji i progu klasyfikacji\n');
fprintf('To moze potrwac kilka minut.\n\n');
fprintf('Krok uczenia: %f\n',eta);
fprintf('Wielkoœæ mini-batcha: %i\n',mini_batch);
fprintf('Liczba epok: %i\n',epochs);
fprintf('Parametry regularyzacji: {0, 10^-5, 10^-4, 10^-3, 10^-2, 10^-1}\n');
fprintf('Progi klasyfikacji: od 0.1 do 0.9 z krokiem co 0.05\n');

[lambda theta w F] = model_selection(data.xTrain,data.yTrain,data.xVal,data.yVal,...
    w0,epochs,eta,mini_batch,lambdas,thetas);

fprintf('\nSelekcja modelu zakonczona!!!\n');
fprintf('Najlepszy parametr regularyzacji lambda: %f\n',lambda);
fprintf('Najlepszy prog klasyfikacji theta: %f\n',theta);
fprintf('Wartoœæ miary F na ciagu walidacyjnym: %f\n',max(max(F)));

figure;
colormap('hot');
imagesc(F);
colorbar;
xlabel('Prog klasyfikacji \theta');
ylabel('Parametr regularyzacji \lambda');
title('Wartoœci miary F na ci¹gu walidacyjnym');

set(gca, 'XTick',1:17, 'XTickLabel',{'0.1','','0.2','','0.3','','0.4','','0.5','','0.6',...
    '','0.7','','0.8','','0.9'});
set(gca, 'YTick',1:6, 'YTickLabel',{'0' '10^-5', '10^-4' '10^-3' '10^-2' '10^-1'});

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n');
pause;

fprintf('\n***DETEKCJA TWARZY***\n');
fprintf('Koñcowy model po selekcji modelu\n');
fprintf('Prog klasyfikacji: %f\n',theta);

face_detect(image,w,20,theta);

end 