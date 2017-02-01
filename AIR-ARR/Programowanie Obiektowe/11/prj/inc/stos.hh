#ifndef STOS_HH
#define STOS_HH

#include <stack>
#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <cctype>
#include "dana.hh"

/*!
 *\file
 *\brief	Plik nagłówkowy zawierający definicję klasy Stos.
*/

using namespace std;

/*!
 *\brief	Definicja klasy Stos dziedziczącej po szablonie std::stack. Klasa dostosowana jest do przechowywania stringów.
*/
class Stos : private stack<string> {
public:
/*! \brief Konstruktor bezparametrowy. */
	Stos() {}
/*! \brief Destruktor bezparametrowy. */
	~Stos() {}
/*! \brief Obudowa funkcji size(). \return Zwraca aktualny rozmiar stosu. */
	int rozmiar() { return size(); }
/*! \brief Obudowa funkcji top(). \return Zwraca string z wierzchołka lub komunikat o pustym stosie - zależnie od rozmiaru. */
	string szczyt() { return rozmiar() > 0 ? top() : "Stos jest pusty."; }
/*! \brief Obudowa funkcji pop(). */
	void usun() { if (rozmiar() > 0) pop(); else cout << "Stos jest pusty." << endl; }
/*! \brief Obudowa funkcji push(string). */
	void doloz(const string& x) { push(x); }
/*! \brief Funkcja sprawdzająca czy na stosie są choć dwa elementy. \return Zwraca true jeśli są choć dwa elementy, a false jeśli nie. */
	bool czyDwa() { return rozmiar() > 1; }
/*! \brief Funkcja czyszcząca stos. Ściąga kolejno wszystkie elementy. */
	void czysc() { while (rozmiar() > 0) pop(); }
/*! \brief Funkcja wyświetlająca całą zawartość stosu. */
	void drukuj();
};

#endif
