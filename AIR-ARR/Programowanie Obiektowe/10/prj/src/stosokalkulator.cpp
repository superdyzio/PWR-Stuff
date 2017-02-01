#include "stosokalkulator.hh"

/*!
 *\file
 *\brief	Plik zawiera implementację wybranych metod klasy Stos.
*/

void Stosokalkulator::zamien() {
	if (size() > 1) {
		Zespolona pom = top();
		pop();
		Zespolona pom2 = top();
		pop();
		push(pom);
		push(pom2);
	}
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Stosokalkulator::duplikuj() {
	if (size() > 0)
		push(top());
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Stosokalkulator::wyswietl() {
	if (size() > 0) {
		cout << endl << "Stos:" << endl;
		Zespolona a;
		Stosokalkulator pom = (*this);
		while (pom.size() > 0) {
			a = pom.top();
			pom.pop();
			cout << a << endl;
		}
	}
	else cout << "Stos jest pusty." << endl;
}

void Stosokalkulator::dodaj() {
	if (size() > 1) {
		Zespolona a, b;
		a = top();
		pop();
		b = top();
		pop();
		push(a+b);
		cout << "Wykonano dodawanie.";
	}
	else cout << "Na stosie jest mało elementów." << endl;
	cout << endl << "Liczba obiektów ogólnie: " << Zespolona::getIlosc();
	cout << endl << "Liczba obiektów na stosie: " << Zespolona::getIloscA() << endl;
}

void Stosokalkulator::odejmij() {
	if (size() > 1) {
		Zespolona a, b;
		a = top();
		pop();
		b = top();
		pop();
		push(b-a);
		cout << "Wykonano odejmowanie.";
	}
	else cout << "Na stosie jest za mało elementów." << endl;
	cout << endl << "Liczba obiektów ogólnie: " << Zespolona::getIlosc();
	cout << endl << "Liczba obiektów na stosie: " << Zespolona::getIloscA() << endl;
}

void Stosokalkulator::mnoz() {
	if (size() > 1) {
		Zespolona a, b;
		a = top();
		pop();
		b = top();
		pop();
		push(a*b);
		cout << "Wykonano mnożenie.";
	}
	else cout << "Na stosie jest za mało elementów." << endl;
	cout << endl << "Liczba obiektów ogólnie: " << Zespolona::getIlosc();
	cout << endl << "Liczba obiektów na stosie: " << Zespolona::getIloscA() << endl;
}

void Stosokalkulator::dziel() {
	if (size() > 1) {
		Zespolona a, b;
		a = top();
		pop();
		b = top();
		pop();
		push(b/a);
		cout << "Wykonano dzielenie.";
	}
	else cout << "Na stosie jest za mało elementów." << endl;
	cout << endl << "Liczba obiektów ogólnie: " << Zespolona::getIlosc();
	cout << endl << "Liczba obiektów na stosie: " << Zespolona::getIloscA() << endl;
}

void Stosokalkulator::usun() {
	if (size() > 0) pop();
	else cout << "Stos jest pusty." << endl;
}

void Stosokalkulator::czysc() {
	while (size() > 0) pop();
	cout << endl << "Liczba obiektów ogólnie: " << Zespolona::getIlosc();
	cout << endl << "Liczba obiektów na stosie: " << Zespolona::getIloscA() << endl;
}
