#ifndef PUNKTPRZECIECIA_H
#define PUNKTPRZECIECIA_H

#include <string>
#include "Punkt3d.h"
using namespace std;

class PunktPrzeciecia {
	bool b_jest;
	Punkt3d c_wspolrzedne;
	double d_t;
	string s_typ;
	string s_id_bryly;

public:
	PunktPrzeciecia(bool bJest, Punkt3d cWspol, double dT, string sTyp, string sId):b_jest(bJest),c_wspolrzedne(cWspol),d_t(dT),s_typ(sTyp),s_id_bryly(sId) {}
	PunktPrzeciecia(bool bJest):b_jest(bJest),c_wspolrzedne(),d_t(0),s_typ(""),s_id_bryly("") {}
	PunktPrzeciecia(const PunktPrzeciecia & cPunkt):b_jest(cPunkt.b_jest),c_wspolrzedne(cPunkt.c_wspolrzedne),d_t(cPunkt.d_t),s_typ(cPunkt.s_typ),s_id_bryly(cPunkt.s_id_bryly) {}
	~PunktPrzeciecia() {}

	bool getCzyJest() { return b_jest; }
	Punkt3d & getPunkt() { return c_wspolrzedne; }
	double getT() { return d_t; }
	string getTyp() { return s_typ; }
	string getIdBryly() { return s_id_bryly; }
	void setTyp(string sTyp) { s_typ = sTyp; }
	void setIdBryly(string sIdBryly) { s_id_bryly = sIdBryly; }
};

#endif