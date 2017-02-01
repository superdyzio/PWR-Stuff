#ifndef STOS_H
#define STOS_H

#include <cstdlib>
#include <iostream>
;
using namespace std;
;
/*	Klasa reprezentujaca element stosu. Zawiera pole przechowujace dana typu int oraz pole wskaznikowe na obiekt tego samego typu
	przechowujace wskaznik na nastepny element stosu. */
class Element {
	int dane;
	Element *nast;

public:
/*	Kompletny zestaw konstruktorow oraz destruktor. */
	Element():dane(0),nast(NULL) {}
	Element(int d):dane(d),nast(NULL) {}
	Element(int d, Element* n):dane(d),nast(n) {}
	~Element() {}

/*	Funkcje pozwalajace ustawic wartosci prywatnych pol klasy. */
	void setDane(int d) { dane = d; }
	void setNast(Element* n) { nast = n; }
/*	Funkcje pozwalajace pobrac wartosci prywatnych pol klasy. */
	int getDane() { return dane; }
	Element* getNast() { return nast; }
} typedef Element;

/*	Klasa reprezentujaca stos. Zawiera pole wskaznikowe typu Element wskazujace na poczatek stosu lub na NULL w przypadku stosu
	pustego. Jest to struktura typu LIFO. */
class Stos {
	Element* poczatek;

public:
/*	Kompletny zestaw konstruktorow i destruktor. */
	Stos():poczatek(NULL) {}
	Stos(Element* wsk):poczatek(wsk) {}
	~Stos() {}

/*	Funkcja zwracajaca rozmiar (ilosc elementow) stosu. */
	int rozmiar() { int wynik = 0; Element* pom = poczatek; if (pusta()) return 0; while (pom->getNast() != NULL) { pom = pom->getNast(); wynik++; } return wynik; }
/*	Funkcja zwracajaca informacje czy stos jest pusty. */
	bool pusta() { return poczatek == NULL; }
/*	Funkcja pozwalajaca dodac element na koniec stosu. */
	void dodaj(int liczba);
/*	Funkcja pozwalajaca dodac element w dowolne miejsce stosu. */
	void dodaj(int liczba, int indeks);
/*	Funkcja majaca za zadanie wyswietlenie kolejki na standardowe wyjscie. */
	void wyswietl();
/*	Funkcja pozwalajaca usunac ostatnio dodany do stosu element (struktura LIFO). */
	void usun();
/*	Funkcja pozwalajaca usunac element o wskazanym indeksie. */
	void usun(int indeks);
/*	Funkcja usuwajaca wszystkie elementy ze stosu. */
	void czysc();
// funkcja zwracajaca wierzcholek
	int top() { Element *pom = poczatek; while (pom != NULL && pom->getNast() != NULL) pom = pom->getNast(); return pom->getDane(); }
} typedef Stos;

#endif