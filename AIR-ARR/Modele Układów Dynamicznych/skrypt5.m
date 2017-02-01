% parametry
a = 1;
ksi = -1.1;
w = 3;
d = 1;
u0 = 0;
u10 = 0;
du = 1;
d1u = 0;
czas_skoku = 2;
dt = 0.05;
x10 = 0;
x0 = d*u0/w*w;
tabx0 = [ -4 0 4 ];
tabx10 = [-10 0 10 ];
tabksi = [ -1.1 -0.4 0 0.6 1.5 ];

for i = 1:5;
    ksi = tabksi(i);
    d1u = 0;
    u0 = 0;
    du = 1;
    x10 = 0;
    x0 = d*u0 / w*w;
    figure;
    
    % bieguny uk≥adu
    p1 = (((-2)*ksi*w)+2*w*sqrt(ksi*ksi-1))/2;
    p2 = (((-2)*ksi*w)-2*w*sqrt(ksi*ksi-1))/2;
    subplot(2,2,1);
    hold on;
    plot(real(p1),imag(p1),'*');
    plot(real(p2),imag(p2),'*');
    grid on;
    
    % odpowiedü skokowa
    sim('sim5');
    subplot(2,2,2);
    plot(t,X);
    grid on;
    
    % odpowiedü impulsowa
    d1u = du;
    sim('sim5');
    subplot(2,2,3);
    plot(t,X);
    grid on;
    
    % portret fazowy
    u0 = 1;
    du = 0;
    d1u = 0;
    x0 = 0;
    x10 = -8;
    subplot(2,2,4);
    grid on;
    hold all on;
    for j = 1:3;
        x10 = tabx10(j);
        if (ksi <= -1)
            for k = 1:3;
                x0 = tabx0(k);
                sim('sim5',0.2);
                plot(X,X1);
            end;
        else
            for k = 1:3;
                x0 = tabx0(k);
                sim('sim5',5);
                plot(X,X1);
            end;
        end;
    end;
end;