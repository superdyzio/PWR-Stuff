#include "Lista.h"
;
using namespace std;
#define T int

void main() {
	T tT1 = 0;
	T* ptT1 = &tT1;
	T tT2 = 1;
	T* ptT2 = &tT2;
	T tT3 = 10;
	T* ptT3 = &tT3;
	T tT4 = 5;
	T* ptT4 = &tT4;
//	T tT5 = 99;
//	T* ptT5 = &tT5;
/*
	T tT1 = 15.04;
	T* ptT1 = &tT1;
	T tT2 = 10.67;
	T* ptT2 = &tT2;
	T tT3 = 70.9;
	T* ptT3 = &tT3;
	T tT4 = 22.13;
	T* ptT4 = &tT4;
	T tT5 = 21.5;
	T* ptT5 = &tT5;
*/
	CLista<T>* plLista = new CLista<T>();

	plLista->vDodaj(ptT1,0);
	*plLista += ptT2;
	plLista->vDodajNaKoniec(ptT1);
	*plLista += ptT3;
	*plLista += ptT4;
	*plLista += ptT3;
//	*plLista += ptT5;
//	*plLista += ptT5;
	*plLista += new int(99);
	*plLista += new int(991);
	*plLista += new int(99);
	*plLista += new int(993);
//	*plLista += ptT5;
	*plLista += new int(99);
	*plLista += new int(992);
//	*plLista += ptT5;
	*plLista += new int(99);
	*plLista += new int(991);
	

//	*plLista += ptT5;
	cout << UTWORZONA << endl;
	plLista->vDrukuj();

	plLista->vUsunDuplikaty();
	cout << BEZDUPLIKATOW << endl;
	plLista->vDrukuj();

	plLista->vPush(ptT2);
	cout << DODANEPUSH << endl;
	plLista->vDrukuj();

	plLista->vDodaj(ptT3,3);
	cout << DODANEWSRODEK << endl;
	plLista->vDrukuj();

	plLista->vDodajNaPoczatek(ptT4);
	plLista->bUsun(4);
	cout << DODANEPOCUSUNKON << endl;
	plLista->vDrukuj();

	cout << INDEKSUJACY << *((*plLista)[3]->ptGetDane()) << endl;

	CLista<T>* plLista2 = new CLista<T>();
	plLista2->vDodaj(ptT3,3);
	cout << UTWORZONA << endl;
	plLista2->vDrukuj();
	cout << POROWNANIE2 << (plLista == plLista2) << endl;

	CLista<T>* plLista3 = plLista->plClone();
	cout << KLON << endl;
	plLista3->vDrukuj();

	cout << POROWNANIE << (*plLista3==plLista) << endl;

	cout << POP << *(T*)(plLista->pwPop()->ptGetDane()) << endl;
	cout << LISTAPOP << endl;
	plLista->vDrukuj();
	
	T** tab = plLista->wDoTablicy();
	cout << TABLICA << endl;
	for (int i = 0; i < plLista->iDlugosc(); i++)
		cout << "[" << *(tab[i]) << "] ";
	cout << endl;
	
	cout << LISTA << endl;
	plLista->vDrukuj();
	cout << KLON << endl;
	plLista3->vDrukuj();

	cout << COMPARE << plLista->iCompare(plLista3) << endl;
	cout << COMPARE2  << plLista->iCompare(plLista) << endl;

/*	plLista3->vSort();
	plLista3->vDrukuj();
	//plLista3->vDrukuj();
	plLista3->bUsun(5);
	plLista3->vSort();
	plLista3->vDrukuj();

	plLista3->vParzWart();
	plLista3->vDrukuj();
*/
	system("pause");
}