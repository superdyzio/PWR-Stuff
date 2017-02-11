#include "LiczZesp.h"

ostream & operator << (ostream & cWyj, const CLiczZesp cZ) {
	return cWyj << '(' << cZ.d_re << showpos << cZ.d_im << noshowpos << 'i' << ')';
}

istream & operator >> (istream & cWej, CLiczZesp & cZ) {
	if ( (cWej.peek() == ' ') || (cWej.peek() == '\n') ) cWej.ignore();
	if (cWej.peek() == '(') {
		cWej.ignore();
		cWej >> cZ.d_re >> cZ.d_im;
		if (cWej.fail()) return cWej;
		if (cWej.peek() != 'i') {
			cWej.setstate(ios::failbit); 
			return cWej;
		}
		cWej.ignore();
		if (cWej.peek() != ')') {
			cWej.setstate(ios::failbit); 
			return cWej;
		}
		cWej.ignore();
		cZ.b_ok = cZ.d_modul()>0 ? true : false;
		return cWej;
	}
	else {
		cWej.setstate(ios::failbit);
		return cWej;
	}
}

CLiczZesp operator + (const CLiczZesp cA, CLiczZesp cB) {
	cB.d_re = cA.d_re + cB.d_re;
	cB.d_im = cA.d_im + cB.d_im;
	return cB;
}

CLiczZesp operator - (const CLiczZesp cA, CLiczZesp cB) {
	cB.d_re = cA.d_re - cB.d_re;
	cB.d_im = cA.d_im - cB.d_im;
	return cB;
}

CLiczZesp operator * (const CLiczZesp cA, CLiczZesp cB) {
	CLiczZesp c_pom = cB;
	cB.d_re = ((cA.d_re) * (cB.d_re)) - ((cB.d_im) * (cA.d_im));
	cB.d_im = ((cA.d_re) * (c_pom.d_im)) + ((c_pom.d_re) * (cA.d_im));
	return cB;
}

CLiczZesp operator / (const CLiczZesp cA, CLiczZesp cB) {
	float d_dzielnik =  (float) pow(cB.d_modul(),2);	
	if (d_dzielnik != 0) {
		cB = cA * cB.c_sprzezenie();
		cB.d_re = cB.d_re / d_dzielnik;
		cB.d_im = cB.d_im / d_dzielnik;
	}
	else {
		cerr << ZLE << endl;
		cB.b_ok = false;
	}
	return cB;	
}

bool operator == (const CLiczZesp cA, const CLiczZesp cB) {
	return ( (cA.d_re == cB.d_re) && (cA.d_im == cB.d_im) );
}