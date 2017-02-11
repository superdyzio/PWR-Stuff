#include "Scena.h"

int Scena::i_znajdz_bryle(const string sNazwa) {
	unsigned int indeks = 0;
	bool bJest = false;
	for (indeks = 0; indeks < vvc_scena.size() && !bJest ; indeks++)
		if (sNazwa == vvc_scena[indeks] -> getId() )
			bJest = true;
	return bJest ? indeks : -1;
}

void Scena::vDodajBryle(Bryla* cBryla) {
	int bIstnieje = i_znajdz_bryle(cBryla -> getId());
	if(bIstnieje != -1)
		throw ElementIstnieje();
	else
		vvc_scena.push_back(cBryla);
}

bool Scena::bUsunBryle(const string sNazwa)
{
	int indeks = i_znajdz_bryle(sNazwa);
	if (indeks == -1)
		return false;
	else {
		vvc_scena.erase(vvc_scena.begin() + ( indeks == 0 ? 0 : (indeks -1)));
		return true;
	}
}

PunktPrzeciecia Scena::cNajblizszePrzeciecie(Promien3d & cR)
{
	PunktPrzeciecia cNajblizsze(false);
	double dMinOdl = DBL_MAX;
	for(unsigned int i = 0; i < vvc_scena.size() ; i++) {
		PunktPrzeciecia cElement = vvc_scena[i]->cZnajdzPrzeciecie(cR);
		if (cElement.getCzyJest())
			if(dMinOdl > cElement.getPunkt().dOdleglosc(cR.getPunkt())) {
					cNajblizsze = cElement;
					dMinOdl = cNajblizsze.getPunkt().dOdleglosc(cR.getPunkt());
				}
	}
	return cNajblizsze;
}

bool Scena::bZaladuj(string sPlik) {
	ifstream dane;
	dane.open(sPlik);
	if(dane.good()) {
		string sBryla;
		while(!dane.eof()) {
			dane >> sBryla;
			if (sBryla == "") {
				dane.close();
				return true;
			}
			if (sBryla == "kula") {
				Kula* kula= new Kula();
				if(!kula->bWczytaj(dane)) {
						dane.close();
						return false;
				}
				vvc_scena.push_back(kula);
			}
			else 
				if (sBryla == "walec") {
					Walec* walec= new Walec();
					if(!walec->bWczytaj(dane)) {
						dane.close();
						return false;
					}
					vvc_scena.push_back(walec);
				}
				else 
					if (sBryla == "prostopadloscian") {
						Prostopadloscian* prostopadloscian = new Prostopadloscian();
						if(!prostopadloscian->bWczytaj(dane)) {
							dane.close();
							return false;
						}
						vvc_scena.push_back(prostopadloscian);
					}
					else 
						if (sBryla == "plaszczyzna") {
							Plaszczyzna3d* plaszczyzna = new Plaszczyzna3d();
							if(!plaszczyzna->bWczytaj(dane)) {
								dane.close();
								return false;
							}
							vvc_scena.push_back(plaszczyzna);
						}
						else 
							if (sBryla == "prostokat") {
								Prostokat3d* prostokat = new Prostokat3d();
								if (!prostokat->bWczytaj(dane)) {
									dane.close();
									return false;
								}
								vvc_scena.push_back(prostokat);
							}
							else {
								dane.close();
								return false;
							}
		}
		dane.close();
		return true;
	}
	else
		return false;
}

bool Scena::bZapisz(string sPlik) {
	ofstream zapis;
	zapis.open(sPlik, ios::trunc | ios::out);
	if(zapis.good()) {
		bool ok = true;
		for (unsigned int i = 0 ; i < vvc_scena.size() && ok ; i++)
			ok = vvc_scena[i] -> bZapisz(zapis);
		zapis.close();
		return ok;
	}
	else
		return false;

}
