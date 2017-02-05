#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

// klasa modelująca pojedynczą operację
class Operacja {
public:
	int numer, czas, l_poprz, cmax;	// numer operacji, czas wykonania, liczba poprzedników, cmax
	bool wtopo;	// czy jest już w kolejce?
	Operacja():numer(-1),czas(-1),l_poprz(0),cmax(-1),wtopo(false) {}
	Operacja(int n, int t):numer(n),czas(t),l_poprz(0),cmax(0),wtopo(false) {}
};

// klasa odpowiadająca za działanie algorytmu
class INSA {
public:
	int ln, lm, cmax;		// liczba operacji, liczba maszyn, cmax
	vector<Operacja*> op;		// wektor operacji
	deque<int> k;			// kolejka topologiczna
	int t[750], m[750], pt[750], pm[750];	// tablice odpowiednio nastepnikow technologicznych i maszynowych oraz poprzednikow
	INSA() { 
		ln = lm = cmax = 0; 
		for (int i = 0; i > 750; i++) 
			t[i] = m[i] = pt[i] = pm[i] = 0; 
		op.clear();
		k.clear();
	}

	// metoda sprawdzająca czy wszystkie zadania zostały już dodane do kolejki
	bool wszystkowtopo() {
		for (int i = 0; i < ln; i++)
			if (!op[i]->wtopo)
				return false;
		return true;
	}	
	
	// metoda sprawdzająca czy wszystkie zadania mają już wyliczony cmax
	bool wszystkoc() {
		for (int i = 0; i < ln; i++)
			if (op[i]->cmax == 0)
				return false;
		return true;
	}

	void wypelnijtopo() {
		for (int i = 0; i < ln; i++) { 
			if (op[i]->l_poprz == 0 && !op[i]->wtopo) {
				k.push_back(op[i]->numer);
				op[i]->wtopo = true;
				if (t[i])
					op[t[i]-1]->l_poprz--;
				if (m[i])
					op[m[i]-1]->l_poprz--;
			}
		}
	}

	// funkcja wyznaczająca kolejność topologiczną
	void ustawtopo() {
		wypelnijtopo();
		while (!k.empty()) {
			for (int i = 0; i < ln; i++)
				if (op[i]->l_poprz == 0 && !op[i]->wtopo) {
					k.push_back(op[i]->numer);
					op[i]->wtopo = true;
					if (t[i])
						op[t[i]-1]->l_poprz--;
					if (m[i])
						op[m[i]-1]->l_poprz--;
				}
			int i = k.front()-1;
			k.pop_front();
			int poprzt = pt[i] > 0 && pt[i] <= ln ? op[pt[i]-1]->cmax : 0;
			int poprzm = pm[i] > 0 && pm[i] <= ln ? op[pm[i]-1]->cmax : 0;
			op[i]->cmax = max(poprzt,poprzm) + op[i]->czas;
			if (op[i]->cmax > cmax)
				cmax = op[i]->cmax;
		}
	}

	// metoda sprawdzająca czy plik o podanej jako argument nazwie istnieje
	bool plikIstnieje(const char *nazwa) {
	    fstream plik(nazwa);
	    return plik.good();
	}

	// metoda wczytująca dane z pliku o podanej jako argument nazwie
	int wczytaj(char *nazwa) {
		int pom;
		fstream plik;
		ln = -1;
		if (!plikIstnieje(nazwa)) {
			cout << "Bledna nazwa pliku." << endl;
			return ln;
		}
		plik.open(nazwa,ios::in);
		plik >> ln;
	      	for (int i = 0; i < ln; i++) {
			plik >> pom; 
			t[i] = pom;
		}
	      	for (int i = 0; i < ln; i++) {
			plik >> pom; 
			m[i] = pom;
		}
	      	for (int i = 0; i < ln; i++) {
			plik >> pom; 
			op.push_back(new Operacja(i+1,pom));
		}
		plik >> lm;
		cout << "Wczytano " << ln << " danych." << endl;
		plik.close();
		for (int i = 0; i < ln; i++) {
			int nr = t[i];
			if (nr > 0 && nr <= ln) {
				pt[nr-1] = i+1;
				op[nr-1]->l_poprz++;
			}
			else
				pt[nr-1] = 0;
			nr = m[i];
			if (nr > 0 && nr <= ln) {
				pm[nr-1] = i+1;
				op[nr-1]->l_poprz++;
			}
			else
				pm[nr-1] = 0;
		}
		return ln;
	}

	// pomocnicza metoda wypisująca potrzebne informacje
	void wypisz() {
		cout << "Topologiczne:";
		for (int i = 0; i < k.size(); i++)
			cout << k[i] << " ";
		cout << endl;
		cout << "Op   " << "p   " << "NT   " << "PT   " << "NM   " << "PM   " << "LP   " << endl;
		for (int i = 0; i < ln; i++)
			cout << op[i]->numer << "    " << op[i]->czas << "   " << t[i] << "    " << pt[i] << "    " << m[i] << "    " 
				<< pm[i] << "    " << op[i]->l_poprz << "    " << endl;
		cout << endl;
	}

	// metoda generująca plik z rozwiązaniem
	void generujPlikZRozwiazaniem() {
		if (plikIstnieje("wynik.txt"))
			remove("wynik.txt");
		ofstream plik("wynik.txt");
		for (int i = 0; i < ln; i++)
			plik << op[i]->cmax - op[i]->czas << " " << op[i]->cmax << endl;
		plik << cmax << endl;
		plik.close();
	}
};

int main() {
	INSA insa;
	char *nazwa_we;				
	nazwa_we = new char[60];
	cout << "Podaj nazwe pliku z danymi: ";
	cin >> nazwa_we;
	if (insa.wczytaj(nazwa_we) <= 0)
		return -1;
	insa.ustawtopo();
	insa.generujPlikZRozwiazaniem();
	cout << "Koncowy wynik to: " << insa.cmax << endl;
	return 0;
}
