#ifndef PROMIEN3D_H
#define PROMIEN3D_H	

#include"Wektor3d.h"
#include "Punkt3d.h"

class Promien3d {
	Wektor3d c_wektor;
	Punkt3d c_punkt;
public:
	Promien3d(double dX, double dY, double dZ, double dXX, double dYY, double dZZ):c_wektor(dXX,dYY,dZZ),c_punkt(dX,dY,dZ) {}
	Promien3d(const Punkt3d & cPunkt, const Wektor3d & cWektor):c_wektor(cWektor),c_punkt(cPunkt) {}
	~Promien3d() {}

	Punkt3d getPunkt() { return c_punkt; }
	double getPX() { return c_punkt.getX(); }
	double getPY() { return c_punkt.getY(); }
	double getPZ() { return c_punkt.getZ(); }
	double getWX() { return c_wektor.getX(); }
	double getWY() { return c_wektor.getY(); }
	double getWZ() { return c_wektor.getZ(); }
	void setPX(double dX) { c_punkt.setX(dX); }
	void setPY(double dY) { c_punkt.setX(dY); }
	void setPZ(double dZ) { c_punkt.setX(dZ); }
	void setWX(double dX) { c_wektor.setX(dX); }
	void setWY(double dY) { c_wektor.setX(dY); }
	void setWZ(double dZ) { c_wektor.setX(dZ); }
};

#endif