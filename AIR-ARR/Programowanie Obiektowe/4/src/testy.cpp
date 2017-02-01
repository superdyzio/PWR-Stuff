#include "LZespolone.hh"
#include "testy.hh"

void ZadajWyrazenie(LZespolona a, LZespolona b, char znak) {
	cout << "Podaj wynik operacji: " << a << znak << b << endl;
}

int OdpowiedzWyrazenie(LZespolona a, LZespolona b, char znak) {
	int ret = -1;
	LZespolona wynik, odp;
	switch (znak) {
		case '+': wynik = a+b; break;
		case '-': wynik = a-b; break;
		case '*': wynik = a*b; break;
		case '/': wynik = a/b; break;
	}
	while (ret < 0) {
		cout << "Twoja odpowiedź: ";
		cin >> odp;
		if (cin.fail()) {
			cerr << endl << "Błąd. Spróbuj ponownie." << endl;
			cin.clear();
			cin.ignore(10000,'\n');
		}
		else {
			if (wynik == odp) {
				cout << "Odpowiedź poprawna!" << endl;
				ret = 1;
			}
			else {
				cout << "Błąd. Poprawny wynik to: " << wynik << endl;
				ret = 0;
			}
		}
	}
	return ret;
}

void TestWyrazenia() {
	LZespolona a, b;
	char op;
	ifstream fin;
	float dobre = 0, zle = 0, p;
	fin.open("wyrazenia.dat");
	if (fin.is_open()) {
		while (!fin.eof()) {
			if (fin.fail()) {
				fin.clear();
				fin.ignore(10000,'\n');
			}
			fin >> a >> op >> b;
			if ((fin.fail()) || (!strchr("+-*/", op))) {
				if (!fin.eof()) cerr << "Wykryto błędną operację w pliku. Linia zostaje pominięta." << endl;
			}
			else {
				ZadajWyrazenie(a, b, op);
				if (OdpowiedzWyrazenie(a, b, op) == 1) dobre++;
				else zle++;
			}
		}
	}
	else cerr << "Nie udało się otworzyć pliku." << endl;
	p = (dobre * 100) / (dobre + zle);
	cout << "Koniec testu." << endl << "Odpowiedzi dobre: " << dobre << endl << "Odpowiedzi złe: " << zle << endl;
	cout << "Wynik: " << p << "%" << endl;
	fin.close();
}

void ZadajLiczbe(LZespolona a) {
	cout << "Podaj działanie, którego wynikiem jest: " << a << endl;
}

int OdpowiedzLiczba(LZespolona a) {
	char znak;
	LZespolona x, y, wynik;
	int popr = 0, ret = -1;
	while (ret < 0) {
		while (popr <= 0) {
			cout << "Twoja odpowiedź :";
			cin >> x;
			if (cin.fail()) {
				cerr << "Błędny pierwszy argument. Spróbuj ponownie." << endl;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else {
				cin >> znak;
				if (cin.fail() ||  !strchr("+-*/", znak)) {
					cerr << "Błędny operator. Spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(10000,'\n');
				}
				else {	
					cin >> y;
					if (cin.fail()) {
						cerr << "Błędny drugi argument. Spróbuj ponownie." << endl;
						cin.clear();
						cin.ignore(10000,'\n');
					}
					else popr = 1;
				}
			}
			switch (znak) {
				case '+': wynik = x+y; break;				
				case '-': wynik = x-y; break;
				case '*': wynik = x*y; break;
				case '/': wynik = x/y;
					  if (wynik.ok == false) {
						 cerr << "Niedozwolone działanie. Wprowadź ponownie: " << endl;
						 popr = -1;
					  }
					  break;
			}
		}
		if (wynik == a) {
			cout << "Odpowiedź poprawna!" << endl;
			ret = 1;
		}
		else {
			cout << "Blad. Twój wynik to: " << wynik << endl;
			ret = 0;
		}
	}
	return ret;	
}

void TestLiczby() {
	ifstream fin;
	LZespolona a;
	float dobre = 0, zle = 0, p;
	fin.open("liczby.dat");
	if (fin.is_open()) {
		while (!fin.eof()) {
			if (fin.fail()) {
				fin.clear();
				fin.ignore(10000,'\n');
			}
			fin >> a;
			if (fin.fail()) {
				if (!fin.eof())	cerr << "Błędny zapis w pliku. Linia zostanie pominięta." << endl;	
			}
			else {
				ZadajLiczbe(a);
				if (OdpowiedzLiczba(a) == 1) dobre++;
				else zle++;
			}
		}
		p = (dobre * 100)/(dobre+zle);
		cout << "Koniec testu." << endl << "Odpowiedzi dobre: " << dobre << endl << "Odpowiedzi złe: " << zle << endl;
		cout << "Wynik: " << p << "%" << endl;
	}
	else cerr << "Nie udało się otworzyć pliku." << endl;
	fin.close();
}

void menu() {
	char wybor = 'a';
	while (wybor != '3') {
		cout << "----------MENU----------" << endl;
		cout << "1 - test z wyrażen zespolonych" << endl;
		cout << "2 - test z liczb zespolonych" << endl;
		cout << "3 - KONIEC" << endl;
		cin >> wybor;
		switch (wybor) {
			case '1': TestWyrazenia(); break;
			case '2': TestLiczby(); break;
			case '3': cout << "PAPA" << endl; break;
			default: cout << "Nie ma takiej opcji.";
		}
	}
}