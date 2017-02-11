/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z1/trunk/src/menu.cpp $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (wto) $
$Revision: 9 $
*/

#include "menu.hh"

/*!
 * \file
 * \brief Plik zawierający implementację metod klasy pomocniczej przy obsłudze programu.
 */

void Menu::wyswietlListe() {
	for (auto& lib : _lista)
		lib.second->PrintSyntax();
}

void Menu::wyswietlKomendy() {
	for (unsigned int i = 0; i < _komendy.size(); i++) { 
		cout << i+1 << ": ";
		_komendy[i]->PrintCmd();
	}
}

const Biblioteka* Menu::znajdzBiblioteke(string klucz) const { 
	typedef map<string,Biblioteka*>::const_iterator MapIterator;
	MapIterator iter;
	for (iter = _lista.begin(); iter != _lista.end(); iter++)
		if (iter->first == klucz) 
			break;
	if (iter == _lista.end()) 
		return NULL;
	else 
		return iter->second;
}

bool Menu::wczytajPlik(istringstream& dane, string nazwa) {
	string prep = "cpp -P ";
	FILE *wPlik;
	char linia[20];
	ostringstream plik;
	prep += nazwa;
	wPlik = popen(prep.c_str(),"r");
	if (!wPlik) {
		cout << "Nie udało się otworzyć pliku.";
		return false;
	}
	while (fgets(linia,20,wPlik))
		plik << linia;
	dane.str(plik.str());
	if (!wPlik) 
		return false;
	return pclose(wPlik) == 0;
}

bool Menu::wczytajKomendy(istringstream& dane) {
	_komendy.clear();
	string klucz;
	while (dane >> klucz)  {
		auto bib = znajdzBiblioteke(klucz.c_str());
		if (bib != NULL) {
			auto komenda = bib->CreateCmd();
			if (komenda) {
				komenda->ReadParams(dane);
				komenda->PrintCmd();
				_komendy.push_back(komenda);
			}
			else
				return false;
		}
	}
	return true;
}

void Menu::wyswietlMenu() {
	cout << endl;
	cout << "1 - Wczytanie pliku z komendami" << endl;
	cout << "2 - Pokazanie wczytanej sekwencji" << endl;
	cout << "3 - Pokazanie dostępnych instrukcji" << endl;
	cout << "4 - Wykonanie wczytanej sekwencji" << endl;
	cout << "5 - Dodawanie nowej wtyczki" << endl;
	cout << "6 - Usuwanie wtyczki" << endl;
	cout << "0 - KONIEC" << endl;
	cout << "Twój wybór: ";
}

void Menu::wykonajSekwencje(RobotMobilny& robot) {
	for (auto kom : _komendy)
		kom->ExecCmd(&robot);
}

void Menu::dodaj(const char* nazwawtyczki) {
	_lista.dodaj(nazwawtyczki);
}
 
bool Menu::usun(const char* nazwawtyczki) {
	return _lista.usun(nazwawtyczki);
}
