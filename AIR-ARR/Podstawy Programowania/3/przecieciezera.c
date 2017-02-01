#include <stdio.h>
#include <math.h>
#define STOP 99             /* STOP to liczba konczaca dane wejsciowe, MIN i MAX to zakres dopuszczalnych wartosci */
#define MIN -10    
#define MAX 10                              
#define A 5                 /* A i B to zakres prawidlowej czestotliwosci wystapien przeciec */
#define B 8

int main()
{ 
  int x = 0;                /* x,y to dwie zmienne przeznaczone dla wprowadzanych i sprawdzanych wartosci */
  int y = 0;    
  int n = 0;                /* n to liczba juz wprowadzonych danych w obecnej grupie, a p to liczba przeciec */
  int p = 0; 
  printf("Podaj dane wejsciowe:\n");
  while ( (x < MIN) || (x > MAX) || (x == 0) )
    { scanf("%d\n",&x);
      if (x == STOP) return 0;
    }
  n++;
  while ( (x != STOP) && (y != STOP) )
    { while ( (y < MIN) || (y > MAX) ||(y == 0) )
	{ scanf("%d\n",&y);
	  if (y == STOP) return 0;
	}
      n++;
      if (x*y < 0) p++;
      x = y;
      scanf("%d\n",y);
      if (n == STOP) 
	{ if ( (p < A) || (p > B) ) printf("Bledna czestotliwosc.\n");
	  p = 0;
	  n = 0;
	  x = 0;
	  while ( (x < MIN) || (x > MAX) || (x == 0) ) scanf("%d\n",&x);
	  n++;
	}
    }
  return 0;
}
