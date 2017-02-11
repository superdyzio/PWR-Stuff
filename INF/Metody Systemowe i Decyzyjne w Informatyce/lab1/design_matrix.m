%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 2: Regresja liniowa
% autorzy: A. Gonczarek, J.M. Tomczak
% 2013
%--------------------------------------------------------------------------

function DesignMatrix = design_matrix( xTrain, M )
% Funkcja wylicza Design Matrix dla wielomianu rzedu M
% xTrain - ciag treningowy Nx1
% M - stopien wielomianu 0,1,2,...

N = size(xTrain,1);
DesignMatrix = zeros(N,M+1); 

%--------------------------------------------------------------------------
%--------------------- TUTAJ WLASNA IMPLEMENTACJA -------------------------
%--------------------------------------------------------------------------

for i = 1 : N
   for stopien = 1 :(M+1)
      DesignMatrix(i,stopien) = xTrain(i)^(stopien-1);
      % xTrain wygl¹da tak: [x1 x2 x3... xN]
      % Macierz wynikowa:
      % x1^0  x1^1  x1^2 ... x1^(M+1)
      % x2^0  x2^1  x2^2 ... x2^(M+1)
      % ...
      % xN^0  xN^1  xN^2 ... xN^(M+1)
   end
end

%--------------------------------------------------------------------------

end