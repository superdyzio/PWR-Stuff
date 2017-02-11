#ifndef WEKTOR3D_H
#define WEKTOR3D_H

class Wektor3d {
	double d_x, d_y, d_z;
public:
	Wektor3d(double dX=1, double dY=1, double dZ=1):d_x(dX),d_y(dY),d_z(dZ) {}
	Wektor3d(const Wektor3d & cWektor):d_x(cWektor.d_x),d_y(cWektor.d_y),d_z(cWektor.d_z) {}
	~Wektor3d() {}

	double getX() { return d_x; }
	double getY() { return d_y; }
	double getZ() { return d_z; }
	void setX(double dX) { d_x = dX; }
	void setY(double dY) { d_y = dY; }
	void setZ(double dZ) { d_z = dZ; }
};


#endif