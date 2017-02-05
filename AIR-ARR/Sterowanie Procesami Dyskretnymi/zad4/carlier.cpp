#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

// struktura modelująca zadanie, przechowuje informacje o numerze zadania, jego czasie przybycia, wykonania i dostarczenia
struct zadanie {
	zadanie(void);
    	zadanie(int nn, int rr, int pp, int qq):n(nn),r(rr),p(pp),q(qq) {}
    	int n, r, p, q;
};

// struktura służąca do szeregowania zadań w kolejce priorytetowej wg czasu przybycia
class porownanie_r {
public:
	bool operator () (const zadanie &z1, const zadanie &z2) const { 
		return z1.r == z2.r ? z1.q < z2.q : z1.r > z2.r; 
	}
};

// struktura służąca do szeregowania zadań w kolejce priorytetowej wg czasu dostarczenia
class porownanie_q {
public:
	bool operator () (const zadanie &z1, const zadanie &z2) const { 
		return z1.q < z2.q; 
	}
};

// algorytm Schrage, wyznacza również element b
int schrage(const vector<int> &r, const vector<int> &p, const vector<int> &q, vector<int> &pi, int &b) {
	priority_queue<zadanie, vector<zadanie>, porownanie_r> N;
  	priority_queue<zadanie, vector<zadanie>, porownanie_q> G;
  	vector<int> c(r.size());
  	int cmax = 0, t = 0, k = 0;
  	pi.resize(r.size());
  	for (unsigned int i = 1; i < r.size(); ++i)
    		N.push(zadanie(i, r[i], p[i], q[i]));
  	while (!G.empty() || !N.empty()) {
    		while (!N.empty() && t >= N.top().r) {
      			G.push(N.top());
      			N.pop();
      		}
    		if (G.empty())
      			t = N.top().r;
    		else {
      			++k;
      			t += G.top().p;
      			cmax = max(cmax, t+G.top().q);
      			pi[k] = G.top().n;
      			c[pi[k]] = t;
      			G.pop();
      		}
    	}
  	for (b = c.size()-1; cmax != c[pi[b]] + q[pi[b]]; --b); /* wyznaczamy b */
  	return cmax;
}

// algorytm Schrage z podziałem
int preschrage(const vector<int> &r, const vector<int> &p, const vector<int> &q) {
  	priority_queue<zadanie, vector<zadanie>, porownanie_r> N;
  	priority_queue<zadanie, vector<zadanie>, porownanie_q> G;
  	for (unsigned int i = 1; i < r.size(); ++i)
    		N.push(zadanie(i, r[i], p[i], q[i]));
  	int czas = 0, cmax = 0;
  	zadanie biezace(0, 1, 1, 30000);
  	while (!G.empty() || !N.empty()) {
    		while (!N.empty() && N.top().r <= czas) {
      			G.push(N.top());
      			N.pop();
      			if (G.top().q > biezace.q) {
        			biezace.p = czas-G.top().r;
        			czas = G.top().r;
        			if (biezace.p > 0)
          				G.push(biezace);
        		}
      		}
    		if (G.empty())
      			czas = N.top().r;
    		else {
      			biezace = G.top();
      			czas += G.top().p;
      			cmax = max(cmax, czas+G.top().q);
      			G.pop();
      		}
    	}
  	return cmax;
}

// funkcja wyznaczająca element a
int wyznacz_a(const vector<int> &r, const vector<int> &p, const vector<int> &q, const vector<int> &pi, int b, int cmax) {
  	int a = 0, suma;
  	do {
    		++a;
    		suma = r[pi[a]]+q[pi[b]];
    		for (int s = a; s <= b; ++s)
      			suma += p[pi[s]];
    	}
  	while (cmax != suma);
  	return a;
}

// funkcja wyznaczająca zadanie referencyjne
int wyznacz_c(const vector<int> &q, const vector<int> &pi, int a, int b) {
 	for (int j = b; j >= a; --j)
    	if (q[pi[j]] < q[pi[b]])
      		return j;
  	return 0;
}

// pomocnicza funkcja wyznaczająca sumę czasów wykonania
int wyznacz_pp(const vector<int> &p, const vector<int> &pi, int b, int c) {
  	int pp = 0;
  	for (int j = c+1; j <= b; ++j)
   		pp += p[pi[j]];
  	return pp;
}

// funkcja sprawdzająca czy plik o podanej jako argument nazwie istnieje
bool plikIstnieje(const char *fileName) {
    	fstream infile(fileName);
    	return infile.good();
}

// funkcja wczytująca dane do podanych jako argumenty wektorów z pliku o podanej jako argument nazwie
int wczytaj(char *nazwa, vector<int> &r, vector<int> &p, vector<int> &q) {
	int i, j, rr, pp, qq;
	fstream plik;
	int n = -1;
	if (!plikIstnieje(nazwa)) {
		cout << "Bledna nazwa pliku." << endl;
		return n;
	}
	plik.open(nazwa,ios::in);
	plik >> n;
      	for (i = 0; i < n; ++i) {
		plik >> rr;
		plik >> pp;
		plik >> qq;
		r.push_back(rr);
		p.push_back(pp);
		q.push_back(qq);
	}
	cout << "Wczytano " << n << " danych." << endl;
	plik.close();	
	return n;
}

// algorytm Carliera
void carlier(vector<int> r, vector<int> p, vector<int> q, int &ub) {
  	int u, b, c;
  	vector<int> pi(1);
  	u = schrage(r, p, q, pi, b);
  	if (u < ub) 
   	 	ub = u;
  	if ((c = wyznacz_c(q, pi, wyznacz_a(r, p, q, pi, b, u), b))) { 
    		int rp, pp, qp, lb, rc = r[pi[c]], qc = q[pi[c]];
    		rp = r[pi[b]]; 
    		pp = wyznacz_pp(p, pi, b, c);
    		qp = q[pi[b]];
    		r[pi[c]] = max(r[pi[c]], rp+pp); 
    		lb = preschrage(r, p, q); 
    		if (lb < ub)
      			carlier(r, p, q, ub); 
    		r[pi[c]] = rc; 
    		q[pi[c]] = max(q[pi[c]], qp+pp); 
    		lb = preschrage(r, p, q); 
    		if (lb < ub) 
      			carlier(r, p, q, ub); 
    		q[pi[c]] = qc; 
    	}
}

// funkcja generująca plik z rozwiązaniem
void generujPlikZRozwiazaniem(int wynik) {
	if (plikIstnieje("wynik.txt"))
		remove("wynik.txt");
	ofstream PLIK("wynik.txt");
	PLIK << wynik;
	PLIK.close();
}

int main() {
	int ilosc;
	char *nazwa_we;		// nazwa pliku z danymi wejsciowymi
	vector<int> r(1), p(1), q(1);
	nazwa_we = new char[60];
	cout << "Podaj nazwe pliku z danymi: ";
	cin >> nazwa_we;
	ilosc = wczytaj(nazwa_we,r,p,q);
	if (ilosc <= 0)
		return -1;
	int wynik = 9999999;
	carlier(r,p,q,wynik);
	cout << "Czas dostarczenia ostatniego zadania: " << wynik << endl;
	generujPlikZRozwiazaniem(wynik);
	return 0;
  }
