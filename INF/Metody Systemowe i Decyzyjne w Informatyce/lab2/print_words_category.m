%--------------------------------------------------------------------------
%------------  Metody Systemowe i Decyzyjne w Informatyce  ----------------
%--------------------------------------------------------------------------
% Zadanie 3: KNN i Naiwny Bayes
% autorzy: M. Ziêba, A. Gonczarek, J.M. Tomczak, S. Zarêba
% 2016
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%----------------- TA FUNKCJA MA POZOSTAC NIEZMODYFIKOWANA ----------------
%--------------------------------------------------------------------------

function [] = print_words_category( p_x_y,wordlist,groupnames )

M = size(p_x_y,1);

K = 8;
for m = 1:M
   [~,ind] = sort(p_x_y(m,:),'descend');
   fprintf('S³owa dla kategorii: %s \n',groupnames{m})
   word_temp = wordlist(ind);
   for k=1:K
       fprintf('%s \n',word_temp{k})
   end
   fprintf('\n\n')
end
%-------------------------------------------------------------------------
end