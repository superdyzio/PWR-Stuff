#include "Funkcje.h"

pair<int,int> menu() {
	pair<int,int> wynik = make_pair(0,0);
	char wybor = ' ';
	while (wynik.first == 0) {
		cout << "Wybierz rozmiar planszy:" << endl;
		cout << "3 - plansza 3x3" << endl;
		cout << "4 - plansza 4x4" << endl;
		cout << "5 - plansza 5x5" << endl;
		cout << "6 - plansza 6x6" << endl;
		cout << "7 - plansza 7x7" << endl;
		cout << "0 - KONIEC" << endl;
		cin >> wybor;
		switch (wybor) {
		case '3': wynik.first = 3; cout << NAGLOWEK3; break;
		case '4': wynik.first = 4; cout << NAGLOWEK4; break;
		case '5': wynik.first = 5; cout << NAGLOWEK5; break;
		case '6': wynik.first = 6; cout << NAGLOWEK6; break;
		case '7': wynik.first = 7; cout << NAGLOWEK7;
		}
	}
	while (wynik.second == 0) {
		cout << endl << "Wybierz poziom trudnosci:" << endl;
		if (wynik.first == 3) {
			cout << "3 - trudny - 3 znaki w rzedzie lub na ukos" << endl;
			cin >> wybor;
			switch (wybor) {
			case '3': wynik.second = 3;
			}
		}
		if (wynik.first == 4) {
			cout << "3 - latwy - 3 znaki w rzedzie lub na ukos" << endl;
			cout << "4 - trudny - 4 znaki w rzedzie lub na ukos" << endl;
			cin >> wybor;
			switch (wybor) {
			case '3': wynik.second = 3; break;
			case '4': wynik.second = 4;
			}
		}
		if (wynik.first == 5) {
			cout << "3 - latwy - 3 znaki w rzedzie lub na ukos" << endl;
			cout << "4 - sredni - 4 znaki w rzedzie lub na ukos" << endl;
			cout << "5 - trudny - 5 znakow w rzedzie lub na ukos" << endl;
			cin >> wybor;
			switch (wybor) {
			case '3': wynik.second = 3; break;
			case '4': wynik.second = 4; break;
			case '5': wynik.second = 5;
			}
		}
		if (wynik.first == 6) {
			cout << "3 - latwy - 3 znaki w rzedzie lub na ukos" << endl;
			cout << "4 - sredni - 4 znaki w rzedzie lub na ukos" << endl;
			cout << "5 - trudny - 5 znakow w rzedzie lub na ukos" << endl;
			cout << "6 - bardzo trudny - 6 znakow w rzedzie lub na ukos" << endl;
			cin >> wybor;
			switch (wybor) {
			case '3': wynik.second = 3; break;
			case '4': wynik.second = 4; break;
			case '5': wynik.second = 5; break;
			case '6': wynik.second = 6;
			}
		}
		if (wynik.first == 7) {
			cout << "3 - latwy - 3 znaki w rzedzie lub na ukos" << endl;
			cout << "4 - sredni - 4 znaki w rzedzie lub na ukos" << endl;
			cout << "5 - trudny - 5 znakow w rzedzie lub na ukos" << endl;
			cout << "6 - bardzo trudny - 6 znakow w rzedzie lub na ukos" << endl;
			cin >> wybor;
			switch (wybor) {
			case '3': wynik.second = 3; break;
			case '4': wynik.second = 4; break;
			case '5': wynik.second = 5; break;
			case '6': wynik.second = 6;
			}
		}
	}
	return wynik;
}