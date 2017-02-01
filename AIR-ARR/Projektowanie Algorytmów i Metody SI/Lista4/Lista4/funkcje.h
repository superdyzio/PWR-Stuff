#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <cstdlib>
#include <math.h>
#include <cmath>
#include <random>
#include <ctime>
#include <iostream>

using namespace std;

#define ROZMIAR 500000		// stala definiujaca rozmiar tablicy
#define ZAKRES 2000000		// stala definiujaca zakres do losowania liczb

/* Klasa sluzaca do przeprowadzania testow. Ma pole na tablice typu int, pole na tablice posortowana typu int oraz pole przechowujace ilosc liczb
   juz posortowanych - sluzy ono do generowania tablic czesciowo posortowanych. */
class Klasa {
	int tab[ROZMIAR];
	int sort[ROZMIAR];
	int ilosc;
public:
// konstruktor i destruktor
	Klasa(double i);
	~Klasa() {}
// funkcja wyswietlajaca tablice nieposortowana
	void wyswietlTab();
// funkcja wyswietlajaca tablice posortowana
	void wyswietlSort();
// funkcja sprawdzajaca poprawnosc sortowania
	bool dobrze();
// funkcja odwracajaca tablice
	void odwrocTab();
// funkcja generujaca nowa tablice o wlasciwosciach zadanych do konstruktora
	void nowaTab();

// funkcja scalajaca
	void merge(int a, int b, int c);
// rekurencyjna wersja sortowania przez scalanie
	void merge_sort(int low, int high);
// iteracyjna wersja sortowania przez scalanie
	void Merge_Sort_Iterative(int left, int right);

// sortowanie szybkie - wariant z pivotem na elemencie skrajnym (poczatkowym)
	void quicksort(int lewy, int prawy);
// sortowanie szybkie - wariant z pivotem na elemencie srodkowym
	void quicksort2(int lewy, int prawy);

// funkcja inicjujaca sortowanie introspektywne
	void sortIntro();
// funkcja sortowania podstawowego - sortowanie szybkie, z parametrem kontrolujacym glebokosc rekurencji
	void IntroQuick(int poc, int kon, int rec);
// funkcja sortowania pomocniczego - sortowanie przez kopcowanie
	void Heapify(int i, int dl);
} typedef Klasa;

#endif