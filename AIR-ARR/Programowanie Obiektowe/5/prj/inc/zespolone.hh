#ifndef ZESPOLONE_HH
#define ZESPOLONE_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

/*!
 * \file 
 * \brief Klasa publiczna zawierająca definicję struktury Liczba Zespolona. Jej elementami są pola typu float przeznaczone dla wartości 
 *	rzeczywistej i urojonej, umożliwające przedstawienie liczby w postaci (Re+Im*i), gdzie nawiasy są konieczne. Zawarta w niej jest      
 *	również zmienna boolowska, która przechowuję informację czy przez podaną liczbę można dzielić.
*/
class Zespolona{
	public:
	float Re, Im;
	bool OK;
};

/*! 	
 * \brief Operator wyjścia dla typu Zespolona.
 * \param[in] Jako argumenty przyjmuje strumień wyjściowy oraz zmienną typu Zespolona.
 * \return Zwraca podany jako argument strumień wyjściowy.
*/
ostream & operator << (ostream & wy, Zespolona x);

/*!
 * \brief Operator wejścia dla typu Zespolona.
 * \param[in] Jako argumenty przyjmuje strumień wejściowy oraz zmienną w której zostanie zapamiętana (w przyadku poprawnego wczytania) wartość 
 * 	typu Zespolona. Konieczne jest podanie liczby w formacie (Re+Im*i), gdzie nawiasów nie można pominąć.
 * \return Zwracany jest wejściowy strumień podany jako argument (w przypadku błędu we wczytywaniu ze stanem ustawionym na 'fail').
*/
istream & operator >> (istream & we, Zespolona & x);

/*!
 * \brief Operator dwuargumentowy '+'.
 * \param[in] Jako argumenty przyjmuje dwie zmienne typu Zespolona.
 * \return Zwraca ich sumę.
*/
Zespolona operator + (Zespolona x, Zespolona y);

/*!
 * \brief Operator dwuargumentowy '*'.
 * \param[in] Jako argumenty przyjmuje dwie zmienne typu Zespolona.
 * \return Zwraca iloczyn argumentów.
*/
Zespolona operator * (Zespolona x, Zespolona y);

/*!
 * \brief Operator dwuargumentowy '=='.
 * \param[in] Jako argumenty przyjmuje dwie zmienne typu Zespolona.
 * \return Zwraca 'true', jeśli są one równe, oraz 'false' w przypadku przeciwnym.
*/
bool operator == (Zespolona x, Zespolona y);

/*!
 * \brief Funkcja zerująca zmienną typu Zespolona.
 * \param[in] Ustawia wartości Re oraz Im zmiennej podanej jako argument na 0.
 * \return Zwraca wyzerowną zmienną.
*/
Zespolona Zeruj(Zespolona x);
	
#endif
