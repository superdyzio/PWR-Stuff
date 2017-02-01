#include "zespolone.hh"

/*! 
 *\file	
 *\brief	Plik zawierający implementację wybranych przeciążeń operatorów oraz dwóch funkcji z modułu zespolone.hh.
*/

ostream & operator << (ostream & wyj, Zespolona x) {
	if (Zespolona::NotacjaWykWyj) if (x.fi != 360) return wyj << '(' << x.modul << "e^i" << x.fi << ")";
					else { cerr << "Argument nie zdefiniowany!"; return wyj; }
	else return wyj << '(' << x.Re << showpos << x.Im << noshowpos << 'i' << ')';
}

istream & operator >> (istream & wej, Zespolona & x) {
	if (Zespolona::NotacjaWykWej) {
		string linia;
		wej >> linia;
		if (wej.fail()) return wej;
		if (linia[0] == '(') {
			linia = linia.substr(1);
			x.modul = atof(linia.c_str());
		}
		else {
			wej.setstate(ios::failbit);
			return wej;
		}
		linia = linia.substr(linia.find('e'));
		if (linia[0] == 'e' && linia[1] == '^' && linia[2] == 'i') {
			linia = linia.substr(3);
			x.fi = atof(linia.c_str());
			if (linia.find(')') == string::npos) {
				wej.setstate(ios::failbit);
				return wej;
			}
			else {
				x.Re = x.modul * cos(x.fi);
				x.Im = x.modul * sin(x.fi);
			}
		}
		else {
			wej.setstate(ios::failbit);
			return wej;
		}
	}
	else {
		if ( (wej.peek() == ' ') || (wej.peek() == '\n') ) wej.ignore();
		if (wej.peek() == '(') {
			wej.ignore();
			wej >> x.Re >> x.Im;
			if (wej.fail()) return wej;
			if (wej.peek() != 'i') {
				wej.setstate(ios::failbit); 
				return wej;
			}
			wej.ignore();
			if (wej.peek() != ')') {
				wej.setstate(ios::failbit); 
				return wej;
			}
			wej.ignore();
			x.OK = true;
			return wej;
		}
		else {
			wej.setstate(ios::failbit);
			return wej;
		}
	}
	return wej;
}

Zespolona Zespolona::operator * (Zespolona a) {
	Zespolona pom = a;
	a.Re = ((Re) * (a.Re)) - ((a.Im) * (Im));
	a.Im = ((Re) * (pom.Im)) + ((pom.Re) * (Im));
	return a;
}

Zespolona Zespolona::operator / (Zespolona a) {
	float dzielnik = ((a.Re) * (a.Re)) + ((a.Im) * (a.Im));	
	if (dzielnik != 0) {
		a.Sprzezenie();
		a.operator*(*this);
		a.Re = a.Re / dzielnik;
		a.Im = a.Im / dzielnik;
	}
	else {
		cerr << "Dzielenie niepoprawne!";
		a.OK = false;
	}
	return a;
}

void Zeruj(Zespolona &x) {
	x.Re = x.Im = 0;
}

void Zespolona::wykladnicza() {
	modul = sqrt(pow(Re,2)+pow(Im,2));
	if (modul == 0) fi = 360;
	else fi = atan2(Im,Re);
}
