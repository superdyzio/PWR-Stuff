#ifndef TABLICA2W_H
#define TABLICA2W_H

#include <ctime>
#include <cstdlib>
#include <iostream>
;
using namespace std;

class Tablica2W {
	int **tablica;
	int wiersze, kolumny;
	bool utworzona;
public:
	Tablica2W(int n, int m):wiersze(n),kolumny(m) { tablica = new int * [wiersze]; for (int i = 0; i < kolumny; i++) tablica[i] = new int[kolumny]; }
	~Tablica2W() {}

	void wypelnij(int x);
	void wyswietl();
	int max();
};

#endif