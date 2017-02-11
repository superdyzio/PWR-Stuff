/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z1/trunk/inc/menu.hh $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (wto) $
$Revision: 9 $
*/

#ifndef MENU_HH
#define MENU_HH

#include <iostream>
#include <iomanip>
#include <dlfcn.h>
#include <cassert>
#include <unistd.h>
#include <vector>
#include <string>
#include <sstream>
#include "Biblioteka.hh"
#include "ListaBibliotek.hh"
#include "command.hh"
#include "RobotMobilny.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;

/*!
 * \file
 * \brief Plik zawierający definicję klasy pomocniczej przy obsłudze programu.
 */

/*!
 * \brief Klasa pozwalająca na prostą i poprawną obsługę programu.
 */
class Menu {
/*!
 * \brief Wektor przechowujący dostępne komendy.
 */
	vector<Command*> _komendy;
/*!
 * \brief Pole klasy ListaBibliotek przechowujące listę dołączonych bibliotek.
 */
	ListaBibliotek _lista;
public:
/*!
 * \brief Konsturktor.
 */
	Menu() { _lista.dodaj("command4turn.so");	_lista.dodaj("command4rotate.so");	_lista.dodaj("command4move.so"); };
/*!
 * \brief Metoda wyświetlająca listę bibliotek.
 *
 * \return Nic nie zwraca.
 */
	void wyswietlListe();
/*!
 * \brief Metoda wyświetlająca listę komend.
 *
 * \return Nic nie zwraca.
 */
	void wyswietlKomendy();
/*!
 * \brief Metoda znajdująca bibliotekę w mapie i zwracającą wskaźnik do jej obiektu.
 *
 * \param[in]	klucz - słowo kluczowe pozwalające na znalezienie biblioteki
 * \return Metoda zwraca stały wskaźnik na obiekt typu Biblioteka.
 */
	const Biblioteka* znajdzBiblioteke(string klucz) const;
/*!
 * \brief Metoda wczytująca dane z pliku.
 *  
 * \param[in]	dane - referencja na strumień wejściowy
 * \param[in]	nazwa - napis stanowiący nazwę pliku wejściowego
 * \return Zwraca wartość logiczną mówiącą o powodzeniu wykonania operacji.
 */
	bool wczytajPlik(istringstream& dane, string nazwa);
/*!
 * \brief Metoda wczytująca komendy.
 *
 * \param[in]	dane - referencja na strumień wejściowy
 * \return Zwraca wartość logiczną mówiącą o powodzeniu wykonania operacji.
 */
	bool wczytajKomendy(istringstream& dane); 
/*!
 * \brief Metoda wyświetlająca tekstowe menu użytkownika.
 */
	void wyswietlMenu();
/*!
 * \brief Metoda powodująca egzukucję wczytanych komend.
 */
	void wykonajSekwencje(RobotMobilny& robot);
/*!
 * \brief Metoda pozwalająca na dodanie wtyczki do programu.
 *
 * \param[in]	nazwawtyczki - nazwa pliku z wtyczką
 * \return Nic nie zwraca.
 */
	void dodaj(const char* nazwawtyczki);
/*!
 * \brief Metoda pozwalająca na usunięcie wtyczki z programu.
 *
 * \param[in]	nazwawtyczki - nazwa pliku z wtyczką
 * \return Zwraca wartość logiczną mówiącą o powodzeniu wykonania operacji.
 */
	bool usun(const char* nazwawtyczki);
};

#endif
