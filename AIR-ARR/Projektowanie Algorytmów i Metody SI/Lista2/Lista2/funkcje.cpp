#include "funkcje.h"

void menu() {
	cout << endl << "----------MENU----------" << endl;
	cout << "1 - prezentacja dzialania zadania 1" << endl;
	cout << "2 - obsluga listy jednokierunkowej" << endl;
	cout << "3 - obsluga kolejki" << endl;
	cout << "4 - obsluga deque" << endl;
	cout << "0 - KONIEC " << endl;
	cout << "Twoj wybor: ";
}

bool jestPal(string testStr) {
	return testStr[0] == testStr[testStr.length()-1] && (testStr.length() > 2 ? jestPal(testStr.substr(1,testStr.length()-2)) : true);
}

int permutacje(string prefix, string tekst, string palindromy[], int liczba) {
    if (tekst.size() <= 1) {
        if (jestPal(prefix+tekst)) {
			palindromy[liczba] = (prefix+tekst);
			liczba++;
		}
	}
    else {
        string::iterator it = tekst.begin();
        for (; it != tekst.end(); ++it) {
            char c = *it;
            tekst.erase(it);
            liczba = permutacje( prefix + c, tekst, palindromy, liczba);
            tekst.insert(it, c);
        }
    }
	return liczba;
}

bool jestDup(string palindromy[]) {
	for (int i = 0; i < ROZMIAR_TAB && palindromy[i] != ""; i++)
		for (int j = i+1; j < ROZMIAR_TAB && palindromy[j] != ""; j++)
			if (palindromy[i] == palindromy[j])
				return true;
	return false;
}

void usunDup(string palindromy[]) {
	for (int i = 0; i < ROZMIAR_TAB && palindromy[i] != ""; i++)
		for (int j = 0; j < i; j++)
			if (palindromy[i] == palindromy[j])
				for (int k = i; k < ROZMIAR_TAB; k++)
					palindromy[k] = palindromy[k+1];
}

void zadanie1(string palindromy[], int liczba) {
	string lancuch;
	cout << "Podaj lancuch: ";
	cin >> lancuch;
	cout << endl;
	liczba = permutacje("",lancuch,palindromy,liczba);
	cout << "Oto lista twoich palindromow:" << endl;
	if (liczba == 0)
		cout << "BRAK" << endl;
	for (int i = 0; i < liczba; i++)
		cout << palindromy[i] << endl;;
	while (jestDup(palindromy))
		usunDup(palindromy); 
	cout << endl << endl << "Oto lista twoich palindromow po usunieciu duplikatow:" << endl;
	if (liczba == 0)
		cout << "BRAK" << endl;
	for (int i = 0; i < liczba && palindromy[i] != ""; i++)
		cout << palindromy[i] << endl;
}

void zadanie2() {
	Lista lista;
	int n, indeks, liczba;
	cout << endl << "Ile elementow: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Podaj liczbe: ";
		cin >> liczba;
//		cout << "Podaj indeks: ";
//		cin >> indeks;
		lista.dodaj(liczba);
	}
	cout << "Twoja lista: " << endl;
	lista.wyswietl();
	cout << "Usuwanie elemtnow zakonczy sie przy podaniu ujemnego indeksu." << endl;
	indeks = 0;
	while (indeks >= 0) {
		cout << "Podaj indeks: ";
		cin >> indeks;
		if (indeks >= 0)
			lista.usun();
	}
	cout << "Oto lista po usunieciach:" << endl;
	lista.wyswietl();
	lista.czysc();
	cout << endl << "Oto wyczyszczona lista: " << endl;
	lista.wyswietl();
}

void zadanie3() {
	Kolejka kolejka;
	int n, indeks, liczba;
	cout << endl << "Ile elementow: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Podaj liczbe: ";
		cin >> liczba;
//		cout << "Podaj indeks: ";
//		cin >> indeks;
		kolejka.dodaj(liczba);
	}
	cout << "Twoja kolejka: " << endl;
	kolejka.wyswietl();
	cout << "Usuwanie elementow zakonczy sie przy podaniu ujemnego indeksu." << endl;
	indeks = 0;
	while (indeks >= 0) {
		cout << "Podaj indeks: ";
		cin >> indeks;
		if (indeks >= 0)
			kolejka.usun();
	}
	cout << "Oto kolejka po usunieciach:" << endl;
	kolejka.wyswietl();
	kolejka.czysc();
	cout << endl << "Oto wyczyszczona kolejka: " << endl;
	kolejka.wyswietl();
}

void zadanie5() {
	Deque deque;
	int n, indeks, liczba;
	cout << endl << "Ile elementow: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Podaj liczbe: ";
		cin >> liczba;
		cout << "Aby wstawic na poczatek podaj liczbe ujemna, by na koniec nieujemna: ";
		cin >> indeks;
		if (indeks < 0)
			deque.wstawPierwszy(liczba);
		else
			deque.wstawOstatni(liczba);
	}
	cout << "Twoja kolejka: " << endl;
	deque.wyswietl();
	cout << "Dodatnia by usunac z konca, ujemna by z poczatku, 0 by zakonczyc:" << endl;
	do {
		cout << "Podaj indeks: ";
		cin >> indeks;
		if (!deque.pusta()) {
			if (indeks > 0)
				deque.usunOstatni();
			if (indeks < 0)
				deque.usunPierwszy();
		}
		else
			cout << "Lista pusta!" << endl;
	} while (!deque.pusta() && indeks != 0);
	cout << "Oto kolejka po usunieciach:" << endl;
	deque.wyswietl();
	deque.czysc();
	cout << endl << "Oto wyczyszczona kolejka: " << endl;
	deque.wyswietl();
}