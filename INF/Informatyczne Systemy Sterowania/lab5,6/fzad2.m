function [ kryterium ] = fzad2( wektor )

options = simset('SrcWorkspace','current');

% parametry obiektu
a0 = 6;
a1 = 4;
a2 = 3;
a3 = 1;
b = 3;
zadana = 25;    % wartoœæ zadana

Ki = 1;
K = wektor(1);
Ti = wektor(2);
Td = wektor(3);

sim('model', 30, options);

error = (y - zadana).^2;

kryterium = trapz(error);

end