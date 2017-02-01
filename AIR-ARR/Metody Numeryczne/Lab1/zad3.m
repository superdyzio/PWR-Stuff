clear all;

h = 0.1;        % zadana dok³adnoœæ przybli¿enia
a = 1;
b = 9;
x = [ a : 0.01 : b ];   % przedzia³ na którym liczymy pochodne

% liczymy wszystkie pochodne metod¹ nr 1 - dok³adnoœæ O(h)
for i = 1 : size(x,2) 
    da1(i) = ( exp(x(i)+h) - exp(x(i)) ) / h;
    db1(i) = ( exp(-(x(i)+h)*(x(i)+h)) - exp(-(x(i)*x(i))) ) / h;
    dc1(i) = ( ((x(i)+h)*(x(i)+h)*log(x(i)+h)) - (x(i)*x(i)*log(x(i))) ) / h;
    dd1(i) = ( (1/sqrt(1+(x(i)+h)*(x(i)+h))) - (1/sqrt(1+x(i)*x(i))) )  / h;
end;

% liczymy wszystkie pochodne metod¹ nr 2 - dok³adnoœæ O(h^2)
for i = 1 : size(x,2) 
    da2(i) = ( exp(x(i)+h^2) - exp(x(i)) ) / h^2;
    db2(i) = ( exp(-(x(i)+h^2)*(x(i)+h^2)) - exp(-(x(i)*x(i))) ) / h^2;
    dc2(i) = ( ((x(i)+h^2)*(x(i)+h^2)*log(x(i)+h^2)) - (x(i)*x(i)*log(x(i))) ) / h^2;
    dd2(i) = ( (1/sqrt(1+(x(i)+h^2)*(x(i)+h^2))) - (1/sqrt(1+x(i)*x(i))) )  / h^2;
end;

% pochodne wzorcowe
h = 0.0101;
wzor1 = diff(exp(x))./h;
wzor2 = diff(exp(-(x.*x)))./h;
wzor3 = diff(x.*x.*log(x))./h;
wzor4 = diff(1./sqrt(1+x.^2))./h;
wzor1(801) = wzor1(800);
wzor2(801) = wzor2(800);
wzor3(801) = wzor3(800);
wzor4(801) = wzor4(800);

figure;
hold on;
grid on;
plot(x,log10(abs(wzor1-da1)),'b',x,log10(abs(wzor1-da2)),'r');

figure;
hold on;
grid on;
plot(x,log10(abs(wzor2-db1)),'b',x,log10(abs(wzor2-db2)),'r');

figure;
hold on;
grid on;
plot(x,log10(abs(wzor3-dc1)),'b',x,log10(abs(wzor3-dc2)),'r');

figure;
hold on;
grid on;
plot(x,log10(abs(wzor4-dd1)),'b',x,log10(abs(wzor4-dd2)),'r');