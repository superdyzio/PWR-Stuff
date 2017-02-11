/*
$HeadURL: file:///home/dperdek/repos/z1/trunk/inc/ListaBibliotek.hh $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (Tue, 17 Nov 2015) $
$Revision: 9 $
*/

#ifndef LISTABIBLIOTEK_HH
#define LISTABIBLIOTEK_HH

#include <iostream>
#include <iomanip>
#include <iostream>
#include <dlfcn.h>
#include <map>
#include <string>
#include "command.hh"
#include "Biblioteka.hh"

using namespace std;

/*!
 * \file
 * \brief Plik z definicją klasy do przechowywania i obsługi bibliotek.
 */

/*!
 * \brief Klasa wspomagająca obsługę dodatkowych bibliotek.
 */
class ListaBibliotek : public map<string, Biblioteka*> {
public:
/*!
 * \brief Konstruktor.
 */
	ListaBibliotek() {};
/*!
 * \brief Destruktor.
 */
	~ListaBibliotek();
/*!
 * \brief Metoda pozwalająca na dodanie biblioteki.
 *
 * \param[in]	nazwaBiblioteki - napis przechowujący nazwę biblioteki do dodania
 * \return Zwraca wartość logiczną mówiącą o powodzeniu wykonania operacji.
 */
	bool dodaj(const char* nazwaBiblioteki);
/*!
 * \brief Metoda pozwalająca na usunięcie biblioteki.
 *
 * \param[in]	nazwaBiblioteki - napis przechowujący nazwę biblioteki do usunięcia
 * \return Zwraca wartość logiczną mówiącą o powodzeniu wykonania operacji.
 */
	bool usun(const char* nazwaBiblioteki);

private:
/*!
 * \brief Pole przechowujące wskaźnik na bibliotekę.
 */
	void *pLib;
/*!
 * \brief Metoda pomocnicza znajdująca konkretną bibliotekę.
 *
 * \param[in] nazwa biblioteki
 * \return Nic nie zwraca.
*/
	void find(const char*) {}
};

#endif
