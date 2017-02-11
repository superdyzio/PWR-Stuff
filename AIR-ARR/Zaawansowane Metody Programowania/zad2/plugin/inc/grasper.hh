/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/plugin/inc/grasper.hh $
$Author: dperdek $
$Date: 2015-12-06 20:40:26 +0100 (nie) $
$Revision: 5 $
*/

#ifndef  GRASPER_HH
#define  GRASPER_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <math.h>
#include <cmath>
#include <unistd.h>
#include <iostream>
#include "command.hh"

/*!
 * \file
 * \brief Definicja klasy Grasper.
 *
 * Plik zawiera definicję klasy Grasper, będącej pochodną klasy Command.
 * Modeluje ona chwytak robota.
 */

/*!
 * \brief Klasa modeluje chwytak robota i pozwala na zamknięcie i uniesienie 
 *	oraz zwolnienie i opuszczenia chwytaka.
 *
 * Klasa jest typem komendy, dziedziczy klasę Command.
 */
class Grasper : public Command {
/*!
 * \brief Pole typu double przechowujące informację o szybkości ruchu podanej w mm/s.
 */
		bool _stan;
public:
/*!
 * \brief Konstruktor klasy Command4Turn.
 *
 */
  	Grasper() : _stan(0) {};  
/*!
 * \brief Metoda drukująca komendę.
 *
 * Metoda wirtualna, odziedziczona od klasy nadrzędnej, nie wpływa na obiekt.
 * \return Metoda nic nie zwraca.
 */
  	virtual void PrintCmd() const;
/*!
 * \brief Metoda drukująca składnię komendy.
 *
 * Metoda wirtualna, odziedziczona od klasy nadrzędnej, nie wpływa na obiekt.
 * \return Metoda nic nie zwraca.
 */
	virtual void PrintSyntax() const;
/*!
 * \brief Metoda zwracająca nazwę komendy.
 *
 * Metoda wirtualna, odziedziczona od klasy nadrzędnej, nie wpływa na obiekt.
 * \return Metoda zwraca ciąg znaków będących nazwą komendy.
 */
	virtual const char* GetCmdName() const;
/*!
 * \brief Metoda pozwalająca egzekwować komendę.
 *
 * Metoda wirtualna, odziedziczona od klasy nadrzędnej, nie wpływa na obiekt.
 * \param[in]	pRobPose - wskaźnik na obiekt przechowujący dane o położeniu 
				robota
 * \return Metoda zwraca wartość logiczną mówiąca o powodzeniu wykonania ruchu.
 */
  	virtual bool ExecCmd(RobotPose *pRobPose) const;
/*!
 * \brief Metoda wczytująca parametry z określonego strumienia.
 *
 * Metoda wirtualna, odziedziczona od klasy nadrzędnej, nie wpływa na obiekt.
 * \param[in]	Strm_CmdsList - referencja do strumienia wejściowego 
				z którego czytane mają być komendy
 * \return Metoda zwraca wartość logiczną mówiącą o powodzeniu operacji.
 */
  	virtual bool ReadParams(std::istream& Strm_CmdsList);
/*!
 * \brief Metoda statyczna tworząca obiekt komendy.
 *
 * Metoda statyczna, nie wymagająca definicji w klasie bazowej.
 * \return Metoda zwraca wskaźnik na obiekt typu bazowego Command.
 */
  	static Command* CreateCmd();
 };

#endif
