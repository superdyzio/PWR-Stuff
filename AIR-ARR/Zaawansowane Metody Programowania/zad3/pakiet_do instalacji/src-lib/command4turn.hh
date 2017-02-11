/*
$HeadURL: file:///home/dperdek/repos/z1/trunk/plugin/inc/command4turn.hh $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (Tue, 17 Nov 2015) $
$Revision: 9 $
*/

#ifndef  COMMAND4TURN_HH
#define  COMMAND4TURN_HH

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
 * \brief Definicja klasy Command4Turn.
 *
 * Plik zawiera definicję klasy Command4Turn, będącej pochodną klasy Command.
 * Modeluje ona polecenie wykonania przez robota zakrętu.
 */

/*!
 * \brief Klasa modeluje polecenie dla robota mobilnego, które wymusza wykonanie skrętu przez robota.
 *
 * Klasa jest typem komendy, dziedziczy klasę Command.
 */
class Command4Turn : public Command {
/*
 * Pole typu double przechowujące informację o szybkości ruchu podanej w mm/s.
 */
  	double _Speed_mmS;
/*
 * Pole typu double przechowujące informację o dystansie ruchu podanym w mm.
 */
  	double _Distance_mm;
/*
 * Pole typu double przechowujące informację o promieniu skrętu podanym w mm.
 */
  	double _Radius_mm;
public:
/*!
 * \brief Konstruktor klasy Command4Turn.
 *
 */
  	Command4Turn() : _Speed_mmS(0), _Distance_mm(0), _Radius_mm(0) {};  
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
 * \param[in]	pRobPose - wskaźnik na obiekt przechowujący dane o położeniu robota
 * \return Metoda zwraca wartość logiczną mówiąca o powodzeniu wykonania ruchu.
 */
  	virtual bool ExecCmd(RobotPose *pRobPose) const;
/*!
 * \brief Metoda wczytująca parametry z określonego strumienia.
 *
 * Metoda wirtualna, odziedziczona od klasy nadrzędnej, nie wpływa na obiekt.
 * \param[in]	Strm_CmdsList - referencja do strumienia wejściowego z którego czytane mają być komendy
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
