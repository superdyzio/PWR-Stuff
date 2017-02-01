#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "zespolone.hh"
#include "symbole.hh"
#include "liczba.hh"
#include "typ.hh"
#include "wektor.hh"

using namespace std;

/*!
 *\file
 *\brief	Moduł zawiera definicję klasy Macierz wraz z przeciążeniami wybranych operatorów.
 *		Klasa 'Macierz' przyjmuje nastepujący format:\n
 *			| TYP M(0,0) TYP M(0,1) TYP M(0,2) TYP M(0,3)|\n
 *			| TYP M(1,0) TYP M(1,1) TYP M(1,2) TYP M(1,3)|\n
 *			| TYP M(2,0) TYP M(2,1) TYP M(2,2) TYP M(2,3)|\n
 *			| TYP M(3,0) TYP M(3,1) TYP M(3,2) TYP M(3,3)|\n
 *		Przeciążany zostal operator funkcyjny (int Wiersz, int Kolumna), co umożliwia wygodne odwoływanie się do
 *		poszczególnych elementów.
 *		Przeciążony został operator '*' dla mnożenia Macierz X Macierz.
 */
 
 /*!
 *\brief	Definicja szablonu klasy Macierz. Typy jakie może ona przyjmować to: double, Symbol, Zespolona.
 */
template <typename T>
class Macierz {
private:
	/*! \brief Zmienna do przechowywania macierzy. */
	T tab[3][3]; 
public:
	/*! \brief Przeciążenie operatora indeksującego. */
	T &operator( ) (int Wiersz, int Kolumna) {return tab[Wiersz][Kolumna]; }
	/*! \brief Przeciążenia operatora. */
	T operator( ) (int Wiersz, int Kolumna) const {return tab[Wiersz][Kolumna]; } 
	/*!
	 *\brief	Przeciążenie operatora mnożenia '*' dla działania Macierz X Macierz.
	 *\param[in]	Argument typu Macierz.
	 *\return	Iloczyn z argumentem.
	*/	
	Macierz<T> operator * (Macierz<T> a);
	/*!
	 *\brief	Funkcja wyliczająca wyznacznik macierzy.
	 *\return	Wyznacznik macierzy podanej jako argument.
	*/
	T det();
};

/*!
 *\brief	Przeciążenie operatora wypisywania dla klasy Macierz.
 *\param[in]	Jako argument przyjmuje strumień wyjściowy oraz zmienną, która ma zostać wypisana.
 *\return	Zwraca podany jako argument strumień wyjściowy.
*/	
template <typename T>
ostream & operator << (ostream & wyj, Macierz<T> x) {
	for (int i = 0; i < 3; i++) {
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			cout.width(5);
			cout << x(i,j) << "   ";
		}
		cout << " |" << endl;
	}
	return wyj;
}

/*!
 *\brief	Przeciążenie operatora wczytywania dla klasy Macierz.
 *\param[in]	Jako argument przyjmuje strumień wejściowy oraz zmienną, do której ma zostać zapisana wczytana wartość·
 *\return	Zwraca podany jako argument strumień wejściowy.
*/
template <typename T>
istream & operator >> (istream & wej, Macierz<T> & x) {
  	char znak;
  	for (int i = 0; i < 3; i++) {
		wej >> znak;	
		if (znak != '|') {
			wej.setstate(ios::failbit); 
			return wej;
		}
		else {
			for (int j = 0; j < 3; j++) {
				wej >> x(i,j);
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

template <typename T>
Macierz<T> Macierz<T>::operator * (Macierz<T> a) {
	Macierz<T> w;
	int k;
   	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			w(i,j) = a(i,k) * tab[k][j];
			k = 0;
			for (k = 1; k < 3; k++) {
				w(i,j) = w(i,j) + ( a(i,k) * tab[k][i] );
			}
		}
	}
	return w;
}
	
template <typename T>	
T Macierz<T>::det() {
	T wynik;
	Zeruj(wynik);
	int pom1, pom2;
	for (int i = 0; i < 3; i++) {
		pom1 = (i+1) % 3;
		pom2 = (i+2) % 3;
		wynik = wynik + ( tab[0][i] * tab[1][pom1] * tab[2][pom2] );
	}	
	for (int i = 0; i < 3; i++) {
		pom1 = (i+1) % 3;
		pom2 = (i+2) % 3;
		wynik = wynik - ( tab[0][pom2] * tab[1][pom1] * tab[2][i] );
	}
	return wynik;
}

#endif
