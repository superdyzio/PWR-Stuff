#include "funkcje.h"

Tablica2W* tworz() {
	int n, m, x;
	cout << "Podaj ilosc wierszy: ";
	cin >> n;
	cout << "Podaj ilosc kolumn: ";
	cin >> m;
	Tablica2W *pom = new Tablica2W(n,m);
	cout << "Podaj maksymalna wartosc w tablicy: ";
	cin >> x;
	pom->wypelnij(x);
	return pom;
}

void menu() {
	cout << endl << "----------MENU----------" << endl;
	cout << "1 - tworz i wypelnij tablice" << endl;
	cout << "2 - wyswietl tablice" << endl;
	cout << "3 - znajdz maksymalna wartosc tablicy" << endl;
	cout << "4 - zapisz i wczytaj tablice 1W (txt)" << endl;
	cout << "5 - zapisz i wczytaj tablice 1W (plik binarny)" << endl;
	cout << "6 - wylicz dana potege wybranej liczby" << endl;
	cout << "7 - wylicz silnie zadanej liczby" << endl;
	cout << "8 - sprawdz czy wyraz jest palindromem" << endl;
	cout << "0 - KONIEC" << endl;
}

int potega(int x, int p) {
	return p == 0 ? 1 : x*potega(x,p-1);
}

int silnia(int x) {
	return x == 0? 1 : x*silnia(x-1);
}

bool jestPal(string testStr) {
	return testStr[0] == testStr[testStr.length()-1] && (testStr.length() > 2 ? jestPal(testStr.substr(1,testStr.length()-2)) : true);
}

bool zapistxt(string plik,int tab[]) {
	ofstream dane;
	dane.open(plik,ios::out);
	if (dane.good()) {
		for (int i = 0; i < ROZMIAR; i++)
			dane << tab[i] << " ";
	}
	else return false;
	dane.close();
	return true;
}

bool odczyttxt(string plik) {
	ifstream dane;
	dane.open(plik,ios::in);
	char linia[1024];
	if (dane.good()) {
		dane.read(linia,1024);
	}
	else return false;
	dane.close();
	for (int i = 0; i < 2*ROZMIAR; i++)
		cout << linia[i];
	return true;
}

void punkt4() {
	int tab[ROZMIAR];
	srand((int)time(NULL));
	cout << "Oto tablica: ";
	for (int i = 0; i < ROZMIAR; i++)
		cout << (tab[i] = rand() % ROZMIAR) << " ";
	if (!zapistxt("plik.txt",tab)) {
		cout << "Zapis nieudany." << endl;
		return;
	}
	cout << endl << "Tablica zapisana do pliku." << endl;
	cout << "Oto odczytana tablica:" << endl;
	if (!odczyttxt("plik.txt")) {
		cout << "Odczyt nieudany." << endl;
		return;
	}
}

bool zapisbin(char* plik,int tab[]) {
	ofstream dane;
	dane.open(plik,ios::binary);
	if (dane.good()) {
		for (int i = 0; i < ROZMIAR; i++) {
			char znak[10];
			_itoa(tab[i],znak,10);
			dane.write(znak,1);
		}
	}
	else return false;
	dane.close();
	return true;
}

bool odczytbin(string plik) {
	ifstream dane;
	dane.open(plik,ios::binary);
	char linia[1024];
	if (dane.good()) {
		dane.read(linia,1024);
	}
	else return false;
	dane.close();
	for (int i = 0; i < ROZMIAR; i++)
		cout << linia[i] << " ";
	return true;
}

void punkt5() {
	int tab[ROZMIAR];
	srand((int)time(NULL));
	cout << "Oto tablica: ";
	for (int i = 0; i < ROZMIAR; i++)
		cout << (tab[i] = rand() % ROZMIAR) << " ";
	if (!zapisbin("plik1.bin",tab)) {
		cout << "Zapis nieudany." << endl;
		return;
	}
	cout << endl << "Tablica zapisana do pliku." << endl;
	cout << "Oto odczytana tablica:" << endl;
	if (!odczytbin("plik1.bin")) {
		cout << "Odczyt nieudany." << endl;
		return;
	}
}