#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
n - ilosc zadan
r - termin dostepnosci
p - czas obslugi
*/

// Klasa modelujaca obiekt zadania, przechowuje informacje o czasie przybycia i wykonania zadania. Nie zawiera metod, wylacznie konstruktory.
class Zadanie {
	public:
		int _r, _p, _s, _k;
		Zadanie() {_r = _p = _s = 0; }
		Zadanie(int R, int P) {
			_r = R;		// czas przybycia
			_p = P;		// czas wykonania
			_s = _r;	// czas startu
			_k = _s + _p;	// czas zakonczenia
		}
};

/* Funkcja sprawdzajaca czy zadany wektor jest uporzadkowany rosnaco (wg czasu przybycia). Jako argumenty przyjmuje zmienna przechowujaca
   ilosc danych oraz sam wektor. */
bool czyPorzadek(int iloscDanych, vector<Zadanie> wektor) {
	for (int i = 0; i < iloscDanych-1; i++)
		if (wektor[i]._r > wektor[i+1]._r)
			return false;
	return true;
}

/* Funkcja sortujaca wektor rosnaco wg czasu przybycia, metoda sortowania babelkowego. Jako argumenty przyjmuje zmienna przechowujaca ilosc
   danych oraz sam wektor. */
void bubbleSort(int iloscDanych, vector<Zadanie> &wektor) {
	Zadanie pom;
	while(!czyPorzadek(iloscDanych,wektor)) {
		for (int i=0; i < iloscDanych-1; i++)
			if (wektor[i]._r > wektor[i+1]._r) {
				pom = wektor[i];
				wektor[i] = wektor[i+1];
				wektor[i+1] = pom;
			}
	}
}

// Funkcja sprawdzajaca czy plik o nazwie podanej jako argument istnieje.
bool plikIstnieje(const char *fileName) {
    fstream infile(fileName);
    return infile.good();
}

// Funkcja generujaca plik z rozwiazaniem - podanym jako argument wynikiem.
void generujPlikZRozwiazaniem(int wynik) {
	if (plikIstnieje("wynik.txt"))
		remove("wynik.txt");
	ofstream PLIK("wynik.txt");
	PLIK << wynik;
	PLIK.close();
}

int main() {
	int iloscDanych;
	int r, p, wynik;
	r = p = 0;
	char nazwa[32];
	vector<Zadanie> ListaZadan;
	Zadanie noweZadanie;	// zmienna pomocnicza do wczytywania zadan
	fstream PlikDanych;	// strumien plikowy - udostepnia plik z danymi
	
	cout << endl << "Podaj nazwe pliku z danymi: ";
	scanf("%s",nazwa); 
	if (!plikIstnieje(nazwa)) {
		cout << "Bledna nazwa pliku." << endl;
		return -1;
	}
	PlikDanych.open(nazwa,ios::in);		// otwarcie pliku z danymi w trybie do odczytu

	PlikDanych >> iloscDanych;

	cout << endl << "Wczytuje " << iloscDanych << " danych" << endl;

	for (int i = 0; i < iloscDanych; i++) {		// wrzucanie kolejnych zadan do wektora
		PlikDanych >> r;
		PlikDanych >> p;
		ListaZadan.push_back(Zadanie(r,p));
	}

	PlikDanych.close();

	for (int i = 0; i<iloscDanych; i++)		// wypisanie zadan
		cout << ListaZadan[i]._r << " " << ListaZadan[i]._p << endl;

	bubbleSort(iloscDanych,ListaZadan);		// sortowanie zadan

	for (int i = 1; i < iloscDanych; i++) {		// wyznaczanie czasow poczatkowych i koncowych zadan
		if (ListaZadan[i]._r > ListaZadan[i-1]._s + ListaZadan[i-1]._p)
			ListaZadan[i]._s = ListaZadan[i]._r;
		else
			ListaZadan[i]._s = ListaZadan[i-1]._s + ListaZadan[i-1]._p;
		ListaZadan[i]._k = ListaZadan[i]._s + ListaZadan[i]._p;
	}

	cout << endl << "Posortowane procesy oraz wyniki:" << endl;
	for (int i = 0; i < iloscDanych; i++)		// wypisanie posortowanych zadan
		cout << ListaZadan[i]._r << " " << ListaZadan[i]._p << endl;
	cout << endl << "Start ostatniego zadania: " << ListaZadan[iloscDanych-1]._s;
	cout << endl << "Koniec ostatniego zadania: " << ListaZadan[iloscDanych-1]._k << endl << endl;
	wynik = ListaZadan[iloscDanych-1]._k;		// zapisanie wyniku
	generujPlikZRozwiazaniem(wynik);		// generowanie pliku z wynikiem
	return 0;
}
