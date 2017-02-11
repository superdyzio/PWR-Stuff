#ifndef LICZZESP_H
#define LICZZESP_H

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>

#define ZLE "Dzielenie niepoprawne!"
#define PODAJ "Podaj liczbe zespolona:"
#define POSTAC "Wprowadzona liczba zespolona: "
#define DOD "Wynik dodawania: "
#define ODJ "Wynik odejmowania: "
#define MNOZ "Wynik mnozenia: "
#define DZIEL "Wynik dzielenia: "

using namespace std;

class CLiczZesp {
	double d_re, d_im;		// sk³adowe rzeczywista i urojona liczby zespolonej
	bool b_ok;				// zmienna mówi¹ca o tym czy przez dan¹ liczbê mo¿na dzieliæ (true jeœli mo¿na)
	
	float d_modul() { return (float) sqrt((d_re * d_re) + (d_im * d_im)); }
	CLiczZesp c_sprzezenie() { CLiczZesp c_liczba; c_liczba.d_re = d_re; c_liczba.d_im = -d_im; return c_liczba; }

public:
	CLiczZesp() { d_re = d_im = 0; b_ok = false; }
	CLiczZesp(float dX, float dY) { d_re = dX; d_im = dY; b_ok = (d_modul() > 0); }
	CLiczZesp(const CLiczZesp & cZ):d_re(cZ.d_re),d_im(cZ.d_im),b_ok(cZ.b_ok) {};
	~CLiczZesp() {}

	bool b_get_ok() { return b_ok; }

	friend ostream & operator << (ostream & cWyj, const CLiczZesp cZ);
	friend istream & operator >> (istream & cWej, CLiczZesp & cZ);
	friend CLiczZesp operator + (const CLiczZesp cA, CLiczZesp cB);
	friend CLiczZesp operator - (const CLiczZesp cA, CLiczZesp cB);
	friend CLiczZesp operator * (const CLiczZesp cA, CLiczZesp cB);
	friend CLiczZesp operator / (const CLiczZesp cA, CLiczZesp cB);
	friend bool operator == (const CLiczZesp cA, const CLiczZesp cB);
} typedef CLiczZesp;

#endif