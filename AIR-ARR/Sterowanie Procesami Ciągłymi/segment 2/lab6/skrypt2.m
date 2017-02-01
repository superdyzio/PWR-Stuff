N = 4 : 5 : 1001;       % liczba pomiarów
a = [ -1/2 -1/4 2 1 ];          % parametry obiektu
d = size(a,2);          % rzad ruchomej œredniej

for k = 1 : 1 : size(N,2);
    R = zeros(N(k),d);         % uogólniona macierz wejœæ
    X = zeros(N(k),1);         % wektor pomiarów wyjœæ
    u = rand(N(k)+d-1,1);      % proces wejœciowy
    sredniblad = zeros(1,size(N(k),2));      % wektor œrednich b³êdów 
    suma = 0;
    for R = 1 : 1 : 10;     % liczba testów
        for i = 1 : N(k);
            for j = 1 : d;
                R(i,j) = u(i+d-j,1);
                X(i,1) = X(i,1) + a(j)*u(i+d-j,1);
            end;
        end;
        oszac = inv(R'*R)*R'*X;          % oszacownie wektora parametrów
        suma = suma + norm(oszac-a);
    end;
    sredniblad(k) = suma/10;
end;

plot(N,sredniblad);
grid on;
hold on;