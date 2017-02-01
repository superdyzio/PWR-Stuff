#include "StosDym.h"
;

void StosDym::push(int el) {
	rozmiar++;
	int *pom = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
		pom[i] = tablica[i];
	delete [] tablica;
	pom[rozmiar-1] = el;
	tablica = pom;
}

void StosDym::pop() {
	rozmiar--;
	int *pom = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
		pom[i] = tablica[i];
	delete [] tablica;
	tablica = pom;
}

void StosDym::wyswietl() {
	if (rozmiar == 0) {
		cout << "Stos pusty!" << endl;
		return;
	}
	for (int i = 0; i < rozmiar-1; i++)
		cout << tablica[i] << " -> ";
	cout << tablica[rozmiar-1] << endl;
}