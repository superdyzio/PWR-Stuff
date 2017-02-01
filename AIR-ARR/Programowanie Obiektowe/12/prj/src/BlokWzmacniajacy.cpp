#ifdef __GNUG__
# pragma implementation
#endif

#include "BlokWzmacniajacy.hh"

/*!
 *\file
 *\brief	Plik zawierający definicję wybranych metod z klasy BlokWzmacniajacy.
*/

bool BlokWzmacniajacy::WyliczSygnalWyj(const Sygnal& Syg) {
	ZmienSygnalWyj(Syg.WezCzas(),Syg.WezWartoscSyg() * wzmocnienie);
	return true;
}
