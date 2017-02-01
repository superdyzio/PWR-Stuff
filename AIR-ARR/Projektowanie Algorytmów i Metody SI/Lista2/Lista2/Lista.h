#ifndef LISTA_H
#define LISTA_H

#include <cstdlib>
#include <iostream>

using namespace std;

/*	Klasa reprezentujaca element listy jednokierunkowej. Zawiera pole przechowujace dana typu int oraz pole wskaznikowe na obiekt tego samego typu
	przechowujace wskaznik na nastepny element listy. */
class Element1 {
	int dane;
	Element1 *nast;

public:
/*	Kompletny zestaw konstruktorow oraz destruktor. */
	Element1():dane(0),nast(NULL) {}
	Element1(int d):dane(d),nast(NULL) {}
	Element1(int d, Element1* n):dane(d),nast(n) {}
	~Element1() {}

/*	Funkcje pozwalajace ustawic wartosci prywatnych pol klasy. */
	void setDane(int d) { dane = d; }
	void setNast(Element1* n) { nast = n; }
/*	Funkcje pozwalajace pobrac wartosci prywatnych pol klasy. */
	int getDane() { return dane; }
	Element1* getNast() { return nast; }
} typedef Element1;

/*	Klasa reprezentujaca liste jednokierunkowa. Zawiera pole wskaznikowe typu Element1 wskazujace na poczatek listy lub na NULL w przypadku listy
	pustej. Bedzie dzialala jako struktura typu LIFO. */
class Lista {
	Element1* poczatek;

public:
/*	Kompletny zestaw konstruktorow i destruktor. */
	Lista():poczatek(NULL) {}
	Lista(Element1* wsk):poczatek(wsk) {}
	~Lista() {}

/*	Funkcja zwracajaca rozmiar (ilosc elementow) listy. */
	int rozmiar() { int wynik = 0; Element1* pom = poczatek; if (pusta()) return 0; while (pom->getNast() != NULL) { pom = pom->getNast(); wynik++; } return wynik; }
/*	Funkcja zwracajaca informacje czy lista jest pusta. */
	bool pusta() { return poczatek == NULL; }
/*	Funkcja pozwalajaca dodac element na koniec listy. */
	void dodaj(int liczba);
/*	Funkcja pozwalajaca dodac element w dowolne miejsce listy. */
	void dodaj(int liczba, int indeks);
/*	Funkcja majaca za zadanie wyswietlenie kolejki na standardowe wyjscie. */
	void wyswietl();
/*	Funkcja pozwalajaca usunac ostatnio dodany do listy element (struktura LIFO). */
	void usun();
/*	Funkcja pozwalajaca usunac element o wskazanym indeksie. */
	void usun(int indeks);
/*	Funkcja usuwajaca wszystkie elementy z listy. */
	void czysc();
} typedef Lista;

#endif