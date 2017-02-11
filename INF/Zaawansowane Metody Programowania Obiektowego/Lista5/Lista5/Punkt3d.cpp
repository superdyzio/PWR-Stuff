#include "Punkt3d.h"

double Punkt3d::dOdleglosc(Punkt3d & cPunkt) {
	double dX = d_x - cPunkt.getX();
	double dY = d_y - cPunkt.getY();
	double dZ = d_z - cPunkt.getZ();
	return sqrt( dX*dX + dY*dY + dZ*dZ);
}