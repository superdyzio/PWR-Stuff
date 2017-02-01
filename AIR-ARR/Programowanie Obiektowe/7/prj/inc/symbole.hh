#ifndef SYMBOLE_HH
#define SYMBOLE_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>

/*!
 *\file
 *\brief 	Modul zawierający definicję typu wyliczeniowego 'Symbol'
 *		{e , a , b , c , d}, odpowiadające kolejno wartościom od 0 do 4.
 *		Zapowiedziane są również tutaj przeciążenia odpowiednich operatorów.
*/

using namespace std;

/*!
 *\brief	Deklaracja typu wyliczenowego
*/
enum Symbol { e, a, b, c, d };

/*!
 *\brief	Operator jednoargumentowy '-'.			
 *\param[in]	Jako argument przyjmuje zmienną typu Symbol.			
 *\return	Zwraca Symbol przeciwny do podanego jako argument.
*/
Symbol operator - (Symbol x);
 
/*!
 *\brief	Operator jednoargumentowy '/+'.			
 *\param[in]	Jako argument przyjmuje zmienną typu Symbol.			
 *\return	Zwraca argument bez znaku.
*/
Symbol operator + (Symbol x);
 
/*!
 *\brief	Operator dwuargumentowy '+'.
 *\param[in]	Jako argumenty przyjmuje dwie zmienne typu Symbol.			
 *\return	Zwraca sumę elementów podanych jako argumenty, zgodnie z tabelką dodawania Symboli.
 */
Symbol operator + (Symbol x, Symbol y);

/*!
 *\brief	Operator dwuargumentowy '-'.
 *\param[in]	Jako argumenty przyjmuje dwie zmienne typu Symbol.
 *\return	Zwraca ich różnicę, czyli sumę argumentu pierwszego oraz przeciwności drugiego.
 */
Symbol operator - (Symbol x, Symbol y);

/*!
 *\brief	Operator dwuargumentowy '*'.
 *\param[in]	Jako argumenty przyjmuje dwie zmienne typu Symbol.
 *\return	Zwraca iloczyn argumentów.
 */
Symbol operator * (Symbol x, Symbol y);

/*!
 *\brief	Operator dwuargumentowy '/'.
 *\param[in]	Jako argumenty przyjmuje dwie zmienne typu Symbol.
 *\return	Zwraca ich iloraz, czyli iloczyn argumentu pierwszego i odwrotności drugiego.
 */
Symbol operator / (Symbol x, Symbol y);

/*!
 *\brief	Operator wyjścia dla typu Symbol.
 *\param[in]	Jako argumenty przyjmuje strumień wyjściowy oraz zmienną przechowującą Symbol do wypisania.
 *\return	Zwraca podany jako argument strumień wyjściowy.
*/
ostream & operator << (ostream & wyj, Symbol x);

/*!
 *\brief	Operator wejścia dla typu Symbol.
 *\param[in]	Jako argumenty przyjmuje strumień wejściowy oraz zmienną w której zapisany zostanie wczytany Symbol.
 *\return	Zwraca podany jako argument strumień wejściowy.
*/
istream & operator >> (istream & wej, Symbol & x);

/*!
 *\brief	Funkcja zerująca zmienną typu Symbol.
 *\param[in]	Jako argument przyjmuje zmienną typu Symbol.
 *\return	Zwraca tę zmienną ustawioną na 'e'.
*/
Symbol Zeruj(Symbol x);

#endif
