function [x_int,y_int] = Vandermonde(x,y)

e = 10^-3;
x_int = x(1) : e : x(length(x));

for wier = 1 : 1 : length(x);
    for kol = 1 : 1 : length(x);
        V(wier,kol) = x(wier)^(kol-1);
    end;
end;

a = gauss(V,y);        % wspó³czynniki
 
for i = 1 : 1 : length(x_int);
   y_int(i) = 0;
   for j = 1 : 1 : length(x);
       y_int(i) = y_int(i) + a(j) * x_int(i)^(j-1);
   end;
end;
 
end
