#include "LiczZesp.hh"

;int CLiczZesp::vWczytaj() {
	cout << "Podaj czesc rzeczywista: ";
	cin >> d_re;
	if (cin.fail()) { cin.clear(); cin.ignore(1,'/n'); cerr << "Nieprawidlowa dana." << endl; return 1; }
	else {
		cout << "Podaj czesc urojona: ";
		cin >> d_im;
		if (cin.fail()) { cin.clear(); cin.ignore(10,'/n'); cerr << "Nieprawidlowa dana." << endl; return 1; }
		cout << endl;
		b_ok = (d_modul() > 0);
	}
	return 0;
}

void CLiczZesp::vWypisz() {
	cout << "Oto liczba: " << noshowpos << d_re << showpos << d_im << "i" << endl << endl;
}

CLiczZesp CLiczZesp::cDodaj(CLiczZesp cLiczba) {
	CLiczZesp c_ret;
	c_ret.d_re = d_re + cLiczba.d_re;
	c_ret.d_im = d_im + cLiczba.d_im;
	return c_ret;
}

CLiczZesp CLiczZesp::cOdejmij(CLiczZesp cLiczba) {
	CLiczZesp c_ret;
	c_ret.d_re = d_re - cLiczba.d_re;
	c_ret.d_im = d_im - cLiczba.d_im;
	return c_ret;
}

CLiczZesp CLiczZesp::cPomnoz(CLiczZesp cLiczba) {
	CLiczZesp c_ret;
	c_ret.d_re = d_re * cLiczba.d_re - d_im * cLiczba.d_im;
	c_ret.d_im = d_im * cLiczba.d_re + d_re * cLiczba.d_im;
	return c_ret;
}

CLiczZesp CLiczZesp::cPodziel(CLiczZesp cLiczba) {
	CLiczZesp c_ret;
	if (cLiczba.d_modul() == 0) cLiczba.b_ok = false;
	else {
		double d_dol = cLiczba.d_re * cLiczba.d_re + cLiczba.d_im * cLiczba.d_im;
		c_ret.d_re = (d_re * cLiczba.d_re + d_im * cLiczba.d_im) / d_dol;
		c_ret.d_im = (d_im * cLiczba.d_re - d_re * cLiczba.d_im) / d_dol;
	}
	return c_ret;
}