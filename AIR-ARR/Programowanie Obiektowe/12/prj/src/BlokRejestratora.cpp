#ifdef __GNUG__
# pragma implementation
#endif

#include <iostream>
#include <fstream>
#include "BlokRejestratora.hh"

/*!
 *\file
 *\brief	Plik zawierający implementację wybranych metod klasy BlokRejestratora.
*/

using namespace std;

/*!
 * Inicjalizuje pracę rejestratora sygnału poprzez otwarcie
 * pliku, do którego będą zapisywane kolejne wartości sygnału.
 * \retval true - jeśli operacja zakończyła się powodzeniem,
 * \retval false - w przypadku przeciwnym.
 */
bool BlokRejestratora::RozpocznijPrace()
{
  if (_NazwaPliku.empty()) return false;
  _StrmRejestratora.open(_NazwaPliku.c_str());
  return _StrmRejestratora.is_open();
}


bool BlokRejestratora::WyliczSygnalWyj(const Sygnal& Syg)
{ 
  ZmienSygnalWyj(Syg);
  _StrmRejestratora << Syg.WezCzas() << " " << Syg.WezWartoscSyg() << endl;
  return !_StrmRejestratora.fail();
}


/*!
 * Sprawdza czy czy stan strumienia zapewnia dalszy
 * poprawny zapis.
 * \retval true - gdy strumień pozwala na dalszy poprawny
 *               zapis kolejnych wartości sygnału.
 * \retval false - w przypadku przeciwnym.
 */
bool BlokRejestratora::CzyZakonczycPrace() const
{
  return _StrmRejestratora.fail();
}


/*!
 * Zamyka plik, do którego zostały zapisane wartości
 * sygnału.
 */
void BlokRejestratora::ZakonczPrace()
{
  _StrmRejestratora.flush();
  _StrmRejestratora.close();
}
