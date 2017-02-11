#include "Plaszczyzna3d.h"

PunktPrzeciecia Plaszczyzna3d::cZnajdzPrzeciecie(Promien3d & cR) {
	double dIlWekt = c_wektor.getX() * cR.getWX() + c_wektor.getY() * cR.getWY() + c_wektor.getZ() * cR.getWZ();
	if(dIlWekt != 0) {
		double D = -c_wektor.getX() * c_punkt.getX() -c_wektor.getY() * c_punkt.getY() -c_wektor.getZ() * c_punkt.getZ();
		double licznik = c_wektor.getX() * cR.getPX() + c_wektor.getY() * cR.getPY() + c_wektor.getZ() * cR.getPZ() + D;
		double mianownik = c_wektor.getX() * cR.getWX() + c_wektor.getY() * cR.getWY() + c_wektor.getZ() * cR.getWZ();
		double t = -1 * (licznik / mianownik);
		double x = cR.getPX() + cR.getWX() * t;
		double y = cR.getPY() + cR.getWY() * t;
		double z = cR.getPZ() + cR.getWZ() * t;
		if(t >= 0)
			return PunktPrzeciecia(true,Punkt3d(x,y,z),t,"plaszczyzna",s_id);
		else
			return PunktPrzeciecia(false);
	}
	else
		return PunktPrzeciecia(false);
}

bool Plaszczyzna3d::bWczytaj(istream & in) {
	double dPx, dPy, dPz, dWx, dWy, dWz;
	string sNazwa;
	in >> sNazwa;
	if (!in)
		return false;
	in >> dPx;
	if (!in)
		return false;
	in >> dPy;
	if (!in)
		return false;
	in >> dPz;
	if (!in)
		return false;
	in >> dWx;
	if (!in)
		return false;
	in >> dWy;
	if (!in)
		return false;
	in >> dWz;
	if (!in)
		return false;
	s_id= sNazwa;
	c_punkt.setX(dPx);
	c_punkt.setY(dPy);
	c_punkt.setZ(dPz);
	c_wektor.setX(dWx);
	c_wektor.setY(dWy);
	c_wektor.setZ(dWz);
	return true;
}

bool Plaszczyzna3d::bZapisz(ostream & out) {
	string sDoZapisu1 = "plaszczyzna";
	string sDoZapisu2 =  '\n' + s_id + " " + to_string(c_punkt.getX()) + " " + to_string(c_punkt.getY()) + " " + to_string(c_punkt.getZ()) + " " + to_string(c_wektor.getX()) + " " + to_string(c_wektor.getY()) + " " + to_string(c_wektor.getZ()) + '\n';
	out << sDoZapisu1 << sDoZapisu2;
	return out.good();
}