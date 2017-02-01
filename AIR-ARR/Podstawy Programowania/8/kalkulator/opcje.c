#include "opcje.h"

void kalkulator()
{
  char dane = 'w';
  char ciag[30];
  Stos *x = NULL;
  Stos *y = NULL;
  int a, b, il, i;
  printf("Kalkulator:\n");
  while (dane != 'q')
  {
   scanf("%s",ciag);
   il = ilosc(x);
   for (i=0; i<strlen(ciag); i++){     // pętla pozwalająca odróżnić minus jako działanie od znaku liczby
   dane = ciag[i];
   if ((dane<'0') || (dane>'9')) 
    switch (dane)
    {
      case 'm': if (il > 0)
		{
			y = push(x->liczba,y);
			free(pop(&x));    // zapisywanie elementu na pomocniczym stosie
		}
		else printf("Stos pomocniczy jest pusty!\n");
		break;
      case 'r': if (ilosc(y) > 0)
			free(pop(&y));    // usuwanie elementu z pamięci dodatkowej
		else printf("Stos pomocniczy jest pusty!\n");
		break;
      case 'd': if (ilosc(y) > 0)
		{
			x = push(y->liczba,x);    // wrócenie elementu na główny stos
			free(pop(&y));
		}
		else printf("Stos pomocniczy jest pusty!\n");	
		break;
      case 't': print(y);
		break;
      case '^': if (il > 1)          // potęgowanie
		{
		  a = x->liczba;
		  free(pop(&x));
		  b = x->liczba;
		  free(pop(&x));
		  x = push((int)pow((double)b,(double)a),x);     // seria rzutowań, aby nie było problemów ze zgodnością typów
		}
		else printf("Na stosie jest za mało elementów!\n");
		break;
      case 'p': if (il > 0)         // wyciąganie pierwiastka kwadratowego
		{
		  a = x->liczba;
		  free(pop(&x));
		  x = push((int)sqrt((double)a),x);
		}
		else printf("Stos jest pusty!\n");
		break;
      case '+': if (il > 1)
		{
		  a = x->liczba;
		  free(pop(&x));
		  b = x->liczba;
		  free(pop(&x));
		  x = push(b+a,x);
		}
		else printf("Na stosie jest za mało elementów!\n");
		break;
      case '-': if ((ciag[i+1]==32) || (ciag[i+1]=='\0'))
		if (il > 1)
		{
		  a = x->liczba;
		  free(pop(&x));
		  b = x->liczba;
		  free(pop(&x));
		  x = push(b-a,x);
		}
		else printf("Na stosie jest za mało elementów!\n");
		else if ((ciag[i+1]>=48) && (ciag[i+1]<=57)){
			a = atoi(ciag);
			x = push(a,x);
			i=strlen(ciag);
		}
		break;
      case '/': if (il > 1)
		{
		  a = x->liczba;
		  free(pop(&x));
		  b = x->liczba;
		  free(pop(&x));
		  x = push(b/a,x);
		}
		else printf("Na stosie jest za mało elementów!\n");
		break;
      case '*': if (il > 1)
		{
		  a = x->liczba;
		  free(pop(&x));
		  b = x->liczba;
		  free(pop(&x));
		  x = push(b*a,x);
		}
		else printf("Na stosie jest za mało elementów!\n");
		break;
      case '?': print(x);        // wyświetlanie całej zawartości stosu
		break;
      case '#': if (il > 0)      // usuwanie ostatnio dodanego elementu
	       	  free(pop(&x));
		else printf("Stos jest pusty!\n");
		break;
      case '&': if (il > 0)      // duplikowanie elementu z wierzchołka
		{
		  a = x->liczba;
		  x = push(a,x);
		}
		else printf("Stos jest pusty!\n");
		break;
      case '$': if (il > 1)     // zamiana miejscami dwóch wierzchnich elementów
		{
		  a = x->liczba;
		  free(pop(&x));
		  b = x->liczba;
		  free(pop(&x));
		  x = push(a,x);
		  x = push(b,x);
		}
		else printf("Na stosie jest za mało elementów!\n");
		break;
      case 'q': czysc(&x); 
		czysc(&y);     // koniec działania - zwalnianie pamięci całego stosu
		break;
      default: printf("Błędna komenda.\n");
    }
    else 
    {
	a = atoi(ciag);
	x = push(a,x);         // jeśli znak nie jest żadną z opcji to dodajemy liczbę na stos 
	i = strlen(ciag);
    }
    }
  }
}
