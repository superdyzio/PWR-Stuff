#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Lista.h"
#include "Kolejka.h"
#include "Deque.h"

// do zad. 1.: maksymalny rozmiar tablicy = n!, gdzie n to maksymalna dlugosc slowa (przypadek, gdzie kazda permutacja jest palindromem)
#define ROZMIAR_TAB 120		

using namespace std;

/*	Funkcja wyswietlajaca na standardowym wyjsciu menu. */
void menu();

/*	Funkcja sprawdzajaca czy podany jako argument lancuch tekstu jest palindromem. */
bool jestPal(string testStr);
/*	Funkcja generujaca wszystkie permutacje lancucha tekstowego podanego jako argument (tekst), zapisujaca do tablicy (palindromy[]) permutacje bedace
	palindromami oraz zliczajaca je w argumencie liczba. Argument prefix jest argumentem pomocniczym do rekurencyjnego generowania permutacji. */
int permutacje(string prefix, string tekst, string palindromy[], int liczba);
/*	Funkcja sprawdzajaca czy w podanej jako argument tablicy lancuchow znakowych wystepuja duplikaty. */
bool jestDup(string palindromy[]);
/*	Funkcja usuwajaca duplikaty z podanej jako argument tablicy lancuchow znakowych. */
void usunDup(string palindromy[]);
/*	Funkcja obslugujaca zadanie 1. */
void zadanie1(string palindromy[],int liczba);
/*	Funkcja obslugujaca zadanie 2. */
void zadanie2();
/*	Funkcja obslugujaca zadanie 3. */
void zadanie3();
/* Funkcja obslugujaca zadanie 5. */
void zadanie5();

#endif