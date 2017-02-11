#include "Lista.h"
;
/*
template <typename T>
CWezel<T>* CLista<T>::pwSkocz(int iIndeks) {
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
CWezel<T>* CLista<T>::operator [](int iIndeks) {
	return pwSkocz(iIndeks);
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
	if (iIndeks < 0 || iIndeks > i_liczbaWezlow) { 
		cout << POZALISTA << endl;
		return false;
	}
	if (iIndeks == 0) return bUsunZPoczatku();
	if (iIndeks == i_liczbaWezlow) return bUsunZKonca();
	CWezel<T>* pwPom = pwSkocz(iIndeks);
	pwPom->pwGetPoprzedni()->vSetNastepny(pwPom->pwGetNastepny());
	pwPom->pwGetNastepny()->vSetPoprzedni(pwPom->pwGetPoprzedni());
	delete(pwPom);
	i_liczbaWezlow--;
	return true;
}

template <typename T>
bool CLista<T>::bUsunZPoczatku() {
	CWezel<T>* pwPom = pw_poczatek;
	pwPom->pwGetNastepny()->vSetPoprzedni(NULL);
	pw_poczatek = pwPom->pwGetNastepny();
	delete(pwPom);
	i_liczbaWezlow--;
	return true;
}

template <typename T>
bool CLista<T>::bUsunZKonca() {
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
		cout << *(T*)(pwSkocz(i)->ptGetDane()) << " -> ";
	cout << "NULL" << endl;
}

template <typename T>
CLista<T>* CLista<T>::plClone() {
	CLista<T>* plWynik = new CLista<T>();
	for (int i = 0; i< i_liczbaWezlow; i++)
		plWynik->vDodajNaKoniec(pwSkocz(i)->ptGetDane());
	return plWynik;
}*/