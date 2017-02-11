#ifndef OKRAG_H
#define OKRAG_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Punkt.h"

#define PODAJO "Podaj wspolrzedne x i y srodka okregu oraz dlugosc jego promienia: "
#define WYNIK "Odleglosc punktu od okregu wynosi: "
#define WEW "Punkt lezy wewnatrz okregu!"

using namespace std;

class COkrag {
	CPunkt c_srodek;	// punkt stanowi¹cy œrodek okrêgu
	float d_r;			// promieñ okrêgu
public:
	COkrag():c_srodek(),d_r(1) {};
	COkrag(float dA, float dB, float dR):c_srodek(dA,dB),d_r(dR) {};
	~COkrag() {};
	friend float dOdleglosc(CPunkt cPunkt, COkrag cOkrag);
} typedef COkrag;

float dOdleglosc(CPunkt cPunkt, COkrag cOkrag) {
	return dOdl(cPunkt,cOkrag.c_srodek) - cOkrag.d_r;
}

#endif