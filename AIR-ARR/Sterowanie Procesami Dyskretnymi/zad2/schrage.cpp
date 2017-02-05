#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

/*
n - ilosc zadan
r - termin dostepnosci
p - czas obslugi
q - czas dostarczenia
*/

/* Klasa modelujaca obiekt zadania, przechowuje informacje o czasie przybycia, wykonania i dostarczenia zadania oraz zmienne typu bool
   mowiace o tym czy dane zadanie jest juz gotowe oraz czy zostalo juz wykonane. Nie zawiera metod, wylacznie konstruktory. */
class Zadanie {
	public:
		int _r, _p, _q, _s, _k, _f;
		bool _done, _ready;
		Zadanie() {_r = _p = _s = _q = _f = 0; _done = false; _ready = false; }
		Zadanie(int R, int P, int Q) {
			_r = R;		// czas przybycia
			_p = P;		// czas wykonania
			_q = Q;		// czas dostarczenia
			_s = _r;	// czas startu
			_k = _s + _p;	// czas zakonczenia
			_f = _k + _q;	// moment dostarczenia
			_done = false;	// czy zostalo juz wykonane
			_ready = false; // czy jest gotowe do wykonania
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

/* Funkcja porownujaca czasy dostarczenia dwoch podanych jako argumenty zadan. */
bool porownajQ(Zadanie zad1, Zadanie zad2) {
	return zad1._q > zad2._q;
}

/* Funkcja przyjmujaca jako argumenty wektor do posortowania, poczatek i koniec sortowanego obszaru (jako odleglosc od poczatku wektora) oraz
   zmienna identyfikujaca typ sortowania: 1 - wg czasu przybycia, 2 - wg czasu dostarczenia. Wykorzystuje biblioteczna funkcje sort. */
void sortowanie(vector<Zadanie> &wektor, int start, int stop, int typ) {
	if (typ == 1)
		sort(wektor.begin()+start,wektor.begin()+stop,porownajR);
	else 
		sort(wektor.begin()+start,wektor.begin()+stop,porownajQ);
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

/* Funkcja implementujaca algorytm Schrage. Jako argument przyjmuje wektor przechowujacy liste wszystkich zadan. */
int schrage(vector<Zadanie> &wektor) {
	int czas, start, stop;			// zmienne przechowujace obecny czas oraz pomocnicze indeksy do zakresu sortowania
	sortowanie(wektor,0,wektor.size(),1);		// sortowanie zadan wg R
	for (int i = 1; i < wektor.size(); i++) {		
		int j = i;
		while (wektor[i-1]._r == wektor[i]._r)	// wyznaczanie zakresow wg R, przeznaczonych do sortowania wg Q
			i++;
		sortowanie(wektor,j,i,2);		// sortowanie wg Q
	}
	wektor[0]._k = wektor[0]._s + wektor[0]._p;	// wykonanie pierwszego zadania z posortowanej listy
	czas = wektor[0]._k;				// ustawienie czasu na koniec pierwszego zadania
	wektor[0]._done = true;
	wektor[0]._ready = true;
	wektor[0]._f = wektor[0]._k + wektor[0]._q;
	start = 1; 					// indeks pomocniczy uzywany do przechodzenia po kolejnych zadaniach
	while (!czyWszystkie(wektor)) {			// petle wykonujemy dopoki wszystkie zadania nie zostana wykonane
		stop = -1;				// indeks pomocniczy do sortowan
		for (int i = start; i < wektor.size(); i++)
			if (wektor[i]._r <= czas) {
				wektor[i]._ready = true;
				stop = i+1;		// wyznaczanie indeksu ostatniego gotowego zadania
			}
		if (wektor[start]._ready) {			// jesli najblizsze zadanie jest juz gotowe to je wykonujemy
			sortowanie(wektor,start,stop,2);	// sortowanie obecnie dostepnych zadan
			if (wektor[start]._r > wektor[start-1]._k)	// wykonanie najswiezszego (po sortowaniu - indeks bez zmian) zadania
				wektor[start]._s = wektor[start]._r;
			else
				wektor[start]._s = wektor[start-1]._k;
			wektor[start]._k = wektor[start]._s + wektor[start]._p;
			wektor[start]._done = true;
			wektor[start]._f = wektor[start]._k + wektor[start]._q;	// wyznaczenie faktycznego czasu dostarczenia zadania
		}	
		if (!wektor[start]._ready)		// jesli najblizsze zadanie nie jest jeszcze gotowe to czas rosnie o jeden
			czas++;
		else {
			czas = wektor[start]._k;	// jesli zadanie zostalo wykonane, to obecny czas = koniec zadania i zwiekszamy indeks
			start++;
		}
	}
	int wynik = czas;		// koncowy czas pierwszej czesci algorytmu - czas zakonczenia ostatniego z zadan
	for (int i = 0; i < wektor.size(); i++)	// szukamy czasu dostarczenia ktory moglby wydluzyc koncowy czas
		if (wektor[i]._f > wynik)
			wynik = wektor[i]._f;
	return wynik;		// zwracamy finalny czas
}

int main() {
	int wynik;			// zmienna przechowujaca koncowy wynik
	vector<Zadanie> ListaZadan;	// wektor przechowujacy wszystkie zadania

	if (!wczytaj(ListaZadan))	// w przypadku nieudanego wczytania pliku konczymy dzialanie programu
		return -1;

	wynik = schrage(ListaZadan);	// wywolanie wlasciwego algorytmu	

	cout << endl << "Dostarczenie ostatniego zadania: " << wynik << endl << endl;	// wyswietlenie wyniku

	generujPlikZRozwiazaniem(wynik);		// generowanie pliku z wynikiem

	return 0;
}
