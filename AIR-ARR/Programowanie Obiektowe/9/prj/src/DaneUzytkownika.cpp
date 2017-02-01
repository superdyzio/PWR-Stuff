#include "DaneUzytkownika.hh"

/*!
 *\file
 *\brief	Plik zawierający implementacje wszystkich metod klasy DaneUzytkownika oraz przeciążeń operatorów wejścia/wyjścia.
*/

DaneUzytkownika::DaneUzytkownika() {
	Login = "";
	Imie = "";
	Nazwisko = "";
	Dane = "";
	ID = 0;
	CzyNormalny = false;
}
			
bool DaneUzytkownika::getNorm() {
	return CzyNormalny;
}
		
void DaneUzytkownika::getDane(ostream & wyj) {
	wyj << Dane;
}
		
string DaneUzytkownika::getLogin() {
	return Login;
}
		
int DaneUzytkownika::getID() {
	return ID;
}

ostream & operator << (ostream & wyj, DaneUzytkownika & D) {
	wyj.width(8);
	wyj << D.Login << " ";
	wyj.width(6);
	wyj << D.ID << " ";
	wyj.width(10);
	wyj << D.Imie << " ";
	wyj << D.Nazwisko << " ";
	return wyj;
}

istream & operator >> (istream & wej,  DaneUzytkownika & D) {
	string pomoc;
	unsigned l, m;
	wej >> pomoc;
	if (wej.fail()) return wej;
	else {
		l = pomoc.length();
		m = pomoc.find(":");
		D.Login = pomoc.substr(0,m);
		pomoc = pomoc.substr(m+3,l);
		m = pomoc.find(":");
		D.ID = atoi(pomoc.c_str());
		pomoc = pomoc.substr(m+1,l);
		m = pomoc.find(":");
		pomoc = pomoc.substr(m+1,l);
		D.Imie = pomoc.substr(0,l);
		if (D.Imie[0] >= 'A' && D.Imie[0] <= 'Z' && D.ID >= 1000) {
			D.CzyNormalny = true;
			wej >> pomoc;
			if (wej.fail()) return wej;
			else {	
				m = pomoc.find(",");
				if (m != string::npos) {
					D.Nazwisko = pomoc.substr(0,m);
					pomoc = pomoc.substr(m+1,l);
					m = pomoc.find(":");
					D.Dane = pomoc.substr(0,m);
					if ((D.Dane).compare(",,") == 0) D.Dane = "";
				}
				else {
					D.Nazwisko = "";
					D.Dane = "";
				}
				if (D.ID >= 1000 && D.Nazwisko != "") D.CzyNormalny = true;
				else D.CzyNormalny = false;
			}
		}
		else D.CzyNormalny = false;
	}
	return wej;
}
