x = 0 : pi/36 : 5*pi;
y = sin(x);
subplot(2,1,1);
plot(x,y)
grid on;
title('wykres sinusa');
xlabel('os x');
ylabel('os y');
axis([0,16,(-2),2]);

szum = zeros(1,181);
for i = 1 : 1 : 181;
    szum(1,i) = rand(1);
end;
subplot(2,1,2);
plot(x,y+szum)
grid on;
xlabel('os x');
ylabel('os y');
title('wykres zaszumionego sinusa');
