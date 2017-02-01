function [x_int,y_int] = Newton(x,y)
 
e = 10^-3;
x_int = x(1) : e : x(length(x));
 
for init = 1 : 1 : length(x);
    M(init,1) = y(init);        % inicjalizacja macierzy ró¿nic
end;
 
for kol = 2 : 1 : length(x);    % wyliczenie wszystkich ilorazów ró¿nicowych
    for wier = 1 : 1 : (length(x) - kol +1);
        M(wier,kol) = (M(wier+1,kol-1) - M(wier,kol-1)) / (x(wier+1 + kol-2) - x(wier));
    end;
end;
b = M(1,:);         % bierzemy tylko pierwszy wiersz
 
for i = 1 : 1 : length(x_int);
    y_int(i) = 0;
    s1 = 0;
    s2 = 0;
    for k = 1 : 1 : length(x);
        p = 1;
        for j = 1 : 1 : (k-1);
            p = p*(x_int(i) - x(j));
        end;
        y_int(i) = y_int(i) + b(k)*p;
        %zmienna=b(k)*p;
        %if b(k)*p<0
        %    s1=s1+b(k)*p;
        %else
        %    s2=s2+b(k)*p;
        %end
        %x_int(i)
       % if x_int(i)>2.5
       %     k
       %     zmienna
       % end
        %tablicapomocnicza(k)=zmienna;
    end 
    %y_int(i)=s1+s2;
end
%posortowane=sort(tablicapomocnicza);
end
