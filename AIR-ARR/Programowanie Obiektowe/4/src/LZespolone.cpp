#include "LZespolone.hh"

istream & operator >> (istream & wej, LZespolona & l) {
	if (wej.peek() == ' ' || wej.peek() == '\n') wej.ignore();
	if (wej.peek() == '(') {
		wej.ignore();
		wej >> l.x >> l.y;
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
		l.ok = true;
		return wej;
	}
	else {
		wej.setstate(ios::failbit);
		return wej;
	}
}

ostream & operator << (ostream & wyj, LZespolona l) {
	return wyj << '(' << l.x << showpos << l.y << noshowpos << 'i' << ')';
}

LZespolona operator + (LZespolona a, LZespolona b) {
	LZespolona ret;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return ret;
}

LZespolona operator - (LZespolona a, LZespolona b) {
	LZespolona ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	return ret;
}

LZespolona operator * (LZespolona a, LZespolona b) {
	LZespolona ret;
	ret.x = a.x*b.x - a.y*b.y;
	ret.y = a.x*b.y + b.x*a.y;
	return ret;
}

LZespolona Sprzezenie (LZespolona a) {
	a.y *= -1;
	return a;
}

LZespolona operator / (LZespolona a, LZespolona b) { 
	float dol = b.x*b.x + b.y*b.y;
	LZespolona ret;
	if (dol != 0) {
		ret = a*Sprzezenie(b);
		ret.x /= dol;
		ret.y /= dol;
	}
	else {
		cerr<<"Nie można dzielić przez zero!";
		ret.ok = false;
	}
	return ret;
}

bool operator == (LZespolona a, LZespolona b) {
	return ((a.x == b.x) && (a.y == b.y));
}
