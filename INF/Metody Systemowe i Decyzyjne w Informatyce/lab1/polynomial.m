%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: A. Gonczarek, J.M. Tomczak
% 2013
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%----------------- TA FUNKCJA MA POZOSTAC NIEZMODYFIKOWANA ----------------
%--------------------------------------------------------------------------

function y = polynomial( x, w )
% Funkcja wylicza wartosc wielomianu y w punktach x
% x - wektor argumentow Nx1
% w - parametry wielomianu (M+1)x1 

y = 0;

for i=1:length(w)
    y = y + w(i) .* x.^(i-1);
end

%--------------------------------------------------------------------------

end