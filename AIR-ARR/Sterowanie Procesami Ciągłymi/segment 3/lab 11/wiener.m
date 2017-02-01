clear all;

skok = 0;
% min = 10^9;
% for k1 = 0.2 : 0.2 : 5;
%     for k2 = 0.2 : 0.2 : 5;
%         sim('pd');
%         if kryt(size(kryt,1)) < min;
%             min = kryt(size(kryt,1));
%             a = k1;
%             b = k2;
%         end;
%     end;
% end;

k1 = 5;
k2 = 0.8;
% min

sim('pd');
figure(1);
hold on;
grid on;
plot(czas,y);
title('odpowiedz skokowa');

figure(2);
hold on;
grid on;
title('calka z kwadratu uchybu');
plot(czas, kryt);

figure(3);
hold on;
grid on;
title('e`(e)');
plot(e,de);