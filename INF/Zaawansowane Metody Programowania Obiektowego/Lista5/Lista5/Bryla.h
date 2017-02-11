#ifndef BRYLA_H
#define BRYLA_H

#include <string>
#include "PunktPrzeciecia.h"
#include "Promien3d.h"
using namespace std;

class Bryla {
protected:
	string s_id;
public:
	Bryla(string sNazwa=""):s_id(sNazwa) {}
	virtual ~Bryla() {}

	string getId() { return s_id; }
	void setId(string sNazwa) { s_id = sNazwa; }
	virtual PunktPrzeciecia cZnajdzPrzeciecie(Promien3d & cR) = 0;
	virtual bool bWczytaj(istream & in) = 0;
	virtual bool bZapisz(ostream & out) = 0;
};

#endif