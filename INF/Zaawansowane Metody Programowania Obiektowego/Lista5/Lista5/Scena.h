#ifndef SCENA_H
#define SCENA_H

#include <vector>
#include "Bryla.h"
#include <iostream>
#include <fstream>
#include "Kula.h"
#include "Walec.h"
#include "Prostokat3d.h"
#include "Prostopadloscian.h"
#include "ElementIstnieje.h"
#include "Plaszczyzna3d.h"
using namespace std;

class Scena {
	vector<Bryla*> vvc_scena;
	int i_znajdz_bryle(const string sNazwa);
public:
	Scena() {}
	~Scena() {}

	void vDodajBryle(Bryla* cBryla);
	bool bUsunBryle(const string sNazwa);
	void vWyczysc() { vvc_scena.clear(); }
	PunktPrzeciecia cNajblizszePrzeciecie(Promien3d & cR);

	bool bZaladuj(string sPlik);
	bool bZapisz(string sPlik);
};

#endif