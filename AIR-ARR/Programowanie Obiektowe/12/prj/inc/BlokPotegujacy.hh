#ifndef BLOKPOTEGUJACY_HH
#define BLOKPOTEGUJACY_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

/*!
 *\file
 *\brief	Plik zawierający definicję klasy BlokPotegujacy.
*/

#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <cstdlib>
#include "BlokSygnalowy.hh"
#include "Sygnal.hh"

using namespace std;

/*!
 *\brief 	Definicja klasy BlokPotegujacy, dziedziczącej po klasie BlokSygnalowy. 
*/
class BlokPotegujacy : public BlokSygnalowy {
public:	
/*! \brief Konstruktor. */
	BlokPotegujacy() {}
/*! \brief Przeciązenie metody dająca opis konkretnego bloku. \return Zwraca krótki opis danego bloku. */
	virtual string OpisBloku() { return "Blok potęguje sygnał."; }
/*! \brief Przeciążenie metody wyliczającej sygnał wyjściowy. \param[in] Przyjmuje sygnał. \return Zwraca true. */
	virtual bool WyliczSygnalWyj(const Sygnal& Syg);
/*! \brief Przeciążenie metody dającej identyfikator typu bloków. \return Zwraca liczbę 3, odpowiadającą blokom potęgującym. */
	virtual int Identyfikator() const { return 3; } 
/*! \brief Przeciążenie metody dającej nazwe typu bloków. \return Zwraca naps "Blok potęgujący.". */
	virtual const char* NazwaBloku() const { return "Blok potęgujący."; }
};

#endif
