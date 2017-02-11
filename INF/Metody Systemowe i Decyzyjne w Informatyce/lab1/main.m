%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: A. Gonczarek, J.M. Tomczak
% 2013
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%----------------- TA FUNKCJA MA POZOSTAC NIEZMODYFIKOWANA ----------------
%--------------------------------------------------------------------------

function main()


eps = 0.000001;
test = load('test.mat');
test = test.test;

try
    fprintf('\nWALIDACJA mean_squared_error.m...\n\n');
    err = mean_squared_error(test.meanError.x,test.meanError.y,test.meanError.w);
    diff = abs(err - test.meanError.err);
    assert( diff < eps  );
    fprintf('GRATULACJE! Funkcja mean_squared_error.m jest poprawna\n\n');
catch
    fprintf('Funkcja mean_squared_error.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    
try
    fprintf('\nWALIDACJA design_matrix.m...\n\n');
    DM = design_matrix(test.designMatrix.xTrain,test.designMatrix.M);
    diff = max(max( abs(DM - test.designMatrix.DM) ));
    assert( diff < eps  );
    fprintf('GRATULACJE! Funkcja design_matrix.m jest poprawna\n\n');
catch
    fprintf('Funkcja design_matrix.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    
try
    fprintf('\nWALIDACJA least_squares.m...\n\n');
    [w err] = least_squares(test.LS.xTrain,test.LS.yTrain,test.LS.M);
    diff_w = max( abs(w - test.LS.w) );
    diff_err = abs(err - test.LS.err);
    assert( diff_w < eps && diff_err < eps  );
    fprintf('GRATULACJE! Funkcja least_squares.m jest poprawna\n\n');
catch
    fprintf('Funkcja least_squares.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    
try
    fprintf('\nWALIDACJA regularized_least_squares.m...\n\n');
    [w err] = regularized_least_squares(test.RLS.xTrain,test.RLS.yTrain,test.RLS.M,test.RLS.lambda);
    diff_w = max( abs(w - test.RLS.w) );
    diff_err = abs(err - test.RLS.err);
    assert( diff_w < eps && diff_err < eps  );
    fprintf('GRATULACJE! Funkcja regularized_least_squares.m jest poprawna\n\n');
catch
    fprintf('Funkcja regularized_least_squares.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    
try
    fprintf('\nWALIDACJA model_selection.m...\n\n');
    [w train_err val_err] = model_selection(test.MS.xTrain,test.MS.yTrain,test.MS.xVal,test.MS.yVal);
    diff_w = max( abs(w - test.MS.w) );
    diff_train_err = abs(train_err - test.MS.train_err);
    diff_val_err = abs(val_err - test.MS.val_err);
    assert( diff_w < eps && diff_train_err < eps && diff_val_err < eps  );
    fprintf('GRATULACJE! Funkcja model_selection.m jest poprawna\n\n');
catch
    fprintf('Funkcja model_selection.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    
try
    fprintf('\nWALIDACJA regularized_model_selection.m...\n\n');
    [w train_err val_err lambda] = regularized_model_selection(test.RMS.xTrain,test.RMS.yTrain,test.RMS.xVal,test.RMS.yVal,7);
    diff_w = max( abs(w - test.RMS.w) );
    diff_train_err = abs(train_err - test.RMS.train_err);
    diff_val_err = abs(val_err - test.RMS.val_err);
    diff_lambda = abs(lambda - test.RMS.lambda);
    assert( diff_w < eps && diff_train_err < eps && diff_val_err < eps && diff_lambda < eps );
    fprintf('GRATULACJE! Funkcja regularized_model_selection.m jest poprawna\n\n');
catch
    fprintf('Funkcja regularized_model_selection.m NIE JEST poprawna !!!\n\n');
end
    fprintf('Wcisnij klawisz, aby kontynuowac...\n\n\n');
    pause;
    


%--------------------------------------------------------------------------
data = load('data.mat');
data = data.data;
xPlot = 0:0.01:1;
xPlot = xPlot';
yObject = sin(2.*pi.*xPlot);

fprintf('\nDopasowanie wielomianow do danych metoda najmniejszych kwadratow.\nLiczba punktow treningowych N=8.\n\n');

figure;
for i=1:8
    [w err] = least_squares(data.xTrain8,data.yTrain8,i-1);
    yModel = polynomial(xPlot,w);
    subplot(2,4,i)
    plotModel(data.xTrain8,data.yTrain8,xPlot,yObject,yModel);
    title(['M=' num2str(i-1)]);
end

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n');
pause;

fprintf('\nDopasowanie wielomianow do danych metoda najmniejszych kwadratow\nLiczba punktow treningowych N=50.\n\n');

figure;
for i=1:8
    [w err] = least_squares(data.xTrain50,data.yTrain50,i-1);
    yModel = polynomial(xPlot,w);
    subplot(2,4,i)
    plotModel(data.xTrain50,data.yTrain50,xPlot,yObject,yModel);
    title(['M=' num2str(i-1)]);
end

fprintf('Wcisnij klawisz, aby kontynuowac...\n\n');
pause;

fprintf('\nSelekcja modelu dla liniowego zadania najmniejszych kwadratów.\nModele wielomianowe stopnia M=0,...,7. \nLiczba punktow treningowych N=50. \nLiczba punktow walidacyjnych N=20.\n\n');

figure;
[w train_err val_err] = model_selection(data.xTrain50,data.yTrain50,data.xVal20,data.yVal20);
yModel = polynomial(xPlot,w);
M = length(w)-1;
fprintf('Dopasowano wielomian stopnia: %d',M);
fprintf('\nBlad na ciagu treningowym: %f',train_err);
fprintf('\nBlad na ciagu walidacyjnym: %f',val_err);
plotModel(data.xTrain50,data.yTrain50,xPlot,yObject,yModel);
plot(data.xVal20,data.yVal20,'or','MarkerSize',8,'LineWidth',2);
title(['M=' num2str(M)]);

fprintf('\n\nWcisnij klawisz, aby kontynuowac...\n\n');
pause;

fprintf('\nSelekcja modelu dla liniowego zadania najmniejszych kwadratów z regularyzacja.\nModel wielomianowy stopnia M=7. \nLiczba punktow treningowych N=50. \nLiczba punktow walidacyjnych N=20.\n\n');

figure;
M = 7;
[w train_err val_err lambda] = regularized_model_selection(data.xTrain50,data.yTrain50,data.xVal20,data.yVal20,M);
yModel = polynomial(xPlot,w);
fprintf('Parametr regularycji lambda=: %f',lambda);
fprintf('\nBlad na ciagu treningowym: %f',train_err);
fprintf('\nBlad na ciagu walidacyjnym: %f\n',val_err);
plotModel(data.xTrain50,data.yTrain50,xPlot,yObject,yModel);
plot(data.xVal20,data.yVal20,'or','MarkerSize',8,'LineWidth',2);
title(['M=' num2str(M) '  lambda=' num2str(lambda)]);

end 

function plotModel(Xtrain,Ytrain,X,YObject,YModel)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Funkcja rysuje rysunki w stylu tych z Bishopa
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Xtrain - wektor wartoœci x punktów ze zbioru treningowego Nx1
% Ytrain - wektor wartoœci y punktów ze zbioru treningowego Nx1
% X - punkty dla których wykreœlone zostan¹ wykresy obiektu i modelu Kx1
% YObject - wartoœci obiektu rzeczywistego w punktach z X, Kx1
% YModel - wartoœci modelu w punktach z X, Kx1
% StdDevs - wartoœci odchylenia standardowego w punktach z X, Kx1

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

XMin = min( min(Xtrain),min(X) );
XMax = max( max(Xtrain),max(X) );
YMin = -1.5; %min( [min(Ytrain),min(YObject),min(YModel)] );
YMax = 1.5; %max( [max(Ytrain),max(YObject),max(YModel)] );

IntX = XMax - XMin;
XBeg = XMin - IntX/14;
XEnd = XMax + IntX/14;
XLabels = [XMin XMax];

IntY = YMax - YMin;
YLabels = [YMin YMin+0.5*IntY YMax];

hold on;
plot(X,YObject,'-g','LineWidth',2);
plot(X,YModel,'-r','LineWidth',2);
plot(Xtrain,Ytrain,'o','MarkerSize',8,'LineWidth',2);
set(gca,'XTick',XLabels);
set(gca,'FontSize',14);
set(gca,'YTick',YLabels);
set(gca,'XLim',[XBeg XEnd]);
set(gca,'YLim',[1.1*YMin,1.1*YMax]);
set(0,'DefaultAxesFontname','Times New Roman');

end
