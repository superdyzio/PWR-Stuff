#include "TablicaSymboli.h"

bool CTablicaSymboli::bUstalWartosc(string sNazwa, double dWartosc) {
	bool b_udane = false, b_znaleziona = false;
	for (int i = 0; i < c_dane.size()-1 && !b_znaleziona; i++)
		if (c_dane.at(i).sWezNazwe() == sNazwa && c_dane.at(i).bCzyZmienna()) {
			b_znaleziona = true;
			if (!c_dane.at(i).bCzyMaWartosc()) {
				c_dane.at(i).vDajWartosc(dWartosc);
				b_udane = true;
			}
		}
	return b_udane;
}

double CTablicaSymboli::dDajWartosc(string sNazwa) {
	bool b_znaleziona = false;
	double d_wynik = 0;
	for (int i = 0; i < c_dane.size()-1 && !b_znaleziona; i++)
		if (c_dane.at(i).sWezNazwe() == sNazwa) {
			b_znaleziona = true;
			d_wynik = c_dane.at(i).iWezWartosc();
		}
	return d_wynik;
}

bool CTablicaSymboli::bCzyZdefiniowana(string sNazwa) {
	bool b_wynik = false;
	for (int i = 0; i < c_dane.size()-1 && !b_wynik; i++)
		if (c_dane.at(i).sWezNazwe() == sNazwa && c_dane.at(i).bCzyZmienna() && c_dane.at(i).bCzyMaWartosc()) b_wynik = true;
	return b_wynik;
}