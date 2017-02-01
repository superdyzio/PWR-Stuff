clear all;

% definiujemy pierwsz� cz�� przedzia�u
a = 0.5;
b = 1.5;

h = 1;        % dok�adno�� przybli�enia ilorazu r�nicowego

%%%%%%%%%% METODA NEWTONA

xk = a;
fk = exp(xk) - 3*xk^2;
fpk = ((exp(xk+h) - 3*(xk+h)^2)-(exp(xk) - 3*xk^2))/h;

iteracje = 0;

while abs(fk) > 10^-6;
    xk = xk - (fk/fpk);
    fk = exp(xk) - 3*xk^2;
    fpk = ((exp(xk+h) - 3*(xk+h)^2)-(exp(xk) - 3*xk^2))/h;
    iteracje = iteracje + 1;
end;

disp('Dodatni pierwiastek nr 1:');
fprintf('%f\n\n',xk);
iteracje

% definiujemy drug� cz�� przedzia�u
a = 3;
b = 4;

%%%%%%%%%% METODA NEWTONA

xk = a;
fk = exp(xk) - 3*xk^2;
fpk = ((exp(xk+h) - 3*(xk+h)^2)-(exp(xk) - 3*xk^2))/h;

iteracje = 0;

while abs(fk) > 10^-6;
    xk = xk - (fk/fpk);
    fk = exp(xk) - 3*xk^2;
    fpk = ((exp(xk+h) - 3*(xk+h)^2)-(exp(xk) - 3*xk^2))/h;
    iteracje = iteracje + 1;
end;

disp('Dodatni pierwiastek nr 2:');
fprintf('%f\n\n',xk);
iteracje