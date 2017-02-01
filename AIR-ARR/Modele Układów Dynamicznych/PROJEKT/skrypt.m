clear all;              % OGRZEWANIE KLIMATYZOWANEGO DWUPOKOJOWEGO MIESZKANIA

V1 = 5*5*3;        V2 = 8*5*3;                                              % objetosci pomieszczen
TzewN = -20;    T1N = 20;  T2N = 15;  TkzN = 30;                            % nominalne temperatury
cp = 1000;      gp = 1.2;                                                   % parametry powietrza
qkN = 20000*0.7;        fkN = qkN / (cp*gp*TkzN);                           % nominalna moc i wartosc funkcji wejsciowej
Cv1 = cp*gp*V1;                     Cv2 = cp*gp*V2;                         % pojemnosci cieplne pomieszczen (stale przy pochodnych)

czas_skoku = 300;                                                           % czas skoku                                         

K0 = (cp*gp*fkN*0.7*(TkzN - T1N)) / (T1N - T2N);                            % wspolczynnik przewodzenia sciany wewnetrznej      K0
K1 = (cp*gp*fkN*0.3*(TkzN-T1N)) / (T1N - TzewN);                            % wspolczynniki przewodzenia scian zewnetrznych     K1
K2 = ((cp*gp*fkN + K0)*(T1N-T2N)) / (T2N - TzewN);                          % sciana K2

dTzew = 0;                                                                  % zmiana tempreatury na zewnatrz
dfk = 0;                                                                    % zmiana wartosci funkcji wejsciowej
dTkz = 0;                                                                  % zmiana tempretatury wprowadzanego powietrza

figure;
hold all on;
for i=1:3;
    Tzew = TzewN+i*5;                                                       % temperatura na zewnatrz
    fk = fkN*0.5;                                                           % wartosc funkcji wejsciowej
    Tkz = TkzN;                                                             % tempretaura wprowadzanego powietrza
    w = cp*gp*fk;                                                           % zmienna pomocnicza do transmitancji
    % warunki poczatkowe dla bloczkow calkujacych
    T10 = (cp*gp*fk*Tkz + K1*Tzew + ((K0*K2*Tzew)/(K0+K2+cp*gp*fk))) / (cp*gp*fk + K1 + K0 - ((K0*(K0+cp*gp*fk))/(K0+K2+cp*gp*fk)));
    T20 = ((K0+cp*gp*fk)*T10 + K2*Tzew) / (K0 + cp*gp*fk + K2);
    sim('trans',2500);
    subplot(2,1,1);
    hold all on;
    plot(time,T1);
    grid on;
    title('Zaleznosc temperatury w pierwszym pomieszczeniu od czasu');
    xlabel('czas [s]');
    ylabel('T [°C]');
    subplot(2,1,2);
    hold all on;
    plot(time,T2);
    grid on;
    title('Zaleznosc temperatury w drugim pomieszczeniu od czasu');
    xlabel('czas [s]');
    ylabel('T [°C]');
end;