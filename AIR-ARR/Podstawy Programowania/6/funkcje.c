#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* utworz(int wym)
{
  return (int(*)[wym])malloc(wym*wym*sizeof(int));
}

void wypelnij(int* tab, int wym)
{
  int i,j;
  for (i=0; i<wym; i++)
    for (j=0; j<wym; j++)
      tab[wym*i+j]=i*j;
}

void wyswietl (int* tab, int wym)
{
  int i,j;
  for (i=0; i<wym; i++)
    {
      for (j=0; j<wym; j++)
	printf("%d ",tab[wym*i+j]);
      printf("\n");
    }
}

void zmiana_znaku(int* tab, int wym)
{
  int i,j;
  for (i=0; i<wym; i++)
    for (j=0; j<wym; j++)
      tab[wym*i+j]*=-1;
}

int main(int argc, char *args[])
{
  int i,j;
  char wybor='a';
  int wymiar=0;
  int *a=NULL, *b=NULL;
  if (argc!=2)
    {
      printf("Niewlasciwa liczba parametrow. Uzycie: './a.out wymiar_tablicy'.\n");
      return 1;
    }
  else wymiar=atoi(args[1]);
  if (wymiar<=0)
    {
      printf("Niepoprawna wartosc parametru. Argument musi byc dodatni.\n");
      return 2;
    }
  while (wybor!='0')
    {
      printf("----------MENU----------\n");
      printf("1 - Tworzenie tablicy.\n");
      printf("2 - Wypełnianie tablicy.\n");
      printf("3 - Wyświetlanie tablicy.\n");
      printf("4 - Zmiana znaków w tablicy.\n");
      printf("5 - Tworzenie drugiej tablicy.\n");
      printf("6 - Przemnożenie dwóch tablic.\n");
      printf("0 - KONIEC\n");
      scanf("%c",&wybor);
      switch (wybor)
	{
	case '1':
	  a=utworz(wymiar);
	  printf("Tablica została utworzona.\n");
	  break;
	case '2':
	  wypelnij(a,wymiar);
	  printf("Tablica została wypełniona.\n");
	  break;
	case '3':
	  wyswietl(a,wymiar);
	  break;
	case '4':
	  zmiana_znaku(a,wymiar);
	  printf("Znak został zmieniony.\n");
	  break;
	case '5':
	  b=utworz(wymiar);
	  for (i=0; i<wymiar; i++)
	    for (j=0; j<wymiar; j++)
	      b[wymiar*i+j]=i*j;
	  break;
	case '6':
	  for (i=0; i<wymiar; i++)
	    for (j=0; j<wymiar; j++)
	      a[wymiar*i+j]*=b[wymiar*i+j];
	  break;
	case '0':
	  if (a!=NULL) free(a);
	  if (b!=NULL) free(b);
	  printf("PAPA!\n");
	}
    }
  return 0;
}
