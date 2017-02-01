#include "Kolejka.h"

void Kolejka::dodaj(int liczba) {
	dodaj(liczba,rozmiar()+1);
}

void Kolejka::dodaj(int liczba, int indeks) {
	Element2* nowy = new Element2(liczba);
	if (pusta()) {
		poczatek = nowy;
		return;
	}
	if (indeks <= 0) {
		nowy->setPrzed(poczatek);
		poczatek = nowy;
		return;
	}
	if (indeks < rozmiar() && indeks > 0) {
		Element2* pom = poczatek;
		for (int i = 0; i < indeks; i++)
			pom = pom->getPrzed();
		nowy->setPrzed(pom->getPrzed());
		pom->setPrzed(nowy);
		return;
	}
	Element2* pom = poczatek;
	while (pom->getPrzed() != NULL) 
		pom = pom->getPrzed();
	pom->setPrzed(nowy);
}

void Kolejka::wyswietl() {
	if (pusta())
		cout << "Pusta Kolejka!" << endl;
	else {
		Element2* pom = poczatek;
		while (pom->getPrzed() != NULL) {
			cout << pom->getDane() << " -> ";
			pom = pom->getPrzed();
		}
		cout << pom->getDane() << endl;
	}
}

void Kolejka::usun() {
	usun(0);
}

void Kolejka::usun(int indeks) {
	if (pusta()) {
		cout << "Kolejka pusta!" << endl;
		return;
	}
	if (indeks <= 0) {
		Element2* pom = poczatek;
		poczatek = poczatek->getPrzed();
		delete pom;
		return;
	}
	if (indeks < rozmiar() && indeks > 0) {
		Element2* pom = poczatek;
		for (int i = 0; i < indeks-1; i++)
			pom = pom->getPrzed();
		Element2* usun = pom->getPrzed();
		pom->setPrzed(pom->getPrzed()->getPrzed());
		delete usun;
		return;
	}
	Element2* pom = poczatek;
	while (pom->getPrzed()->getPrzed() != NULL) 
		pom = pom->getPrzed();
	delete pom->getPrzed();
	pom->setPrzed(NULL);
}

void Kolejka::czysc() {
	while (!pusta())
		usun(0);
}