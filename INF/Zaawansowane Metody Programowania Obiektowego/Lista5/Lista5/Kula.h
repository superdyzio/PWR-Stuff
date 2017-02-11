#ifndef KULA_H
#define KULA_H

#include "Bryla.h"
#include "Punkt3d.h"
using namespace std;

class Kula : public Bryla {
	double d_r;
	Punkt3d c_srodek;
public:
	Kula(string sNazwa, double dX, double dY, double dZ, double dR):Bryla(sNazwa),c_srodek(dX,dY,dZ),d_r(dR) {} 
	Kula(string sNazwa, Punkt3d cSrodek, double dR):Bryla(sNazwa),c_srodek(cSrodek),d_r(dR) {}
	Kula() {}
	~Kula() {}

	PunktPrzeciecia cZnajdzPrzeciecie(Promien3d & dR);
	bool bWczytaj(istream & in);
	bool bZapisz(ostream & out);
	double getR() { return d_r; }
	Punkt3d getSrodek() { return c_srodek; }
	void setR(double dR) { d_r = dR; }
	void setSrodek(double dX, double dY, double dZ);
};

#endif