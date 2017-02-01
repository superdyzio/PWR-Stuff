#include "tablica.h"

void tablice()
{
  char dane = 'w';
  char pom[20];
  int tab[ROZMIAR];
  int a, b, il = 0, i;
  printf("Kalkulator:\n");
  while (dane != 'q')
  {
    scanf("%s",&dane);
    switch (dane)
    {
      case '^': if (il > 1)
		{
		  a = tab[--il];
		  b = tab[--il];
		  tab[il++] = (int) pow((double)b,(double)a);
		}
		else printf("W tablicy jest za mało elementów!\n");
		break;
      case 'p': if (il > 0)
		{
		  a = tab[--il];
		  tab[il++] = (int) sqrt((double)a);
		}
		else printf("Tablica jest pusta!\n");
		break;
      case '+': if (il > 1)
		{
		  a = tab[--il];
		  b = tab[--il];
		  tab[il++] = b+a;
		}
		else printf("W tablicy jest za mało elementów!\n");
		break;
      case '-': if (il > 1)
		{
		  a = tab[--il];
		  b = tab[--il];
		  tab[il++] = b-a;
		}
		else printf("W tablicy jest za mało elementów!\n");
		break;
      case '/': if (il > 1)
		{
		  a = tab[--il];
		  b = tab[--il];
		  tab[il++] = b/a;
		}
		else printf("W tablicy jest za mało elementów!\n");
		break;
      case '*': if (il > 1)
		{
		  a = tab[--il];
		  b = tab[--il];
		  tab[il++] = b*a;
		}
		else printf("W tablicy jest za mało elementów!\n");
		break;
      case '?': i = 0;
		for (i=0; i<il; i++)
		  printf("%d ",tab[i]);
		printf("\n");
		break;
      case '#': if (il > 0)
	       	  il--;
		else printf("Tablica jest pusta!\n");
		break;
      case '&': if (il > 0)
		  tab[il] = tab[il-1];
		else printf("Tablica jest pusta!\n");
		il++;
		break;
      case '$': if (il > 1)
		{
		  a = tab[--il];
		  b = tab[--il];
		  tab[il++] = a;
		  tab[il++] = b;
		}
		else printf("W tablicy jest za mało elementów!\n");
		break;
      case 'q': break;
      default: tab[il++] = atoi(&dane);
    }
  }
}
