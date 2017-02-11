#ifndef TABLICASYMBOLI_H
#define TABLICASYMBOLI_H

#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

class CSymbol {
	bool b_zmienna;			// zmienna przechowujaca informacje czy dany obiekt jest zmienna (true) czy stala (false)
	bool b_wartosc;			// zmienna przechowujaca informacje czy dany obiekt ma wartosc
	double d_wartosc;		// zmienna przechowujaca wartosc zmiennej/stalej (lub 0 jesli zmienna nie ma wartosci -> b_wartosc = false)
	string s_nazwa;			// zmienna przechowujaca podana nazwe zmiennej lub wygenerowana nazwe stalej

	string s_stworz_nazwe() { iNrStalej++; string s_pom = "::";  ostringstream c_str; c_str << iNrStalej; s_pom += c_str.str(); return s_pom; }
public:
	static int iNrStalej;			// statyczne pole zliczajace ilosc utworzonych do tej pory stalych - sluzy do generowania nazw
	CSymbol():b_zmienna(false),b_wartosc(false),d_wartosc(0),s_nazwa("") {}
	CSymbol(int dWart):b_zmienna(false),b_wartosc(true),d_wartosc(dWart),s_nazwa(s_stworz_nazwe()) {}
	CSymbol(string sNazwa):b_zmienna(true),b_wartosc(false),d_wartosc(0),s_nazwa(sNazwa) {}
	CSymbol(int dWart, string sNazwa):b_zmienna(true),b_wartosc(true),d_wartosc(dWart),s_nazwa(sNazwa) {}
	~CSymbol() {}
	bool bCzyZmienna() { return b_zmienna; }
	bool bCzyMaWartosc() { return b_wartosc; }
	void vDajWartosc(double dWart) { d_wartosc = dWart; }
	double iWezWartosc() { return d_wartosc; }
	string sWezNazwe() { return s_nazwa; }
} typedef CSymbol;


class CTablicaSymboli {
	vector<CSymbol> c_dane;

public:
	CTablicaSymboli() {}
	~CTablicaSymboli() {}

	bool bUstalWartosc(string sNazwa, double dWartosc);
	double dDajWartosc(string sNazwa);
	bool bCzyZdefiniowana(string sNazwa);
	void vKasujWszystko() { c_dane.clear(); CSymbol::iNrStalej = 0; }
} typedef CTablicaSymboli;

#endif