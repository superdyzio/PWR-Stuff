#include "modul.hh"

/*!
 *\file
 *\brief	Plik zawiera implementację metody z modułu 'modul.hh', czyli metody służącej do sortowania i wyświetlania zawartości pliku 
 *		'passwd' w odpowiedni sposób.
 */


void PrzetworzListe_Uzytkownikow_i_Grupy(const OpcjeWywolania & Opcje) {
  	DaneUzytkownika Danee;
  	ListaUzytkownikow Baza;
	ifstream fin;
	fin.open("passwd");
	bool Znalazl = false;
	if (fin.is_open()) {
		cout << "     Czyta plik passwd ..." << endl << "          operacja zakonczona powodzeniem." << endl << endl;
		do {
			fin >> Danee;
			if (Danee.getNorm()) (Baza.Lista).push_front(Danee);
		} while (!fin.eof());
		(Baza.Lista).pop_front();
		switch (Opcje.JakSortowac()) {
			case TS_WgNazwisk: 	(Baza.Lista).sort(Nazwiska);
						break;
			case TS_WgLoginow:	(Baza.Lista).sort(Loginy);
						break;
			case TS_WgIdUzytkownika:(Baza.Lista).sort(Idy);
						break;
		}
		switch (Opcje.JakSzukac()) {
			case TSz_NajwiekszyId:	Baza.Znajdz();
						Znalazl = true;
						break;
			case TSz_Login:		Baza.Znajdz(Opcje.WezLogin());
						if ((Baza.uzyt).getLogin() != "")
							Znalazl = true;
						break;
			case TS_WgIdUzytkownika:Baza.Znajdz(Opcje.WezIdUzytkownika());
						if ((Baza.uzyt).getID() != 0)
							Znalazl = true;
						break;
		}
		if (Znalazl) {
			for (list<DaneUzytkownika>::iterator it = (Baza.Lista).begin(); it != (Baza.Lista).end(); ++it)
				if ((*it).getID() != Baza.uzyt.getID() && (*it).getLogin() != Baza.uzyt.getLogin()) 
					cout << (*it) << endl;
			cout << endl << "----------------------------------------------------------------------" << endl << endl;
			cout << Baza.uzyt;
			(Baza.uzyt).getDane(cout);
			cout << endl << endl;
		}
		else {
			for (list<DaneUzytkownika>::iterator it = (Baza.Lista).begin(); it != (Baza.Lista).end(); ++it)
				cout << (*it) << endl;
			cout << endl << "----------------------------------------------------------------------" << endl << endl;
			cout << "Brak Uzytkownika odpowiadajacego zadanym parametrom" << endl << endl;
		}
	}
	fin.close();
}
