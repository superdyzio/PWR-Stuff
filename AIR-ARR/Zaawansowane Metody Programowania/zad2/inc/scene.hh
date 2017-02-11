/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/inc/scene.hh $
$Author: dperdek $
$Date: 2015-12-06 18:51:24 +0100 (nie) $
$Revision: 4 $
*/

#ifndef SCENE_HH
#define SCENE_HH

/*!
 * \file
 * \brief Plik zawiera deklarację klasy modelującej scenę.
 *
 * Klasa jest wykorzystywana przy parsowaniu pliku xml.
 */

#include <vector>
#include "RobotMobilny.hh"
#include "punkt.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;

/*!
 * \brief Deklaracja klasy Scene.
 *
 * Klasa modeluję scenę w której działa robot.
 */
class Scene {
public:
/*
 * \brief Parametry robota.
 *
 * Zmienne przechowujące wczytane z pliku xml współrzędne robota.
 */
	double x, y, kat;
/*
 * \brief Łącze do GNUPlota.
 *
 * Obiekt łącza do GNUPlota potrzebny do utworzenia obiektu robota.
 */
	PzG::LaczeDoGNUPlota lacze;
/*
 * \brief Robot.
 *
 * Pole przechowujące obiekt robota.
 */
	RobotMobilny *robot;
/*
 * \brief Wektor obiektów.
 *
 * Wektor przechowujący obiekty (punkty) na scenie wczytane z pliku xml.
 */
	vector<Punkt> obiekty;
/* 
 * \brief Konstruktor.
 */
	Scene() : x(0), y(0), kat(0) { robot = new RobotMobilny(&lacze); obiekty.clear(); }
};


#endif
