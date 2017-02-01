#include "pliki.h"


int czytaj(FILE *p, t_obraz *obraz)
{
  char s[DL_LINII];
  int znak, koniec=0, i, j;
  if (p==NULL)                                        /* sprawdzenie czy podano prawidlowy uchwyt pliku */
    {
      fprintf(stderr,"Blad: Nie podano uchwytu do pliku.\n");
      return 0;
    }
  if (fgets(s,DL_LINII,p)==NULL)
    koniec=1;
  if ( (s[0]!='P') || (s[1]!='2') || koniec)
    {  
      fprintf(stderr,"Blad: To nie jest plik PGM.\n");        /* sprawdzenie numeru magicznego - powinno byc P2 */
      return 0;
    }
  do {
    if ((znak=fgetc(p))=='#')
      {						
	if (fgets(s,DL_LINII,p)==NULL)                  /* pominiecie komentarzy */
	  koniec=1;
      }
    else ungetc(znak,p);
  } while (!koniec && znak=='#');
  if ( (fscanf(p,"%d",&obraz->wymx)!=1) || (fscanf(p,"%d",&obraz->wymy)!=1) || (fscanf(p,"%d",&obraz->szarosci)!=1) )
    {                                                  
      fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci.\n");   /* pobranie wymiarow oraz liczby odcieni szarosci */
      return 0;
    }
  if ( (obraz->wymx<0) || (obraz->wymx>MAX) || (obraz->wymy<0) || (obraz->wymy>MAX) )   
    {
      fprintf(stderr,"Blad: Bledne wymiary obrazu.\n");              /* sprawdzenie poprawnosci wymiarow */
      return 0;
    }
  if (obraz->piksele==NULL)
	obraz->piksele=malloc(obraz->wymx*obraz->wymy*sizeof(int));
  int (*piksele)[obraz->wymx];
  piksele=(int(*)[obraz->wymx]) obraz->piksele;
  for (i=0; i<obraz->wymy; i++)
    for (j=0; j<obraz->wymx; j++)                                   /* pobranie obrazu i zapisanie go w tablicy obraz_pgm */
      if (fscanf(p,"%d",&piksele[i][j])!=1)
	{
	  fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu.\n");
	  return 0;
	}
  fclose(p);
  return obraz->wymx*obraz->wymy;
}


void wyswietl(char *n_pliku)
{
  char polecenie[1024];
  strcpy(polecenie,"display ");
  strcat(polecenie,n_pliku);
  strcat(polecenie," &");
  system(polecenie);
}


int zapisz(FILE *p, t_obraz obraz, char *nazwa)
{
  char s[DL_LINII];    /* lancuch pomocniczy sluzacy do wprowadzania danych do pliku */
  int znak, koniec=0, i, j;
  if (p==NULL)
	p=fopen(nazwa,"w");
  fputs("P2\n",p);     /* wpisanie na poczatek numeru magicznego */
  sprintf(s,"%d ",obraz.wymx);  /* konwersja int na string - wykonywana przed wprowadzeniem kazdej liczby do pliku */
  fputs(s,p);
  sprintf(s,"%d\n",obraz.wymy);
  fputs(s,p);        /* wprowadzanie do pliku kolejno wymiarow obrazu w jednej linii oddzielonych spacja, a ponizej liczby odcieni szarosci */
  sprintf(s,"%d\n",obraz.szarosci);
  fputs(s,p);
  int (*piksele)[obraz.wymx];
  piksele=(int(*)[obraz.wymx]) obraz.piksele; 
  for (i=0; i<obraz.wymy; i++)
    {
      for (j=0; j<obraz.wymx; j++)
	{
	  sprintf(s,"%d ",piksele[i][j]);   /* konwersja int na string wartosci danego piksela */
	  fputs(s,p);                         /* wprowadzenie piksela do pliku */
	}
      fputs("\n",p);                        /* koniec wiersza, przejscie do nowego w pliku */
    }
  fclose(p);
  return obraz.wymx*obraz.wymy;
}


void wczytaj(t_obraz *obraz)
{
  int i,j;
  int x=0, y=0, szarosci=0;
  while (x<=0)
  {
    printf("Podaj szerokosc obrazka: ");
    scanf("%d",&x);
  }
  obraz->wymx=x;
  while (y<=0)
  {
    printf("Podaj wysokosc obrazka: ");
    scanf("%d",&y);
  }
  obraz->wymy=y;
  while (szarosci<=0)
  {
    printf("Podaj liczbe stopni szarosci: ");
    scanf("%d",&szarosci);
  }
  obraz->szarosci=szarosci;
  if (obraz->piksele==NULL)
	obraz->piksele=malloc(obraz->wymx*obraz->wymy*sizeof(int));
  int (*piksele)[obraz->wymx];
  piksele=(int(*)[obraz->wymx]) obraz->piksele;
  for (i=0; i<y; i++)
     for (j=0; j<x; j++)
       piksele[i][j]=-1;
  for (i=0; i<y; i++)
     for (j=0; j<x; j++)
      while ((piksele[i][j]<0) || (piksele[i][j]>szarosci))
	{
	   printf("Podaj wartosc piksela %d,%d: ",i,j);
	   scanf("%d",&piksele[i][j]);
	}
}


void wypisz(t_obraz obraz)
{
  int i,j;
  int (*piksele)[obraz.wymx];
  piksele=(int(*)[obraz.wymx]) obraz.piksele;
  for (i=0; i<obraz.wymy; i++)
    {
	for (j=0; j<obraz.wymx; j++)
		printf("%d ",piksele[i][j]);
	printf("\n");
    }
}
