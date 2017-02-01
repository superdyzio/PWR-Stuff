#ifndef ZESPOLONE_HH
#define ZESPOLONE_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

/*!
 *\file
 *\brief	Moduł zawierający definicję klasy Zespolona, służącej do przechowywania liczb zespolonych oraz przeciążenia
 *		wybranych operatorów.							
 */

/*!
 *\brief	Definicja klasy Zespolona, która służy do przechowywania liczb zespolonych.
 *		Składa się ona z dwóch pól typu float: Re i Im, dzięki którym liczbę można przedstawić w formie (Re+Im*i), gdzie nawiasy
 *		są niezbędne oraz pola typu bool: OK, przechowującego informację czy przez daną liczbę można dzielić.
 */
class Zespolona {
public:
	/*! \brief Część rzeczywista liczby zespolonej. */
	float Re;
	/*! \brief Część urojona liczby zespolonej. */
	float Im;
	/*! \brief Zmienna przechowująca informację o możliwości dzielenia przez daną liczbę. */
	bool OK;
	/*! \brief Konstruktor bezparametrowy, tworzy wyzerowany obiekt. */	
	Zespolona() { Re = Im = 0; }
	/*! \brief Konstruktor dwuparametrowy \param[in] przyjmuje dwie wartości typu float dla Re i Im. */
	Zespolona(float x, float y) { Re = x; Im = y; }
	/*!
	 *\brief	Operator dwuargumentowy '+'.
	 *\param[in]	Jako argumenty przyjmuje zmienną typu Zespolona.
	 *\return	Zwraca sumę, obliczoną zgodnie z zasadami arytmetyki liczb zespolonych.
	*/
	Zespolona operator + (Zespolona a) { return Zespolona(Re+a.Re,Im+a.Im); }
	/*!
	 *\brief	Funkcja dająca sprzężenie liczby zespolonej.
	 *\param[in]	Jako argument przyjmuje zmienną typu Zespolona.
	 *\return	Zwraca sprzężenie liczby zespolonej podanej jako argument. 
	*/
	void Sprzezenie () { Im = -Im; }
	/*!
	 *\brief	Operator dwuargumentowy '-'.
	 *\param[in]	Jako argumenty przyjmuje dwie zmienne typu Zespolona.
	 *\return	Zwraca rożnicę, obliczoną zgodnie z zasadami arytmetyki liczb zespolonych. 
	*/
	Zespolona operator - (Zespolona a) { return Zespolona(Re-a.Re,Im-a.Im); }
	/*!
	 *\brief	Operator '==' służący do porównań.
	 *\param[in]	Jako argumenty przyjmuje zmienną typu Zespolona.
	 *\return	Zwraca 'true', gdy jest ona równa obiektowe, natomiast 'false' w przypadku przeciwnym.
	*/
	bool operator == (Zespolona a) { return ((Re == a.Re) && (Im == a.Im)); }

	/*!
	 *\brief	Operator dwuargumentowy '*'.
	 *\param[in]	Jako argument przyjmuje zmienną typu Zespolona.
	 *\return	Zwraca iloczyn, obliczony zgodnie z zasadami arytmetki liczb zespolonych. 
	*/
	Zespolona operator * (Zespolona a);
	/*!
	 *\brief	Operator dwuargumentowy '/'.
	 *\param[in]	Jako argument przyjmuje zmienną typu Zespolona.
	 *\return	Jeśli dzielenie jest wykonalne to zwrócony zostanie iloraz argumentów, jeśli natomiast drugi z nich jest zerem, to
	 *		zwrócony będzie drugi argument ze zmienną OK ustawioną na 'false'.
	*/
	Zespolona operator / (Zespolona a);
};

/*!
 *\brief	Funkcja zerująca zmienną typu Zespolona.
 *\param[in]	Jako argument przyjmuje zmienną typu Zespolona.
 *\return	Zwraca wyzerowaną zmienną podaną jako argument. 
*/
void Zeruj(Zespolona &x);
/*!
 *\brief	Przeciążenia operatora wyjścia dla typu Zespolona.
 *\param[in]	Jako argument przyjmuje strumień wyjściowy oraz zmienną, której zawartość ma być wypisana.
 *\return	Zwraca podany jako argument strumień wyjściowy. 
*/
ostream & operator << (ostream & wyj, Zespolona x);
/*!
 *\brief	Przeciążenia operatora wejścia dla typu Zespolona.
 *\param[in]	Jako argumenty przyjmuje strumień wejściowy oraz zmienną, do której zapisana ma być wczytana wartość.
 *\return	Zwraca podany jako argument strumień wejściowy.
*/
istream & operator >> (istream & wej, Zespolona & x);

#endif
