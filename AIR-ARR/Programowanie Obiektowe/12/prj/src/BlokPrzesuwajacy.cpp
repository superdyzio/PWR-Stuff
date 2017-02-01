#ifdef __GNUG__
# pragma implementation
#endif

#include "BlokPrzesuwajacy.hh"

/*!
 *\file
 *\brief	Plik zawierający definicję wybranych metod z klasy BlokPrzesuwajacy.
*/

bool BlokPrzesuwajacy::WyliczSygnalWyj(const Sygnal& Syg) {
	ZmienSygnalWyj(Syg.WezCzas(),Syg.WezWartoscSyg() + przesuniecie);	
	return true;
}
