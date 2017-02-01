#include "Graf.h"
;

Graf::Graf() {
	start = 0;
	wierzcholki.resize(0);
	krawedzie.resize(0);
	int ilosckrawedzi = GESTOSC*ROZMIAR*(ROZMIAR-1)/200;	// wyznaczanie ilosci krawedzi w grafie
	for (int i = 0; i < ROZMIAR; i++) {
		int d = rand() % 100 + 1;
		Vertex* nowy = new Vertex(i,d);	// identyfikatory wierzcholkow numerowane od 0
		wierzcholki.push_back(nowy);
	}
/*	Generowanie krawedzi opracowane jest w taki sposob, by generowany graf zawsze byl spojny bez przeprowadzania scislej kontroli
	podczas tworzenia zbioru krawedzi. */
	for (int i = 0; i < ilosckrawedzi; i++) {
		int pocz = i % ROZMIAR;
		int kon = pocz + 1 + (i/ROZMIAR);
		if (kon >= ROZMIAR)
			kon -= ROZMIAR;
		int waga = rand() % 100 + 1;
		Edge* nowa = new Edge(i+1,wierzcholki[pocz],wierzcholki[kon],waga);
		krawedzie.push_back(nowa);
	}
}

GrafM::GrafM() : Graf() {
	wypelnij();
}

GrafL::GrafL() : Graf() {
	wypelnij();
}

Vertex* Graf::getMinWierzcholek() {
	Vertex* wynik = NULL;
	int min = 9999999999 + ROZMIAR;
	for (int i = 0; i < wierzcholki.size(); i++)
		if (!wierzcholki[i]->odwiedzony && wierzcholki[i]->droga < min) {
			wynik = wierzcholki[i];
			min = wierzcholki[i]->droga;
		}
	return wynik;
}

bool Graf::odczyt() {
	fstream plik("../pliki/zapis.txt",ios::in);
	int rozmiar, ilosckrawedzi, poczatek;
	if (plik.good()) {
		plik >> ilosckrawedzi;
		if (ilosckrawedzi !=  GESTOSC*ROZMIAR*(ROZMIAR-1)/200) {
			cout << "Niewlasciwa ilosc krawedzi w pliku." << endl;
			return false;
		}
		plik >> rozmiar;
		if (rozmiar != ROZMIAR) {
			cout << "Niewlasciwy rozmiar grafu w pliku." << endl;
			return false;
		}
		plik >> poczatek;
		if (poczatek < 0 || poczatek > ROZMIAR-1) {
			cout << "Niewlasciwy wierzcholek poczatkowy." << endl;
			return false;
		}
		wierzcholki.clear();
		krawedzie.clear();
		for (int i = 0; i < rozmiar; i++) {
			int d = rand() % 100 + 1;
			Vertex* nowy = new Vertex(i,d);
			wierzcholki.push_back(nowy);
		}
		for (int i = 0; !plik.eof() && i < ilosckrawedzi; i++) {
			int p, k, w;
			plik >> p;
			plik >> k;
			plik >> w;
			Edge* nowa = new Edge(i+1,wierzcholki[p],wierzcholki[k],w);
			krawedzie.push_back(nowa);
		}
	}
	else {
		cout << "Nie udalo sie otworzyc pliku." << endl;
		return false;
	}
	if (krawedzie.size() == ilosckrawedzi && wierzcholki.size() == rozmiar)
		return true;
	else {
		cout << "Graf wczytany niepoprawnie." << endl;
		return false;
	}
}

void GrafM::wypelnij() {
	for (int i = 0; i < ROZMIAR; i++)
		for (int j = 0; j < ROZMIAR; j++)
			tablica[i][j] = NULL;
// odpowiednie krawedzie dodawane sa do tablicy dwukrotnie, by macierz incydencji byla symetryczna (graf nieskierowany)
	for (int i = 0; i < krawedzie.size(); i++) {
		tablica[krawedzie[i]->getA()->getNumer()][krawedzie[i]->getB()->getNumer()] = krawedzie[i];
		tablica[krawedzie[i]->getB()->getNumer()][krawedzie[i]->getA()->getNumer()] = krawedzie[i];
	}
}

bool GrafM::odczyt() {
	if (Graf::odczyt()) {
		wypelnij();
		return true;
	}
	return false;
}

void GrafM::getMacierz() {
	for (int i = 0; i <= ROZMIAR; i++)
		if (i > 0) {
			cout.width(5);
			cout << internal << i-1;
		}
		else {
			cout.width(5);
			cout << "";
		}
	cout << endl << endl;
	int k = 0;
	for (int i = 0; i < ROZMIAR; i++) {
		cout.width(5);
		cout << internal << k;
		k++;
		cout << "";
		for (int j = 0; j < ROZMIAR; j++) {
			Edge* pom = tablica[i][j];
			if (pom != NULL) {
				cout.width(5);
				cout << internal << pom->getWaga();
			}
			else {
				cout.width(5);
				cout << 0;
			}
		}
		cout << endl;
	}
}

void GrafL::wypelnij() {
	for (int i = 0; i < wierzcholki.size(); i++) {
		wierzcholki[i]->lista.resize(0);
		wierzcholki[i]->lista.reserve(2*ROZMIAR);	
	}
// odpowiednie krawedzie dodawane sa do list sasiedztwa wierzcholkow na obu koncach (graf nieskierowany)
	for (int i = 0; i < krawedzie.size(); i++) {
		Edge* pom = krawedzie[i]; 
		int pocz = pom->getA()->getNumer();
		int kon = pom->getB()->getNumer();
		Graf::getWierzcholekNr(pocz)->lista.push_back(pom);
		Graf::getWierzcholekNr(kon)->lista.push_back(pom);
	} 
}

bool GrafL::odczyt() {
	if (Graf::odczyt()) {
		wypelnij();
		return true;
	}
	return false;
}

void Graf::getWierzcholki() {
	for (int i = 0; i < wierzcholki.size(); i++)
		cout << "Nr: " << wierzcholki[i]->getNumer() << " Dane: " << wierzcholki[i]->getDane() << endl;
}

void Graf::getKrawedzie() {
	for (int i = 0; i < krawedzie.size(); i++)
		cout << "Nr: " << krawedzie[i]->getNumer() << " Poczatek: " << krawedzie[i]->getA()->getNumer() << " Koniec: " << krawedzie[i]->getB()->getNumer() << " Waga: " << krawedzie[i]->getWaga() << endl;
}

bool Graf::zapis() {
	fstream plik("../pliki/zapis.txt",ios::out);
	if (plik.good()) {
		plik << krawedzie.size() << " " << ROZMIAR << " " << start << endl;
		for (int i = 0; i < krawedzie.size(); i++)
			plik << krawedzie[i]->getA()->getNumer() << " " << krawedzie[i]->getB()->getNumer() << " " << krawedzie[i]->getWaga() << endl;
	}
	else {
		cout << "Nie udalo sie otworzyc pliku." << endl; 
		return false;
	}
	plik.close();
// tworzenie plikow ze sciezkami dla kazdego z wierzcholkow
	for (int i = 0; i < wierzcholki.size(); i++) {
		fstream pliczek("../pliki/sciezki/"+to_string(i)+".txt.",ios::out);
		int pom = wierzcholki[i]->getNumer();
		while (pom != start) {
			wierzcholki[i]->sciezka.push_back(getWierzcholekNr(poprzednik[pom]));
			pom = poprzednik[pom];
		}
		if (wierzcholki[i]->droga < 9999999999) {
			pliczek << wierzcholki[i]->droga << endl;
			for (int j = wierzcholki[i]->sciezka.size()-1; j >= 0; j--)
				pliczek << wierzcholki[i]->sciezka[j]->getNumer() << endl;
			pliczek << wierzcholki[i]->getNumer();
			pliczek.close();
		}
		else {
			pliczek << "nie ma sciezki" << endl;
			pliczek.close();
		}
	}
	return true;
}

void Graf::insertVertex(int d) { 
	if (ROZMIAR > wierzcholki.size()) {
		int indeks = -1;
		int zajete[ROZMIAR];
// fragment kodu odpowiedzialny za wyszukanie zajetych indeksow - wykorzystywane potem do znajdowania najnizszego wolnego
		for (int i = 0; i < wierzcholki.size(); i++)
			zajete[wierzcholki[i]->getNumer()] = 1;
		for (int i = 0; i < ROZMIAR && indeks < 0; i++)
			if (zajete[i] != 1)
				indeks = i;
		wierzcholki.push_back(new Vertex(indeks,d));
	}
	else 
		cout << "Graf kompletny." << endl; 
}

void Graf::removeVertex(Vertex* v) {
// sprawdzanie czy graf nie jest pusty
	if (wierzcholki.size() <= 0) {
		cout << "Graf pusty." << endl;
		return;
	}
// sprawdzanie czy zadany wierzcholek nalezy do grafu
	bool jest = false;
	for (int i = 0; i < wierzcholki.size() && !jest; i++)
		if (wierzcholki[i] == v)
			jest = true;
	if (!jest) {
		cout << "Wierzcholek nie nalezy do grafu." << endl;
		return;
	}
// usuwanie wierzcholka i powiazanych z nim krawedzi
	for (int i = 0; i < krawedzie.size(); i++)
		if (krawedzie[i]->getA() == v || krawedzie[i]->getB() == v) {
			krawedzie.erase(krawedzie.begin()+i);
			i--;
		}
		wierzcholki.erase(wierzcholki.begin()+v->getNumer());
}

void Graf::insertEdge(Vertex* v, Vertex* w, int waga) {
// kontrola czy oba wierzcholki naleza do grafu i czy nie laczy ich juz krawedz
	bool jest, jest2;
	jest = jest2 = false;
	for (int i = 0; i < wierzcholki.size() && (!jest || !jest2); i++) {
		if (wierzcholki[i] == v)
			jest = true;
		if (wierzcholki[i] == w)
			jest2 = true;
	}
	if (!(jest && jest2)) {
		cout << "Bledne wierzcholki." << endl;
		return;
	}
	if (areAdjacent(v,w)) {
		cout << "Podane wierzcholki sa juz sasiadami." << endl;
		return;
	}
	const int ilosckrawedzi = ROZMIAR*(ROZMIAR-1)*GESTOSC/200;
	if (ilosckrawedzi > krawedzie.size()) {
		int indeks = -1;
		int zajete[ilosckrawedzi];
// fragment kodu odpowiedzialny za wyszukanie zajetych indeksow - wykorzystywane potem do znajdowania najnizszego wolnego
		for (int i = 0; i < krawedzie.size(); i++)
			zajete[krawedzie[i]->getNumer()-1] = 1;
		for (int i = 0; i < ilosckrawedzi && indeks < 0; i++)
			if (zajete[i] != 1)
				indeks = i+1;
		krawedzie.push_back(new Edge(indeks,v,w,waga));
	}
	else 
		cout << "Graf kompletny." << endl; 
}

void Graf::removeEdge(Edge* e) {
// sprawdzenie czy graf nie jest pusty
	if (krawedzie.size() <= 0) {
		cout << "Graf pusty." << endl;
		return;
	}
// fragment kodu sprawdzajacy czy podana krawedz nalezy do grafu oraz ewentualne zapamietywanie jej indeksu
	bool jest = false;
	int indeks = -1;
	for (int i = 0; i < krawedzie.size() && !jest; i++)
		if (krawedzie[i] == e) {
			jest = true;
			indeks = i;
		}
	if (!jest) {
		cout << "Podana krawedz nie nalezy do grafu." << endl;
		return;
	}
	krawedzie.erase(krawedzie.begin()+indeks);		// usuwanie krawedzi
}

void GrafM::Dijkstra() {
// poczatkowe ustawianie drogi dla kazdego wierzcholka oraz wypelnianie kolejki priorytetowej
	for (int i = 0; i < wierzcholki.size(); i++) {
		if (wierzcholki[i]->getNumer() == start)
			wierzcholki[i]->droga = 0;
		else
			wierzcholki[i]->droga = 9999999999 + i;
		poprzednik[i] = start;
	}
// kod wlasciwego algorytmu
	for (int i = 0; i < wierzcholki.size(); i++) {
	// biorac kolejno wierzcholki z kolejki priorytetowej relaksujemy wzgledem nich pozostale wierzcholki
		Vertex* pom = getMinWierzcholek();
	// kolejka priorytetowa symulowana przez zwykly vector (wyciaganie z niego najmniejszej wartosci poprzez zwykle szukanie minimum i pilnowanie 
	// by nie zwrocic wierzcholka juz odwiedzonego)
		pom->odwiedzony = true;
		for (int i = 0; i < ROZMIAR; i++) 
			if (tablica[pom->getNumer()][i] != NULL) {
				Edge* kra = tablica[pom->getNumer()][i];
				if (kra->getA() == pom) {
					if (kra->getB()->droga > (kra->getWaga() + pom->droga)) {
						kra->getB()->droga = kra->getWaga() + pom->droga;
						poprzednik[kra->getB()->getNumer()] = kra->getA()->getNumer();
					}
				}
				else 
					if (kra->getA()->droga > (kra->getWaga() + pom->droga)) {
						kra->getA()->droga = kra->getWaga() + pom->droga;
						poprzednik[kra->getA()->getNumer()] = kra->getB()->getNumer();
					}
			}
	}
}

void GrafL::Dijkstra() {
// poczatkowe ustawianie drogi dla kazdego wierzcholka oraz wypelnianie kolejki priorytetowej
	for (int i = 0; i < wierzcholki.size(); i++) {
		if (wierzcholki[i]->getNumer() == start)
			wierzcholki[i]->droga = 0;
		else
			wierzcholki[i]->droga = 9999999999 + i;
		poprzednik[i] = start;
	}
// kod wlasciwego algorytmu
	for (int i = 0; i < wierzcholki.size(); i++) {		
	// biorac kolejno wierzcholki z kolejki priorytetowej relaksujemy wzgledem nich pozostale wierzcholki
		Vertex* pom = getMinWierzcholek();		
	// kolejka priorytetowa symulowana przez zwykly vector (wyciaganie z niego najmniejszej wartosci poprzez zwykle szukanie minimum i pilnowanie 
	// by nie zwrocic wierzcholka juz odwiedzonego)
		pom->odwiedzony = true;
		for (int i = 0; i < pom->lista.size(); i++) {
			Edge* kra = pom->lista[i]; 
			if (kra->getA() == pom) {
				if (kra->getB()->droga > (kra->getWaga() + pom->droga)) {
					kra->getB()->droga = kra->getWaga() + pom->droga;
					poprzednik[kra->getB()->getNumer()] = kra->getA()->getNumer();
				}
			}
			else 
				if (kra->getA()->droga > (kra->getWaga() + pom->droga)) {
					kra->getA()->droga = kra->getWaga() + pom->droga;
					poprzednik[kra->getA()->getNumer()] = kra->getB()->getNumer();
				}
		}
	}
}

void GrafM::BellFord() {
// poczatkowe ustawianie drogi dla kazdego wierzcholka oraz wypelnianie kolejki priorytetowej
	for (int i = 0; i < wierzcholki.size(); i++) {
		if (wierzcholki[i]->getNumer() == start)
			wierzcholki[i]->droga = 0;
		else
			wierzcholki[i]->droga = 9999999999 + i;
		poprzednik[i] = start;
	}
// kod wlasciwego algorytmu
	for (int i = 0; i < wierzcholki.size(); i++)		// tyle razy ile mamy wierzcholkow
		for (int j = 0; j < ROZMIAR; j++)
			for (int k = j+1; k < ROZMIAR; k++)
				if (tablica[j][k] != NULL) {
			// przegladamy wszystkie krawedzie
					Edge* kra = tablica[j][k];
					Vertex* pom = kra->getA();
					Vertex* pom2 = kra->getB();
					int odl = pom->droga;
			// i przeprowadzamy relaksacje wierzcholkow, ktore ona laczy
					if (pom->droga > (kra->getWaga() + pom2->droga)) {
						pom->droga = kra->getWaga() + pom2->droga;
						poprzednik[pom->getNumer()] = pom2->getNumer();
						}
					if (pom2->droga > (kra->getWaga() + pom->droga)) {
						pom2->droga = kra->getWaga() + pom->droga;
						poprzednik[pom2->getNumer()] = pom->getNumer();
					}
				}
}

void GrafL::BellFord() {
// poczatkowe ustawianie drogi dla kazdego wierzcholka oraz wypelnianie kolejki priorytetowej
	for (int i = 0; i < wierzcholki.size(); i++) {
		if (wierzcholki[i]->getNumer() == start)
			wierzcholki[i]->droga = 0;
		else
			wierzcholki[i]->droga = 9999999999 + i;
		poprzednik[i] = start;
	}
// kod wlasciwego algorytmu
	for (int i = 0; i < wierzcholki.size(); i++)		// tyle razy ile mamy wierzcholkow
		for (int j = 0; j < wierzcholki.size(); j++)
			for (int k = 0; k < wierzcholki[j]->lista.size(); k++) {
		// przegladamy wszystkie krawedzie
				Edge* kra = wierzcholki[j]->lista[k];
				Vertex* pom = kra->getA();
				Vertex* pom2 = kra->getB();
				int odl = pom->droga;
		// i przeprowadzamy relaksacje wierzcholkow, ktore ona laczy
				if (pom->droga > (kra->getWaga() + pom2->droga)) {
					pom->droga = kra->getWaga() + pom2->droga;
					poprzednik[pom->getNumer()] = pom2->getNumer();
					}
				if (pom2->droga > (kra->getWaga() + pom->droga)) {
					pom2->droga = kra->getWaga() + pom->droga;
					poprzednik[pom2->getNumer()] = pom->getNumer();
				}
			}
}