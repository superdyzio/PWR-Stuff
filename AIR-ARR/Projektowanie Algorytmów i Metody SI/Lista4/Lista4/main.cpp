#include "funkcje.h"

#define TESTY 100		// stala definiujaca ilosc testow

int main() {
	Klasa *hehe = new Klasa(0);
	clock_t t1, t2;
/*
	hehe->wyswietlTab();
	hehe->wyswietlSort();
	hehe->quicksort(0,ROZMIAR-1);
	if (hehe->dobrze()) cout << "ok" << endl;
	hehe->wyswietlSort();
*/
	double suma = 0;
	for (int i = 0; i < TESTY; i++) {
		t1 = clock();
		hehe->quicksort(0,ROZMIAR-1);
		t2 = clock();
		hehe->nowaTab();
		suma += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	}
	cout << "Sredni czas dla 0%: " << suma/TESTY << " [ms]" << endl;
	delete(hehe);

	hehe = new Klasa(25);
	suma = 0;
	for (int i = 0; i < TESTY; i++) {
		t1 = clock();
		hehe->quicksort(0,ROZMIAR-1);
		t2 = clock();
		hehe->nowaTab();
		suma += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	}
	cout << "Sredni czas dla 25%: " << suma/TESTY << " [ms]" << endl;
	delete(hehe);

	hehe = new Klasa(50);
	suma = 0;
	for (int i = 0; i < TESTY; i++) {
		t1 = clock();
		hehe->quicksort(0,ROZMIAR-1);;
		t2 = clock();
		hehe->nowaTab();
		suma += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	}
	cout << "Sredni czas dla 50%: " << suma/TESTY << " [ms]" << endl;
	delete(hehe);

	hehe = new Klasa(75);
	suma = 0;
	for (int i = 0; i < TESTY; i++) {
		t1 = clock();
		hehe->quicksort(0,ROZMIAR-1);
		t2 = clock();
		hehe->nowaTab();
		suma += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	}
	cout << "Sredni czas dla 75%: " << suma/TESTY << " [ms]" << endl;
	delete(hehe);

	hehe = new Klasa(95);
	suma = 0;
	for (int i = 0; i < TESTY; i++) {
		t1 = clock();
		hehe->quicksort(0,ROZMIAR-1);
		t2 = clock();
		hehe->nowaTab();
		suma += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	}
	cout << "Sredni czas dla 95%: " << suma/TESTY << " [ms]" << endl;
	delete(hehe);

	hehe = new Klasa(99);
	suma = 0;
	for (int i = 0; i < TESTY; i++) {
		t1 = clock();
		hehe->quicksort(0,ROZMIAR-1);
		t2 = clock();
		hehe->nowaTab();
		suma += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	}
	cout << "Sredni czas dla 99%: " << suma/TESTY << " [ms]" << endl;
	delete(hehe);

	hehe = new Klasa(99.7);
	suma = 0;
	for (int i = 0; i < TESTY; i++) {
		t1 = clock();
		hehe->quicksort(0,ROZMIAR-1);
		t2 = clock();
		hehe->nowaTab();
		suma += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	}
	cout << "Sredni czas dla 99.7%: " << suma/TESTY << " [ms]" << endl;
	delete(hehe);

	hehe = new Klasa(100);
	hehe->odwrocTab();
	suma = 0;
	for (int i = 0; i < TESTY; i++) {
		t1 = clock();
		hehe->quicksort(0,ROZMIAR-1);
		t2 = clock();
		hehe->nowaTab();
		hehe->odwrocTab();
		suma += (double)(t2-t1) * 1000 / CLOCKS_PER_SEC;
	}
	cout << "Sredni czas dla -100%: " << suma/TESTY << " [ms]" << endl;
	delete(hehe);

	cin.get();
	return 0;
}