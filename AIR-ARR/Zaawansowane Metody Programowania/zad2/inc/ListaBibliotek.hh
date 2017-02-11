/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/inc/ListaBibliotek.hh $
$Author: dperdek $
$Date: 2015-12-05 02:18:25 +0100 (sob) $
$Revision: 3 $
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
 * \param[in]	nazwaBiblioteki - napis przechowujący nazwę pliku biblioteki 
 *																	do dodania
 * \return Zwraca wartość logiczną mówiącą o powodzeniu wykonania operacji.
 */
	bool dodaj(const char* nazwaBiblioteki);
/*!
 * \brief Metoda pozwalająca na usunięcie biblioteki.
 *
 * \param[in]	nazwaBiblioteki - napis przechowujący nazwę biblioteki 
 * 																	do usunięcia
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
