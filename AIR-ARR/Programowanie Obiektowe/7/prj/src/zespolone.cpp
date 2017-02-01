#include "zespolone.hh"

/*!
 *\file
 *\brief	Plik zawiera implementacje metod z nagłówka 'zespolone.hh'.
*/

ostream & operator << (ostream & wyj, Zespolona z) {
	return wyj << '(' << z.Re << showpos << z.Im << noshowpos << 'i' << ')';
}

istream & operator >> (istream & wej, Zespolona & z) {
	if ( (wej.peek() == ' ') || (wej.peek() == '\n') ) wej.ignore();
	if (wej.peek() == '(') {
		wej.ignore();
		wej >> z.Re >> z.Im;
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
		z.OK = true;
		return wej;
	}
	else {
		wej.setstate(ios::failbit);
		return wej;
	}
}

Zespolona operator + (Zespolona a, Zespolona b) {
	b.Re = (a.Re) + (b.Re);
	b.Im = (a.Im) + (b.Im);
	return b;
}

Zespolona Sprzezenie (Zespolona z) {
	z.Im = (-(z.Im));
	return z;
}

Zespolona operator - (Zespolona a, Zespolona b) {
	b.Re = (a.Re) - (b.Re);
	b.Im = (a.Im) - (b.Im);
	return b;
}

Zespolona operator * (Zespolona a, Zespolona b) {
	Zespolona pom = b;
	b.Re = ((a.Re) * (b.Re)) - ((b.Im) * (a.Im));
	b.Im = ((a.Re) * (pom.Im)) + ((pom.Re) * (a.Im));
	return b;
}

Zespolona operator / (Zespolona a, Zespolona b) {
	float dzielnik = ((b.Re) * (b.Re)) + ((b.Im) * (b.Im));	
	if (dzielnik != 0) {
		b = a * Sprzezenie(b);
		b.Re = b.Re / dzielnik;
		b.Im = b.Im / dzielnik;
	}
	else {
		cerr << "Dzielenie niepoprawne!";
		b.OK = false;
	}
	return b;	
}

bool operator == (Zespolona a, Zespolona b) {
	return ( (a.Re == b.Re) && (a.Im == b.Im) );
}

Zespolona Zeruj(Zespolona z) {
	z.Re = z.Im = 0;
	return z;
}
