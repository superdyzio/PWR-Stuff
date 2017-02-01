#ifndef KRAWIE_H
#define KRAWIE_H

#include <cstdlib>
#include <vector>
#include <iostream>
;
using namespace std;

class Vertex;		// zapowiedz klasy (potrzebna dla kompilatora - klasy wzajemnie sie wykorzystuja)

/*	Klasa modelujaca krawedz grafu - zawiera pola przechowujace identyfikator krawedzi (numer), wskazniki na wierzcholki poczatkowy
	i koncowy oraz wage. Dodatkowo zawiera publiczne pole typu bool wykorzystywane przez algorytmy wyznaczania najkrotszej sciezki. */
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
// metoda pozwalajaca ustawic nowa wartosc wagi krawedzi
	void setWaga(int w) { waga = w; }
// metoda zwracajaca wskaznik na poczatkowy wierzcholek krawedzi
	Vertex* getA() { return a; }
// metoda zwracajaca wskaznik na koncowy wierzcholek krawedzi
	Vertex* getB() { return b; }
} typedef Edge;

/*	Klasa modelujaca wierzcholek grafu - zawiera pola przechowujace identyfikator (numer) wierzcholka oraz dane. Dodatkowo zawiera publiczne pole typu 
	typu int oraz wektor wskaznikow na wierzcholki wykorzystywane przez algorytmy wyznaczania najkrótszej œcie¿ki i liste krawedzi incydentnych. */
class Vertex {
	int numer;
	int dane;
public:
	bool odwiedzony;		// zmienna typu bool mowiaca o tym czy wzgledem tego wierzcholka dokonana juz byla relaksacja
	int droga;
	vector < Vertex* > sciezka;
	vector < Edge* > lista;
// komplet potrzebnych konstruktorow oraz destruktor
	Vertex() {}
	Vertex(int n, int d):dane(d),numer(n),droga(10000000+n),odwiedzony(false) {}
	~Vertex() {}
// metoda zwracajaca identyfikator wierzcholka
	int getNumer() { return numer; }
// metoda zwracajaca dane przechowywane w wierzcholku
	int getDane() { return dane; }
// metoda pozwalajaca zmienic przechowywane w wierzcholku dane
	void setDane(int d) { dane = d; }
// metoda wypisujaca na standardowe wyjscie zawartosc listy krawedzi sasiadujacych w formie "numer krawedzi   waga krawedzi"
	void getLista() { for (int i = 0; i < lista.size(); i++) if (lista[i]->getA() == this) cout << lista[i]->getB()->getNumer() << " " << lista[i]->getWaga() << endl; else cout << lista[i]->getB()->getNumer() << " " << lista[i]->getWaga() << endl; }
// metoda wypisujaca w kolejnych liniach kolejne wierzcholki nalezace do najkrotszej sciezki do danego wierzcholka od wierzcholka startowego
	void getSciezka() { for (int i = 0; i < sciezka.size(); i++) cout << sciezka[i]->getNumer() << endl; }
} typedef Vertex;

#endif