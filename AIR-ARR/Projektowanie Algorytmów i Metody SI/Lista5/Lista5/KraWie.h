#ifndef KRAWIE_H
#define KRAWIE_H

#include <cstdlib>
#include <vector>
#include <iostream>
;
using namespace std;

class Vertex;		// deklaracja klasy wierzcholka, by mozna bylo uzywac jej instancji przed jej definicja

/*	Klasa modelujaca krawedz grafu - zawiera pole przechowujace identyfikator krawedzi (numer), wskazniki na wierzcholki poczatkowy
	i koncowy oraz wage. Dodatkowo zawiera publiczne pole typu bool wykorzystywane przez algorytmy wyznaczania MDR. */
class Edge {
	int numer;
	Vertex* a;
	Vertex* b;
	int waga;
public:
	bool dodane;
// komplet potrzebnych konstruktorow oraz destruktor
	Edge() {}	
	Edge(int n, Vertex* p, Vertex* k, int w):numer(n),a(p),b(k),waga(w),dodane(false) {}
	~Edge() {}
// metoda zwracajaca identyfikator krawedzi
	int getNumer() { return numer; }
// metoda zwracajaca wage krawedzi
	int getWaga() { return waga; }
// metoda zwracajaca wskaznik na poczatkowy wierzcholek krawedzi
	Vertex* getA() { return a; }
// metoda zwracajaca wskaznik na koncowy wierzcholek krawedzi
	Vertex* getB() { return b; }
} typedef Edge;

/*	Klasa modelujaca wierzcholek grafu - zawiera pole przechowujace identyfikator (numer) wierzcholka.
	Dodatkowo zawiera publiczne pole typu bool oraz wektor wskaznikow na krawedzie wykorzystywane przez algorytmy wyznaczania MDR. */
class Vertex {
	int numer;
public:
	bool kolor;
	vector < Edge* > lista;
// komplet potrzebnych konstruktorow oraz destruktor
	Vertex() {}
	Vertex(int n):numer(n),kolor(false) {}
	~Vertex() {}
// metoda zwracajaca identyfikator wierzcholka
	int getNumer() { return numer; }
// metoda wypisujaca na standardowe wyjscie zawartosc listy krawedzi sasiadujacych w formie "numer krawedzi   waga krawedzi"
	void getLista() { for (int i = 0; i < lista.size(); i++) cout << lista[i]->getNumer() << " " << lista[i]->getWaga() << endl; }
} typedef Vertex;

/*	Klasa sluzaca do tworzenia priorytetowej kolejki krawedzi - struktury wykorzystywanej przez oba testowane algorytmy wyznaczania
	MDR. Jej jedynym zadaniem jest porownywanie elementow krawedzi, co umozliwia sortowanie ich wedlug wag. */
class CompareEdge {
public:
	bool operator () (Edge* e1, Edge* e2) { return e1->getWaga() > e2->getWaga(); }
} typedef CompareEdge;

#endif