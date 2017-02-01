#ifdef __GNUG__
# pragma implementation
#endif

#include "BlokGeneratora.hh"
#include <unistd.h>

/*!
 *\file
 *\brief	Plik zawierający implementację wybranych metod klasy BlokGeneratora.
*/

/*!
 * Inicjalizuje pracę generatora sygnału poprzez otwarcie
 * pliku, z którego będą czytane kolejne wartości sygnału.
 * \retval true - jeśli operacja zakończyła się powodzeniem,
 * \retval false - w przypadku przeciwnym.
 */
bool BlokGeneratora::RozpocznijPrace()
{
  if (_NazwaPliku.empty()) return false;
  _StrmGeneratora.open(_NazwaPliku.c_str());
  return _StrmGeneratora.is_open();
}


bool BlokGeneratora::WyliczSygnalWej( const Sygnal& SygWe, 
                                      Sygnal& SygObliczony
				    )
{
  _StrmGeneratora >> SygObliczony;
  if (_Pauza_ms) usleep(_Pauza_ms*1000);
  return !_StrmGeneratora.fail();
}


/*!
 * Sprawdza czy osiągnięty został kres pliku z 
 * wartościami sygnału.
 * \retval true - gdy czytanie pliku zostało zakończone
 *               lub przerwane wskutek błędu.
 * \retval false - w przypadku przeciwnym.
 */
bool BlokGeneratora::CzyZakonczycPrace() const
{
  return _StrmGeneratora.fail() || _StrmGeneratora.eof();
}


/*!
 * Zamyka plik, z którego były czytane wartości
 * sygnału.
 */
void BlokGeneratora::ZakonczPrace()
{
  _StrmGeneratora.close();
}
