#include "ListaUzytkownikow.hh"

/*!
 *\file
 *\brief	Plik zawierający implementację wszystkich metod klasy ListaUzytkownikow.
*/

ListaUzytkownikow::ListaUzytkownikow(){
	uzyt.ID = 0;
	uzyt.Login = "";
}
	
void ListaUzytkownikow::Znajdz(){
	for (list<DaneUzytkownika>::iterator it = (this->Lista).begin(); it != (this->Lista).end(); ++it)
			if (uzyt.ID < (*it).ID) 
				uzyt = (*it);
}
	
void ListaUzytkownikow::Znajdz(string PoczatekLoginu) {
	int l = PoczatekLoginu.length();
	for (list<DaneUzytkownika>::iterator it = (this->Lista).begin(); it != (this->Lista).end(); ++it)
		if (((*it).Login).compare(0,l,PoczatekLoginu) == 0) 
			uzyt = (*it);
}
	
void ListaUzytkownikow::Znajdz(int Id) {
	for (list<DaneUzytkownika>::iterator it = (this->Lista).begin(); it != (this->Lista).end(); ++it)
		if ((*it).ID == Id)
			uzyt = (*it);
}

bool Nazwiska(DaneUzytkownika x, DaneUzytkownika y) {
	if (x.Nazwisko != y.Nazwisko) {
		unsigned int i = 0;
  		while ( (i < (x.Nazwisko).length()) && (i < (y.Nazwisko).length()) ) {
    			if (tolower(x.Nazwisko[i]) < tolower(y.Nazwisko[i])) return true;
    			else	if (tolower(x.Nazwisko[i]) > tolower(y.Nazwisko[i])) return false;
    			++i;
  		}
  		if ((x.Nazwisko).length() < (y.Nazwisko).length()) return true;
  		else return false;
	}
	else {
		if (x.Imie != y.Imie) {
			unsigned int i = 0;
			while ( (i < (x.Imie).length()) && (i < (y.Imie).length()) ) {
    				if (tolower(x.Imie[i]) < tolower(y.Imie[i])) return true;
    				else	if (tolower(x.Imie[i]) > tolower(y.Imie[i])) return false;
    				++i;
  			}
  			if ((x.Imie).length() < (y.Imie).length()) return true;
  			else return false;
		}
		else {
			if (x.ID > y.ID) return true;
			else return false;
		}
	}
}

bool Loginy(DaneUzytkownika x, DaneUzytkownika y) {
	unsigned int i = 0;
  	while ( (i < (x.Login).length()) && (i < (y.Login).length()) ) {
    		if (tolower(x.Login[i]) < tolower(y.Login[i])) return true;
    		else	if (tolower(x.Login[i]) > tolower(y.Login[i])) return false;
    		++i;
  	}
  	if ((x.Login).length() < (y.Login).length()) return true;
  	else return false;
}

bool Idy (DaneUzytkownika x, DaneUzytkownika y) {
	if (x.ID < y.ID) return true;
	else return false;
}
