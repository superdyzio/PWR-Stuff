#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>

#include "uklad.hh"
#include "liczba.hh"
#include "zespolone.hh"
#include "symbole.hh"
#include "typ.hh"
#include "wektor.hh"
#include "macierz.hh"

/*!
 *\file 
 *\brief 	Plik zawierający implementację części właściwej programu.
 *		W funkcji 'main()' realizowane są następujące operacje:
 *			1. Wczytanie z pliku dwóch argumentów (typu Macierz lub Wektor). 
 *			2. Rozwiązanie układu równań i wyświetlenie na standardowym wyjściu wyniku lub odpowiedniego komunikatu.
 */	
		
using namespace std;

int main(){
	Uklad u;
	cout.setf(ios::fixed);	// formatowanie zapisu zapewniające odpowiednie wyrównanie kolumn macierzy
	cout.precision(2);	// dwa miejsca po przecinku
	cin >> u;		
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000,'\n');
		cerr << endl << "Nieprawidłowy układ równań." << endl;
	}
	else {
		cout << endl << u << endl << endl;
		u.x = Rozwiaz(u);
		cout << "Wynik: " << endl << u.x;
		u.x = Blad(u);
		cout << endl << "Błąd: " << u.x << endl;
	}
 	cout << endl << "Program został skompliwany dla typu: " << NAZWA_TYPU << endl << endl;
}
