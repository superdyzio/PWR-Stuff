#ifndef DEQUE_H
#define DEQUE_H

#include <cstdlib>
#include <iostream>

using namespace std;

/*	Klasa reprezentujaca element kolejki dwukierunkowej. Zawiera pole przechowujace dana typu int oraz dwa pola wskaznikowe na elementy tego samego
	typu - odpowiednio poprzedni i nastepny element kolejki (domyslnie ustawione na null).	*/
class Element3 {
	int dane;
	Element3 *przed;
	Element3 *nast;

public:
/*	Kompletny zestaw konstruktorow oraz destruktor. */
	Element3():dane(0),przed(NULL),nast(NULL) {}
	Element3(int d):dane(d),przed(NULL),nast(NULL) {}
	Element3(int d, Element3* p, Element3* n):dane(d),przed(p),nast(n) {}
	~Element3() {}

/*	Funkcje pozwalajace ustalic wartosci prywatnych pol klasy. */
	void setDane(int d) { dane = d; }
	void setPrzed(Element3* p) { przed = p; }
	void setNast(Element3* n) { nast = n; }
/*	Funkcje pozwalajace pobrac wartosci prywatnych pol klasy. */
	int getDane() { return dane; }
	Element3* getPrzed() { return przed; }
	Element3* getNast() { return nast; }
} typedef Element3;

/*	Klasa reprezentujaca kolejke dwukierunkowa. Zawiera dwa pola wskaznikowe na obiekty typu Element3 majace wskazywac na poczatek i koniec kolejki. */
class Deque {
	Element3 *poczatek;
	Element3 *koniec;
public:
/*	Konstruktor domyslny oraz destruktor. */
	Deque():poczatek(NULL),koniec(NULL) {}
	~Deque() {}

/*	Funkcja zwracajaca aktualny rozmiar kolejki (ilosc elementow). */
	int rozmiar() const;
/*	Funkcja zwracajaca informacje czy kolejka jest pusta. */
	bool pusta() const { return poczatek == NULL; }
/*	Funkcja majaca za zadanie wyswietlic na standardowe wyjscie zawartosc kolejki. */
	void wyswietl();
/*	Funkcja usuwajaca wszystkie elementy z kolejki. */
	void czysc();
/*	Funkcje pozwalajace pobrac wartosci pierwszego i ostatniego elementu kolejki. */
	int pierwszy();
	int ostatni();
/*	Funkcje pozwalajace na dodanie elementow na poczatek i koniec kolejki. */
	void wstawPierwszy(int obj);
	void wstawOstatni(int obj);
/*	Funkcje pozwalajace usuwac elementy z poczatku i konca kolejki. */
	void usunPierwszy();
	void usunOstatni();
} typedef Deque;

#endif