clear all;

min = 10^9;
minx = -1;
miny = -1;

i = 1;

for x = 2 : 0.01 : 4;
    for y = 3 : 0.01 : 5;
        if (x-3)^2 + (y-4)^2 <= 1;
            plot(x,y,'b');
            a(i) = x;
            b(i) = y;
            i = i+1;
            hold on;
            grid on;
            if x^2 + y^2 < min;
                min = x^2 + y^2;
                minx = x;
                miny = y;
            end;
        end;
    end;
end;

plot(minx,miny,'ro');

figure(2);
[X,Y] = meshgrid(0:0.01:5);
Z = X.^2 + Y.^2;
plot3(X,Y,Z);
hold on;
grid on;
plot3(minx,miny,min,'ro');
minimum = ones(i-1) .* min;
plot3(a,b,minimum,'bx');