#include "Tablica2W.h"
;

void Tablica2W::wypelnij(int x) {
	srand((int)time(NULL));
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			tablica[i][j] = rand() % x;
}

void Tablica2W::wyswietl() {
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++)
			cout << tablica[i][j] << " ";
		cout << endl;
	}
}

int Tablica2W::max() {
	int maks = 0;
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			if (tablica[i][j] > maks)
				maks = tablica[i][j];
	return maks;
}