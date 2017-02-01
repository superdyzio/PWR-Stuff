#include "mapa.hh"

/*!
 *\file
 *\brief	Plik zawierający definicje wybranych metod z klasy Mapa. 
*/

Zespolona Mapa::getWartosc(const string& n) {
	if (czyJest(n)) {
		if (((*this)[n]).getCzyMaWart()) {
			return ((*this)[n]).getWart();
		}
	}
	else {
		erase(n);
	}
	return ((*this)[n]).getWart();
}

void Mapa::przypiszWartosc(const string& n, const Zespolona& x) {
	((*this)[n]).setWartosc(x);
}

void Mapa::wypisz() {
	for (Mapa::iterator iter = begin(); iter != end(); ++iter) cout << (iter)->first << endl;
}

void Mapa::wypiszZm() {
	cout << "Zmienne:" << endl;
	for (Mapa::iterator iter = begin(); iter != end(); ++iter) 
		if ((iter->first)[0] != ':' && (iter->first)[1] != ':') {
			cout << (iter->first) << "          ->   ";
			if ((iter->second).getCzyMaWart()) cout << iter->second.getWart() << " : " << iter->second.getLicznik() << endl;
			else cout << "? : " << (((iter)->second).getLicznik()) << endl;
		}
}

void Mapa::wypiszSt() {
	cout << "Stałe:" << endl;
	for (Mapa::reverse_iterator iter = rbegin(); iter != rend(); ++iter)
		if ((iter->first)[0] == ':' && (iter->first)[1] == ':')
			cout << (((iter)->second).getWart()) << endl;
}