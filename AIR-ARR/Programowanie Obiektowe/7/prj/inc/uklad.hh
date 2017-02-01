#ifndef UKLAD_HH
#define UKLAD_HH

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
#include "macierz.hh"
#include "wektor.hh"

using namespace std;

/*!
 *\file
 *\brief	Moduł zawierający definicję klasy Uklad wraz z przeciążeniami wybranych operatorów, np. operatory wejścia/wyjścia
 *		operator mnożenia macierzy przez wektor.
 *		W module tym zaimplementowany jest również algorytm rozwiązywania układu równań metodą Cramera.
*/
 
/*!
 *\brief	Definicja klasy Uklad:
*/
class Uklad {
	public:
	/*! \brief Macierz współczynników układu równań. */
	Macierz A;
	/*! \brief Rozwiązanie układu równań. */
	Wektor x;
	/*! \brief Wektor wyrazów wolnych. */
	Wektor b;
};

/*!
 *\brief	Operator wejścia dla klasy Uklad.
 *\param[in]	Jako argumenty przyjmuje strumień wejściowy oraz zmienną typu Uklad, w której zapisany zostanie wczytany układ równań.
 *\return	Zwraca podany jako argument strumień wejściowy.
*/
istream & operator >> (istream & wej, Uklad & u);
		
/*!
 *\brief	Operator wyjścia dla klasy Uklad.
 *\param[in]	Jako argumenty przyjmuje strumień wyjściowy oraz zmienną typu Uklad, która ma zostać wypisana.
 *\return	Zwraca podany jako argument strumień wyjściowy.
*/
ostream & operator << (ostream & wyj, Uklad & u);	

/*!
 *\brief	Funkcja służąca do podstawienia w miejsce wybranej kolumny macierzy wektora wyrazów wolnych, co umożliwi wyliczenia wyznacznika
 *		i rozwiązanie układu Cramera.
 *\param[in]	Jako argumenty przyjmuje macierz i wektor wyrazów wolnych z rozwiązywanego układu równań oraz numer kolumny do której ma być
 *		dokonane podstawienie.
 *\return	Zwraca macierz z podmienioną kolumną.
*/
Macierz ZamianaKolumny(Macierz m, Wektor w, int k);

/*!
 *\brief	Funkcja ma za zadanie rozwiązać układ równań Cramera.
 *\param[in]	Jako argument funkcja przyjmuje zmienną typu Uklad.
 *\return	Zwraca wektor będący zestawem rozwiązań układu.
*/	
Wektor Rozwiaz(Uklad u);

/*!
 *\brief	Operator dwuargumentowy '*', w tym miejscu służący do mnożenia macierzy przez wektor.
 *\param[in]	Jako argumenty przyjmuje zmienną typu Macierz oraz drugą typu Wektor.
 *\return	Zwraca wynik mnożenia Macierz X Wektor.
*/
Wektor operator * (Macierz m, Wektor w);

/*!
 *\brief	Funkcja wyliczająca błąd wyliczenia rozwiązania układu równań.
 *\param[in]	Jako argument przyjmuje zmienną przechowującą układ równań.
 *\return	Zwraca wektor wskazujący wartość błędu wyliczenia rozwiązania dla każdego z elementów rozwiązania.
*/
Wektor Blad(Uklad u);

#endif
