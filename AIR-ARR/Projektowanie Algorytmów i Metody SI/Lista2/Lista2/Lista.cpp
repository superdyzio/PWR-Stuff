#include "Lista.h"

void Lista::dodaj(int liczba) {
	dodaj(liczba,rozmiar()+1);
}

void Lista::dodaj(int liczba, int indeks) {
	Element1* nowy = new Element1(liczba);
	if (pusta()) {
		poczatek = nowy;
		return;
	}
	if (indeks <= 0) {
		nowy->setNast(poczatek);
		poczatek = nowy;
		return;
	}
	if (indeks < rozmiar() && indeks > 0) {
		Element1* pom = poczatek;
		for (int i = 0; i < indeks; i++)
			pom = pom->getNast();
		nowy->setNast(pom->getNast());
		pom->setNast(nowy);
		return;
	}
	Element1* pom = poczatek;
	while (pom->getNast() != NULL) 
		pom = pom->getNast();
	pom->setNast(nowy);
}

void Lista::wyswietl() {
	if (pusta())
		cout << "Pusta lista!" << endl;
	else {
		Element1* pom = poczatek;
		while (pom->getNast() != NULL) {
			cout << pom->getDane() << " -> ";
			pom = pom->getNast();
		}
		cout << pom->getDane() << endl;
	}
}

void Lista::usun() {
	usun(rozmiar());
}

void Lista::usun(int indeks) {
	if (pusta()) {
		cout << "Lista pusta!" << endl;
		return;
	}
	if (indeks <= 0) {
		Element1* pom = poczatek;
		poczatek = poczatek->getNast();
		delete pom;
		return;
	}
	if (indeks < rozmiar() && indeks > 0) {
		Element1* pom = poczatek;
		for (int i = 0; i < indeks-1; i++)
			pom = pom->getNast();
		Element1* usun = pom->getNast();
		pom->setNast(pom->getNast()->getNast());
		delete usun;
		return;
	}
	Element1* pom = poczatek;
	while (pom->getNast()->getNast() != NULL) 
		pom = pom->getNast();
	delete pom->getNast();
	pom->setNast(NULL);
}

void Lista::czysc() {
	while (!pusta())
		usun(0);
}