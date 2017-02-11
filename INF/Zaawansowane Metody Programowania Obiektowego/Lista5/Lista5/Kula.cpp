#include "Kula.h"

PunktPrzeciecia Kula::cZnajdzPrzeciecie(Promien3d & dR) {
	double a = dR.getWX() * dR.getWX() + dR.getWY() * dR.getWY() + dR.getWZ() * dR.getWZ();
	double b = 2 * ( dR.getWX() * (dR.getPX() - c_srodek.getX()) + dR.getWY() * (dR.getPY() - c_srodek.getY()) + dR.getWZ() * (dR.getPZ() - c_srodek.getZ()));
	double c = c_srodek.getX() * c_srodek.getX() + c_srodek.getY() * c_srodek.getY() + c_srodek.getZ() * c_srodek.getZ() + dR.getPX() * dR.getPX() + dR.getPY() * dR.getPY() + dR.getPZ() * dR.getPZ() - 2 * (c_srodek.getX() * dR.getPX() + c_srodek.getY() * dR.getPY() + c_srodek.getZ() * dR.getPZ()) - d_r * d_r;
	double delta = b * b - 4 * a * c;
	if (delta < 0)
		return PunktPrzeciecia(false);
	else 
		if (delta == 0) {
			double t = -b / (2*a);
			double x = dR.getPX() + dR.getWX() * t;
			double y = dR.getPY() + dR.getWY() * t;
			double z = dR.getPZ() + dR.getWZ() * t;
			if (t >= 0)
				return PunktPrzeciecia(true,Punkt3d(x,y,z),t,"kula",s_id);
			else
				return PunktPrzeciecia(false);
		}
		else {
			double t1 = (-b - sqrt(delta)) / (2 * a);
			double t2 = (-b + sqrt(delta)) / (2 * a);
			if (t1 < t2 && t1 >= 0) {
				double x = dR.getPX() + dR.getWX() * t1;
				double y = dR.getPY() + dR.getWY() * t1;
				double z = dR.getPZ() + dR.getWZ() * t1;
				return PunktPrzeciecia(true,Punkt3d(x,y,z),t1,"kula",s_id);
			}
			else {
				double x = dR.getPX() + dR.getWX() * t2;
				double y = dR.getPY() + dR.getWY() * t2;
				double z = dR.getPZ() + dR.getWZ() * t2;
				if (t2 >= 0)
					return PunktPrzeciecia(true,Punkt3d(x,y,z),t2,"kula",s_id);
				else
					return PunktPrzeciecia(false);
			}
	}
}

bool Kula::bWczytaj(istream & in) {
		double dX, dY, dZ, dR;
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
		s_id = sNazwa;
		c_srodek.setX(dX);
		c_srodek.setY(dY);
		c_srodek.setZ(dZ);
		d_r = dR;
		return true;
}

bool Kula::bZapisz(ostream & out) {
	string sDoZapisu1 = "kula";
	string sDoZapisu2 = '\n' + s_id + " " + to_string(c_srodek.getX()) + " " + to_string(c_srodek.getY()) + " " + to_string(c_srodek.getZ()) + " " + to_string(d_r) + '\n';
	out << sDoZapisu1 << sDoZapisu2;
	return out.good();
}

void Kula::setSrodek(double dX, double dY, double dZ) {
	c_srodek.setX(dX);
	c_srodek.setY(dY);
	c_srodek.setZ(dZ);
}