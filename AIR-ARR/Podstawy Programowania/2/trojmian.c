/* 
    kompilacja: Sun C: cc -Xc trojmian.c -lm
                GNU C: gcc -pedantic -Wall trojmian.c -lm*/
#include <stdio.h>
#include <math.h>

int main() {
  float a,b,c,delta;

  printf("Program oblicza pierwiastki rownania w postaci\n");
  printf("  ax + bx + c =0\n");
  printf("Podaj wartosc a:");
  scanf("%f",&a);
  printf("Podaj wartosc b:");
  scanf("%f",&b);
  printf("Podaj wartosc c:");
  scanf("%f",&c);
  
  if (a==0.0)                                                   /* przypadek rownania liniowego */
    if (b!=0.0) 
      printf("Jest to równanie liniowe o rozwiazaniu x=%f\n",-c/b);
    else  if (c==0.0)  /* oraz a==b==0.0 */
      printf("Rozwiazaniem jest dowolne x\n");
          else              /* a==b==0.0 != c  */
            printf("Brak rozwiazan\n");
  else {                                                       /* przypadek rownania kwadratowego */
    delta=pow(b,2)-4.0*a*c;
    if (delta<0) 
      printf("Brak rozwiazan rzeczywistych\n");
    else            /* delta>=0 */
      if (delta>0) 
	printf("Rozwiazaniem sa x1=%f i x2=%f\n",(-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a));
      else
      	printf("Rozwiazaniem sa x1=x2=%f\n",-b/(2*a));
  }

}



/*            Dawid Perdek, 15.10.2012 (godz. 18.55)

   Testy mialy na celu sprawdzenie czy program radzi sobie z roznymi wariantami
   danych wejsciowych (dodatnie lub ujemne, duze i male wartosci), odpowiadajacych 
   rownaniom kwadratowym o roznych wartosciach delty, rownianiom liniowym, sprzecznoscia oraz tozsamoscia.

      1) a=b=c=0           Program wyswietlil komunikat o tozsamosci.
      2) b=c=0 a!=0        Program prawidlowo wyswietlil rozwiazanie x=0.
      3) a=c=0 b!=0        Program prawidlowo wyswietlil rozwiazanie x=0.
      4) a=b=0 c!=0        Program wyswietlil komunikat o sprzecznosci.
      5) tylko c=0         Program prawidlowo podawal dwa rozwiazania, z ktorych jedno to x=0.
      6) tylko b=0         Program prawidlowo podawal dwa rozwiazania dla a<0 lub c<0
                           oraz wyswietlal komunikat o braku rozwiazan dla a i c tego samego znaku.
      7) tylko a=0         Program prawidlowo wyswietlal jedno rozwiazanie dla rownania liniowego.
      8) a!=0 b!=0 c!=0    Program prawidlowo wyliczal delte i podawal jedno lub dwa rozwiazania
                           albo wyswietlal komunikat o braku rozwiazan rzeczywistych. 
     
      9) Wprowadzenie danych w blednej formie (litery lub liczby z przecinkiem zamiast kropki) 
         doprowadzalo do wylaczenia programu bez zwrocenia wyniku. Jedynie sytuacja w ktorej
	 a i b zostalo wprowadzone poprawnie, a jedynie c niepoprawnie pozwalala programowi na
	 zwrocenie prawidlowego wyniku.
			   
   Test pokazal, ze program dziala dobrze i radzi sobie z kazdym zestawem poprawnych danych 
   wejsciowych (liczb) oraz z jednym przypadkiem blednych danych, zwracajac poprawny wynik lub prawdziwe zdanie.
   
   W instrukcji nalezaloby zwrocic uwage uzytkownika na poprawnosc wprowadzanych przez niego danych,
   a bedzie mogl sie cieszyc dzialajacym bez zarzutu programem.
   
*/
