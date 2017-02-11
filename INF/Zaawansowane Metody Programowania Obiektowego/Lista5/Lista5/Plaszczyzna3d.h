#ifndef PLASZCZYZNA3D_H
#define PLASZCZYZNA3D_H

#include "Bryla.h"
using namespace std;

class Plaszczyzna3d : public Bryla {
	Punkt3d c_punkt;
	Wektor3d c_wektor;
public:
	Plaszczyzna3d(string sNazwa, double dPx, double dPy, double dPz, double dWx, double dWy, double dWz):Bryla(sNazwa),c_punkt(dPx,dPy,dPz),c_wektor(dWx,dWy,dWz) {}
	Plaszczyzna3d(string sNazwa, Punkt3d & cPunkt, Wektor3d & cWektor):Bryla(sNazwa),c_punkt(cPunkt),c_wektor(cWektor) {}
	Plaszczyzna3d() {}
	~Plaszczyzna3d() {}

	PunktPrzeciecia cZnajdzPrzeciecie(Promien3d & cR);

	bool bWczytaj(istream & in);
	bool bZapisz(ostream & out);

	Punkt3d getPunkt() { return c_punkt; }
	Wektor3d getWektor() { return c_wektor; }
	void setPunkt(double dX, double dY, double dZ);
	void setWektor(double dX, double dY, double dZ);
};

#endif