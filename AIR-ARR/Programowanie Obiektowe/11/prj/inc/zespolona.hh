#ifndef ZESPOLONA_HH
#define ZESPOLONA_HH

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

/*!
 *\file
 *\brief	Plik nagłówkowy zawierający definicję klasy Zespolona, umożliwiającej przechowywanie liczb zespolonych, oraz przeciążenia
 *		koniecznych operatorów.
*/

/*!
 *\brief	Zdefiniowana stała reprezentująca liczbę PI w przybliżeniu. Używana przy wyliczaniu postaci wykładniczej liczby zespolonej.
*/ 
#define PI 3.14

using namespace std;

/*!
 *\brief	Definicja klasy Zespolona.
*/
class Zespolona {
public:
/*! \brief Zmienna reprezentująca część rzeczywistą liczby zespolonej. */
	float Re;
/*! \brief Zmienna reprezentująca część urojoną liczby zespolonje. */
	float Im;
/*! \brief Zmienna reprezentująca moduł liczby zespolonej. */
	float modul;
/*! \brief Zmienna reprezentująca argument główny liczby zespolonej. */
	float alfa;
/*! \brief Statyczna zmienna przechowująca informację o notacji w jakiej wczytywane mają być kolejne liczby zespolone. True dla wykładniczej,
 *	fale dla tradycyjnej. */
	static bool NotacjaWykWej;
/*! \brief Statyczna zmienna przechowująca informację o notacji w jakiej wyświetlane mają być liczby zespolone. True dla wykładniczej, false
 *	dla tradycyjnej. */
	static bool NotacjaWykWyj;
/*! \brief Konstruktor bezparametrowy, tworzy wyzerowaną liczbę zespoloną. */
	Zespolona() { Re = Im = 0; wykladnicza(0,0); }
/*! \brief Konstruktor dwuparametrowy. 
 *  \param[in] Jako argumenty przyjmuje dwie zmienne typu float odpowiadające części rzeczywistej i urojonej. */
	Zespolona(float x, float y) { Re = x; Im = y; wykladnicza(x,y); }
/*! \brief Konstruktor kopiujący, kopiuje do nowej zmiennej zawartość obiektu podanego jako argument.
 *  \param[in] Jako argument przyjmuje referencję do zmiennej typu Zespolona. */
	Zespolona(const Zespolona& x) { Re = x.Re; Im = x.Im; modul = x.modul; alfa = x.alfa; }
/*! \brief Bezparametrowy destruktor dla typu Zespolona. */
	~Zespolona() {}
/*! \brief Przeciążenie operatora porównania dla typu Zespolona.
 *  \param[in] Jako argument przyjmuje referencję do zmiennej typu Zespolona.
 *  \return Zwraca true jeśli obiekt i argument są równe, false w przypadku przeciwnym. */
	bool operator == (const Zespolona& x) const { return ((Re == x.Re) && (Im == x.Im)); }
/*! \brief Bezparametrowa metoda wyliczająca sprzężenie liczby zespolonej. */
	void sprzezenie() { Im *= -1; }
/*! \brief Przeciążenie operatora dodawania dla typu Zespolona.
 *  \param[in] Jako argument przyjmuje referencję do obiektu typu Zespolona.
 *  \return Zwraca nowy obiekt będący wynikiem dodawania danego obiektu i obiektu podanego jako argument. */
	Zespolona operator + (const Zespolona& a) const { return Zespolona(Re+a.Re,Im+a.Im); }
/*! \brief Przeciążenie operatora odejmowania dla typu Zespolona.
 *  \param[in] Jako argument przyjmuje referencję do obiektu typu Zespolona.
 *  \return Zwraca nowy obiekt będący wynikiem odejmowania od danego obiektu obiektu podanego jako argument. */
	Zespolona operator - (const Zespolona& a) const { return Zespolona(Re-a.Re,Im-a.Im); }
/*! \brief Funkcja wyliczająca postać wykładniczą liczby zespolonej.
 *  \param[in] Jako argumenty przyjmuje dwie zmienne typu float, reprezentujące odpowiednio część rzeczywistą i urojoną liczby zespolonej. */
	void wykladnicza(float x, float y);
/*! \brief Przeciążenie operatora mnożenia dla typu Zespolona.
 *  \param[in] Jako argument przyjmuje referencję do obiektu typu Zespolona.
 *  \return Zwraca nowy obiekt będący wynikiem mnożenia danego obiektu i obiektu podanego jako argument. */
	Zespolona operator * (const Zespolona& a) const;
/*! \brief Przeciążenie operatora dzielenia dla typu Zespolona.
 *  \param[in] Jako argument przyjmuje referencję do obiektu typu Zespolona.
 *  \return Zwraca nowy obiekt będący wynikiem dzielenia danego obiektu przez obiekt podany jako argument. */
	Zespolona operator / (Zespolona& a) const;
};

/*!
 *\brief	Przeciążenie operatora wyjścia dla typu Zespolona.
 *\param[in]	Jako argumenty przyjmuje referencję do strumienia wyjściowego oraz referencję do obiektu typu Zespolona, którego zawartość
 *		ma zostać wypisana.
 *\return	Zwraca referencję do strumienia wyjściowego podanego jako argument.
*/
ostream & operator << (ostream& wyj, const Zespolona& x);

/*!
 *\brief	Przeciążenie operatora wejścia dla typu Zespolona.
 *\param[in]	Jako argumenty przyjmuje referencję do strumienia wejściowego oraz referencję do obiektu typu Zespolona, w którym zapisane mają
 *		być wczytane dane.
 *\return	Zwraca referencję do strumienia wejściowego podanego jako argument.
*/
istream & operator >> (istream& wej, Zespolona& x);

#endif
