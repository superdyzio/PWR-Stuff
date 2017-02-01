b = 2;  L = -1; U = 2;          % zadane parametry
d = [ 0 1 ];                    % mo�liwe cyfry w liczbie
indeks = 1;                     % zmienna do indeksowania wektora liczb
for z = [ -1 1 ];               % znak
    for e = L : 1 : U;          % cecha
        for i = [ 1 2 ];        % pierwsza cyfra
            for j = [ 1 2 ];    % druga cyfra
                for k = [ 1 2 ];    % trzecia cyfra
                    liczby(indeks) = (d(i)/b + d(j)/b^2 + d(k)/b^3) * z * (b^e);
                    indeks = indeks + 1;
                end;
            end;
        end;
    end;
end;

% wykres wszystkich liczb nale��cych do zbioru
plot(liczby,zeros(size(liczby,2)),'o');
grid on;
hold on;

liczbyposort = sort(liczby);     % sortowanie wszystkich liczb
indeks = 1;                  % zmienna do indeksowania unikalnych warto�ci
for i = 1 : 1 : size(liczbyposort,2)-1;
    if liczbyposort(i) ~= liczbyposort(i+1)
        liczby2(indeks) = liczbyposort(i);
        indeks = indeks + 1;
    end;
end;
% p�tla wy�oni�a wszystkie unikalnie warto�ci opr�cz ostatniej warto�ci w
% wektorze - maj�c te wiedz� dodajemy j� r�cznie
liczby2(indeks) = liczbyposort(size(liczbyposort,2));

ind = 1; % zmienna pomocnicza do indeksowania sum nie nale��cych do zbioru
for i = 1 : 1 : size(liczby2,2);
    for j = i : 1 : size(liczby2,2);
        suma = liczby2(i) + liczby2(j);
        kontrolka = 0;
% sprawdzanie czy suma dw�ch unikalnych warto�ci nale�y do zbioru
% wszystkich warto�ci (kontrolka przechowuje wynik: 1 - tak)
        for k = 1 : 1 : size(liczby2,2);
            if suma == liczby2(k)
                kontrolka = 1;  
                k = size(liczby,2) + 1;
            end;
        end;
% je�li suma nie nale�y do zbioru wszystkich warto�ci dodajemy tworz�ce j�
% liczby do macierzy par, natomiast sam� sum� do wektora sum
        if kontrolka == 0; 
            pary(ind,1) = liczby2(i);
            pary(ind,2) = liczby2(j);
            sumy(ind) = suma;
            ind = ind + 1;       
        end;
    end;
end;

% wykres wszystkich sum nie nale��cych do zbioru
figure(2);
plot(sumy,zeros(size(sumy,2)),'o');
grid on;
