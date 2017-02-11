#ifndef LISTA_H
#define LISTA_H

#define POZALISTA "Indeks poza zakresem listy"
#define PUSTALISTA "Lista jest pusta"

#define UTWORZONA "Utworzona lista:"
#define DODANEPUSH "Element dodany metoda PUSH:"
#define DODANEWSRODEK "Element dodany w srodek listy:"
#define DODANEPOCUSUNKON "Element dodany na poczatek listy i usuniety ze srodka:"
#define INDEKSUJACY "Uzycie operatora indeksujacego: "
#define KLON "Sklonowana lista:"
#define POROWNANIE "Wynik porownania listy z klonem: "
#define POROWNANIE2 "Wynik porownania listy z nowo utworzona: "
#define POP "Element sciagniety metoda POP: "
#define LISTAPOP "Lista po uzyciu POP:"
#define TABLICA "Wydrukowana tablica utworzona na podstawie listy:"
#define LISTA "Lista na ktorej wykonywane byly dzialania:"
#define COMPARE "Liczba takich samych elementow w liscie i klonie: "
#define COMPARE2 "Liczba takich samych elementow w liscie i liscie: "
#define SORTOWANIE "Posortowana lista:"
#define BEZDUPLIKATOW "Lista po usunieciu duplikatow:"

#include <cstdlib>
#include <iostream>
#include "Wezel.h"
;
using namespace std;

template <typename T>
class CLista {
	CWezel<T>* pw_poczatek;
	CWezel<T>* pw_koniec;
	int i_liczbaWezlow;
public:
	CLista<T>() { pw_poczatek = pw_koniec = NULL; i_liczbaWezlow = 0; }
	CLista<T>(CLista<T>* plLista) { pw_poczatek = plLista->pwGetPoczatek(); pw_koniec = plLista->pwGetKoniec(); i_liczbaWezlow = plLista->iDlugosc(); }
	~CLista<T>() {}

	CWezel<T>* operator [](int iIndeks) { return pwSkocz(iIndeks); }
	void operator += (T* pwObiekt);
	bool operator == (CLista<T>* plLista);

	int iDlugosc() { return i_liczbaWezlow; }
	void vDrukuj();
	CWezel<T>* pwGetPoczatek() { return pw_poczatek; }
	CWezel<T>* pwGetKoniec() { return pw_koniec; }
	CWezel<T>* pwSkocz(int iIndeks);
	bool bCzyPusta() { return i_liczbaWezlow == 0; }
	T** wDoTablicy();
	void vDodaj(T* ptDane, int iIndeks);
	void vDodajNaPoczatek(T* ptDane);
	void vDodajNaKoniec(T* ptDane);
	bool bUsun(int iIndeks);
	bool bUsunZPoczatku();
	bool bUsunZKonca();
	void vPush(T* ptDane) { vDodajNaKoniec(ptDane); }
	CWezel<T>* pwPop();
	CLista<T>* plClone();
	int iCompare(CLista<T>* plLista);
	void vSort();
	void vParzWart();
	void vUsunDuplikaty();
};

template <typename T>
CWezel<T>* CLista<T>::pwSkocz(int iIndeks) {
	if (bCzyPusta()) {
		cout << PUSTALISTA << endl;
		return NULL;
	}
	if (iIndeks >= i_liczbaWezlow || iIndeks < 0) {
		cout << POZALISTA << endl;
		return NULL;
	}
	CWezel<T>* pwPom = pw_poczatek;
	for (int i = 0; i < iIndeks; i++)
		pwPom = pwPom->pwGetNastepny();
	return pwPom;
}

template <typename T>
void CLista<T>::operator += (T* ptDane) { 
	if (bCzyPusta()) {
		CWezel<T>* pwNowy = new CWezel<T>(ptDane);
		pw_poczatek = pw_koniec = pwNowy;
	}
	else {
			CWezel<T>* pwPom = pwSkocz(i_liczbaWezlow-1);
			CWezel<T>* pwNowy = new CWezel<T>(ptDane);
			pwPom->vSetNastepny(pwNowy);
			pwNowy->vSetPoprzedni(pwPom);
			pw_koniec = pwNowy;
	}
	i_liczbaWezlow++;
}

template <typename T>
bool CLista<T>::operator == (CLista<T>* plLista) {
	bool bWynik = false;
	if (i_liczbaWezlow == plLista->iDlugosc()) {
		bWynik = true;
		for (int i = 0; i < i_liczbaWezlow && bWynik; i++)
			if (pwSkocz(i)->ptGetDane() != plLista->pwSkocz(i)->ptGetDane())
				bWynik = false;
	}
	return bWynik;
}

template <typename T>
T** CLista<T>::wDoTablicy() {
	T** pptTab = new T*[i_liczbaWezlow];
	for (int i = 0; i < i_liczbaWezlow; i++) {
		pptTab[i] = pwSkocz(i)->ptGetDane();
	}
	return pptTab;
}

template <typename T>
void CLista<T>::vDodaj(T* ptDane, int iIndeks) {
	if (iIndeks <= 0 || bCzyPusta()) vDodajNaPoczatek(ptDane);
	else
		if (iIndeks >= i_liczbaWezlow) vDodajNaKoniec(ptDane);
		else {
			CWezel<T>* pwPom = pwSkocz(iIndeks);
			CWezel<T>* pwNowy = new CWezel<T>(ptDane);
			pwNowy->vSetNastepny(pwPom->pwGetNastepny());
			pwPom->vSetNastepny(pwNowy);
			pwNowy->vSetPoprzedni(pwPom);
			i_liczbaWezlow++;
		}
}

template <typename T>
void CLista<T>::vDodajNaPoczatek(T* ptDane) {
	CWezel<T>* pwNowy = new CWezel<T>(ptDane);
	CWezel<T>* pwPom = pw_poczatek;
	if (!bCzyPusta()) {
		pwPom->vSetPoprzedni(pwNowy);
		pwNowy->vSetNastepny(pwPom);
	}
	if (bCzyPusta()) pw_koniec = pwNowy;
	pw_poczatek = pwNowy;
	i_liczbaWezlow++;
}

template <typename T>
void CLista<T>::vDodajNaKoniec(T* ptDane) {
	CWezel<T>* pwNowy = new CWezel<T>(ptDane);
	CWezel<T>* pwPom = pw_koniec;
	if (!bCzyPusta()) {
		pwNowy->vSetPoprzedni(pwPom);
		pwPom->vSetNastepny(pwNowy);
	}
	if (bCzyPusta()) pw_poczatek = pwNowy;
	pw_koniec = pwNowy;
	i_liczbaWezlow++;
}

template <typename T>
bool CLista<T>::bUsun(int iIndeks) {
	if (bCzyPusta()) {
		cout << PUSTALISTA << endl;
		return false;
	}
	if (iIndeks < 0 || iIndeks > i_liczbaWezlow) { 
		cout << POZALISTA << endl;
		return false;
	}
	if (iIndeks == 0) return bUsunZPoczatku();
	if (iIndeks == i_liczbaWezlow-1) return bUsunZKonca();
	CWezel<T>* pwPom = pwSkocz(iIndeks);
	pwPom->pwGetPoprzedni()->vSetNastepny(pwPom->pwGetNastepny());
	pwPom->pwGetNastepny()->vSetPoprzedni(pwPom->pwGetPoprzedni());
	delete(pwPom);
	i_liczbaWezlow--;
	return true;
}

template <typename T>
bool CLista<T>::bUsunZPoczatku() {
	if (bCzyPusta()) {
		cout << PUSTALISTA << endl;
		return false;
	}
	CWezel<T>* pwPom = pw_poczatek;
	pwPom->pwGetNastepny()->vSetPoprzedni(NULL);
	pw_poczatek = pwPom->pwGetNastepny();
	delete(pwPom);
	i_liczbaWezlow--;
	return true;
}

template <typename T>
bool CLista<T>::bUsunZKonca() {
	if (bCzyPusta()) {
		cout << PUSTALISTA << endl;
		return false;
	}
	CWezel<T>* pwPom = pw_koniec;
	pwPom->pwGetPoprzedni()->vSetNastepny(NULL);
	pw_koniec = pwPom->pwGetPoprzedni();
	delete(pwPom);
	i_liczbaWezlow--;
	return true;
}

template <typename T>
int CLista<T>::iCompare(CLista<T>* plLista) {
	int iWynik = 0;
	for (int i = 0; i < i_liczbaWezlow; i++) {
		for (int j = 0; j < plLista->iDlugosc(); j++)
			if (pwSkocz(i)->ptGetDane() == plLista->pwSkocz(j)->ptGetDane())
				iWynik++;
	}
	return iWynik;
}

template <typename T>
CWezel<T>* CLista<T>::pwPop() {
	if (!bCzyPusta()) {
		i_liczbaWezlow--;
		CWezel<T>* pwPom = pw_koniec;
		pwPom->pwGetPoprzedni()->vSetNastepny(NULL);
		pw_koniec = pwPom->pwGetPoprzedni();
		return pwPom;
	}
	else {
		cout << PUSTALISTA << endl;
		return NULL;
	}
}

template <typename T>
void CLista<T>::vDrukuj() {
	cout << "NULL -> ";
	for (int i = 0; i < i_liczbaWezlow; i++)
		cout << *(pwSkocz(i)->ptGetDane()) << " -> ";
	cout << "NULL" << endl;
}

template <typename T>
CLista<T>* CLista<T>::plClone() {
	CLista<T>* plWynik = new CLista<T>();
	for (int i = 0; i< i_liczbaWezlow; i++)
		plWynik->vDodajNaKoniec(pwSkocz(i)->ptGetDane());
	return plWynik;
}

template <typename T>
void CLista<T>::vSort() {
	T** tab = wDoTablicy();
	T* ptPom;
	for (int i = 0; i < i_liczbaWezlow-1; i++)
		for (int j = i+1; j < i_liczbaWezlow; j++)
			if (*tab[i] > *tab[j]) {
				ptPom = tab[i];
				tab[i] = tab[j];
				tab[j] = ptPom;
			}
	for (int i = 0; i < i_liczbaWezlow; i++)
		pwSkocz(i)->vSetDane(tab[i]);
}

template <typename T>
void CLista<T>::vParzWart() {
	T** tab = wDoTablicy();
	T* ptPom;
	for (int i = 0; i < i_liczbaWezlow-1; i++)
		for (int j = i+1; j < i_liczbaWezlow; j++)
			if (*tab[i] > *tab[j]) {
				ptPom = tab[i];
				tab[i] = tab[j];
				tab[j] = ptPom;
			}
	int iInd = 0;
	for (int i = 0; i < i_liczbaWezlow; i++)
		if ((*tab[i]) % 2 == 0) {
			pwSkocz(iInd)->vSetDane(tab[i]);
			iInd++;
		}
	for (int i = 0; i < i_liczbaWezlow; i++)
		if ((*tab[i]) % 2 == 1) {
			pwSkocz(iInd)->vSetDane(tab[i]);
			iInd++;
		}
}

template <typename T>
void CLista<T>::vUsunDuplikaty() {
	for (int i = 0; i < i_liczbaWezlow; i++)
		for (int j = i+1; j < i_liczbaWezlow; j++)
			if (*(pwSkocz(i)->ptGetDane()) == *(pwSkocz(j)->ptGetDane())) {
				bUsun(j);
				j--;
			}
}

#endif