#ifndef STOSDYM_H
#define STOSDYM_H

#include <cstdlib>
#include <iostream>
;
using namespace std;

// klasa implementujaca stos oparty na tablicy dynamicznej, zawiera wskaznik na tablice oraz zmienna pilnujaca obecnego rozmiaru stosu
class StosDym {
	int *tablica;
	int rozmiar;
public:
// zestaw konstuktorow i destruktorow
	StosDym():rozmiar(0) { tablica = new int[rozmiar]; }
	~StosDym() {}

// wszystkie potrzebne do obslugi stosu metody - dodawanie, usuwanie, podgladanie wierzcholka, czyszczenie oraz wyswietlanie stosu
	void push(int el);
	void pop();
	int top() { return tablica[rozmiar-1]; };
	void czysc() { delete tablica; rozmiar = 0; };
	void wyswietl();
}
;
#endif