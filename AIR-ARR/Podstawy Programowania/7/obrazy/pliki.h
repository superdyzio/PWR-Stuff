#ifndef PLIKI_H
#define PLIKI_H

#include "przetwarzanie.h"
#include "opcje.h"
#include <stdlib.h>
#include <string.h>
#define MAX 512
#define DL_LINII 80

/* PRE: Funkcja ta przyjmuje jako argumenty wczytany z argumentów wywołania i zainicjowany w funkcji przetwarzanie_opcji wskaźnik na plik oraz
	wskaźnik na strukturę obraz, do której zapisany zostanie wczytany z pliku obraz. W trakcie działania tworzona jest dynamiczna tablica
	mająca za zadanie przechowywać wartości poszczególnych pikseli.          */

int czytaj(FILE *p, t_obraz *obraz);

/* POST: Jesli w czasie dzialania funkcji wystapil jakis blad, zwrocone zostalo 0, a funkcja przerwana po jego napotkaniu. Jezeli nie bylo
	 bledu zwrocony zostanie iloczyn wymiarow obrazu, ktory w wyniku dzialania funkcji zostal zapisany w strukturze.   */


/* PRE: Funkcja ta sluzy do wyswietlania obrazu o zadanej nazwie za pomoca programu 'display'. Przyjmuje jeden argument typu string, bedacy
	nazwa pliku z obrazem do wyswietlenia.   */

void wyswietl(char *n_pliku);

/* POST: Funkcja nie zwraca zadnej wartosci. W wyniku jej dzialania w nowym oknie otworzy sie podglad obrazu.  */


/* PRE: Funkcja przyjmuje jako argumenty wskaznik do pliku oraz strukture z naszym obrazem, w którym uwzględnione są wszelkie dokonane zmiany.
   	Dodatkowo przekazujemy łańcuch zawierający nazwę pliku - jest to element rozwiązania mającego umożliwić nadpisywanie plików.Funkcja ma
	za zadanie zapisac do nowego pliku (lub nadpisac stary plik) obraz w formacie pgm. */

int zapisz(FILE *p, t_obraz obraz, char *nazwa);

/* POST: Funkcja zwraca 0 w przypadku wystapienia bledu. W przeciwnym razie zwraca wartosc iloczynu wymiarow obrazu, a wynikiem jej dzialania
	 jest zapisanie, do podanego uprzednio pliku, obrazu w ktorym widoczne sa efekty naszych poprzednich dzialan - np. progowanie. */


/* PRE: Funkcja przyjmuje jako argument wskaźnik na strukturę przechowującą nasz obraz i ma za zadanie wypełnić ją danymi podawanymi przez
	użytkownika w terminalu. */

void wczytaj(t_obraz *obraz);

/* POST: Funkcja nie zwraca żadnej wartości, a wyniku jej działania otrzymujemy strukturę zawierającą wszystkie dane konieczne do zapisania,
	 wyświetlania czy obrabiania obrazka. */


/* PRE: Funkcja przyjmuje jako argument strukturę przechowującą obraz i ma za zadanie wypisać go (w formie tekstowej) na terminal */

void wypisz(t_obraz obraz);

/* POST: Funkcja robi dokładnie to, co robić powinna. Nie zwraca żadnej wartości. */

#endif