/*!
 * \file 
 * \brief Plik źródłowy klasy DaneSymulacji.
*/

#include "DaneSymulacji.hpp"

using namespace std;

DaneSymulacji::DaneSymulacji() {
	_plikSymulacji = "";	// zerowanie nazwy pliku z danymi
	_aktualnyCzas = 0;	// zerowanie aktualnego czasu symulacji
}

void DaneSymulacji::wczytajDane(string plik) {
	_aktualnyCzas = 0;
	_wartosci.clear();	// zerowanie aktualnego czasu i wektorów czasu oraz wartości
	_czas.clear();
	int i = 0;
	string linia;
	plik = "data/"+plik;
	ifstream uchwytPliku(plik.c_str());	// definiowanie uchwytu do pliku
	if (uchwytPliku.is_open()) {		// sprawdzenie poprawności otwarcia pliku
		_plikSymulacji = plik.c_str();
		while (getline(uchwytPliku,linia)) {	// wczytywanie linia po linii	
		 	_wartosci.push_back(atof(linia.c_str()));
		 	_czas.push_back((double)i/10);
		 	i++;
		} // while
		uchwytPliku.close();
	}
	else // if
		cout << "Nie udało się otworzyć pliku.";
}
