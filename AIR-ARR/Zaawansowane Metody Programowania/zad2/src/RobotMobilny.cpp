/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/src/RobotMobilny.cpp $
$Author: dperdek $
$Date: 2015-12-04 22:30:22 +0100 (pią) $
$Revision: 2 $
*/

#pragma implementation
#include "RobotMobilny.hh"
#include <cassert>

using namespace std;

#define NAZWA_PLIKU_SCIEZKA_ROBOTA  "sciezka_robota.dat"
#define NAZWA_PLIKU_POZYCJA_ROBOTA  "pozycja_robota.dat"
#define ROZMIAR_ROBOTA              4

/*!
 * \file 
 * \brief Plik zawierający implementację metod klasy RobotMobilny.
 */

RobotMobilny::RobotMobilny(PzG::LaczeDoGNUPlota *pPlotter) : _pPlotter(pPlotter) {
	assert(pPlotter != nullptr);
}

bool RobotMobilny::WriteCoord() {
	double  x_mm, y_mm;
	Get(x_mm,y_mm);
	_Strm4Path.open(NAZWA_PLIKU_SCIEZKA_ROBOTA,ios::app);
	if (!_Strm4Path.is_open()) {
		cerr << "! Blad otwarcia pliku: " << NAZWA_PLIKU_SCIEZKA_ROBOTA << endl;
		return false;
	}
	if (!(_Strm4Path << x_mm << " " << y_mm << endl)) {
		cerr << "! Blad zapisu do pliku: " << NAZWA_PLIKU_SCIEZKA_ROBOTA << endl;
		return false;
	}
  	_Strm4Path.close();
	ofstream  Strm4Position(NAZWA_PLIKU_POZYCJA_ROBOTA);
	if (!Strm4Position.is_open()) {
		cerr << "! Blad otwarcia do zapisu pliku: " << NAZWA_PLIKU_POZYCJA_ROBOTA << endl;
		return false;
	}
	if (!(Strm4Position << x_mm << " " << y_mm << endl)) {
		cerr << "! Blad zapisu do pliku: " << NAZWA_PLIKU_POZYCJA_ROBOTA << endl;
		return false;
	}
	return true;
}

bool RobotMobilny::Init() {
	assert(_pPlotter != nullptr);
	_Strm4Path.open(NAZWA_PLIKU_SCIEZKA_ROBOTA);
	if (!_Strm4Path.is_open()) 
		return false;
	_Strm4Path.close();
	if (!WriteCoord()) 
		return false;
	_Strm4Path.close();
	_pPlotter->DodajNazwePliku(NAZWA_PLIKU_SCIEZKA_ROBOTA);
	_pPlotter->DodajNazwePliku(NAZWA_PLIKU_POZYCJA_ROBOTA,PzG::RR_Punktowy,ROZMIAR_ROBOTA);
	_pPlotter->Rysuj();
	return true;
}

bool RobotMobilny::AfterUpdate() {
	assert(_pPlotter != nullptr);
	if (!WriteCoord()) 
		return false;
	_pPlotter->Rysuj();
	return true;
}
