#include "Okrag.h"
#include "Punkt.h"
#include "LiczZesp.h"
#include <conio.h>


int main() {
	
	float dXP, dYP, dXO, dYO, dRO;			// zmienne do wczytania parametrów P - punktu i O - okregu
	cout << PODAJP << endl;
	cin >> dXP >> dYP;
	CPunkt cPunkt(dXP,dYP);
	cout << PODAJO << endl;
	cin >> dXO >> dYO >> dRO;
	COkrag cOkrag(dXO,dYO,dRO);
	float dOdleg = dOdleglosc(cPunkt,cOkrag);
	if (dOdleg < 0) cout << WEW << endl << endl;
	else cout << WYNIK << dOdleglosc(cPunkt,cOkrag) << endl << endl;
	
	CLiczZesp cLiczba1, cLiczba2;
	do {
		if (cin.fail()) { cin.clear(); cin.ignore(); }
		cout << PODAJ << endl;
		cin >> cLiczba1;
	} while (cin.fail());
	do {
		if (cin.fail()) { cin.clear(); cin.ignore(); }
		cout << PODAJ << endl;
		cin >> cLiczba2;
	} while (cin.fail());
	cout << DOD << cLiczba1+cLiczba2 << endl;
	cout << ODJ << cLiczba1-cLiczba2 << endl;
	cout << MNOZ << cLiczba1*cLiczba2 << endl;
	if (cLiczba2.b_get_ok()) cout << DZIEL << cLiczba1/cLiczba2 << endl;
	else cout << ZLE << endl;
	
	_getch();
	return 0;
}