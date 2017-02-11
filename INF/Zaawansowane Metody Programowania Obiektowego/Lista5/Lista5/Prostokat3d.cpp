#include "Prostokat3d.h"

PunktPrzeciecia Prostokat3d::cZnajdzPrzeciecie(Promien3d & cR) {
	if (h_os == 'x' || h_os == 'X' ) {
		double t = -(cR.getPX() - d_d)/cR.getWX();
		if (t >= 0) {
			double x = cR.getPX() + cR.getWX() * t;
			double y = cR.getPY() + cR.getWY() * t;
			double z = cR.getPZ() + cR.getWZ() * t;
			if(y >= d_umin && y <= d_umax && z >= d_vmin && z <= d_vmax)
				return PunktPrzeciecia(true,Punkt3d(x,y,z),t,"prostokat",s_id);
			else
				return PunktPrzeciecia(false);
			}
		else
			return PunktPrzeciecia(false);	
	}
	else 
		if (h_os == 'y' || h_os == 'Y') {
			double t = -(cR.getPY() - d_d)/cR.getWY();
			if (t >= 0) {
				double x = cR.getPX() + cR.getWX() * t;
				double y = cR.getPY() + cR.getWY() * t;
				double z = cR.getPZ() + cR.getWZ() * t;
				if(x >= d_umin && x <= d_umax && z >= d_vmin && z <= d_vmax)
					return PunktPrzeciecia(true,Punkt3d(x,y,z),t,"prostokat",s_id);
				else
					return PunktPrzeciecia(false);
			}
			else
				return PunktPrzeciecia(false);
		}
		else {
			double t = -(cR.getPZ() - d_d)/cR.getWZ();
			if (t >= 0) {
				double x = cR.getPX() + cR.getWX() * t;
				double y = cR.getPY() + cR.getWY() * t;
				double z = cR.getPZ() + cR.getWZ() * t;
				if(x >= d_umin && x <= d_umax && y >= d_vmin && y <= d_vmax)
					return PunktPrzeciecia(true,Punkt3d(x,y,z),t,"prostokat",s_id);
				else
					return PunktPrzeciecia(false);
			}
			else
				return PunktPrzeciecia(false);
		}
}

bool Prostokat3d::bWczytaj(istream & in) {
	double dUmin, dUmax, dVmin, dVmax, dD;
	char hOs;
	string sNazwa;
	in >> sNazwa;
	if (!in)
		return false;
	in >> dUmin;
	if (!in)
		return false;
	in >> dUmax;
	if (!in)
		return false;
	in >> dVmin;
	if (!in)
		return false;
	in >> dVmax;
	if (!in)
		return false;
	in >> dD;
	if (!in)
		return false;
	in >> hOs;
	if (!in)
		return false;
	s_id = sNazwa;
	d_d = dD;
	d_umin = dUmin;
	d_umax = dUmax;
	d_vmin = dVmin;
	d_vmax = dVmax;
	h_os = hOs;
	return true;
}

bool Prostokat3d::bZapisz(ostream & out) {
	string sDoZapisu1 = "prostokat";
	string sDoZapisu2 = '\n' + s_id + " " + to_string(d_umin) + " " + to_string(d_umax) + " " + to_string(d_vmin) + " " + to_string(d_vmax) + " " + to_string(d_d) + " " + h_os + '\n';
	out << sDoZapisu1 << sDoZapisu2;
	return out.good();
}
