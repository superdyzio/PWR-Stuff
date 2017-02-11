/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/inc/punkt.hh $
$Author: dperdek $
$Date: 2015-12-05 02:18:25 +0100 (sob) $
$Revision: 3 $
*/

#ifndef PUNKT_HH
#define PUNKT_HH

/*!
 * \file
 * \brief Plik zawiera deklarację klasy modelującej obiekt.
 *
 * Klasa jest wykorzystywana przy parsowaniu pliku xml.
 */

/*!
 * \brief Deklaracja klasy Punkt.
 *
 * Klasa modeluję obiekt (punkt) znajdujący się na scenie działania robota.
 */
class Punkt {
public:
/*
 * \brief Współrzędne punktu.
 *
 * Zmienne przechowujące wczytane z pliku xml współrzędne punktu.
 */
	double x, y;
/* 
 * \brief Konstruktor.
 *
 * \param[in]	xx	-	współrzędna x punktu
 * \param[in]	yy	-	współrzędna y punktu
 */
	Punkt(double xx, double yy) : x(xx), y(yy) {}
};


#endif
