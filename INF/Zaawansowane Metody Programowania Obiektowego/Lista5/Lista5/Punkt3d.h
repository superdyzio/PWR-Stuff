#ifndef PUNKT3D_H
#define PUNKT3D_H

#include <math.h>

class Punkt3d {
	double d_x, d_y, d_z;
public:
	Punkt3d(double dX, double dY, double dZ):d_x(dX),d_y(dY),d_z(dZ) {}
	Punkt3d(const Punkt3d & cPunkt):d_x(cPunkt.d_x),d_y(cPunkt.d_y),d_z(cPunkt.d_z) {}
	Punkt3d() { d_x = d_y = d_z = 0; }
	~Punkt3d() {}

	double dOdleglosc(Punkt3d & cPunkt);
	double getX() { return d_x; }
	double getY() { return d_y; }
	double getZ() { return d_z; }
	void setX(double dX) { d_x = dX; }
	void setY(double dY) { d_y = dY; }
	void setZ(double dZ) { d_z = dZ; }
};

#endif
