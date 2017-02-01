#include <stdio.h>
#include <malloc.h>
#include "liczby.h"

/*  Zwracana wartość:
 *  0 - działanie programu przebiegło bez problemów 
 *  1 - wystąpił błąd w funkcji tworzenia tablicy
*/

int main(){
  int ilosc;
  int *TabLiczb = NULL;
  if (utworzTab(&ilosc, &TabLiczb) != 0) {
    fprintf(stderr,":( Brak pamieci. Tablica liczb nie zostala utworzona\n");
    return 1;
  }
  else {  	
    pobieranie(&ilosc, &TabLiczb);
    sortowanie(&ilosc, &TabLiczb);
    wyswietl(&ilosc, &TabLiczb);
  }
  printf("Koniec dzialania programu.\n");
  free(TabLiczb);
  return 0;
}
