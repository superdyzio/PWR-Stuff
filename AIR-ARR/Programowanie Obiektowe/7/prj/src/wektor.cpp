#include "wektor.hh"

/*!
 *\file
 *\brief	Plik zawiera implementacje metod z nagłówka 'wektor.hh'.
*/

istream & operator >> (istream & wej, Wektor & w) {
	char znak;
	wej >> znak;
	if (znak != '(') {
		wej.setstate(ios::failbit); 
		return wej;
	}
	else {
		for(int i = 0; i < 3; i++) {
			wej >> w[i] >> znak;
			if ( (znak != ',') && (znak != ')') ) {
					wej.setstate(ios::failbit); 
					return wej;
			}
		}
	}
	return wej;
}

ostream & operator << (ostream & wyj, Wektor & w) {
	wyj << "( " << w[0] << ", " << w[1] << ", " << w[2] << " )" << endl;
	return wyj;
}

TYP operator * (Wektor a, Wektor b) {
	TYP w;
	w = ( (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]) );
	return w;
}
		
Wektor operator - (Wektor a, Wektor b) {
	for (int i = 0; i < 3; i++) a[i] = a[i] - b[i];
	return a;
}
		
Wektor Zeruj(Wektor w) {
	w[0] = w[1] = w[2] = Zeruj(w[0]);
	return w;
}
