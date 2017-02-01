function [x_int,y_int] = Lagrange(x,y)
 
e = 0.1;            % dokladnosc interpolacji
x_int = x(1) : e : x(length(x));
 
for i = 1 : 1 : length(x_int);      % wyliczanie poszczegolnych y(x) = sum(Lk)
   y_int(i) = 0;
   for k = 1 : 1 : length(x);       % wyliczanie poszczegolnych Lk
       Lk = 1;
       for j = 1 : 1 : length(x);
           if (j ~= k);
               Lk = Lk * ( (x_int(i) - x(j)) / (x(k) - x(j)) );
           end;
       end;
       y_int(i) = y_int(i) + Lk * y(k);
   end;
end;
 
end