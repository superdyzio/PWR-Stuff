#include "uklad.hh"

/*!
 *\file
 *\brief	Plik zawiera implementacje metod z nagłówka 'uklad.hh'.
*/

istream & operator >> (istream & wej, Uklad & u) {
  	cin >> u.A;
  	if (wej.fail()) return wej; 
	else {
		cin >> u.b;
		if (wej.fail()) return wej;
		else return wej;
	}
}
		
ostream & operator << (ostream & wyj, Uklad & u) {
	for (int i = 0; i < 3; i++) {
		wyj << "| ";
		for (int j = 0; j < 3; j++) {
			wyj.width(5);
			wyj << u.A(i,j);
		}
		wyj << "|  | X_" << i+1 << "|";
		if (i == 1) cout << " = | ";
		else wyj << "   | ";
		wyj << u.b[i] << " |" << endl;
	}
	return wyj;
}	


Macierz ZamianaKolumny(Macierz m, Wektor w, int k) {
	if ( (k > 2) || (k < 0) ) {
		cerr << "Nieprawidłowy numer kolumny. Przyjęta zostanie reszta z dzielenia podanej wartości przez 3." << endl;
		k = k % 3;
	}
	for (int i = 0; i < 3; i++) m(i, k) = w[i];
	return m;
}
		
Wektor Rozwiaz(Uklad u) {
	TYP detA;
	Macierz pom;
	Wektor wynik;
	pom = u.A;
	detA = det(pom);
	for (int i = 0; i < 3; i++) {
		pom = ZamianaKolumny(pom,u.b,i);
		wynik[i] = det(pom) / detA;
		pom = u.A;
	}
	return wynik;
}
		
Wektor operator * (Macierz m, Wektor w) {
	Wektor wynik;
	wynik = Zeruj(wynik);
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++)
			wynik[i] = wynik[i] + ( m(i,j) * w[j] );
  return wynik;
}

Wektor Blad(Uklad u) {
	return u.A * u.x - u.b;
}
