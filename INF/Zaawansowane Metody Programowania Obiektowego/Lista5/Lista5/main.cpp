#include "Scena.h"

int main(int argc, char* argv[]) {
	Scena proba;
	cout << "Utworzono pusta scene." << endl;
	cout << "Zaladowano dane z pliku dane.txt : " << proba.bZaladuj("dane.txt") << endl;
	/*Plaszczyzna3d *plaszcz= new Plaszczyzna3d("obiekt3", 5, 5, 5, 2, 2, 2);
	try{
		proba.dodajBryle(plaszcz);
		cout << "Dodano do sceny nowa plaszczyzne." << endl;
	}
	catch(ElementIstnieje &e)
	{
		cout << e.what() << endl;
	}
	cout << "Usunieto ze sceny plaszczyzne obiekt3: " << proba.usunBryle("obiekt3") << endl;*/
	PunktPrzeciecia wynik = proba.cNajblizszePrzeciecie(Promien3d(0, 0, 0, 1, 0, 0));
	cout << "Najblizsze znalezione przeciecie dla promienia[srodek(0, 0, 0); wektor(1, 0, 0)]ma wspolrzedne: " << wynik.getPunkt().getX() << " " << wynik.getPunkt().getY() << " "
		<< wynik.getPunkt().getZ() << " wartosc parametru t = " << wynik.getT() << endl;
	/*cout << "Dodano do sceny prostokat prostopadly do osi OX, d = 1, umin = 0, umax= 4, vmin = 0, vmax= 4. " << endl;
	Prostokat3d prost("Obiekt6", 'x', 1, 0, 4, 0, 4);
	proba.vDodajBryle(&prost);
	wynik = proba.cNajblizszePrzeciecie(Promien3d(0, 0, 0, 1, 0, 0));
	cout << "Najblizsze znalezione przeciecie dla promienia[srodek(0, 0, 0); wektor(1, 0, 0)]ma wspolrzedne: " << wynik.getPunkt().getX() << " " << wynik.getPunkt().getY() << " "
		<< wynik.getPunkt().getZ() << " wartosc parametru t = " << wynik.getT() << endl;
	//cout << "Zapisano scene do pliku dane.txt : " << 	proba.zapisz("dane.txt") << endl;

	
	// DO TESTOWANIA POSZCZEGÓLNYCH BRY£
	//Prostokat3d prost("Obiekt4", 'x', 2, 0, 4, 0, 4);
	/*Kula prost("Obiekt10", 2, 2, 2, 1);*/
	/*Walec prost("Obiekt11", 4, 0, 0, 1, 'y');*/
	/*Plaszczyzna3d prost("Obiekt12", 5, 0, 0, 1, 0, 0);*/
	/*Prostopadloscian prost("Obiekt13", 3, 5, 0, 5, 0, 5);
	Promien3d prom(0, 0, 0, 1, 0, 0);
	PunktPrzeciecia wynik = prost.znajdzPrzeciecie(prom);
	if(wynik.czyZnaleziono())
		cout << "Wyliczona wartosc parametru t= " << wynik.get_param_t() << endl << "Wspolrzedne punktu przeciecia: " << wynik.getPunkt().getX() << " " << wynik.getPunkt().getY() << " "
		 << wynik.getPunkt().getZ() << endl;
	else
		cout << "Nic nie znaleziono. " << endl;*/
	system("pause");
	return 0;
}