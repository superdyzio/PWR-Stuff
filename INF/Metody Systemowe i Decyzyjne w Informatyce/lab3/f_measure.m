%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

function f = f_measure(yTrue, yPred)
% Funkcja wylicza wartosc miary F
% yTrue - rzeczywiste etykiety
% yPred - etykiety przewidziane przez model

f = 0;

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

n = size(yTrue,1);
tp = 0;
fp = 0;
fn = 0;

for i = 1 : n;
    if yTrue(i) && yPred(i);
        tp = tp + 1;
    elseif ~yTrue(i) && yPred(i);
        fp = fp + 1;
    elseif yTrue(i) && ~yPred(i);
        fn = fn + 1;
    end;

f = 2 * tp / (2*tp+fp+fn);

%--------------------------------------------------------------------------

end