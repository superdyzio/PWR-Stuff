#include "Stos.h"

void Stos::dodaj(int liczba) {
	dodaj(liczba,rozmiar()+1);
}

void Stos::dodaj(int liczba, int indeks) {
	Element* nowy = new Element(liczba);
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
		Element* pom = poczatek;
		for (int i = 0; i < indeks; i++)
			pom = pom->getNast();
		nowy->setNast(pom->getNast());
		pom->setNast(nowy);
		return;
	}
	Element* pom = poczatek;
	while (pom->getNast() != NULL) 
		pom = pom->getNast();
	pom->setNast(nowy);
}

void Stos::wyswietl() {
	if (pusta())
		cout << "Pusty stos!" << endl;
	else {
		Element* pom = poczatek;
		while (pom->getNast() != NULL) {
			cout << pom->getDane() << " -> ";
			pom = pom->getNast();
		}
		cout << pom->getDane() << endl;
	}
}

void Stos::usun() {
	usun(rozmiar()+1);
}

void Stos::usun(int indeks) {
	if (pusta()) {
		cout << "Stos pusty!" << endl;
		return;
	}
	if (indeks <= 0) {
		Element* pom = poczatek;
		poczatek = poczatek->getNast();
		delete pom;
		return;
	}
	if (indeks < rozmiar() && indeks > 0) {
		Element* pom = poczatek;
		for (int i = 0; i < indeks-1; i++)
			pom = pom->getNast();
		Element* usun = pom->getNast();
		pom->setNast(pom->getNast()->getNast());
		delete usun;
		return;
	}
	Element* pom = poczatek;
	while (pom->getNast()->getNast() != NULL) 
		pom = pom->getNast();
	delete pom->getNast();
	pom->setNast(NULL);
}

void Stos::czysc() {
	while (!pusta())
		usun(0);
}