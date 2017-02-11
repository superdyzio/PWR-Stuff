function [ kryterium ] = fzad2( wektor )

options = simset('SrcWorkspace','current');

% parametry obiektu
d = 3;
B = 2;
alfa = 12;
beta = 3;
zadana = 5;    % wartoœæ zadana

Ki = 1;
K = wektor(1);
Ti = wektor(2);
Td = wektor(3);

sim('model', 60, options);

error = (y - zadana).^2;

kryterium = trapz(error);

end