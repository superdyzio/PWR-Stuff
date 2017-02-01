#include <iostream>
#include <unistd.h>
#include "UkladSygnalowy.hh"
#include "ListaBlokow.hh"
#include "BlokGeneratora.hh"
#include "BlokOscyloskopu.hh"
#include "BlokCalkujacy.hh"
#include "BlokDyskryminujacy.hh"
#include "BlokPotegujacy.hh"
#include "BlokPrzesuwajacy.hh"
#include "BlokProstujacy.hh"
#include "BlokWzmacniajacy.hh"
#include "BlokSygnalowy.hh"

/*!
 *\file
 *\brief	Plik główny programu.
*/

using namespace std;

int main(int argc, char** argv) {
	int opt = -1;
	char wybor;
   	UkladSygnalowy Lista;
    	bool CzyRejestrator = false;
   	char* wyj;
	double pom = 0;
	char a = 'a';
	wyj = &a;
    	// przetwarzanie argumentów wywołania programu
    	if (argc > 1) {
        	if (argv[1][1] == 'i') {
            		while ( (opt = getopt(argc, argv, "i:o:GW:P:SCD:")) != -1) {
                		switch (opt) {
                		case 'i':	Lista.DodajGenerator(optarg);				break;
                		case 'o':	CzyRejestrator = true; wyj = optarg;                    break;
                		case 'W':	Lista.DodajBlokWzmacniajacy(optarg);			break;
                		case 'G':	Lista.DodajBlokPotegujacy();				break;
                		case 'P':	Lista.DodajBlokPrzesuwajacy(optarg);			break;
                		case 'S':	Lista.DodajBlokProstujacy();				break;
                		case 'C':	Lista.DodajBlokCalkujacy();				break;
                		case 'D':	Lista.DodajBlokDyskryminujacy(optarg);			break;
                		default:	cerr << "Bledne wywolanie programu." << endl;	return 1;      
				}
			}
			//Lista.DodajOscyloskop(0,10,-5,5,"wyjscie_syg/tmp_osc1.syg")->ZmienTytulOkienka("Sygnal ze srodka polaczenia");
            		if (CzyRejestrator) Lista.DodajRejestrator(wyj);
            		if (!Lista.RozpocznijPrace()) {
                		cerr << "Rozpoczęcie pracy bloków nie powiodło się." << endl;
                		return 1;
            		}
            		while (!Lista.WyliczSygnal());
            		cout << endl << "*** Nacisnij ENTER aby zakonczyc ***" << endl;
            		cin.ignore();
            		Lista.ZakonczPrace();
			}
        	else cerr << "Pierwszym argumentem musi być blok generatora (-i oraz nazwa pliku wejściowego)." << endl;
	}
    	else {
    		cout << endl << "INTERFEJS UŻYTKOWNIKA" << endl << endl;
		cout << "Podaj nazwę pliku wejściowego: ";
		cin >> wyj;
		Lista.DodajGenerator(wyj);
		cout << "Podaj nazwę pliku wyjściowego: ";
		cin >> wyj;
		CzyRejestrator = true;
		while (opt != 0) {
			cout << endl << "Wciśnij 1 by dodać blok lub 2 by usunąć." << endl << "0 by zakończyć." << endl;
			cin >> opt;
			switch (opt) {
			case 1:	cout << "Podaj literke bloku do dodania: ";
				cin >> wybor;
				break;
			case 2: cout << "Podaj numer bloku do usunięcia: ";
				cin >> wybor;
				break;
			}
			if (opt == 1) 
                		switch (wybor) {
                		case 'W':	cout << "Podaj wzmocnienie: ";
						cin >> pom;
						Lista.DodajBlokWzmacniajacy(pom);
						cout << "Dodano blok wzmacniający." << endl;			
						break;
                		case 'G':	Lista.DodajBlokPotegujacy();
						cout << "Dodano blok potęgujący." << endl;
						break;
                		case 'P':	cout << "Podaj przesunięcie: ";
						cin >> pom;
						Lista.DodajBlokPrzesuwajacy(pom);
						cout << "Dodano blok przesuwający." << endl;
						break;
                		case 'S':	Lista.DodajBlokProstujacy();			
						cout << "Dodano blok prostujący." << endl;
						break;
                		case 'C':	Lista.DodajBlokCalkujacy();				
						cout << "Dodano blok całkujący." << endl;
						break;
                		case 'D':	cout << "Podaj próg dyskryminacji: ";
						cin >> pom;
						Lista.DodajBlokDyskryminujacy(pom);		
						cout << "Dodano blok dyskryminujący." << endl;	
						break;
				default:	cout << "Błędne wywołanie bloku." << endl;
				}
			if (opt == 2)
				switch (wybor) {
				}
		}
         	if (CzyRejestrator) Lista.DodajRejestrator(wyj);
            	if (!Lista.RozpocznijPrace()) {
               		cerr << "Rozpoczęcie pracy bloków nie powiodło się." << endl;
               		return 1;
       		}
        	while (!Lista.WyliczSygnal());
            	Lista.ZakonczPrace();
	}
	return 0;
}
