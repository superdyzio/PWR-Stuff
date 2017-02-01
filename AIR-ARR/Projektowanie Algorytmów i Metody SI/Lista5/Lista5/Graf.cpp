#include "Graf.h"
;

Graf::Graf() {
	wierzcholki.resize(0);
	krawedzie.resize(0);
	int ilosckrawedzi = GESTOSC*ROZMIAR*(ROZMIAR-1)/200;	// wyznaczanie ilosci krawedzi w grafie
	for (int i = 1; i <= ROZMIAR; i++) {
		Vertex* nowy = new Vertex(i);	// identyfikatory wierzcholkow numerowane od 1
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

bool Graf::zapis(string nazwa) {
	fstream plik(nazwa,ios::out);
	if (plik.good()) {
		plik << ROZMIAR << endl;
		plik << krawedzie.size() << endl;
		for (int i = 0; i < ROZMIAR; i++)
			plik << wierzcholki[i]->getNumer() << endl;
		for (int i = 0; i < krawedzie.size(); i++)
			plik << krawedzie[i]->getNumer() << " " << krawedzie[i]->getA()->getNumer() << " " << krawedzie[i]->getB()->getNumer() << " " << krawedzie[i]->getWaga() << endl;
	}
	else {
		cout << "Nie udalo sie otworzyc pliku." << endl; 
		return false;
	}
	plik.close();
	return true;
}

bool Graf::odczyt(string nazwa) {
	fstream plik(nazwa,ios::in);
	int rozmiar, ilosckrawedzi;
	if (plik.good()) {
		plik >> rozmiar;
		if (rozmiar != ROZMIAR) {
			cout << "Niewlasciwy rozmiar grafu w pliku." << endl;
			return false;
		}
		plik >> ilosckrawedzi;
		if (ilosckrawedzi !=  GESTOSC*ROZMIAR*(ROZMIAR-1)/200) {
			cout << "Niewlasciwa ilosc krawedzi w pliku." << endl;
			return false;
		}
		wierzcholki.clear();
		krawedzie.clear();
		for (int i = 0; !plik.eof() && i < rozmiar; i++) {
			int n;
			plik >> n;
			Vertex* nowy = new Vertex(n);
			wierzcholki.push_back(nowy);
		}
		for (int i = 0; !plik.eof() && i < ilosckrawedzi; i++) {
			int n, p, k, w;
			plik >> n;
			plik >> p;
			plik >> k;
			plik >> w;
			Edge* nowa = new Edge(n,wierzcholki[p-1],wierzcholki[k-1],w);
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

void Graf::getWierzcholki() {
	for (int i = 0; i < wierzcholki.size(); i++)
		cout << "Nr: " << wierzcholki[i]->getNumer() << endl;
}

void Graf::getKrawedzie() {
	for (int i = 0; i < krawedzie.size(); i++)
		cout << "Nr: " << krawedzie[i]->getNumer() << " Poczatek: " << krawedzie[i]->getA()->getNumer() << " Koniec: " << krawedzie[i]->getB()->getNumer() << " Waga: " << krawedzie[i]->getWaga() << endl;
}

void GrafM::wypelnij() {
	for (int i = 0; i < ROZMIAR; i++)
		for (int j = 0; j < ROZMIAR; j++)
			tablica[i][j] = NULL;
// odpowiednie krawedzie dodawane sa do tablicy dwukrotnie, by macierz incydencji byla symetrycza (graf nieskierowany)
	for (int i = 0; i < krawedzie.size(); i++) {
		tablica[krawedzie[i]->getA()->getNumer()-1][krawedzie[i]->getB()->getNumer()-1] = krawedzie[i];
		tablica[krawedzie[i]->getB()->getNumer()-1][krawedzie[i]->getA()->getNumer()-1] = krawedzie[i];
	}
}

GrafM::GrafM() : Graf() {
	wypelnij();
}

void GrafM::getMacierz() {
	for (int i = 0; i <= ROZMIAR; i++)
		if (i > 0) {
			cout.width(5);
			cout << internal << i;
		}
		else {
			cout.width(5);
			cout << "";
		}
	cout << endl << endl;
	int k = 1;
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

bool GrafM::odczyt(string nazwa) {
	if (Graf::odczyt(nazwa)) {
		wypelnij();
		return true;
	}
	return false;
}

GrafL::GrafL() : Graf() {
	wypelnij();
}

bool GrafL::odczyt(string nazwa) {
	if (Graf::odczyt(nazwa)) {
		wypelnij();
		return true;
	}
	return false;
}

void GrafL::wypelnij() {
	for (int i = 0; i < ROZMIAR; i++) {
		wierzcholki[i]->lista.resize(0);
		wierzcholki[i]->lista.reserve(2*ROZMIAR);	
	}
// odpowiednie krawedzie dodawane sa do list sasiedztwa wierzcholkow na obu koncach (graf nieskierowany)
	for (int i = 0; i < krawedzie.size(); i++) {
		Edge* pom = krawedzie[i];
		int pocz = pom->getA()->getNumer() - 1;
		int kon = pom->getB()->getNumer() - 1;
		wierzcholki[pocz]->lista.push_back(pom);
		wierzcholki[kon]->lista.push_back(pom);
	} 
}

// jesli ktorykolwiekwierzcholek nie nalezy do MDR to jeszcze nie wyznaczlismy MDR (kolor == true oznacza bycie elementem MDR)
bool Graf::mdr() {
	for (int i = 0; i < ROZMIAR; i++) 
		if (!wierzcholki[i]->kolor)
			return false;
	return true;
}

int GrafM::kruskal() {
	int wynik = 0;
	drzewo.reserve(ROZMIAR*2);
	Kolejka* kol = new Kolejka();
// tworzymy kolejke priorytetowa wszystkich krawedzi (sortowana rosnaco wg wag) - wyciaganie danych z macierzy (macierz symetryczna)
	for (int j = 0; j < ROZMIAR; j++) 
		for (int k = j+1; k < ROZMIAR; k++)
			if (tablica[j][k] != NULL && !tablica[j][k]->dodane) {
				tablica[j][k]->dodane = true;
				kol->push(tablica[j][k]);
			}
	int k = kol->size(); // potrzebna zmienna pomocnicza, bo w trakcie dzialania petli rozmiar kolejki sie zmienia
	bool koniec = false; // przechowuje informacje o tym czy juz wyznaczylismy MDR
// petle konczymy gdy wyczerpia nam sie krawdzie lub gdy zbudujemy MDR
	for (int i = 0; i < k && !koniec; i++) {
		Edge* pom = kol->top();
		kol->pop();	// usuwamy sprawdzana krawedz z kolejki
// jesli choc jeden z koncow krawedzi nie nalezy do MDR to dodajemy krawedz oraz nienalezace wierzcholki
		if ((!pom->getA()->kolor && !pom->getB()->kolor) || (pom->getA()->kolor != pom->getB()->kolor)) {
			drzewo.push_back(pom);		// dodajemy krawedz do drzewa
			pom->getB()->kolor = pom->getA()->kolor = true;	// kolorujemy odpowiednie wierzcholki
			wynik += pom->getWaga();
		}
		koniec = mdr();
	}
	return wynik;
}

int GrafL::kruskal() {
	int wynik = 0;
	drzewo.reserve(ROZMIAR*2);
	Kolejka* kol = new Kolejka();
// tworzymy kolejke priorytetowa wszystkich krawedzi (sortowana rosnaco wg wag) - wyciaganie danych z list sasiedztwa wierzcholkow
	for (int i = 0; i < ROZMIAR; i++)
		for (int j = 0; j < wierzcholki[i]->lista.size(); j++) 
			if (!wierzcholki[i]->lista[j]->dodane) {
				kol->push(wierzcholki[i]->lista[j]);
				wierzcholki[i]->lista[j]->dodane = true;
			}
	int k = kol->size(); // potrzebna zmienna pomocnicza, bo w trakcie dzialania petli rozmiar kolejki sie zmienia
	bool koniec = false; // przechowuje informacje o tym czy juz wyznaczylismy MDR
	for (int i = 0; i < k && !koniec; i++) {
		Edge* pom = kol->top();
		kol->pop();	// usuwamy sprawdzana krawedz z kolejki
// jezeli choc jeden z koncow krawedzi nie nalezy do MDR to dodajemy krawedz oraz nienalezace wierzcholki
		if ((!pom->getA()->kolor && !pom->getB()->kolor) || (pom->getA()->kolor != pom->getB()->kolor)) {
			drzewo.push_back(pom);		// dodajemy krawedz do drzewa
			pom->getB()->kolor = pom->getA()->kolor = true;	// kolorujemy odpowiednie wierzcholki
			wynik += pom->getWaga();
		}
		koniec = mdr();
	}
	return wynik;
}

int GrafM::prim() {
	int wynik = 0;
	drzewo.reserve(2*ROZMIAR);
// priorytetowa kolejka krawedzi - sortowana wg wag
	Kolejka* kol = new Kolejka();
// jako poczatkowy wierzcholek wybieramy pierwszy (indeks 0) i dodajemy go do drzewa, a jego krawedzie do kolejki
	for (int i = 0; i < ROZMIAR; i++)
		if (tablica[0][i] != NULL && !tablica[0][i]->dodane) {
			kol->push(tablica[0][i]);
			tablica[0][i]->dodane = true;
		}
	wierzcholki[0]->kolor = true;
	while (!mdr()) {
		Edge* pom = kol->top();
		kol->pop();
// nie istnieje szansa sprawdzania dwoch nienalezacych wierzcholkow, wiec sprawdzamy tylko czy ich "przynaleznosc jest rozna"
		if (pom->getA()->kolor != pom->getB()->kolor) {
// do kolejki dodajemy krawedzie wychodzace z jeszcze nieodwiedzonego wierzcholka oraz kolorujemy go
			if (pom->getB()->kolor) {
				for (int i = pom->getA()->getNumer(); i < ROZMIAR; i++) {
					if (tablica[pom->getA()->getNumer()-1][i] != NULL && !tablica[pom->getA()->getNumer()-1][i]->dodane) {
						kol->push(tablica[pom->getA()->getNumer()-1][i]);
						tablica[pom->getA()->getNumer()-1][i]->dodane = true;
					}
				}
				pom->getA()->kolor = true;
			}
			else {
				for (int i = pom->getB()->getNumer(); i < ROZMIAR; i++) {
					if (tablica[pom->getB()->getNumer()-1][i] != NULL && !tablica[pom->getB()->getNumer()-1][i]->dodane) {
						kol->push(tablica[pom->getB()->getNumer()-1][i]);
						tablica[pom->getB()->getNumer()-1][i]->dodane = true;
					}
				}
				pom->getB()->kolor = true;
			}
			wynik += pom->getWaga();
			drzewo.push_back(pom);	// dodajemy krawedz do drzewa
		}
	}
	return wynik;
}

int GrafL::prim() {
	int wynik = 0;
	drzewo.reserve(2*ROZMIAR);
// priorytetowa kolejka krawedzi - sortowana wg wag
	Kolejka* kol = new Kolejka();
// jako poczatkowy wierzcholek wybieramy pierwszy (indeks 0) i dodajemy go do drzewa, a jego krawedzie do kolejki
	for (int i = 0; i < wierzcholki[0]->lista.size(); i++)
		if (!wierzcholki[0]->lista[i]->dodane) {
			kol->push(wierzcholki[0]->lista[i]);
			wierzcholki[0]->lista[i]->dodane = true;
		}
	wierzcholki[0]->kolor = true;
	while (!mdr()) {
		Edge* pom = kol->top();
		kol->pop();
// nie istnieje szansa sprawdzania dwoch nienalezacych wierzcholkow, wiec sprawdzamy tylko czy ich "przynaleznosc jest rozna"
		if (pom->getA()->kolor != pom->getB()->kolor) {
// do kolejki dodajemy krawedzie wychodzace z jeszcze nieodwiedzonego wierzcholka oraz kolorujemy go
			if (pom->getA()->kolor) {
				pom->getB()->kolor = true;
				for (int i = 0; i < wierzcholki[pom->getB()->getNumer()-1]->lista.size(); i++) {
					if (!wierzcholki[pom->getB()->getNumer()-1]->lista[i]->dodane) {
						kol->push(wierzcholki[pom->getB()->getNumer()-1]->lista[i]);
						wierzcholki[pom->getB()->getNumer()-1]->lista[i]->dodane = true;
					}
				}
			}
			else {
				pom->getA()->kolor = true;
				for (int i = 0; i < wierzcholki[pom->getA()->getNumer()-1]->lista.size(); i++) {
					if (!wierzcholki[pom->getA()->getNumer()-1]->lista[i]->dodane) {
						kol->push(wierzcholki[pom->getA()->getNumer()-1]->lista[i]);
						wierzcholki[pom->getA()->getNumer()-1]->lista[i]->dodane = true;
					}
				}
			}
			wynik += pom->getWaga();
			drzewo.push_back(pom);	// dodajemy krawedz do drzewa
			for (int i = 0; i < wierzcholki[pom->getB()->getNumer()-1]->lista.size(); i++)
				if (!wierzcholki[pom->getB()->getNumer()-1]->lista[i]->dodane) {
					kol->push(wierzcholki[pom->getB()->getNumer()-1]->lista[i]);
					wierzcholki[pom->getB()->getNumer()-1]->lista[i]->dodane = true;
				}
		}
	}
	return wynik;
}