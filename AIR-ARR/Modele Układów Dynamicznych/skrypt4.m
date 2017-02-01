a0 = 6;        
a1 = 3;        
b = 2;         
u0 = 0;        
du = 1;        
czas_skoku = 0;

hold all on;
grid on;
xlabel('t[s]');
ylabel('x(t)');

%{
title('Rozwiazanie rownania rozniczkowego 1.rzedu: x`(0) = 0; du = 0');
x0 = b*u0/a0;
sim('sim4');
plot(time, out, '-b');
plot(time, b*(u0+du)/a0, 'ro');
legend('Rozwiazanie symulacyjne', 'Rozwiazanie analityczne x(t)=0.(6)', 'Location', 'Best');
%}


title('Rozwiazanie rownania rozniczkowego 1.rzedu: x`(0) = 2; du = 0');
x0 = (-1)*(a0/a1)+b*u0/a0;               
sim('sim4');
plot(time, out, '-b');
plot(time, (-1)*a0/a1*exp(-a0/a1*time)+b*(u0+du)/a0, 'ro');
legend('Rozwiazanie symulacyjne', 'Rozwiazanie analityczne -e^{-2t} + 0.(6)', 'Location', 'Best');


%{
title('Rozwiazanie rownania rozniczkowego 1.rzedu: x(0) = 0; du = 0');
x0 = (-2/3)+b*u0/a0;               
sim('sim4');
plot(time, out, '-b');
plot(time, (-2/3)*exp(-a0/a1*time)+b*u0/a0, 'ro');
legend('Rozwiazanie symulacyjne', 'Rozwiazanie analityczne -(2/3)*e^{-2t} + 0.(6)', 'Location', 'Best');
%}

%{
title('Rozwiazanie rownania rozniczkowego 1.rzedu: x(0) = 4; du = 0');
x0 = (-10/3)+b*u0/a0;               
sim('sim4');
plot(time, out, '-b');
plot(time, (-10/3)*exp(-a0/a1*time)+b*u0/a0, 'ro');
legend('Rozwiazanie symulacyjne', 'Rozwiazanie analityczne -(10/3)*e^{-2t} + 0.(6)', 'Location', 'Best')
%}