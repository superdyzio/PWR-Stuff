#include "zespolone.hh"

ostream & operator << (ostream & wy, Zespolona x) {
	return wy << '(' << x.Re << showpos << x.Im << noshowpos << 'i' << ')';
}

istream & operator >> (istream & we, Zespolona & x) {
	if ( (we.peek() == ' ') || (we.peek() == '\n') ) we.ignore();
	if (we.peek() == '(') {
		we.ignore();
		we >> x.Re >> x.Im;
		if (we.fail()) return we;
		if (we.peek() != 'i') {
			we.setstate(ios::failbit); 
			return we;
		}
		we.ignore();
		if (we.peek() != ')') {
			we.setstate(ios::failbit); 
			return we;
		}
		we.ignore();
		x.OK = true;
		return we;
	}
	else {
		we.setstate(ios::failbit);
		return we;
	}
}

Zespolona operator + (Zespolona x, Zespolona y) {
	y.Re = (x.Re) + (y.Re);
	y.Im = (x.Im) + (y.Im);
	return y;
}

Zespolona operator * (Zespolona x, Zespolona y) {
	Zespolona pom = y;
	y.Re = (((x.Re)*(y.Re)) - ((y.Im)*(x.Im)));
	y.Im = (((x.Re)*(pom.Im)) + ((pom.Re)*(x.Im)));
	return y;
}

bool operator == (Zespolona x, Zespolona y) {
	if ( (x.Re == y.Re) && (x.Im == y.Im) ) return true;
	else return false;
}

Zespolona Zeruj(Zespolona x) {
	x.Re=0;
	x.Im=0;
	return x;
}
