#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_LICZBA_MASZYN 22 		// maksymalna liczba maszyn powiekszona o 2 (w celach obliczeniowych)
#define MAX_LICZBA_ZADAN 502 		// maksymalna liczba zadan powiekszona o 2 (w celach obliczeniowych)

class Zadanie {
public:
	int czas_trwania;
	int laczny_czas;
	int numer_zadania;
};

// globalne tablice statyczne do przechowywania zadan
Zadanie ZAD[1][MAX_LICZBA_MASZYN];		// tablica jednowymiarowa na pojedyncze zadanie (pojedynczy wiersz)
Zadanie R[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN]; // tablica zawierajaca macierz R (na potrzeby algorytmu NEH z akceleracja)
Zadanie Q[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN]; // tablica zawierajaca macierz Q (na potrzeby algorytmu NEH z akceleracja) 
Zadanie* Kolumna;				// wskaznik na pojedyncza kolumne pomocnicza

int l_zadan;		// globalnie przechowywana liczba zadan
int l_maszyn;		// globalnie przechowywana liczba maszyn

// funkcja przyjmuje jako argument lancuch przechowujacy nazwe pliku i zwraca 'true' jesli plik istnieje, 'false' w przeciwnym przypadku
bool plikIstnieje(const char *fileName) {
    fstream infile(fileName);
    return infile.good();
}
	
// funkcja wczytujaca dane z pliku o podanej nazwie
int wczytaj(char *nazwa, Zadanie tab[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN]) {
	int i;
	fstream plik;
	int n = -1;
	if (!plikIstnieje(nazwa)) {
		cout << "Bledna nazwa pliku." << endl;
		return n;
	}
	plik.open(nazwa,ios::in);
	plik >> n >> l_maszyn;
	l_zadan = n;
      	for (i = 0; i < l_zadan; i++) 
		for (int j = 0; j < l_maszyn; j++) {
			tab[i][j].numer_zadania = i+1;
			plik >> tab[i][j].czas_trwania;
		}
	cout << "Wczytano " << n << " danych." << endl;
	plik.close();	
	return n;
}

// funkcja tworzaca plik z wynikiem algorytmu
void generujPlikZRozwiazaniem(int wynik) {
	if (plikIstnieje("wynik.txt"))
		remove("wynik.txt");
	ofstream PLIK("wynik.txt");
	PLIK << wynik;
	PLIK.close();
}

// algorytm iteracyjnego wyznaczenia Cmax
int licz_Cmax(Zadanie tab[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], int l_zadan, int l_maszyn) {
	Zadanie tab_Cmax[MAX_LICZBA_ZADAN+1][MAX_LICZBA_MASZYN+1];
	for (int i = 0; i <= l_zadan; ++i)
		for (int j = 0; j <= l_maszyn; ++j)
			tab_Cmax[i][j].czas_trwania = 0;
	for (int i = 1; i <= l_zadan; ++i)
		for (int j = 1; j <= l_maszyn; ++j)
			tab_Cmax[i][j].czas_trwania = max(tab_Cmax[i-1][j].czas_trwania, tab_Cmax[i][j-1].czas_trwania) + 
							tab[i-1][j-1].czas_trwania;
    	return tab_Cmax[l_zadan][l_maszyn].czas_trwania;
}

// funkcja wstawiajaca wybrane zadanie przed podane zadanie w tablicy zadan 'tab'
void Wstaw_przed(Zadanie ZAD[1][MAX_LICZBA_MASZYN], Zadanie tab[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], 
int l_zadan, int l_maszyn, int numer_zadania) {
	// tworzenie miejsca w tablicy na nowe zadanie przez przesuwanie dalszych w prawo, nastepnie wstawienie zadania
	for (int i = l_zadan; i > numer_zadania; i--)
		for (int j = 0; j < l_maszyn; j++) {
			tab[i][j].czas_trwania = tab[i-1][j].czas_trwania;
			tab[i][j].numer_zadania = tab[i-1][j].numer_zadania;
		}
	for (int i = 0; i < l_maszyn; i++) {
		tab[numer_zadania][i].czas_trwania = ZAD[0][i].czas_trwania;
		tab[numer_zadania][i].numer_zadania = ZAD[0][i].numer_zadania;
	}
}

// tworzenie kopii tablicy tab1 w tablicy tab2
void tabKopia(Zadanie tab1[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], Zadanie tab2[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], 
int l_zadan, int l_maszyn) {
	for (int i = 0; i < l_zadan; i++)
		for (int j = 0; j < l_maszyn; j++) {
			tab2[i][j].numer_zadania = tab1[i][j].numer_zadania;
			tab2[i][j].czas_trwania = tab1[i][j].czas_trwania;
		}
}

// tworzenie kopii zadania z tablicy tab
void ZadanieKopia(Zadanie tab[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN],Zadanie ZAD[1][MAX_LICZBA_MASZYN],int l_maszyn,int numer) {
	for (int j = 0; j < l_maszyn; j++) {
		ZAD[0][j].numer_zadania = tab[numer][j].numer_zadania;
		ZAD[0][j].czas_trwania = tab[numer][j].czas_trwania;
	}
}

// tworzenie kopii zadania z kolumny
void KolumnaKopia(Zadanie tab[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], Zadanie* Kolumna, int l_zadan, int numer) {
	for (int j = 0; j < l_zadan; j++) {
		Kolumna[j].numer_zadania = tab[j][numer].numer_zadania;
		Kolumna[j].czas_trwania = tab[j][numer].czas_trwania;
		Kolumna[j].laczny_czas = tab[j][numer].laczny_czas;
	}
}

// wykorzystywana przy sortowaniu funkcja porownujaca laczne czasy wykonania zadan
bool porownaj_zadania(Zadanie pierwsze, Zadanie drugie) {
        return (pierwsze.laczny_czas > drugie.laczny_czas);
}

// algorytm NEH
int NEH(Zadanie tmp[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], Zadanie dane[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN]) {
	int minimum = 0;
	int Najlepsza_opcja = 0;
	for (int y = 1; y < l_zadan; y++) {
		ZadanieKopia(dane,ZAD,l_maszyn,(Kolumna[y].numer_zadania-1));		// pobranie zadania z tablicy
		Wstaw_przed(ZAD,tmp,y,l_maszyn,y);				// wstawianie skopiowanego zadania na koniec tmp
		int Cmax = licz_Cmax(tmp,y+1,l_maszyn);
		minimum = Cmax;					// minimalny Cmax
		Najlepsza_opcja = y;    		// po wstawieniu przed tym zadaniem uzyskamy minimalnego Cmaxa
		for (int k = y; k > 0; k--) {			// przesuwanie zadania i liczenie aktualnego Cmaxa
			for(int j = 0; j < l_maszyn; j++) {
				swap(tmp[k][j].czas_trwania,tmp[k-1][j].czas_trwania);
				swap(tmp[k][j].numer_zadania,tmp[k-1][j].numer_zadania);
			}
	            	Cmax = licz_Cmax(tmp,y+1,l_maszyn); 	// wyliczanie Cmax odbywa sie po kazdej zmianie w tablicy tmp
			if (Cmax <= minimum) {					// sprawdzenie nowego Cmaxa
				minimum = Cmax;
				Najlepsza_opcja = k-1;
			}
		}
		for (int i = 0; i < Najlepsza_opcja; i++)       // przesuniecie zadania z poczatku tablicy na wyznaczona optymalna pozycje
			for (int j = 0; j < l_maszyn; j++) {	// zrobienie miejsca na zadanie
				tmp[i][j].czas_trwania = tmp[i+1][j].czas_trwania;
				tmp[i][j].numer_zadania = tmp[i+1][j].numer_zadania;
			}
		for (int j = 0; j < l_maszyn; j++) {		// wstawienie zadania w powstala luke
			tmp[Najlepsza_opcja][j].czas_trwania = ZAD[0][j].czas_trwania;
			tmp[Najlepsza_opcja][j].numer_zadania = ZAD[0][j].numer_zadania;
		}
	}
	return minimum;
}

int main() {
	Zadanie dane[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN];
	Zadanie tmp[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN];
	int Cmax = 0;	
	int ilosc = 0;
	int minimum = 0;		// minimalny z Cmaxow
	int najlepsza_opcja = 0;	// najlepsze miejsce do wstawienia nowego zadania
	char *nazwa_we;				// nazwa pliku z danymi wejsciowymi
	nazwa_we = new char[60];
	cout << "Podaj nazwe pliku z danymi: ";
	cin >> nazwa_we;
	ilosc = wczytaj(nazwa_we,dane);
	if (ilosc <= 0)
		return -1;
	Kolumna = new Zadanie[l_zadan];		// wyliczenie sumy czasow wykonywania poszczegolnych zadan na wszystkich maszynach
	for (int i = 0; i < l_zadan; i++) {
		dane[i][0].laczny_czas = 0;
		for (int j = 0; j < l_maszyn; j++)
			dane[i][0].laczny_czas += dane[i][j].czas_trwania;
	}
	KolumnaKopia(dane,Kolumna,l_zadan,0);	// kopiowanie kolumny i sortowanie zadan od tego o najwiekszej sumie czasow wykonywania
	stable_sort(Kolumna,Kolumna+l_zadan,porownaj_zadania); 	// wykorzystanie stable_sort dla optymalnego czasu sortowania
	// posortowanie umozliwia odczytanie kolejnosci zadan (Kolumna zawiera numery zadan w odpowiedniej kolejnosci)
	// wstawianie zadan do tab we wczesniej ustalonej kolejnosci
	for(int k = 0; k < l_maszyn; k++) {
		tmp[0][k].czas_trwania = dane[Kolumna[0].numer_zadania-1][k].czas_trwania;
		tmp[0][k].numer_zadania = dane[Kolumna[0].numer_zadania-1][k].numer_zadania;
	}
	//Cmax = NEHakceleracja(tmp,dane);
	Cmax = NEH(tmp,dane);
	cout << "Koncowy wynik to: " << Cmax << endl;
	return 0;
}
