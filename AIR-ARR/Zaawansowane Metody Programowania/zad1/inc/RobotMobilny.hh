/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z1/trunk/inc/RobotMobilny.hh $
$Author: dperdek $
$Date: 2015-11-12 03:07:21 +0100 (czw) $
$Revision: 7 $
*/

#ifndef ROBOTMOBILNY_HH
#define ROBOTMOBILNY_HH

#pragma interface

#include <fstream>
#include "robotpose.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \file
 * \brief Definicja klasy RobotMobilny.
 *
 * Plik zawiera definicję klasy RobotMobilny, dziedziczącej po klasie RobotPose.
 */

/*!
 * \brief Klasa modelująca obiekt robota mobilnego.
 *
 *  Klasa modeluje obiekt robota mobilnego przechowując informację m.in. o jego położeniu i orientacji.
 */
class RobotMobilny : public RobotPose {
public:
/*!
 * \brief Konstruktor klasy RobotMobilny.
 *
 * \param[in]	pPlotter - wskaźnik na obiekt łącza do GNUPlota
 */
	RobotMobilny(PzG::LaczeDoGNUPlota *pPlotter);
/*!
 * \brief Metoda inicjalizująca struktury robota.
 *
 * \return Zwraca wartość logiczną mówiącą o powodzeniu operacji.
 */
	bool Init();
/*!
 * \brief Metoda resetująca struktury robota.
 *
 * \return Zwraca wartość logiczną mówiącą o powodzeniu operacji.
 */
	bool Reset();
/*!
 * \brief Metoda zapisująca współrzędne robota do pliku.
 *
 * \return Zwraca wartość logiczną mówiącą o powodzeniu operacji.
 */
	bool WriteCoord();
/*!
 * \brief Metoda wirtualna, odziedziczona od klasy RobotPose.
 *
 * Metoda wywoływana jest po aktualizacji pozycji robota.
 * \return Zwraca wartość logiczną mówiącą o powodzeniu operacji.
 */
	virtual bool AfterUpdate();

private:
/*!
 * \brief Pole przechowujące wskaźnik na obiekt typu LaczeDoGNUPlota.
 *
 * Wskazywany przez te pole obiekt służy wyświetlaniu trasy robota.
 */
	PzG::LaczeDoGNUPlota *_pPlotter;
/*!
 * \brief Zmienna przechowująca strumień wyjściowy.
 * 
 * W strumieniu tym zapisywane są kolejne współrzędne robota.
 */
	std::ofstream _Strm4Path;
};

#endif
