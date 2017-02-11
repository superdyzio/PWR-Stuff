#ifndef LICZZESP_HH
#define LICZZESP_HH

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class CLiczZesp {
	double d_re, d_im;		// sk³adowe rzeczywista i urojona liczby zespolonej
	bool b_ok;				// zmienna mówi¹ca o tym czy przez dan¹ liczbê mo¿na dzieliæ (true jeœli mo¿na)
	
	float d_modul() { return sqrt((d_re * d_re) + (d_im * d_im)); }
	CLiczZesp c_sprzezenie(CLiczZesp cLiczba) { cLiczba.d_im *= (-1); return cLiczba; }

public:
	CLiczZesp() { d_re = d_im = 0; b_ok = false; }
	CLiczZesp(float dX, float dY) { d_re = dX; d_im = dY; b_ok = (d_modul() > 0); }
	~CLiczZesp() {}

	bool b_get_ok() { return b_ok; }
	int vWczytaj();
	void vWypisz();
	CLiczZesp cDodaj(CLiczZesp cLiczba);
	CLiczZesp cOdejmij(CLiczZesp cLiczba);
	CLiczZesp cPomnoz(CLiczZesp cLiczba);
	CLiczZesp cPodziel(CLiczZesp cLiczba);
} typedef CLiczZesp

#endif;