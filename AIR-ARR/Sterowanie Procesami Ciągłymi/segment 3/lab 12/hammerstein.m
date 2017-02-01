clear all;

N = 1000;
g0 = 2;
g1 = 1;
c1 = 2;
c2 = 3;
u0 = 0;
teta = [ g0*c1 g0*c2 g1*c1 g1*c2 ]';

for k = 1 : N;
    u(k) = rand()*4 - 2;
    z(k) = rand()/5 - 0.1;
    mi(k) = c1*u(k)^2 + c2*u(k);
    if k == 1;
        fi = [ u(k)^2 ; u(k) ; u0^2 ; u0 ];
        y(k) = teta' * fi + z(k);
        FI = fi';
    end;
    if k > 1;
        fi = [ u(k)^2 ; u(k) ; u(k-1)^2 ; u(k-1) ];
        y(k) = teta' * fi + z(k);
        FI = [ FI ; fi' ];
    end;
end;

tetaw = inv(FI' * FI) * FI' * y';

A = [ tetaw(1) tetaw(2) ; tetaw(3) tetaw(4) ];
[P,D,Q] = svd(A);