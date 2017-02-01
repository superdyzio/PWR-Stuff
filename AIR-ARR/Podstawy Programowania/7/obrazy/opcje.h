#ifndef OPCJE_H
#define OPCJE_H

#include<stdio.h>
#include<string.h>
#define W_OK 0                   /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1    /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY   -2
#define B_BRAKWARTOSCI  -3
#define B_BRAKPLIKU   -4

/* strukura do zapamietywania opcji podanych w wywolaniu programu */
typedef struct {
  FILE *plik_we, *plik_wy;        /* uchwyty do pliku wej. i wyj. */
  char *nazwa_we, *nazwa_wy;
  int negatyw,progowanie,konturowanie,wyswietlenie;      /* opcje */
  int rozmywanie, wyostrzanie, obracanie, splot;
  int w_progu;              /* wartosc progu dla opcji progowanie */ 
  int filtr[9];			/* macierz dla filtrow */
} w_opcje;


/*******************************************************/
/* Funkcja inicjuje strukture wskazywana przez wybor   */
/* PRE:                                                */
/*      poprawnie zainicjowany argument wybor (!=NULL) */
/* POST:                                               */
/*      "wyzerowana" struktura wybor wybranych opcji   */
/*******************************************************/

void wyzeruj_opcje(w_opcje *wybor);


/************************************************************************/
/* Funkcja rozpoznaje opcje wywolania programu zapisane w tablicy argv  */
/* i zapisuje je w strukturze wybor                                     */
/* Skladnia opcji wywolania programu                                    */
/*         program {[-i nazwa] [-p liczba] [-n] [-k] [-r] [-w] [-s]	*/
/*			[-b] [-o nazwa] [-d] } 				*/
/*	macierz - 9 liczb calkowitych oddzielonych przecinkami      	*/
/* Argumenty funkcji:                                                   */
/*         argc  -  liczba argumentow wywolania wraz z nazwa programu   */
/*         argv  -  tablica argumentow wywolania                        */
/*         wybor -  struktura z informacjami o wywolanych opcjach       */
/* PRE:                                                                 */
/*      brak                                                            */
/* POST:                                                                */
/*      funkcja otwiera odpowiednie pliki, zwraca uchwyty do nich       */
/*      w strukturze wybór, do tego ustawia na 1 pola, ktore            */
/*	poprawnie wystapily w linii wywolania programu,                 */
/*	pola opcji nie wystepujacych w wywolaniu ustawione sa na 0;     */
/*	zwraca wartosc W_OK, gdy wywolanie bylo poprawne                */
/*	lub kod bledu zdefiniowany stalymi B_* (<0)                     */
/*	kolejnosc podawania argumentow wywolania programu               */
/*	nie ma znaczenia (lecz kolejnosc wykonywania dzialan scisle	*/
/*	okreslona, brak opcji -o oznacza wyswietlenie obrazu     	*/
/*	na standardowym wyjsciu					        */
/* UWAGA:                                                               */
/*      funkcja nie sprawdza istnienia i praw dostepu do plikow         */
/*      w takich przypadkach zwracane uchwyty maja wartosc NULL         */
/************************************************************************/

int przetwarzaj_opcje(int argc, char **argv, w_opcje *wybor);

#endif
