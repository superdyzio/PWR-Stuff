#ifndef KALKULATOR_HH
#define KALKULATOR_HH

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "stos.hh"
#include "mapa.hh"
#include "dana.hh"
#include "zespolona.hh"

/*! 
 *\file
 *\brief	Plik zawierający definicję klasy Kalkulator.
*/

using namespace std;

/*!
 *\brief	Definicja klasy Kalkulator.
*/
class Kalkulator {
public:
/*! \brief Pole typu Mapa. Służy do przechowywania wszystkich pojawiających się elementów. */
	Mapa mapka;
/*! \brief Pole typu Stos. Służy do wykonywania operacji. */ 
	Stos stosik;
/*! \brief Konstruktor bezparametrowy. */
	Kalkulator() {}
/*! \brief Destruktor bezparametrowy. */
	~Kalkulator() {}
/*! \brief Funkcja arytmetyczna dodawania. Dodaje dwa wierzchnie elementy. Wynik odkłada na stos. */
	void dodaj();
/*! \brief Funkcja arytmetyczna odejmowania. Odejmuje drugi od góry element od wierzchniego. Wynik odkłada na stos. */
	void odejmij();
/*! \brief Funkcja arytmetyczna mnożenia. Mnoży przez siebie dwa wierzchnie elementy. Wynik odkłada na stos. */
	void mnoz();
/*! \brief Funkcja arytmetyczna dzielenia. Dzieli wierzchni element przez drugi od góry. Wynik odkłada na stos. */
	void dziel();
/*! \brief Funkcja duplikująca wierzchni element stosu. */
	void duplikuj();
/*! \brief Funkcja zamieniająca miejscami dwa wierzchnie elementy stosu. */
	void zamien();
/*! \brief Funkcja interakcji z użytkownikiem. */
	void uruchom();
/*! \brief Funkcja wypisująca całą zawartość stosu w odpowiednim formacie. */
	void wypiszStos();
/*! \brief Funkcja przypisująca wartość z wierzchu stosu zmiennej pod nią. */
	void nadajWartosc();
/*! \brief Funkcja usuwająca wierzch stosu. Usuwa też z mapy. */
	void usunDana();
/*! \brief Funkcja zmieniająca notację wejściową na wykładniczą. */
	void wejNotWyk() { Zespolona::NotacjaWykWej = true; }
/*! \brief Funkcja zmieniająca notację wejściową na tradycyjną. */
	void wejNotTrad() { Zespolona::NotacjaWykWej = false; }
/*! \brief Funkcja zmieniająca notację wyjściową na wykładniczą. */
	void wyjNotWyk() { Zespolona::NotacjaWykWyj = true; }
/*! \brief Funkcja zmieniająca notację wyjściową na tradycyjną. */
	void wyjNotTrad() { Zespolona::NotacjaWykWyj = false; }
};

#endif
