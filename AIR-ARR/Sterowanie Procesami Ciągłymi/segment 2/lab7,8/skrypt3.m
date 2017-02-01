N = 10^3;

xn = [ 2 3 1 4 ];
a0 = zeros(1,4);
p0 = eye(4);
p1 = p0 - p0*xn*xn'*p0 / (1 + xn'*p0*xn);
a1 = a0 + p1*xn
