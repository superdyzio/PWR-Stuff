#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "Okrag.h"

#define PODAJP "Podaj wspolrzedne x i y punktu: "

using namespace std;

class CPunkt {
	float d_x;					// wspolrzedna x punktu
	float d_y;					// wspolrzedna y punktu
public:
	CPunkt():d_x(0),d_y(0) {};
	CPunkt(float dA, float dB):d_x(dA),d_y(dB) {};
	~CPunkt() {};
	friend float dOdl(CPunkt cPunkt1, CPunkt cPunkt2);
} typedef CPunkt;

float dOdl(CPunkt cPunkt1, CPunkt cPunkt2) {
	return sqrt(pow(cPunkt1.d_x - cPunkt2.d_x,2) + pow(cPunkt1.d_y - cPunkt2.d_y,2));
}

#endif