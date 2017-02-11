/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z1/trunk/inc/Biblioteka.hh $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (wto) $
$Revision: 9 $
*/

#ifndef BIBLIOTEKA_HH
#define BIBLIOTEKA_HH

#include <string>
#include <dlfcn.h>
#include "command.hh"

/*!
 * \file
 * \brief Plik zawierający definicję klasy Biblioteka.
 */

/*!
 * \brief Klasa modelująca pojedynczą bibliotekę.
 */
class Biblioteka {
public:
/*!
 * \brief Konstruktor.
 */
	Biblioteka() {};
/*!
 * \brief Destruktor.
 */
	~Biblioteka() {};
/*!
 * \brief Metoda wczytująca bibliotekę.
 *
 * \param[in]	nazwaBiblioteki - napis stanowiący nazwę biblioteki do wczytania
 * \return Zwraca wartość logiczną mówiącą o powodzeniu wykonania operacji.
 */
	bool wczytaj(const char* nazwaBiblioteki);
/*!
 * \brief Metoda drukująca składnię komendy dostarczanej przez bibliotekę.
 * \return Nic nie zwraca.
 */
	void PrintSyntax();
/*!
 * \brief Metoda drukująca komendę dostarczaną przez bibliotekę.
 * \return Nic nie zwraca.
 */
	void PrintCmd();
/*!
 * \brief Metoda tworząca komendę dostarczaną przez bibliotekę.
 * \return Zwraca wskaźnik na obiekt klasy bazowej komendy.
 */
	Command* CreateCmd() const { return _pCreateCmd(); }
/*!
 * \brief Metoda zwracająca nazwę komendy dostarczanej przez bibliotekę.
 *
 * Metoda nie wpływa na obiekt.
 * \return Zwraca stały napis.
 */
	const char* GetCmdName() const;
/*!
 * \brief Metoda wczytująca parametry z określonego strumienia.
 *
 * Metoda wirtualna, przekazywana klasom potomnym, nie wpływa na obiekt.
 * \param[in]	Strm_CmdsList - referencja do strumienia wejściowego z którego czytane mają być komendy
 * \return Metoda zwraca wartość logiczną mówiącą o powodzeniu operacji.
 */
	bool ReadParams(std::istream& Strm_CmdsList);
private:
/*!
 * \brief Pole wskazujące na bibliotekę.
 */
	void *pLib;
/*!
 * \brief Wskaźnik na komendę.
 *
 * Pole te przechowuje wskaźnik typu bazowego (Command) na konkretną, dostarczaną przez bibliotekę komendę.
*/
	Command *(*_pCreateCmd)(void);
/*!
 * \brief Pole przechowujące nazwę komendy.
 *
 * Wartości tego pola nie można zmieniać. Mówi ono o nazwie dostarczanego przez bibliotekę polecenia.
 */
	const char* CmdName;
/*!
 * \brief Pole przechowujące wskaźnik typu bazowego na obiekt komendy dostarczanej przez biblioteke.
 */
	Command *_pCmd ;
};

#endif
