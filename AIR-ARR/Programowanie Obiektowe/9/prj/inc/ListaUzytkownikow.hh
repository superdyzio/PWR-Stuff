#ifndef LISTAUZYTKOWNIKOW_HH
#define LISTAUZYTKOWNIKOW_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>

#include "OpcjeWywolania.hh"
#include "DaneUzytkownika.hh"

/*!
 *\file
 *\brief	Plik zawierający definicję klasy ListaUzytkownikow oraz potrzebnych metod. Zaimplementowane są tu również metody
 *		zaprzyjaźnione z klasą DaneUzytkownika.
*/
using namespace std;

/*!
 *\brief	Definicja klasy ListaUzytkownikow. */
class ListaUzytkownikow {
public:
	/*! \brief Kolekcja w której przechowywane będą elementy typu DaneUzytkownika. */
	list<DaneUzytkownika> Lista;
	/*! \brief Zmienna mająca zapamiętać użytkownika, który ma nie być wyświetlony wraz ze wszystkimi. */
	DaneUzytkownika uzyt;
	/*! \brief Konstruktor bezparametrowy, tworzący pusty obiekt. */
	ListaUzytkownikow();
	friend bool Idy(DaneUzytkownika x, DaneUzytkownika y);
	friend bool Nazwiska(DaneUzytkownika x, DaneUzytkownika y);
	friend bool Loginy (DaneUzytkownika x, DaneUzytkownika y);
	/*! \brief	Bezparametrowa funkcja wyszukiwania, wyszukująca użytkownika o największym ID. */
	void Znajdz();
	/*! \brief 	Jednoparametrowa funkcja wyszukiwania, wyszukująca użytkownika o Loginie rozpoczynającym się od zadanych znaków.
 	 * \param[in]	Przyjmuje jako argument ciąg znaków od którego rozpoczynać ma się login znalezionego użytkownika.
	 */
	void Znajdz(string PoczatekLoginu);
	/*! \brief	Jednoparametrowa funkcja wyszukiwania, wyszukująca użytkownika o zadanym ID.
	 * \param[in]	Przyjmuje jako argument zmienną typu int - wartość szukaną wśrod identyfikatorów.
	 */	
	void Znajdz(int s);
};

/*!
 *\brief	Funkcja porównująca dwóch użytkowników wg nazwisk. W przypadku równości porównywani się jeszcze wg imion oraz ID.
 *\param[in]	Dwie zmienne typu DaneUzytkownika, które będą ze sobą porównywane.
 *\return	Zwraca true jeśli są równi (również, gdy nazwisko pierwszego zawiera się w nazwisku drugiego). W przeciwnym wypadku false.
*/
bool Nazwiska(DaneUzytkownika x, DaneUzytkownika t);

/*!
 *\brief	Funkcja porównująca dwóch użytkowników wg loginów.
 *\param[in]	Dwie zmienne typu DaneUzytkownika, które będą ze sobą porównywane.
 *\return	Zwraca true jeśli login pierwszego jest wcześniejszy od loginu drugiego (również, gdy pierwszy zawiera się w drugim).
 *		W przeciwnym wypadku false.
*/
bool Loginy(DaneUzytkownika x, DaneUzytkownika y);

/*!
 *\brief	Funkcja porówująca użytkowników wg ID.
 *\param[in]	Dwie zmienne typu DaneUzytkownika, które będą ze sobą porównywane.
 *\return	Zwraca true jeśli ID pierwszego jest wcześniejsze od ID drugiego. W przeciwnym wypadku false.
*/
bool Idy(DaneUzytkownika x, DaneUzytkownika y);

#endif
