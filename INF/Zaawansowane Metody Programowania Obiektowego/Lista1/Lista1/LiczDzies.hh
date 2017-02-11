#ifndef LICZDZIES_HH
#define LICZDZIES_HH

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

;using namespace std;

#define MAX_SIZE 100
#define DEFAULT_SIZE 10

class CLiczDzies {
	int* pi_liczba;
	int d_dlugosc;

	void v_zeruj(int* tab);

public:
	CLiczDzies() { d_dlugosc = DEFAULT_SIZE; pi_liczba = new int[d_dlugosc]; v_zeruj(pi_liczba); }
	CLiczDzies(int dDl) { d_dlugosc = dDl; pi_liczba = new int[d_dlugosc]; v_zeruj(pi_liczba); }
	~CLiczDzies() {};

	void vWypiszD();
	friend CLiczDzies vWczytajD();
	CLiczDzies cDodajD(CLiczDzies cLiczba);
	CLiczDzies cOdejmijD(CLiczDzies cLiczba);
	CLiczDzies cPomnozD(CLiczDzies cLiczba);
} typedef CLiczDzies;

#endif