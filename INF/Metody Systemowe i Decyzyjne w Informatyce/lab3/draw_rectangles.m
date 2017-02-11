%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: Detekcja twarzy
% autorzy: A. Gonczarek, J.M. Tomczak, S. Zarêba, M. Ziêba
% 2016
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%----------------- TA FUNKCJA MA POZOSTAC NIEZMODYFIKOWANA ----------------
%--------------------------------------------------------------------------

function draw_rectangles(im,points)

imshow(im);

N = size(points,1);
hold on;
for n=1:N-1
   i_min = points(n,1) - 56;
   j_min = points(n,2) - 46;
   i_max = points(n,1) + 56;
   j_max = points(n,2) + 46;
   
   plot([j_min j_min],[i_min i_max],'-g','LineWidth',2);
   plot([j_max j_max],[i_min i_max],'-g','LineWidth',2);
   plot([j_min j_max],[i_min i_min],'-g','LineWidth',2);
   plot([j_min j_max],[i_max i_max],'-g','LineWidth',2);
end
   i_min = points(N,1) - 56;
   j_min = points(N,2) - 46;
   i_max = points(N,1) + 56;
   j_max = points(N,2) + 46;
   
   plot([j_min j_min],[i_min i_max],'-r','LineWidth',2);
   plot([j_max j_max],[i_min i_max],'-r','LineWidth',2);
   plot([j_min j_max],[i_min i_min],'-r','LineWidth',2);
   plot([j_min j_max],[i_max i_max],'-r','LineWidth',2);

end