#ifndef PROSTOPADLOSCIAN_H
#define PROSTOPADLOSCIAN_H

#include "Bryla.h"
#include "PunktPrzeciecia.h"
#include "Prostokat3d.h"
#include <vector>
using namespace std;

class Prostopadloscian : public Bryla {
	double d_xmin, d_xmax, d_ymin, d_ymax, d_zmin, d_zmax;
public:
	Prostopadloscian(string sNazwa, double dXmin, double dXmax, double dYmin, double dYmax, double dZmin, double dZmax):Bryla(sNazwa),d_xmin(dXmin),d_xmax(dXmax),d_ymin(dYmin),d_ymax(dYmax),d_zmin(dZmin),d_zmax(dZmax) {}
	Prostopadloscian() {}
	~Prostopadloscian() {}
	
	PunktPrzeciecia cZnajdzPrzeciecie(Promien3d & cR);

	bool bWczytaj(istream & in);
	bool bZapisz(ostream & out);

	double getXmin() { return d_xmin; }
	double getYmin() { return d_ymin; }
	double getZmin() { return d_zmin; }
	double getXmax() { return d_xmax; }
	double getYmax() { return d_ymax; }
	double getZmax() { return d_zmax; }
	void setXmin(double dX) { d_xmin = dX; }
	void setYmin(double dY) { d_ymin = dY; }
	void setZmin(double dZ) { d_zmin = dZ; }
	void setXmax(double dX) { d_xmax = dX; }
	void setYmax(double dY) { d_ymax = dY; }
	void setZmax(double dZ) { d_zmax = dZ; }
};

#endif