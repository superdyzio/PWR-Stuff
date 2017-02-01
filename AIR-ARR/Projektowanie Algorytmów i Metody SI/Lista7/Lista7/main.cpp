#include "Funkcje.h"
#include "Gra.h"
;
int main() {
	char wybor = '0';
	pair<int,int> parametry = menu();
	Gra* gra = new Gra(parametry.first,parametry.second);
	do {
		gra->zeruj();
		char gracz = *GRACZ;		// zmienna przechowujaca obecnie grajacego gracza - pierwszy ruch nalezy do gracza
		int licznik = 0;			// licznik ruchow komputera
		while (!gra->wygrana(*GRACZ,false) && !gra->wygrana(*SI,false) && !gra->remis(false)) {
			gra->ruch(gracz,licznik);
			if (gracz == *SI)
				licznik++;
		}
		cout << endl << endl << "Jeszcze raz? (T - TAK)" << endl;
		cin >> wybor;
	} while (wybor == 'T' || wybor == 't');
	return 0;
}