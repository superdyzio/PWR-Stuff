#ifndef BLOKWZMACNIAJACY_HH
#define BLOKWZMACNIAJACY_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

/*!
 *\file
 *\brief	Plik zawierający definicję klasy BlokWzmacniajacy.
*/

#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include "BlokSygnalowy.hh"
#include "Sygnal.hh"

using namespace std;

/*!
 *\brief 	Definicja klasy BlokWzmacniajacy, dziedziczącej po klasie BlokSygnalowy. 
*/
class BlokWzmacniajacy : public BlokSygnalowy {
/*! \brief Pole przechowujące wartość wzmocnienia sygnału. */
	double wzmocnienie;
public:	
/*! \brief Konstruktor. \param[in] Jako argument przyjmuje liczbę typu double, reprezentującą krotność wzmocnienia. */
	BlokWzmacniajacy(double w) { wzmocnienie = w; }
/*! \brief Konstruktor. \param[in] Jako argument przyjmuje wartość wzmocnienia, jako c-string. */
	BlokWzmacniajacy(const char* w) { wzmocnienie = atof(w); }
/*! \brief Przeciązenie metody dająca opis konkretnego bloku. \return Zwraca krótki opis danego bloku. */
	virtual string OpisBloku() { return "Blok wzmacnia sygnał o zadaną wartość."; }
/*! \brief Przeciążenie metody wyliczającej sygnał wyjściowy. \param[in] Przyjmuje sygnał. \return Zwraca true. */
	virtual bool WyliczSygnalWyj(const Sygnal& Syg);
/*! \brief Przeciążenie metody dającej identyfikator typu bloków. \return Zwraca liczbę 6, odpowiadającą blokom wzmacniającym. */
	virtual int Identyfikator() const { return 6; } 
/*! \brief Przeciążenie metody dającej nazwe typu bloków. \return Zwraca naps "Blok wzmacniający.". */
	virtual const char* NazwaBloku() const { return "Blok wzmacniający."; }
};

#endif
