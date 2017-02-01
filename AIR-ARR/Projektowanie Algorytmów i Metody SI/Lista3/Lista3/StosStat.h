#ifndef STOSSTAT_H
#define STOSSTAT_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stack>

// maksymalny rozmiar danych wejsciowych - tablica nie musi byc nigdy wieksza
#define MAX_ROZMIAR 500000

using namespace std;

// klasa implementujaca stos na tablicy statycznej, zawiera zmienna licznik sluzaca do pilnowania obecnego rozmiaru stosu
class StosStat {
	int licznik;
	int *tablica;
public:
// zestaw konstuktorow i destruktorow
	StosStat():licznik(0) { tablica = new int[MAX_ROZMIAR]; };
	~StosStat() { delete tablica; };

// wszystkie potrzebne do obslugi stosu metody - dodawanie, usuwanie, podgladanie wierzcholka, czyszczenie i wyswietlanie stosu
	void push(int el) { tablica[licznik] = el; licznik++; };
	void pop() { licznik--; };
	int top() { return tablica[licznik-1]; };
	void czysc() { licznik = 0; };
	void wyswietl();
}

#endif