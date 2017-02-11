#ifndef WALEC_H
#define WALEC_H

#include "Bryla.h"
using namespace std;

class Walec : public Bryla {
	Punkt3d c_srodek;
	char h_os;
	double d_r;

	bool bOsOk(char hOs) { return hOs == 'x' || hOs == 'y' || hOs == 'z' || hOs == 'X' || hOs == 'Y' || hOs == 'Z'; }

public:
	Walec(string sNazwa, double dX, double dY, double dZ, double dR, char hOs):Bryla(sNazwa),c_srodek(dX,dY,dZ),d_r(dR) { h_os = bOsOk(hOs) ? hOs : 'x'; }
	Walec(string sNazwa, Punkt3d cPunkt, double dR, char hOs):Bryla(sNazwa),c_srodek(cPunkt),d_r(dR),h_os(hOs) {}
	Walec() {}
	~Walec() {}

	PunktPrzeciecia cZnajdzPrzeciecie(Promien3d & cR);

	bool bWczytaj(istream & in);
	bool bZapisz(ostream & out);

	Punkt3d getSrodek() { return c_srodek; }
	char getOs() { return h_os; }
	double getR() { return d_r; }
	void setSrodek(double dX, double dY, double dZ);
	void setOs(char hOs) { h_os = hOs; }
	void setR(double dR) { d_r = dR; }
};

#endif