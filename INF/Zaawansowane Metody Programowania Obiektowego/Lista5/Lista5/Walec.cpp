#include "Walec.h"

bool Walec::bWczytaj(istream & in) {
	double dX, dY, dZ, dR;
	char hOs;
	string sNazwa;
	in >> sNazwa;
	if (!in)
		return false;
	in >> dX;
	if (!in)
		return false;
	in >> dY;
	if (!in)
		return false;
	in >> dZ;
	if (!in)
		return false;
	in >> dR;
	if (!in)
		return false;
	in >> hOs;
	if (!in)
		return false;
	s_id= sNazwa;
	c_srodek.setX(dX);
	c_srodek.setY(dY);
	c_srodek.setZ(dZ);
	d_r = dR;
	h_os = hOs;
	return true;
}

bool Walec::bZapisz(ostream & out) {
	string sDoZapisu1 = "walec";
	string sDoZapisu2 = '\n' + s_id + " " + to_string(c_srodek.getX()) + " " + to_string(c_srodek.getY()) + " " + to_string(c_srodek.getZ()) + " " + to_string(d_r) + " " + h_os + '\n';
	out << sDoZapisu1 << sDoZapisu2;
	return out.good();
}

PunktPrzeciecia Walec::cZnajdzPrzeciecie(Promien3d & cR) {
	double a, b, c, delta;
	if (h_os == 'x' || h_os == 'X') {
		a = cR.getWY() * cR.getWY() + cR.getWZ() * cR.getWZ();
		b = 2 * ( cR.getWY() * (cR.getPY() - c_srodek.getY()) + cR.getWZ() * (cR.getPZ() - c_srodek.getZ()));
		c = c_srodek.getY() * c_srodek.getY() + c_srodek.getZ() * c_srodek.getZ() +  cR.getPY() * cR.getPY() + cR.getPZ() * cR.getPZ() - 2 * (c_srodek.getY() * cR.getPY() + c_srodek.getZ() * cR.getPZ()) - d_r * d_r;
	}
	else 
		if (h_os == 'y' || h_os == 'Y') {
			a = cR.getWX() * cR.getWX() + cR.getWZ() * cR.getWZ();
			b = 2 * ( cR.getWX() * (cR.getPX() - c_srodek.getX()) + cR.getWZ() * (cR.getPZ() - c_srodek.getZ()));
			c = c_srodek.getX() * c_srodek.getX() + c_srodek.getZ() * c_srodek.getZ() +  cR.getPX() * cR.getPX() + cR.getPZ() * cR.getPZ() - 2 * (c_srodek.getX() * cR.getPX() + c_srodek.getZ() * cR.getPZ()) - d_r * d_r;
		}
		else {
			a = cR.getWX() * cR.getWX() + cR.getWY() * cR.getWY();
			b = 2 * ( cR.getWX() * (cR.getPX() - c_srodek.getX()) + cR.getWY() * (cR.getPY() - c_srodek.getY()));
			c = c_srodek.getX() * c_srodek.getX() + c_srodek.getY() * c_srodek.getY() +  cR.getPX() * cR.getPX() + cR.getPY() * cR.getPY() - 2 * (c_srodek.getX() * cR.getPX() + c_srodek.getY() * cR.getPY()) - d_r * d_r;
		}
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return PunktPrzeciecia(false);
	else 
		if (delta == 0) {
			double t = -b / (2*a);
			double x = cR.getPX() + cR.getWX() * t;
			double y = cR.getPY() + cR.getWY() * t;
			double z = cR.getPZ() + cR.getWZ() * t;
			return PunktPrzeciecia(true,Punkt3d(x,y,z),t,"walec",s_id);
		}
		else {
			double t1 = (-b - sqrt(delta)) / (2 * a);
			double t2 = (-b + sqrt(delta)) / (2 * a);
			if (t1 < t2 && t1 >= 0) {
				double x = cR.getPX() + cR.getWX() * t1;
				double y = cR.getPY() + cR.getWY() * t1;
				double z = cR.getPZ() + cR.getWZ() * t1;
				return PunktPrzeciecia(true,Punkt3d(x,y,z),t1,"walec",s_id);
			}
			else {
				double x = cR.getPX() + cR.getWX() * t2;
				double y = cR.getPY() + cR.getWY() * t2;
				double z = cR.getPZ() + cR.getWZ() * t2;
				if (t2 >= 0)
					return PunktPrzeciecia(true,Punkt3d(x,y,z),t2,"walec",s_id);
				else
					return PunktPrzeciecia(false);
			}
		}
}