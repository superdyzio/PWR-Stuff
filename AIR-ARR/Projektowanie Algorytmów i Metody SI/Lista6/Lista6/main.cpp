#include "Graf.h"

#define TESTY 100			// stala okreslajaca liczbe przeprowadzanych testow
;
using namespace std;

int main() {
	srand(time(NULL));
	clock_t t1, t2;
	GrafM* graf = new GrafM();
	GrafL* graf2 = new GrafL();
	double sdm, sdl, sbm, sbl;
	sdm = sdl = sbm = sbl = 0;
	for (int i = 0; i < TESTY; i++) {
	// dijkstra macierze
		t1 = clock();
		graf->Dijkstra();
		t2 = clock();
		sdm += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	// dijkstra listy
		t1 = clock();
		graf2->Dijkstra();
		t2 = clock();
		sdl += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	// zapisywanie grafow po wyliczeniach
		graf->zapis();
		graf2->zapis();
	// wczytywanie tych samych grafow (od poczatku, by byly przygotowane na dzialania algorytmow)
		graf->odczyt();
		graf2->odczyt();
	// bellman-ford macierze
		t1 = clock();
		graf->BellFord();
		t2 = clock();
		sbm += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	// bellman-ford listy
		t1 = clock();
		graf2->BellFord();
		t2 = clock();
		sbl += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
		delete(graf);
		delete(graf2);
		graf = new GrafM();
		graf2 = new GrafL();
	}
	cout << "Sredni czas dzialania algorytmu Dijkstry (macierze): " << sdm / TESTY << " [ms]." << endl;
	cout << "Sredni czas dzialania algorytmu Dijkstry (listy): " << sdl / TESTY << " [ms]." << endl;
	cout << "Sredni czas dzialania algorytmu Bellmana-Forda (macierze): " << sbm / TESTY << " [ms]." << endl;
	cout << "Sredni czas dzialania algorytmu Bellmana-Forda (listy): " << sbl / TESTY << " [ms]." << endl;
	cin.get();
	return 0;
}