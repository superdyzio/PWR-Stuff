#ifndef BLOKPRZESUWAJACY_HH
#define BLOKPRZESUWAJACY_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

/*!
 *\file
 *\brief	Plik zawierający definicję klasy BlokPrzesuwajacy.
*/

#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <unistd.h>
#include "BlokSygnalowy.hh"
#include "Sygnal.hh"

using namespace std;

/*!
 *\brief	Definicja klasy BlokPrzesuwajacy, dziedziczącej po klasie BlokSygnalowy.
*/
class BlokPrzesuwajacy : public BlokSygnalowy {
/*! \brief	Pole przechowujące wartość przesunięcie o jakie zmieniony ma zostać sygnał. */
	double przesuniecie;
public:	
/*! \brief Konstruktor. \param[in] Przyjmuje jako argument wartość przesunięcia, typu double. */
	BlokPrzesuwajacy(double p) { przesuniecie = p; }
/*! \brief Konstruktor. \param[in] Przyjmuje jako argument wartość przesunięcia, jako c-stringa. */
	BlokPrzesuwajacy(const char* p) { przesuniecie = atof(p); }
/*! \brief Przeciążenie metody dającej opis bloku. \return Zwraca krótki opis konkretnego bloku. */
	virtual string OpisBloku() { return "Blok przesuwa sygnał o zadaną wartość."; }
/*! \brief Przeciążenie metody wyliczającej sygnał wyjściowy. \param[in] Przyjmuje sygnał wejściowy. \return Zwraca true. */
	virtual bool WyliczSygnalWyj(const Sygnal& Syg);
/*! \brief Przeciążenie metody dającej identyfikator typu bloków. \return Zwraca liczbę 5, odpowiadającą blokom przesuwającym. */
	virtual int Identyfikator() const { return 5; } 
/*! \brief Przeciążenie metody dającej nazwę typu bloków. \return Zwraca napis "Blok przesuwający.". */
	virtual const char* NazwaBloku() const { return "Blok przesuwający."; }
};

#endif
