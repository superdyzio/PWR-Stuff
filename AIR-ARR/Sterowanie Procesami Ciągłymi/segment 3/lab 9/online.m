clear all;

teta = [0.5 0.25 2 1];
N = 1000;
Yn = zeros(N,1);
Un = rand(N,1)*3;
z = randn(N,1);
PN = eye(4).*1000;
AN = 0;
 
figure(1);
hold on;
grid on;
axis([0 1000 -2 4]);
xlabel('N');
title('lambda = 1.5');
 
lambda = 1.5;

for n=3:N
    XN = [Yn(n-1) Yn(n-2) Un(n) Un(n-1)]';
    Yn(n) = sum(teta.*XN') + z(n);
    PN = (PN-(PN*XN*XN'*PN)/(lambda+XN'*PN*XN))/lambda;
    AN = AN+PN*XN*(Yn(n)-XN'*AN);
    if (n == 500)
        teta = [0.7 0.15 1 1.5];
    end;
    plot(n, AN(1,:), 'r.');
    plot(n, AN(2,:), 'g.');
    plot(n, AN(3,:), 'b.');
    plot(n, AN(4,:), 'k.');
    
end