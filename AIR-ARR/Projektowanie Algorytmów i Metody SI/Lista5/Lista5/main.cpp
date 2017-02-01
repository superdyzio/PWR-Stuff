#include "Graf.h"

#define NAZWA "plik.txt"	// stala przechowujaca nazwe wykorzystywanego pliku
#define TESTY 100			// stala okreslajaca liczbe przeprowadzanych testow
;
using namespace std;

int main() {
	srand(time(NULL));
	clock_t t1, t2;
	//GrafM* kra = new GrafM();
	GrafL* kra2 = new GrafL();
	//kra->zapis(NAZWA);
	//kra2->odczyt(NAZWA);
	//double suma = 0;
	double suma2 = 0;
	//double suma3 = 0;
	//double suma4 = 0;
	for (int i = 0; i < TESTY; i++) {
		//t1 = clock();
		//kra->kruskal();
		//t2 = clock();
		//suma += (double)(t2-t1) / CLOCKS_PER_SEC;
		t1 = clock();
		kra2->kruskal();
		t2 = clock();
		suma2 += (double)(t2-t1) / CLOCKS_PER_SEC;
		//cout << "K-M: Srednia po " << i+1 << " testach: " << suma / (i+1) << endl;
		cout << "K-L: Srednia po " << i+1 << " testach: " << suma2 / (i+1) << endl << endl;
		//kra->odczyt(NAZWA);
		//kra2->odczyt(NAZWA);
		//t1 = clock();
		//kra->prim();
		//t2 = clock();
		//suma3 += (double)(t2-t1) / CLOCKS_PER_SEC;
		//t1 = clock();
		//kra2->prim();
		//t2 = clock();
		//suma4 += (double)(t2-t1) / CLOCKS_PER_SEC;
		//cout << "P-M: Srednia po " << i+1 << " testach: " << suma3 / (i+1) << endl;
		//cout << "P-L: Sredni*/a po " << i+1 << " testach: " << suma4 / (i+1) << endl << endl;
		//delete(kra);
		delete(kra2);
		//kra = new GrafM();
		kra2 = new GrafL();
	}
	cin.get();
	return 0;
}