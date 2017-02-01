clear all;

m = 6;      % liczba funkcji bazowych

% ustalone granice przedzialów
a = -3;
b = 3;
 
l = 50;     % wybrana liczba wêz³ów -1
 
% x = a : (b-a)/l : b;   % wêz³y równoodleg³e

% for i = 1 : 1 : l+1;
%     x(i) = (a-b) * cos((2*i-1)*pi/(2*l+2)) / 2 + (a+b) / 2;   % wêz³y Czebyszewa
% end;

% do zadañ 1-3
% f1 = exp(x);
% f2 = 1 ./ (1+x.^2);

% do zadania 3, 4
load('dane.mat');
x = A(:,1)';
f1 = A(:,2)';

% funkcje bazowe - zadanie 1
% for i = 1 : m;
%     for j = 1 : l+1;
%         D(j,i) = x(j) .^ (i-1);
%     end;
% end;

% funkcje bazowe - zadanie 2: wielomiany Czebyszewa
% for ll = 1 : l+1;
%     s(ll) = 2 / (b-a) * x(ll) + (a+b) / (a-b);
% end;
% for i = 1 : l+1;
%     D(i,1) = 1;
%     D(i,2) = s(i);
%     for mm = 3 : m;
%         D(i,mm) = 2*s(i)*D(i,mm-1) - D(i,mm-2);
%     end;
% end;

% wielomian optymalny - zadanie 3
beta(1) = 0;
alfa(1) = 0;
for i = 1 : l+1;
    alfa(1) = alfa(1) + x(i);
end;
alfa(1) = alfa(1) / (l+1);
D(:,1) = (x - alfa(1));
alfa(2) = 0;
mianownik = 0;
for i = 1 : l+1;
    alfa(2) = alfa(2) + x(i)*D(i,1)^2;
    mianownik = mianownik + D(i,1)^2;
end;
alfa(2) = alfa(2) / mianownik;
beta(2) = mianownik;
beta(2) = beta(2) / (l+1);
D(:,2) = (x' - alfa(2)) .* D(:,1) - beta(2)*ones(l+1,1);
for i = 3 : m;
    alfa(i) = 0;
    mianownik = 0;
    for j = 1 : l+1;
        alfa(i) = alfa(i) + x(j)*D(j,i-1)^2;
        mianownik = mianownik + D(j,i-1)^2;
    end;
    alfa(i) = alfa(i) / mianownik;
    beta(i) = mianownik;
    mianownik = 0;
    for j = 1 : l+1;
        mianownik = mianownik + D(j,i-2)^2;
    end;
    beta(i) = beta(i) / mianownik;
    D(:,i) = (x' - alfa(i)) .* D(:,i-1) - beta(i)*D(:,i-2);
end;

% A = gauss(D,f1');     % zadania 1, 2

% do zadania 1
% F = 0;
% for i = 1 : m;
%     F = F + A(i)*x.^(i-1);
% end;

% do zadania 2
% F = 0;
% for i = 1 : m;
%     F = F + A(i)*D(:,i);
% end;

% do zadania 3
C = zeros(1,m);
S = zeros(1,m);
A = zeros(1,m);
for i = 1 : m;
    for j = 1 : l+1;
        C(i) = C(i) + f1(j)*D(j,i);
        S(i) = S(i) + D(j,i)^2;
    end;
    A(i) = C(i) / S(i);
end;
F = 0;
for i = 1 : m;
    F = F + A(i)*D(:,i);
end;
    
% [ zx,zy ] = Lagrange(x,f1);
figure();
hold on;
grid on;
plot(x,F,'b');
% plot(zx,zy,'b');
plot(x,f1,'bo');
title('wielomian optymalny; m = 6');

% A = gauss(D,f2');     % zadania 1, 2

% do zadania 1
% F = 0;
% for i = 1 : m;
%     F = F + A(i)*x.^(i-1);
% end;

% do zadania 2
% F = 0;
% for i = 1 : m;
%     F = F + A(i)*D(:,i);
% end;

% do zadania 3
% C = zeros(1,m);
% S = zeros(1,m);
% A = zeros(1,m);
% for i = 1 : m;
%     for j = 1 : l+1;
%         C(i) = C(i) + f2(j)*D(j,i);
%         S(i) = S(i) + D(j,i)^2;
%     end;
%     A(i) = C(i) / S(i);
% end;
% F = 0;
% for i = 1 : m;
%     F = F + A(i).*D(:,i);
% end;

% [ zx,zy ] = Lagrange(x,f2);
% figure();
% hold on;
% grid on;
% plot(x,F,'b');
% % plot(zx,zy,'b');
% plot(x,f2,'bo');
% title('50 wezlow Czebyszewa, 30 funkcji bazowych');