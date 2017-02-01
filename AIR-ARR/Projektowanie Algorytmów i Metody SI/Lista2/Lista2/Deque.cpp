#include "Deque.h"

int Deque::rozmiar() const {
	Element3 *pom = poczatek;
	int wynik = 0;
	if (pusta()) 
		return 0;
	while (pom->getNast() != NULL) {
		pom = pom->getNast();
		wynik++;
	}
	return wynik;
}

int Deque::pierwszy() {
	return poczatek->getDane();
}

int Deque::ostatni() {
	return koniec->getDane();
}

void Deque::wstawPierwszy(int obj) {
	Element3 *nowy = new Element3(obj);
	if (pusta()) {
		poczatek = nowy;
		koniec = nowy;
	}
	else {
		Element3 *pom = poczatek;
		pom->setPrzed(nowy);
		nowy->setNast(pom);
		poczatek = nowy;
	}
}

void Deque::wstawOstatni(int obj) {
	Element3 *nowy = new Element3(obj);
	if (pusta()) {
		poczatek = nowy;
		koniec = nowy;
	}
	else {
		Element3 *pom = koniec;
		pom->setNast(nowy);
		nowy->setPrzed(pom);
		koniec = nowy;
	}
}

void Deque::usunPierwszy() {
	if (pusta())
		cout << "Lista pusta!" << endl;
	else {
		Element3 *pom = poczatek;
		if (pom->getNast() != NULL) {
			pom->getNast()->setPrzed(NULL);
			poczatek = pom->getNast();
			delete pom;
		}
		else {
			delete pom;
			poczatek = NULL;
			koniec = NULL;
		}
	}
}

void Deque::usunOstatni() {
	if (pusta()) 
		cout << "Lista pusta!" << endl;
	else {
		Element3 *pom = koniec;
		if (pom->getPrzed() != NULL) {
			pom->getPrzed()->setNast(NULL);
			koniec = pom->getPrzed();
			delete pom;
		}
		else {
			delete pom;
			koniec = NULL;
			poczatek = NULL;
		}
	}
}

void Deque::wyswietl() {
	Element3 *pom = poczatek;
	if (pusta())
		cout << "Lista pusta!" << endl;
	else {
		while (pom->getNast() != NULL) {
			cout << pom->getDane() << " -> ";
			pom = pom->getNast();
		}
		cout << pom->getDane() << endl;
	}
}

void Deque::czysc() {
	while (!pusta()) 
		usunPierwszy();
}