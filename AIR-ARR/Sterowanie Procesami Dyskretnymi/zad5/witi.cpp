#include <cmath>		
#include <iostream>		
#include <fstream>		

#define MAX 99999999	// zmienna pomocnicza do wyznaczania minimum

using namespace std;

/* Funkcja przyjmuje jako argument lancuch przechowujacy nazwe pliku i zwraca 'true' jesli plik istnieje, 'false' w przeciwnym przypadku. */
bool plikIstnieje(const char *fileName) {
    fstream infile(fileName);
    return infile.good();
}

/* Funkcja przyjmuje jako argument lancuch przechowujacy nazwe pliku. Jej zadaniem jest wczytanie danych z podanego pliku do podanej jako     	 argument tablicy. Zwraca liczbe wczytanych danych lub -1 dla niepowodzenia. */
int wczytaj(char *nazwa, long int** & tab) {
	int i;
	fstream plik;
	int n = -1;
	if (!plikIstnieje(nazwa)) {
		cout << "Bledna nazwa pliku." << endl;
		return n;
	}
	plik.open(nazwa,ios::in);
	plik >> n;
      	for (i = 0; i < n; i++) {
		plik >> tab[i][0];	
		plik >> tab[i][1];
		plik >> tab[i][2];
	}
	cout << "Wczytano " << n << " danych." << endl;
	plik.close();	
	return n;
}

/* Funkcja ma za zadanie utworzyc plik z wynikiem dzialania algorytmu wiTi, ktory to wynik jest przekazany do niej jako argument. */
void generujPlikZRozwiazaniem(int wynik) {
	if (plikIstnieje("wynik.txt"))
		remove("wynik.txt");
	ofstream PLIK("wynik.txt");
	PLIK << wynik;
	PLIK.close();
}

long int tab_obliczen[33554433][3];		// tablica zawierajaca ponad 2^25 wierszy

int main() {	
	int ilosc, wynik = MAX;			// zmienne okreslajaca liczbe zadan oraz koncowy wynik
	long int liczba_permutacji;		// zmienna okreslajaca liczbe permutacji
	double base = 2;			// podstawa do potegowania	
	long int temp_r, mini, mini_2 = -1;
	long int **tab_zadan = new long int * [25]; 	// tablica przechowujaca dane na temat zadan (p, k, q - wykonanie, kara, termin)
    	long int **tab_poteg = new long int * [26]; 	// tablica zawierajaca w 1 kolumnie wartosci minimalne i czasy w drugiej
    	for (int j = 0; j < 26; j++) {
   		tab_poteg[j] = new long int[2];
   		if (j < 25) 
			tab_zadan[j] = new long int[3]; 
	}
	char *nazwa_we;				// nazwa pliku z danymi wejsciowymi
	nazwa_we = new char[60];
	cout << "Podaj nazwe pliku z danymi: ";
	cin >> nazwa_we;
	ilosc = wczytaj(nazwa_we,tab_zadan);
	if (ilosc <= 0)
		return -1;
	liczba_permutacji = pow(base,ilosc);			// wyliczenie liczby permutacji
	tab_poteg[ilosc-1][0] = liczba_permutacji / 2;		// wpisanie informacji do tablicy poteg
	liczba_permutacji--;					// liczba permutacji jest teraz mniejsza
	for (int i = ilosc-2; i >= 0; i--) {			// wyliczenie wartosci w tablicy poteg
		tab_poteg[i][0] = tab_poteg[i+1][0] / 2;
    		tab_poteg[i][1] = tab_poteg[i][0];
    		tab_poteg[i+1][1] = liczba_permutacji - tab_poteg[i+1][0];
	}
	tab_poteg[0][0] = 1;					// uzupelnienie pozostalych pol tablicy poteg
	tab_poteg[0][1] = liczba_permutacji-1;
	tab_poteg[ilosc][0] = MAX;
	for (int i = 1; i <= liczba_permutacji; i++) {
		int j = 0;
		mini = MAX;
		mini_2 = -1;
		while (tab_poteg[j][0] <= i) {	
			temp_r = (tab_zadan[j][0] + tab_obliczen[tab_poteg[j][1]&i][1] - tab_zadan[j][2]) * tab_zadan[j][1];
			if (temp_r < 0)
				temp_r = 0;
			temp_r = temp_r + tab_obliczen[tab_poteg[j][1]&i][0];	
			if (temp_r < mini) {
				mini = temp_r;
				mini_2 = j;
			}		
			j++;
		}
		if (mini_2 >= 0) {	
			tab_obliczen[i][0] = mini;
			tab_obliczen[i][1] = tab_obliczen[tab_poteg[mini_2][1]&i][1] + tab_zadan[mini_2][0];
			tab_obliczen[i][2] = tab_poteg[mini_2][1]&i;
		}
		tab_obliczen[i+1][0] = MAX;
		tab_obliczen[i+1][1] = MAX;
	}
	wynik = wynik < tab_obliczen[liczba_permutacji][0] ? wynik : tab_obliczen[liczba_permutacji][0];
	mini = liczba_permutacji;				// zapisanie pozycji minimalnej
	int i = 1;
	while (mini != 0) {
		tab_zadan[ilosc-i][0] = mini;
		mini = tab_obliczen[mini][2];
		i++;
	}
	liczba_permutacji = 0;
	cout << "Koncowy wynik to: " << wynik << endl;
	generujPlikZRozwiazaniem(wynik);
	for (int j = 0; j < 26; j++) {
     		if (j < 25) 
			delete [] tab_zadan[j];
     		delete [] tab_poteg[j];
	}
    	delete [] tab_poteg;
    	delete [] tab_zadan;
	return 0;
}
