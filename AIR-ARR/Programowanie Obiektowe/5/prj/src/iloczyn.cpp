#include "iloczyn.hh"
#include "zespolone.hh"
#include "symbole.hh"
#include "typ.hh"

ostream & operator << (ostream & wy, Wektor & w) {
	wy<< "( "<< w[0] << ", " << w[1] << ", " << w[2] <<", " << w[3] <<" )" <<endl;
	return wy;
}

istream & operator >> (istream & we, Wektor & w) {
	char znak;
	int i;
	we >> znak;
	if (znak != '(') {
		we.setstate(ios::failbit); 
		return we;
	}
	else {
		for(i = 0; i < 4; i++) {
			we >> w[i] >> znak;
			if ( (znak != ',') && (znak != ')') ) {
					we.setstate(ios::failbit); 
					return we;
			}
		}
	}
	return we;
}

TYP operator * (Wektor a, Wektor b) {
	TYP w;
   	w = (a[0]*b[0]) + (a[1]*b[1]) + (a[2]*b[2]) + (a[3]*b[3]);
	return w;
}

ostream & operator << (ostream & wy, Macierz & m) {
	int i, j;
	for (i = 0; i < 4; i++) {
		cout << "| ";
		for (j = 0; j < 4; j++) {
			cout.width(5);
			cout << m(i,j) << "   ";
		}
		cout << " |" << endl;
	}
	return wy;
}

istream & operator >> (istream & we,  Macierz & m){
  	char znak;
  	for (int i = 0; i < 4; i++) {
		we >> znak;	
		if (znak != '|') {
			we.setstate(ios::failbit); 
			return we;
		}
		else {
			for (int j = 0; j < 4; j++) {
				we >> m(i,j);
				if(we.fail()) return we;
			}
			we >> znak;
			if (znak != '|') {
				we.setstate(ios::failbit); 
				return we;
			}
		}
	}
	return we;
}

Macierz operator * (Macierz a, Macierz b) {
	Macierz w;
	int i, j;
	int k = 0;
   	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			w(i,j) = a(i,k)*b(k,j);
			for(k = 1; k < 4; k++) {
				w(i,j) = (w(i,j))+(a(i,k)*b(k,i));
			}
			k = 0;
		}
	}
	return w;
}

double Zeruj(double x) {
	return 0;
}

Wektor Zeruj(Wektor w) {
	for (int i = 0; i < 4; i++) {
		w[i] = Zeruj(w[i]);
	}
	return w;
}

Wektor operator * (Macierz m, Wektor w){
	Wektor wyn;
	wyn = Zeruj(w);
	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			wyn[i] = ((w[i]) + (w[j]*m(i,j)));
		}
	}
  return w;
}
