#include "opcje.h"


void wyzeruj_opcje(w_opcje * wybor) 
{
  int i;
  wybor->plik_we=NULL;
  wybor->plik_wy=NULL;
  wybor->negatyw=0;
  wybor->konturowanie=0;
  wybor->progowanie=0;
  wybor->w_progu=-1;
  wybor->wyswietlenie=0;
  wybor->rozmywanie=0;
  wybor->wyostrzanie=0;
  wybor->obracanie=0;
  wybor->splot=0;
  for (i=0; i<9; i++)
	wybor->filtr[i]=0;
}


int przetwarzaj_opcje(int argc, char **argv, w_opcje *wybor)
{
  int i, prog;
  char *nazwa_pliku_we, *nazwa_pliku_wy;
  wyzeruj_opcje(wybor);
  wybor->plik_wy=stdout;        /* na wypadek gdy nie podano opcji "-o" */
  for (i=1; i<argc; i++)
  {
    if (argv[i][0] != '-')  /* blad: to nie jest opcja - brak znaku "-" */
      return B_NIEPOPRAWNAOPCJA; 
    switch (argv[i][1]) 
    { 
      case 'i':                  /* opcja z nazwa pliku wejsciowego */
       if (++i<argc)   /* wczytujemy kolejny argument jako nazwe pliku */
       { 
	 nazwa_pliku_we=argv[i];
 	 if (strcmp(nazwa_pliku_we,"-")==0) /* gdy nazwa jest "-"        */
	   wybor->plik_we=stdin;            /* ustwiamy wejscie na stdin */
	 else                               /* otwieramy wskazany plik   */
	   {
	     wybor->plik_we=fopen(nazwa_pliku_we,"r");
	     wybor->nazwa_we=nazwa_pliku_we;
	   }
       } else 
	 return B_BRAKNAZWY;                   /* blad: brak nazwy pliku */
      	break;
    case 'o':                 /* opcja z nazwa pliku wyjsciowego */
      if (++i<argc)     /* wczytujemy kolejny argument jako nazwe pliku */
      { 
	nazwa_pliku_wy=argv[i];
	if (strcmp(nazwa_pliku_wy,"-")==0)/* gdy nazwa jest "-"         */
	  wybor->plik_wy=stdout;          /* ustwiamy wyjscie na stdout */
	else                              /* otwieramy wskazany plik    */
	  {
	    wybor->nazwa_wy=nazwa_pliku_wy;
	    if (strcmp(wybor->nazwa_we,wybor->nazwa_wy) != 0)
	      wybor->plik_wy=fopen(nazwa_pliku_wy,"w");      /* rozwiązanie te ma służyć możliwości nadpisywania plików */
	    else wybor->plik_wy=NULL;
	  }
      } else return B_BRAKNAZWY;                   /* blad: brak nazwy pliku */
      break;
    case 'p': 
      if (++i<argc)  /* wczytujemy kolejny argument jako wartosc progu */
	if (sscanf(argv[i],"%d",&prog)==1)
	{ 
	  wybor->progowanie=1;
	  wybor->w_progu=prog;
	} else return B_BRAKWARTOSCI;     /* blad: niepoprawna wartosc progu */
        else return B_BRAKWARTOSCI;             /* blad: brak wartosci progu */
      break;
    case 'n':                 /* mamy wykonac negatyw */
      wybor->negatyw=1;
      break;
    case 'k':                 /* mamy wykonac konturowanie */
      wybor->konturowanie=1;
      break;
    case 'd':                 /* mamy wyswietlic obraz */
      wybor->wyswietlenie=1;
      break;
    case 'r':			/* mamy rozmyc obraz */
	wybor->rozmywanie=1;
	break;
    case 'w':			/* mamy wyostrzyc obraz */
	wybor->wyostrzanie=1;
	break;
    case 'b':			/* mamy obrocic obraz o 90 stopni zgodnie z ruchem wskazowek zegara */
	wybor->obracanie=1;
	break;
    case 'f':			/* mamy przefiltrowac obraz */
	if (++i<argc) 		/* wczytujemy kolejny argument jako macierz filtru - kolejne cyfry calkowite oddzielone przecinkami */	
	 if (sscanf(argv[i],"%d,%d,%d,%d,%d,%d,%d,%d,%d",&wybor->filtr[0],&wybor->filtr[1],&wybor->filtr[2],&wybor->filtr[3],&wybor->filtr[4],
		&wybor->filtr[5],&wybor->filtr[6],&wybor->filtr[7],&wybor->filtr[8])==9)	
			wybor->splot=1;
	 else return B_BRAKWARTOSCI;
	  else return B_BRAKWARTOSCI;
	break;
    default:                    /* nierozpoznana opcja */
      return B_NIEPOPRAWNAOPCJA;
    } /*koniec switch */
  } /* koniec for */
  if (wybor->plik_we!=NULL)     /* ok: wej. strumien danych zainicjowany */
    return W_OK;
  else 
    return B_BRAKPLIKU;         /* blad:  nie otwarto pliku wejsciowego  */
}
