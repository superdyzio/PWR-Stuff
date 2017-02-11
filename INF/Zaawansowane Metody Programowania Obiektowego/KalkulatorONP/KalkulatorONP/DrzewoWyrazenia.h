#ifndef DRZEWOWYRAZENIA_H
#define DRZEWOWYRAZENIA_H

#include "TablicaSymboli.h"

class CWezel {
	CSymbol c_dana;
	CWezel *pc_lewy;
	CWezel *pc_prawy;
	bool b_czy_operator;
	string s_operator;

public:
	CWezel():c_dana(),pc_lewy(NULL),pc_prawy(NULL),b_czy_operator(false),s_operator("") {}
	CWezel(CSymbol cDana):c_dana(cDana),pc_lewy(NULL),pc_prawy(NULL),b_czy_operator(false),s_operator("") {}
	CWezel(string sOperator, CSymbol cLewy, CSymbol cPrawy):c_dana(),b_czy_operator(true),s_operator(sOperator) { pc_lewy = new CWezel(cLewy); pc_prawy = new CWezel(cPrawy); }
	~CWezel() {}

	bool bCzyOperator() { return b_czy_operator; }
	string sDajOperator() { return s_operator; }
	CWezel* cDajLewy() { return pc_lewy; }
	CWezel* cDajPrawy() { return pc_prawy; }
} typedef CWezel;

class CDrzewoWyrazenia {
	CWezel c_korzen;
	
public:
	CDrzewoWyrazenia():c_korzen() {}
	CDrzewoWyrazenia(CWezel cKorzen):c_korzen(cKorzen) {}
	~CDrzewoWyrazenia() {}

	bool vTworzDrzewo(string sWyrazenie);
	void vDajNiezdefiniowane();
	double dOblicz();
} typedef CDrzewoWyrazenia;
#endif