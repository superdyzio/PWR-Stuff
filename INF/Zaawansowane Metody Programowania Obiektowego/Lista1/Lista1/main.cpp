#include "LiczZesp.hh"
#include "LiczDzies.hh"

;int main() {
	char wybor = 'a';
	int d_licznik;
	CLiczZesp c_liczba1, c_liczba2, c_wynik;
	while (wybor != '0') {
		cout << "----------MENU----------" << endl << "1 - wprowadzenie dwoch liczb" << endl << "2 - dodawanie" << endl <<
			"3 - odejmowanie" << endl << "4 - mnozenie" << endl << "5 - dzielenie" << endl << "0 - KONIEC" << endl;
		cin >> wybor;
		switch(wybor) {
		case '1': 
					d_licznik = 3; 
					while (d_licznik > 0 && c_liczba1.vWczytaj() == 1) { 
						d_licznik--; 
					} 
					c_liczba1.vWypisz(); 
					d_licznik = 3; 
					while (d_licznik > 0 && c_liczba2.vWczytaj() == 1) { 
						d_licznik--;
					}
					c_liczba2.vWypisz(); 
			break;
		case '2': c_wynik = c_liczba1.cDodaj(c_liczba2); c_wynik.vWypisz();				break;
		case '3': c_wynik = c_liczba1.cOdejmij(c_liczba2); c_wynik.vWypisz();			break;
		case '4': c_wynik = c_liczba1.cPomnoz(c_liczba2); c_wynik.vWypisz();			break;
		case '5': 
					if (c_liczba2.b_get_ok()) {
						c_wynik = c_liczba1.cPodziel(c_liczba2);
						c_wynik.vWypisz();
					}	// if (b.b_get_ok())
					else cout << "Nie mozna dzielic przez te liczbe." << endl;
			break;
		case '0': cout << "PAPA" << endl;							break;
		} // switch(wybor)
	} // while (wybor != '0')
/*	CLiczDzies a,b;
	a = vWczytajD();
	a.vWypiszD();
	b = vWczytajD();
	b.vWypiszD();
	CLiczDzies c = a.cDodajD(b);
	c.vWypiszD();
	int x; cin >> x; */
	return 0;
}