% deklaracja poszczególnych kolum macierzy
A = [ 10^(-10) ; 3 ];
B = [ 1 ; 10^(-12) ]; 
C = [ 10^-9 ; 10^-11 ];

% przemna¿amy drugie równanie przez (-1)
B(2,1) = ( B(2,1) * -A(1,1) ) / A(2,1);
C(2,1) = ( C(2,1) * -A(1,1) ) / A(2,1);
A(2,1) = -A(1,1);

% sumowanie kolumnami
b = B(1,1) + B(2,1);
c = C(1,1) + C(2,1);
y = c / b;          % wyznaczenie drugiej niewiadomej
x = ( C(1,1) - y * B(1,1) ) / A(1,1); % wyznaczenie pierwszej niewiadomej
% wypisanie na wyjœcie wartoœci niewiadomych
x
y