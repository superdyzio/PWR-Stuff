#include "Tablica2W.h"
#include "funkcje.h"

int main() {
	char wybor = 'a';
	char linia[256];
	string wyraz;
	int podst, wyk, sil;
	Tablica2W *tab2w = NULL;
	while (wybor != '0') {
		menu();
		cin.getline(linia,256);
		wybor = linia[0];
		switch(wybor) {
		case '1': tab2w = tworz(); cout << "Tablica utworzona i wypelniona!" << endl; cin.ignore(); break;
		case '2': if (tab2w != NULL) { cout << endl << "Oto tablica:" << endl; tab2w->wyswietl(); } 
					else cout << "Tablica jeszcze nie istnieje." << endl;	break;
		case '3': if (tab2w != NULL) { cout << "Najwiekszy element to: "; cout << tab2w->max() << endl; }
					else cout << "Tablica jeszcze nie istnieje." << endl;	break;
		case '4': punkt4(); break;
		case '5': punkt5(); break;
		case '6': cout << "Podaj podstawe potegi: "; cin >> podst; cout << "Podaj wykladnik potegi: "; cin >> wyk; 
					cout << endl << "Twoja liczba to: " << potega(podst,wyk) << endl; cin.ignore(); break;
		case '7': cout << "Podaj liczbe: "; cin >> sil; cout << endl << "Silnia wynosi: " << silnia(sil) << endl; cin.ignore(); break;
		case '8': cout << "Podaj wyraz: "; cin >> wyraz; 
					if (jestPal(wyraz))
						cout << endl << "Wyraz jest palindromem." << endl; 
					else cout << endl << "Wyraz nie jest palindromem." << endl;
					cin.ignore(); break;
		}
		while (!cin) cin.get();
	}
	return 0;
}