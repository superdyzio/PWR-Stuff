#include "zespolone.hh"

/*!
 *\file
 *\brief	Plik zawiera implementacje metod z nagłówka 'zespolone.hh'.
*/

ostream & operator << (ostream & wyj, Zespolona x) {
	return wyj << '(' << x.Re << showpos << x.Im << noshowpos << 'i' << ')';
}

istream & operator >> (istream & wej, Zespolona & x) {
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
