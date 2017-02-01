clear all;
 
s = tf('s');
 
figure;
hold all on;

S=100*s/((50*s+1)*(2*s+1));
bode(S);

tabk = [2 4];
tabti = [12 3];
tabtd = [6 7];

for i=1:2;
    for j=1:2;
        for k=1:2;
            S=tabk(i)*(1+s*tabtd(k)/(0.01*s+1)+1/(tabti(j)*s));
            step(S,0.1);
        end;
    end;
end;    

grid on;
axis([0,0.1,0,100]);