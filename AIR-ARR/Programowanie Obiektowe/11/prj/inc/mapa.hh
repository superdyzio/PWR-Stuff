#ifndef MAPA_HH
#define MAPA_HH

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
#include <iomanip>
#include "dana.hh"
#include "zespolona.hh"

/*!
 *\file
 *\brief	Plik zawierający definicję klasy Mapa oraz wszytkich potrzebnych funkcji. 
*/

using namespace std;

/*!
 *\brief 	Definicja klasy Mapa, dziedziczącej po szablonie std::map. Przystosowana do przechowywania elementów typu Dana, gdzie kluczem
 *		jest string.
*/
class Mapa : private map<string, Dana> {
/*! \brief Licznik stałych słuzacy do tworzenia nowych obiektów tego typu w mapie. */
	int iloscStalych;
public:
/*! \brief Konstruktor bezparemtrowy, ustawia iloscStalych na 0. */
	Mapa() { iloscStalych = 0; }
/*! \brief Destruktor bezparametrowy. */
	~Mapa() {}
/*! \brief Przeciążenie operatora indeksującego. \return Zwraca element o podanym kluczu (tworzy go w razie potrzeby). */
	Dana operator () (const string & n) { return (*this)[n]; }
/*! \brief Funkcja sprawdzająca czy element o danym kluczu jest w mapie. \return Zwraca true jeśli jest, false w przypadku przeciwnym. */
	bool czyJest(const string & n) { return (*this)[n].getLicznik() > 0; }
/*! \brief Getter dla ilości stałych w mapie. */
	int getIlStalych() const { return iloscStalych; }
/*! \brief Funkcja tworząca nową nazwę stałej. \return Zwraca nazwę stałej postaci "::x", gdzie x to aktualna iloscStalych. */
	string stworzNazwe() {  iloscStalych++; string w; ostringstream s; s << iloscStalych; w = "::"; w += s.str(); return w; }
/*! \brief Funkcja czyszcząca mapę. Kasuje wszystkie elementy. */
	void czysc() { clear(); }
/*! \brief Funkcja dodająca element o zadanym kluczu do mapy. \param[in] Przyjmuje klucz nowego elementu. */
	void dodajDana(const string& n) { ((*this)[n]).incLicznik(); }
/*! \brief Funkcja usuwająca element o zadanym kluczu z mapy. \param[in] Przyjmuje klucz elementu do usunięcia. */
	void usunDana(const string & n) { ((*this)[n]).decLicznik(); if (((*this)[n]).getLicznik() <= 0) erase(n); }
/*! \brief Getter dla wartości danego elementu mapy. \param[in] Przyjmuje klucz elementu. \return Zwraca wartość elementu. */
	Zespolona getWartosc(const string& n);
/*! \brief Funkcja przypisująca wartość elementowi. \param[in] Przyjmuje klucz elementu oraz wartość, która ma zostać mu przypisana. */
	void przypiszWartosc(const string& n, const Zespolona& x);
/*! \brief Funkcja wypisująca całą zawartość mapy. */
	void wypisz();
/*! \brief Funkcja wypisująca wszystkie zmienne przechowywane w mapie w kolejności alfabetycznej. */
	void wypiszZm();
/*! \brief Funkcja wypisująca wszystkie stałe przechowywane w mapie. */
	void wypiszSt();
};

#endif
