% deklaracja poszczególnych kolumn macierzy
A = [ 10^(-10) ; 3 ];
B = [ 1 ; 10^(-12) ];
C = [ 10^-9 ; 10^-11 ];

M1 = [ A B ];   % wyjœciowa macierz wspó³czynników
M2 = [ A C ];   % macierz z kolumn¹ wyrazów wolnych na drugim miejscu
M3 = [ C B ];   % macierz z kolumn¹ wyrazów wolnych na pierwszym miejscu

W = M1(1,1) * M1(2,2) - M1(1,2) * M1(2,1);
Wy = M2(1,1) * M2(2,2) - M2(1,2) * M2(2,1);
Wx = M3(1,1) * M3(2,2) - M3(1,2) * M3(2,1);

% wyznaczenie i wypisanie rozwi¹zañ
if W ~= 0
    x = Wx / W
    y = Wy / W
end;

if W == 0
    if Wx == 0
        if Wy == 0
            disp('Uk³ad ma nieskoñczenie wiele rozwi¹zañ.');
        end;
        if Wy ~= 0
            disp('Uk³ad nie ma rozwi¹zañ.');
        end;
    end;
    if Wy == 0
        if Wx ~= 0
            disp('Uk³ad nie ma rozwi¹zañ.');
        end;
    end;
    if Wx ~= 0
        if Wy ~= 0
            disp('Uk³ad nie ma rozwi¹zañ.');
        end;
    end;
end;