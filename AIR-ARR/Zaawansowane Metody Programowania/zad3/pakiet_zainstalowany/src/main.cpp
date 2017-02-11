/*
$HeadURL: file:///home/dperdek/repos/z1/trunk/src/main.cpp $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (Tue, 17 Nov 2015) $
$Revision: 9 $
*/

#include "menu.hh"

using namespace std;

/*!
 * \file
 * \brief Plik zawierający funkcję main() programu.
 */

int main() {
	int wybor = -1;
	istringstream dane;
	Menu menu;
	string nazwa;
	PzG::LaczeDoGNUPlota lacze;
	RobotMobilny robot(&lacze);
	lacze.Inicjalizuj();
	lacze.ZmienTrybRys(PzG::TR_2D);
	lacze.UstawZakresY(-10,40);
	lacze.UstawZakresX(-10,40);
	robot.Init();
	while (wybor != 0) {
		menu.wyswietlMenu();
		cin >> wybor;
		switch (wybor) {
			case 1:	cout << "Podaj nazwę pliku: ";
				cin >> nazwa;
				if (!menu.wczytajPlik(dane,nazwa))
					cout << "Błąd wczytywania pliku." << endl;
				if (!menu.wczytajKomendy(dane))
					cout << "Błąd wczytywania komend." << endl;
				break;
			case 2:	menu.wyswietlKomendy();
				break;
			case 3:	menu.wyswietlListe(); 
				break;
			case 4:	menu.wykonajSekwencje(robot);
				break;
			case 5:	cout << "Podaj nazwę pliku z wtyczką: ";
				cin >> nazwa;
				menu.dodaj(nazwa.c_str());
				break;
			case 6:	cout << "Podaj nazwę wtyczki: ";
				cin >> nazwa; 
				if (!menu.usun(nazwa.c_str()))
					cout << "Operacja nieudana." << endl;
				break;
			case 0:	break;
		default:	cout << "Niepoprawne polecenie." << endl;
				break;	
		}
	}
	return 0;
}
