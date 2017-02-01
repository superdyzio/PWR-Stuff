#ifndef KOLEJKA_H
#define KOLEJKA_H

#include <cstdlib>
#include <iostream>

using namespace std;

/*	Klasa reprezentujaca element kolejki jednokierunkowej. Zawiera pole przechowujace wartosc typu int oraz pole wskaznikowe na element tego samego typu
	przechowujace wskaznika na poprzedni element. */
class Element2 {
	int dane;
	Element2 *przed;

public:
/*	Kompletny zestaw konstuktorow oraz destruktor. */
	Element2():dane(0),przed(NULL) {}
	Element2(int d):dane(d),przed(NULL) {}
	Element2(int d, Element2* p):dane(d),przed(p) {}
	~Element2() {}

/*	Funkcje pozwalajace ustalic wartosci prywatnych pol klasy. */
	void setDane(int d) { dane = d; }
	void setPrzed(Element2* p) { przed = p; }
/*	Funkcje pozwalajace pobrac wartosci prywatnych pol klasy. */
	int getDane() { return dane; }
	Element2* getPrzed() { return przed; }
} typedef Element2;

/*	Klasa reprezentujaca kolejke jednokierunkowa. Zawiera pole wskaznikowe typu Element2 majace wskazywac poczatek kolejki lub NULL w przypadku kolejki
	pustej. W uzyciu bedzie dzialala jako struktura typu FIFO. */
class Kolejka {
	Element2* poczatek;

public:
/*	Zestaw konstruktorow oraz destruktor. */
	Kolejka():poczatek(NULL) {}
	Kolejka(Element2* wsk):poczatek(wsk) {}
	~Kolejka() {}

/*	Funkcja zwracajaca rozmiar (ilosc elementow) kolejki. */
	int rozmiar() { int wynik = 0; Element2* pom = poczatek; if (pusta()) return 0; while (pom->getPrzed() != NULL) { pom = pom->getPrzed(); wynik++; } return wynik; }
/*	Funkcja zwracajaca informacje czy kolejka jest pusta. */
	bool pusta() { return poczatek == NULL; }
/*	Funkcja pozwalajaca dodac element na poczatek kolejki. */
	void dodaj(int liczba);
/*	Funkcja pozwalajaca dodac element na wybrane miejsce kolejki. */
	void dodaj(int liczba, int indeks);
/* Funkcja majaca za zadanie wyswietlic zawartosc kolejki na standardowe wyjscie. */
	void wyswietl();
/*	Funkcja pozwalajaca usunac element z poczatku kolejki (najdluzej w niej bedacy - FIFO). */
	void usun();
/*	Funkcja pozwalajaca usunac z kolejki element o dowolnym indeksie. */
	void usun(int indeks);
/*	Funkcja usuwajaca wszystkie elementy z kolejki. */
	void czysc();
} typedef Kolejka;

#endif