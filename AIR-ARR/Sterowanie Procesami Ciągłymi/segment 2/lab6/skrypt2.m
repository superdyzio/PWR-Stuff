N = 4 : 5 : 1001;       % liczba pomiar�w
a = [ -1/2 -1/4 2 1 ];          % parametry obiektu
d = size(a,2);          % rzad ruchomej �redniej

for k = 1 : 1 : size(N,2);
    R = zeros(N(k),d);         % uog�lniona macierz wej��
    X = zeros(N(k),1);         % wektor pomiar�w wyj��
    u = rand(N(k)+d-1,1);      % proces wej�ciowy
    sredniblad = zeros(1,size(N(k),2));      % wektor �rednich b��d�w 
    suma = 0;
    for R = 1 : 1 : 10;     % liczba test�w
        for i = 1 : N(k);
            for j = 1 : d;
                R(i,j) = u(i+d-j,1);
                X(i,1) = X(i,1) + a(j)*u(i+d-j,1);
            end;
        end;
        oszac = inv(R'*R)*R'*X;          % oszacownie wektora parametr�w
        suma = suma + norm(oszac-a);
    end;
    sredniblad(k) = suma/10;
end;

plot(N,sredniblad);
grid on;
hold on;