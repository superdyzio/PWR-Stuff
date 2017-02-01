#include <iostream>
#include "Sygnal.hh"

/*!
 *\file
 *\brief	Plik zawierający implementację wybranych metod klasy Sygnal.
*/

using namespace std;

std::istream& operator >> (std::istream &StrmWe, Sygnal &Syg)
{
  double  Czas, WartoscSyg;

  StrmWe >> Czas >> WartoscSyg;
  if (StrmWe.fail()) return StrmWe;
  Syg.ZmienSyg(Czas,WartoscSyg);
  return StrmWe;
}


std::ostream& operator << (std::ostream &StrmWy, const Sygnal &Syg)
{
  return StrmWy << Syg.WezCzas() << " " << Syg.WezWartoscSyg();
}
