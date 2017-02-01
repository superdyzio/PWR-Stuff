#ifndef GRAF_H
#define GRAF_H

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <cmath>
#include <fstream>
#include <queue>
#include <stack>
#include "KraWie.h"

#define ROZMIAR 100			// stala definiujaca rozmiar grafu (ilosc wierzcholkow)
#define GESTOSC 100			// stala definiujaca gestosc grafu (w procentach)
;
using namespace std;

/*	Klasa bazowa modelujaca graf. Zawiera chronione wektory wskaznikow na krawedzie (jeden z nich przechowuje MDR) oraz publiczny
	wektor wskaznikow na wierzcholki. */
class Graf {
protected:
	vector < Edge* > krawedzie;		// wektor wskaznikow na krawedzie
	vector < Edge* > drzewo;		// wektor wskaznikow na krawedzie MDR
public:
	vector < Vertex* > wierzcholki;	// wektor wskaznikow na wierzcholki
// konstruktor bezparametrowy
	Graf();
// destruktor
	~Graf() {}
// metoda pozwalajaca wczytac graf o zadanym rozmiarze i gestosci z pliku
	bool odczyt(string nazwa);
// metoda pozwalajaca zapisac obecny graf do pliku
	bool zapis(string nazwa);
// metoda wypisujaca na standardowe wyjscie liste wierzcholkow (wszystkie pola, oddzielone spacjami)
	void getWierzcholki();
// metoda wypisujaca na standardowe wyjscie liste krawedzi (wszystkie pola, oddzielone spacjami)
	void getKrawedzie();
// wirtualna metoda wyznaczania MDR algorytmem Kruskala
	virtual int kruskal() { cout << "Algorytm niezaimplementowany." << endl; return -1; }
// wirtualna metoda wyznaczania MDR algorytmem Prima
	virtual int prim() { cout << "Algorytm niezaimplementowany." << endl; return -1; }
// metoda sprawdzajaca czy wyznaczone juz zostalo MDR
	bool mdr();
} typedef Graf;

/*	Klasa modelujaca graf w reprezentacji macierzowej. Dziedziczy i obudowuje ona klase Graf. Zawiera dodatkowo publiczna tablice
	ROZMIAR x ROZMIAR przechowujaca wskazniki do krawedzi pod odpowiednimi wspolrzednymi jesli wierzcholki sasiaduja albo NULL 
	w przypadku przeciwnym. */
class GrafM : public Graf {
public:
	Edge* tablica[ROZMIAR][ROZMIAR];
// konstruktor
	GrafM();
// destruktor
	~GrafM() {}
// metoda wypisujaca na standardowe wyjscie macierz incydencji
	void getMacierz();
// metoda wypelniajaca macierz incydencji na podstawie istniejacego grafu (korzysta z list wierzcholkow i krawedzi)
	void wypelnij();
// przeciazenie metody wczytujacej graf z pliku - rozszerze jej dzialanie o wywolanie metody wypelnij()
	bool odczyt(string nazwa);
// przeciazenie metody wyznaczajacej MDR za pomoca algorytmu Kruskala
	int kruskal();
// przeciazenie metody wyznaczajacej MDR za pomoca algorytmu Prima
	int prim();
} typedef GrafM;

/*	Klasa modelujaca graf w reprezentacji listowej. Dziedziczy i obudowuje ona klase Graf. Nie zawiera dodatkowych pol, natomiast 
	w tej reprezentacji wykorzystywane sa listy sasiedztwa w kazdym z wierzcholkow. */
class GrafL : public Graf {
public:
// konstruktor
	GrafL();
// destruktor
	~GrafL() {}
// metoda wypelniajaca listy sasiedztwa w wierzcholkach na podstawie istniejacego grafu (korzysta z list wierzcholkow i krawedzi)
	void wypelnij();
// przeciazenie metody wczytujacej graf z pliku - rozszerza jej dzialanie o wywolanie metody wypelnij()
	bool odczyt(string nazwa);
// przeciazenie metody wyznaczajacej MDR za pomoca algorytmu Kruskala
	int kruskal();
// przeciazenie metody wyznaczajacej MDR za pomoca algorytmu Prima
	int prim();
} typedef GrafL;

/*	Klasa modelujaca kolejke priorytetowa (dziedziczy po jej konkretnym wariancie) tak, aby mozliwe bylo ustalenie pojemnosci
	kontenera znajdujacego sie pod kolejka - wyklucza to koniecznosc realokacji pamieci wektora, co w przypadku duzych grafow mocno
	zwiekszalo czas dzialania algorytmow. */
class Kolejka : public priority_queue<Edge*,vector<Edge*>,CompareEdge> {
public:
// konstruktor od razu ustawiajacy pojemnosc kontenera na niemozliwa do zapelnienia przez dowolny zadany graf
	Kolejka() { this->c.reserve((ROZMIAR*(ROZMIAR-1)*GESTOSC/200) + 1); }
// przeciazenie metody zwracajacej pojemnosc kontenera
	int capacity() { return this->c.capacity(); }
// przeciazenie metody czyszczacej kontener (nie zmniejsza pojemnosci, tylko obecny rozmiar - do zera)
	void clear() { this->c.clear(); }
}

#endif