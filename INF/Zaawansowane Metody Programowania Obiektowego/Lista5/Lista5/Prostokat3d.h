#ifndef PROSTOKAT3D_H
#define PROSTOKAT3D_H

#include "Bryla.h"
#include "PunktPrzeciecia.h"
using namespace std;

class Prostokat3d :	public Bryla {
	char h_os;
	double d_d;
	double d_umin, d_umax, d_vmin, d_vmax;
	bool bOsOk(char hOs) { return hOs == 'x' || hOs == 'y' || hOs == 'z' || hOs == 'X' || hOs == 'Y' || hOs == 'Z'; }
public:
	Prostokat3d(string sNazwa, char hOs, double dD, double dUmin, double dUmax, double dVmin, double dVmax):Bryla(sNazwa),d_d(dD),d_umin(dUmin),d_umax(dUmax),d_vmin(dVmin),d_vmax(dVmax) { h_os = bOsOk(hOs) ? hOs : 'x'; }
	Prostokat3d() {}
	~Prostokat3d() {}

	PunktPrzeciecia cZnajdzPrzeciecie(Promien3d & cR);

	bool bWczytaj(istream & in);
	bool bZapisz(ostream & out);

	char getOs() { return h_os; }
	double getD() { return d_d; }
	double getUmin() { return d_umin; }
	double getUmax() { return d_umax; }
	double getVmin() { return d_vmin; }
	double getVmax() { return d_vmax; }
	void setUmin(double dU) { d_umin = dU; }
	void setUmax(double dU) { d_umax = dU; }
	void setVmin(double dV) { d_vmin = dV; }
	void setVmax(double dV) { d_vmax = dV; }
};

#endif