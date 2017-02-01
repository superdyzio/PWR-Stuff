#ifndef STOSOKALKULATOR_HH
#define STOSOKALKULATOR_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stack>
#include "zespolone.hh"

/*! 
 *\file
 *\brief	Plik zawierający definicję klasy Stos.
*/

using namespace std;

/*!
 *\brief	Definicja klasy Stos dziedziczącej po klasie stack. Przystosowana jest ona do obiektów typu Zespolona. 
*/
class Stosokalkulator : public stack<Zespolona> {
public:	
/*! \brief Wskaźnik na zmienną typu Zespolona, przechowującą początek stosu. */
	Zespolona *pocz;
/*! \brief Konstuktor bezparametrowy, ustawia początek stosu na NULL. */
	Stosokalkulator() { pocz = NULL; }
/*! \brief Konstruktor jednoargumentowy. \param[in] Jako argument przyjmuje zmienną typu Zespolona, którą ustawia jako początek stosu. */
	Stosokalkulator(Zespolona &x) { pocz = &x; }
/*! \brief Destruktor dla klasy Stos. */
	~Stosokalkulator() {};
/*! \brief Bezargumentowa funkcja zamiany miejscami dwóch wartości z wierzchu stosu. */
	void zamien();
/*! \brief Bezargumentowa funkcja duplikująca wartość z wierzchołka stosu. */
	void duplikuj();
/*! \brief Bezargumentowa funkcja wyświetlająca zawartość całego stosu. Nie ingeruje w jego strukturę. */
	void wyswietl();
/*! \brief Bezargumentowa funkcja dodająca do siebie dwa wierzchnie elementy i zapisująca na stos wynik operacji. */
	void dodaj();
/*! \brief Bezargumentowa funkcja odejmująca od wierzchni element od kolejnego i zapisująca na stos wynik operacji. */
	void odejmij();
/*! \brief Bezargumentowa funkcja mnożąca dwa wierzchnie elementy i zapisująca na stos wynik operacji. */
	void mnoz();
/*! \brief Bezargumentowa funkcja dzieląca drugi element przez wierzchni i zapisująca na stos wynik operacji. */
	void dziel();
/*! \brief Bezargumentowa funkcja usuwająca element z wierzchołka stosu. */
	void usun();
/*! \brief Bezargumentowa funkcja ustawiająca notację wykładniczą na wyjście programu. */
	void wyjNotWyk() { Zespolona::NotacjaWykWyj = true; }
/*! \brief Bezargumentowa funkcja ustawiająca notację tradycyjną na wyjście programu. */
	void wyjNotTrad() { Zespolona::NotacjaWykWyj = false; }
/*! \brief Bezargumentowa funkcja ustawiająca notację wykładniczą na wejście programu. */
	void wejNotWyk() { Zespolona::NotacjaWykWej = true; }
/*! \brief Bezargumentowa funkcja ustawiająca notację tradycyjną na wejśćie programu. */
	void wejNotTrad() { Zespolona::NotacjaWykWej = false; }
/*! \brief Bezargumentowa funkcja czyszcząca stos. */
	void czysc();
};

#endif
