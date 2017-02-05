#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

/*
Dane wczytywane z pliku:
n - ilosc zadan
r - termin dostepnosci
p - czas obslugi
q - czas dostarczenia
*/

/* Klasa modelujaca obiekt zadania, przechowuje informacje o czasie przybycia, wykonania (poczatkowym i pozostalym) i dostarczenia zadania
   oraz zmienne typu bool mowiace o tym czy dane zadanie jest juz gotowe oraz czy zostalo juz wykonane. Nie zawiera metod, wylacznie
   konstruktory. */
class Zadanie {
	public:
		int _r, _p, _q, _s, _k, _f, _z;
		bool _done, _ready;
		Zadanie() {_r = _p = _s = _q = _f = _z =0; _done = false; _ready = false;}
		Zadanie(int R, int P, int Q) {
			_r = R;		// czas przybycia
			_p = P;		// czas wykonania
			_q = Q;		// czas dostarczenia
			_s = _r;	// czas startu
			_z = _p;	// czas pozostaly do wykonania
			_k = _s + _p;	// czas zakonczenia
			_f = _k + _q;	// moment dostarczenia
			_done = false;	// czy zostalo juz wykonane
			_ready = false; // czy jest juz gotowe do wykonania
		}
};

/* Funkcja sprawdzajaca czy wszystkie zadania z wektora podanego jako argument zostaly juz wykonane. */
bool czyWszystkie(vector<Zadanie> wektor) {
	for (int i = 0; i < wektor.size(); i++)
		if (!wektor[i]._done)
			return false;
	return true;
}

/* Funkcja porownujaca czasy przybycia dwoch podanych jako argumenty zadan. */
bool porownajR(Zadanie zad1, Zadanie zad2) {
	return zad1._r < zad2._r;
}

/* Struktura sluzaca do porwnywania dwoch zadan i szeregowania ich wg malejacego Q. */
struct porownajQ {
	bool operator () (Zadanie zad1, Zadanie zad2) {
		return zad1._q < zad2._q;
	}
};

/* Funkcja sortujaca podany jako argument wektor rosnaco wg R. Uzywa funkcji bilbiotecznej sort. */
void sortowanie(vector<Zadanie> &wektor) {
	sort(wektor.begin(),wektor.end(),porownajR);
}

/* Funkcja sprawdzajaca czy plik o nazwie podanej jako argument istnieje. */
bool plikIstnieje(const char *fileName) {
    fstream infile(fileName);
    return infile.good();
}

/* Funkcja generujaca plik z rozwiazaniem - podanym jako argument wynikiem. */
void generujPlikZRozwiazaniem(int wynik) {
	if (plikIstnieje("wynik.txt"))
		remove("wynik.txt");
	ofstream PLIK("wynik.txt");
	PLIK << wynik;
	PLIK.close();
}

/* Funkcja wczytujaca dane z zadanego pliku do podanego jako argument wektora. */
bool wczytaj(vector<Zadanie> &wektor) {
	Zadanie noweZadanie;	// zmienna pomocnicza do wczytywania zadan
	fstream PlikDanych;	// strumien plikowy - udostepnia plik z danymi
	int r, p, q, n;	
	char nazwa[32];
	cout << endl << "Podaj nazwe pliku z danymi: ";	// pobranie nazwy pliku od uzytkownika
	scanf("%s",nazwa); 
	if (!plikIstnieje(nazwa)) {		// zabezpieczenie przed bledna nazwa pliku
		cout << "Bledna nazwa pliku." << endl;
		return false;
	}
	PlikDanych.open(nazwa,ios::in);		// otwarcie pliku z danymi w trybie do odczytu
	PlikDanych >> n;
	cout << endl << "Wczytuje " << n << " danych" << endl;
	for (int i = 0; i < n; i++) {		// wrzucanie kolejnych zadan do wektora
		PlikDanych >> r;
		PlikDanych >> p;
		PlikDanych >> q;
		wektor.push_back(Zadanie(r,p,q));
	}
	PlikDanych.close();		// zamkniecie strumienia plikowego
	return true;
}

/* Funkcja wypisujaca na standardowe wyjscie zawartosc podanego jako argument wektora - listy zadan, w formacie "R P Q". */
void wypisz(vector<Zadanie> &wektor) {
	for (int i = 0; i < wektor.size(); i++)		
		cout << wektor[i]._r << " " << wektor[i]._p << " " << wektor[i]._q << endl;	
}

void wykonane(vector<Zadanie> &wektor, Zadanie zad, int czas) {
	for (int i = 0; i < wektor.size(); i++) 
		if (wektor[i]._r == zad._r && wektor[i]._p == zad._p && wektor[i]._q == zad._q) {
			wektor[i]._done = true;
			wektor[i]._k = czas;
			wektor[i]._f = wektor[i]._k + wektor[i]._q;
			return;
		}
}

/* Funkcja implementujaca algorytm Schrage. Jako argument przyjmuje wektor przechowujacy liste wszystkich zadan. */
int schrageP(vector<Zadanie> &wektor) {
	int czas = -1;							// zmienna przechowujaca obecny czas
	priority_queue<Zadanie,vector<Zadanie>,porownajQ> gotowe;	// kolejka priorytetowa zadan gotowych do wykonania
	sortowanie(wektor);						// sortowanie zadan wg R
	for (czas = 0; !czyWszystkie(wektor); czas++) {			// petle wykonujemy dopoki wszystkie zadania nie zostana wykonane
		for (int i = 0; i < wektor.size() && wektor[i]._r <= czas; i++)
			if (!wektor[i]._ready) {
				wektor[i]._ready = true;		// dodawanie zadan do zbioru gotowych do wykonania
				gotowe.push(wektor[i]);				
			}
		if (!gotowe.empty()) {					// jesli istnieje zadanie do wykonania to robimy jeden takt
			Zadanie pom = gotowe.top();
			gotowe.pop();
			pom._z--;
			if (pom._z > 0)					
				gotowe.push(pom);			// jesli to jeszcze nie koniec zadania to wraca do kolejki
			else
				wykonane(wektor,pom,czas+1);		// zaznaczanie ze zadanie zostalo wykonane
		}
	}
	for (int i = 0; i < wektor.size(); i++)				// szukamy czasu dostarczenia ktory moglby wydluzyc koncowy czas
		if (wektor[i]._f > czas)
			czas = wektor[i]._f;
	return czas;
}

int main() {
	int wynik;			// zmienna przechowujaca koncowy wynik
	vector<Zadanie> ListaZadan;	// wektor przechowujacy wszystkie zadania

	if (!wczytaj(ListaZadan))	// w przypadku nieudanego wczytania pliku konczymy dzialanie programu
		return -1;

	wynik = schrageP(ListaZadan);	// wywolanie wlasciwego algorytmu	

	cout << endl << "Dostarczenie ostatniego zadania: " << wynik << endl << endl;	// wyswietlenie wyniku

	generujPlikZRozwiazaniem(wynik);		// generowanie pliku z wynikiem

	return 0;
}
