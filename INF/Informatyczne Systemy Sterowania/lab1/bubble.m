clear all;

x = floor(rand*1000);

for i = 1 : 99;
   x = [x floor(rand*1000)];
end;

for i = 1 : size(x,2);
    for j = i+1 : size(x,2);
        if x(i) > x(j)
            temp = x(j);
            x(j) = x(i);
            x(i) = temp;
        end;
    end;
end;

y = [];
for i = 1 : 10;
    hehe = liczby(floor(randn*10));
    if hehe == 0;
        i = 10;
    else
        y = [y hehe];
    end;
end;

y