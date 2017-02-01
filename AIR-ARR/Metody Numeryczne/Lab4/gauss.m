function [x] = gauss(A,b)

format long;

%%%%%%%%%%%%%%%%%%%% ALGORYTM GAUSSA

rozmiar = size(A,2);
wolne = b;        % wektor wyraz�w wolnych
x = zeros(rozmiar,1);           % wektor warto�ci x
koniec = false;                 % zmienna pomocnicza m�wi�ca o b��dzie w algorytmie
e = 10^-24;                     % b��d przybli�enia
mnoznik = 0;        % warto�� przez jak� przemna�amy dodawany do innego wiersz
suma = 0;           % zmienna na podstawie kt�rej wyznaczamy ko�cow� warto�� danego x
M = [ A wolne ];    % macierz A z do��czon� kolumn� wyraz�w wolnych
i = 1;
j = 1;
k = 1;

while koniec == false && i <= rozmiar;
    j = i+1;
    while koniec == false && j <= rozmiar;
        if abs(M(i,i)) < e;
            koniec = true;
        end;
        if koniec == false;
            mnoznik = -M(j,i)/M(i,i);       % wyznaczanie warto�ci wsp�czynnika
        end;
        k = 1;
        while koniec == false && k <= rozmiar+1;
            M(j,k) = M(j,k) + mnoznik * M(i,k);     % sumowanie wierszy
            k = k+1;
        end;
        j = j+1;
    end;
    i = i+1;
end;
i = rozmiar;
while koniec == false && i > 0;
    suma = M(i,rozmiar+1);      % pobranie odpowiedniego wyrazu wolnego
    j = rozmiar;
    while koniec == false && j > i;
        suma = suma - M(i,j) * x(j);        % pomniejszanie wyrazu wolnego o odpowiednie iloczyny
        j = j-1;
    end;
    if abs(M(i,i)) < e;
        koniec = true;
    end;
    if koniec == false;
        x(i) = suma / M(i,i);           % wyznaczanie ko�cowej warto�ci x
    end;
    i = i-1;
end;

% %%%%%%%%%%%%%%%%%%%% ALGORYTM GAUSSA Z PE�NYM WYBOREM ELEMENTU G��WNEGO
% 
% rozmiar = size(A,2);
% wolne = b;                      % wektor wyraz�w wolnych
% x = zeros(rozmiar,1);           % wektor warto�ci x
% koniec = false;                 % zmienna pomocnicza m�wi�ca o b��dzie w algorytmie
% e = 10^-9;                     % b��d przybli�enia
% mnoznik = 0;        % warto�� przez jak� przemna�amy dodawany do innego wiersz
% suma = 0;           % zmienna na podstawie kt�rej wyznaczamy ko�cow� warto�� danego x
% M = [ A wolne ];    % macierz A z do��czon� kolumn� wyraz�w wolnych
% i = 1;
% j = 1;
% k = 1;
% z = 1;              % indeks do macierzy zamiany kolumn - jednocze�nie przechowuje liczb� dokonanych zamian
% 
% while koniec == false && i <= rozmiar;
%     j = i+1;
%     while koniec == false && j <= rozmiar;
%         if abs(M(i,i)) < e;
%             max = M(i,i);
%             ind1 = i;
%             ind2 = i;
%             for m = i : 1 : rozmiar;
%                 for l = m+1 : 1 : rozmiar;
%                     if M(l,m) > max;
%                         max = abs(M(l,i));
%                         ind1 = l;
%                         ind2 = m;
%                     end;
%                 end;
%             end;
%             if max < e;
%                 koniec = true;
%             end;
%             if koniec == false;
%                 if ind2 == i;
%                     pom = M(i,1:rozmiar+1);
%                     M(i,1:rozmiar+1) = M(ind1,1:rozmiar+1);
%                     M(ind1,1:rozmiar+1) = pom;
%                 end;
%                 if ind2 ~= i;
%                     pom = M(i,1:rozmiar+1);
%                     M(i,1:rozmiar+1) = M(ind1,1:rozmiar+1);
%                     M(ind1,1:rozmiar+1) = pom;
%                     pom = M(1:rozmiar,i);
%                     M(1:rozmiar,i) = M(1:rozmiar,ind2);
%                     M(1:rozmiar,ind2) = pom;
%                     zamiany(z,1) = i;
%                     zamiany(z,2) = ind2;
%                     z = z + 1;
%                 end;
%             end;
%         end;
%         if koniec == false;
%             mnoznik = -M(j,i)/M(i,i);       % wyznaczanie warto�ci wsp�czynnika
%         end;
%         k = 1;
%         while koniec == false && k <= rozmiar+1;
%             M(j,k) = M(j,k) + mnoznik * M(i,k);     % sumowanie wierszy
%             k = k+1;
%         end;
%         j = j+1;
%     end;
%     i = i+1;
% end;
% i = rozmiar;
% while koniec == false && i > 0;
%     suma = M(i,rozmiar+1);      % pobranie odpowiedniego wyrazu wolnego
%     j = rozmiar;
%     while koniec == false && j > i;
%         suma = suma - M(i,j) * x(j);        % pomniejszanie wyrazu wolnego o odpowiednie iloczyny
%         j = j-1;
%     end;
%     if abs(M(i,i)) < e;
%         koniec = true;
%     end;
%     if koniec == false;
%         x(i) = suma / M(i,i);           % wyznaczanie ko�cowej warto�ci x
%     end;
%     i = i-1;
% end;
% 
% end