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

/*	Klasa bazowa modelujaca graf. Zawiera chroniony wektory wskaznikow na krawedzie oraz wskaznikow na wierzcholki. */
class Graf {
protected:
	vector < Edge* > krawedzie;		// wektor wskaznikow na krawedzie
	vector < Vertex* > wierzcholki;	// wektor wskaznikow na wierzcholki
	int start;						// pole przechowujace numer startowego wierzcholka (do algorytmow wyznaczania najkrotszej sciezki)
public:
	int poprzednik[ROZMIAR];		// tablica przechowujaca bezposrednich poprzednikow kolejnych wierzcholkow
// konstruktor bezparametrowy
	Graf();
// destruktor
	~Graf() {}
// metoda zwracajaca krawedz o zadanym indeksie
	Edge* getKrawedz(int i) { return krawedzie[i]; }
// metoda zwracajaca wierzcholek o zadanym indeksie
	Vertex* getWierzcholek(int i) { return wierzcholki[i]; }
// metoda zwracajaca wierzcholek o zadanym numerze
	Vertex* getWierzcholekNr(int nr) { for (int i = 0; i < wierzcholki.size(); i++) if (wierzcholki[i]->getNumer() == nr) return wierzcholki[i]; return NULL; }
// metoda zwracajaca najblizszy, jeszcze nieodwiedzony, wierzcholek
	Vertex* getMinWierzcholek();
// metoda pozwalajaca wczytac graf o zadanym rozmiarze i gestosci z pliku
	bool odczyt();
// metoda pozwalajaca zapisac obecny graf do pliku
	bool zapis();
// metoda wypisujaca na standardowe wyjscie liste wierzcholkow (wszystkie pola, oddzielone spacjami)
	void getWierzcholki();
// metoda wypisujaca na standardowe wyjscie liste krawedzi (wszystkie pola, oddzielone spacjami)
	void getKrawedzie();
// metoda zwracajaca pare wierzcholkow - koncow zadanej jako argument krawedzi
	vector < Vertex* > endVertices(Edge* e) { vector < Vertex* > wynik; wynik.push_back(e->getA()); wynik.push_back(e->getB()); return wynik; }
// metoda zwracajaca wierzcholek przeciwlegly do zadanego wzgledem zadanej krawedzi
	Vertex* opposite(Vertex* v, Edge* e) { Vertex* wynik = NULL; if (e->getA() == v) wynik = e->getB(); if (e->getB() == v) wynik = e->getA(); return wynik; } 
// metoda sprawdzajaca czy dwa zadane wierzcholki ze soba sasiaduja
	virtual bool areAdjacent(Vertex* w, Vertex* v) { for (int i = 0; i < krawedzie.size(); i++) if ( (krawedzie[i]->getA() == w && krawedzie[i]->getB() == v) || (krawedzie[i]->getA() == v && krawedzie[i]->getB() == w) ) return true; return false; }
// metoda pozwalajaca zmienic przechowywane w zadanym wierzcholku dane na dane podane jako drugi argument
	void replace(Vertex* v, int x) { v->setDane(x); }
// metoda pozwalajaca zeminic wage zadanej krawedzi na podana jako drugi argument
	void replace(Edge* e, int w) { e->setWaga(w); }
// metoda wypisujaca na standardowe wyjscie liste krawedzi incydentnych do zadanego wierzcholka
	void incidentEdges(Vertex* v) { v->getLista(); }
// metoda pozwalajaca na dodanie wierzcholka do grafu
	void insertVertex(int d);
// metoda pozwalajaca na usuniecie wierzcholka z grafu
	void removeVertex(Vertex* v);
// metoda pozwalajaca na dodanie krawedzi do grafu
	void insertEdge(Vertex* v, Vertex* w, int waga);
// metoda pozwalajaca na usuniecie krawedzi z grafu
	void removeEdge(Edge* e);
// metoda wirtualna implementujaca algorytm Dijkstry (brak przeciazenia w klasie pochodnej powoduje wypisanie komunikatu)
	virtual void Dijkstra() { cout << "Algorytm Dijkstry niezaimplementowany." << endl; }
// metoda wirtualna implementujaca algorytm Bellmana-Forda (brak przeciazenia w klasie pochodnej powoduje wypisanie komunikatu)
	virtual void BellFord() { cout << "Aglorytm Bellmana-Forda niezaimplementowany." << endl; }
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
	bool odczyt();
// implementacja metody sprawdzajacej czy dwa zadane wierzcholki ze soba sasiaduja
	bool areAdjacent(Vertex* w, Vertex* v) { bool wynik = false; for (int i = w->getNumer(); i < ROZMIAR && !wynik; i++) if ( tablica[w->getNumer()][i] != NULL && (tablica[w->getNumer()][i]->getA() == v || tablica[w->getNumer()][i]->getB() == v) ) wynik = true; return wynik; }
// reimplementacja metody zwracajacej lista krawedzi incydentnych do zadanego wierzcholka - tak, aby dzialalo na macierzowej reprezentacji grafu
	void incidentEdges(Vertex* v) { for (int i = v->getNumer(); i < ROZMIAR; i++) if (tablica[v->getNumer()][i] != NULL) if (tablica[v->getNumer()][i]->getA() == v) cout << tablica[v->getNumer()][i]->getB()->getNumer() << " " << tablica[v->getNumer()][i]->getWaga() << endl; else cout << tablica[v->getNumer()][i]->getA()->getNumer() << " " << tablica[v->getNumer()][i]->getWaga() << endl; }
// reimplementacja metody pozwalajacej dodac wierzcholek do grafu
	void insertVertex(int d) { Graf::insertVertex(d); wypelnij(); }
// reimplementacja metody pozwalajacej usunac wierzcholek z grafu
	void removeVertex(Vertex* v) { Graf::removeVertex(v); wypelnij(); }
// reimplementacja metody pozwalajacej dodac krawedz do grafu
	void insertEdge(Vertex* v, Vertex* w, int waga) { Graf::insertEdge(v,w,waga); wypelnij(); }
// reimplementacja metody pozwalajacej usunac krawedz z grafu
	void removeEdge(Edge* e) { Graf::removeEdge(e); wypelnij(); }
// metoda implementujaca algorytm Dijkstry
	void Dijkstra();
// metoda implementujaca algorytm Bellmana-Forda
	void BellFord();
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
	bool odczyt();
// implementacja metody sprawdzajacej czy dwa zadane wierzcholki ze soba sasiaduja
	bool areAdjacent(Vertex* w, Vertex* v) { bool wynik = false; for (int i = 0; i < w->lista.size() && !wynik; i++) if (w->lista[i]->getA() == v || w->lista[i]->getB() == v) wynik = true; return wynik; }
// reimplementacja metody pozwalajacej na dodanie wierzcholka do grafu
	void insertVertex(int d) { Graf::insertVertex(d); wypelnij(); }
// reimplementacja metody pozwalajacej na usuniecie wierzcholka z grafu
	void removeVertex(Vertex* v) { Graf::removeVertex(v); wypelnij(); }
// reimplementacja metody pozwalajacej dodac krawedz do grafu
	void insertEdge(Vertex* v, Vertex* w, int waga) { Graf::insertEdge(v,w,waga); wypelnij(); }
// reimplementacja metody pozwalajacej usunac krawedz z grafu
	void removeEdge(Edge* e) { Graf::removeEdge(e); wypelnij(); }
// metoda implementujaca algorytm Dijkstry
	void Dijkstra();
// metoda implementuja algorytm Bellmana-Forda
	void BellFord();
} typedef GrafL;

#endif