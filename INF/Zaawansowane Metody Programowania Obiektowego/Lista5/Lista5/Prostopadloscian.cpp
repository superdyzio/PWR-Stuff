#include "Prostopadloscian.h"

bool Prostopadloscian::bWczytaj(istream & in) {
	double dXmin,dXmax,dYmin,dYmax,dZmin,dZmax;
	string sNazwa;
	in >> sNazwa;
	if (!in)
		return false;
	in >> dXmin;
	if (!in)
		return false;
	in >> dXmax;
	if (!in)
		return false;
	in >> dYmin;
	if (!in)
		return false;
	in >> dYmax;
	if (!in)
		return false;
	in >> dZmin;
	if (!in)
		return false;
	in >> dZmax;
	if (!in)
		return false;
	s_id = sNazwa;
	d_xmin = dXmin;
	d_xmax = dXmax;
	d_ymin = dYmin;
	d_ymax = dYmax;
	d_zmin = dZmin;
	d_zmax = dZmax;
	return true;
}

bool Prostopadloscian::bZapisz(ostream & out) {
	string sDoZapisu1 = "prostopadloscian";
	string sDoZapisu2 = '\n' + s_id + " " + to_string(d_xmin) + " " + to_string(d_xmax) + " " + to_string(d_ymin) + " " + to_string(d_ymax) + " " + to_string(d_zmin) + " " + to_string(d_zmax) + '\n';
	out << sDoZapisu1 << sDoZapisu2;
	return out.good();
}

PunktPrzeciecia Prostopadloscian::cZnajdzPrzeciecie(Promien3d & cR) {
	PunktPrzeciecia p1 = Prostokat3d("S1",'x',d_xmin,d_ymin,d_ymax,d_zmin,d_zmax).cZnajdzPrzeciecie(cR);
	PunktPrzeciecia p2 = Prostokat3d("S2",'x',d_xmax,d_ymin,d_ymax,d_zmin,d_zmax).cZnajdzPrzeciecie(cR);
	PunktPrzeciecia p3 = Prostokat3d("S3",'y',d_ymin,d_xmin,d_xmax,d_zmin,d_zmax).cZnajdzPrzeciecie(cR);
	PunktPrzeciecia p4 = Prostokat3d("S4",'y',d_ymax,d_xmin,d_xmax,d_zmin,d_zmax).cZnajdzPrzeciecie(cR);
	PunktPrzeciecia p5 = Prostokat3d("S5",'z',d_zmin,d_xmin,d_xmax,d_ymin,d_ymax).cZnajdzPrzeciecie(cR);
	PunktPrzeciecia p6 = Prostokat3d("S6",'z',d_zmax,d_xmin,d_xmax,d_ymin,d_ymax).cZnajdzPrzeciecie(cR);
	std::vector<PunktPrzeciecia> vvPrzeciecia;
	if(p1.getCzyJest() && p1.getT() >= 0)
		vvPrzeciecia.push_back(p1);
	if(p2.getCzyJest() && p2.getT() >= 0)
		vvPrzeciecia.push_back(p2);
	if(p3.getCzyJest() && p3.getT() >= 0)
		vvPrzeciecia.push_back(p3);
	if(p4.getCzyJest() && p4.getT() >= 0)
		vvPrzeciecia.push_back(p4);
	if(p5.getCzyJest() && p5.getT() >= 0)
		vvPrzeciecia.push_back(p5);
	if(p6.getCzyJest() && p6.getT() >= 0)
		vvPrzeciecia.push_back(p6);
	double d_odl;
	PunktPrzeciecia wynik(false);
	for (unsigned int i = 0 ; i < vvPrzeciecia.size(); i++)
		if (!wynik.getCzyJest()) {
				wynik = vvPrzeciecia[i];
				d_odl = cR.getPunkt().dOdleglosc(wynik.getPunkt());
		}
		else {
			double curr_dist= cR.getPunkt().dOdleglosc(vvPrzeciecia[i].getPunkt());
			if(d_odl > curr_dist) {
				wynik = vvPrzeciecia[i];
				d_odl = curr_dist;
			}
		}
	wynik.setTyp("prostopadloscian");
	wynik.setIdBryly(s_id);
	return wynik;
}