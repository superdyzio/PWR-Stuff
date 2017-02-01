#include "macierz.hh"

/*!
 *\file
 *\brief	Plik zawiera implementacje metod z nagłówka 'macierz.hh'.
*/

ostream & operator << (ostream & wyj, Macierz & m) {
	for (int i = 0; i < 3; i++) {
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			cout.width(5);
			cout << m(i,j) << "   ";
		}
		cout << " |" << endl;
	}
	return wyj;
}

istream & operator >> (istream & wej,  Macierz & m) {
  	char znak;
  	for (int i = 0; i < 3; i++) {
		wej >> znak;	
		if (znak != '|') {
			wej.setstate(ios::failbit); 
			return wej;
		}
		else {
			for (int j = 0; j < 3; j++) {
				wej >> m(i,j);
				if (wej.fail()) return wej;
			}
			wej >> znak;
			if (znak != '|') {
				wej.setstate(ios::failbit); 
				return wej;
			}
		}
	}
	return wej;
}

Macierz operator * (Macierz a, Macierz b) {
	Macierz w;
	int k;
   	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			w(i,j) = a(i,k) * b(k,j);
			k = 0;
			for (k = 1; k < 3; k++) {
				w(i,j) = w(i,j) + ( a(i,k) * b(k,i) );
			}
		}
	}
	return w;
}
		
TYP det(Macierz m) {
	TYP wynik = Zeruj(wynik);
	int pom1, pom2;
	for (int i = 0; i < 3; i++) {
		pom1 = (i+1) % 3;
		pom2 = (i+2) % 3;
		wynik = wynik + ( m(0,i) * m(1,pom1) * m(2,pom2) );
	}	
	for (int i = 0; i < 3; i++) {
		pom1 = (i+1) % 3;
		pom2 = (i+2) % 3;
		wynik = wynik - ( m(0,pom2) * m(1,pom1) * m(2,i) );
	}
	return wynik;
} 
