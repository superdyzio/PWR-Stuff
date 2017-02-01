#include "StosStat.h"
;
void StosStat::wyswietl() {
	if (licznik == 0) {
		cout << "Stos pusty!" << endl;
		return;
	}
	for (int i = 0; i < licznik-1; i++)
		cout << tablica[i] << " -> ";
	cout << tablica[licznik-1] << endl;
}