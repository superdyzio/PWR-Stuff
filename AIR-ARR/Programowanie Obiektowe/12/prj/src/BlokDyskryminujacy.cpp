#ifdef __GNUG__
# pragma implementation
#endif

#include "BlokDyskryminujacy.hh"

/*!
 *\file
 *\brief	Plik zawierający definicję wybranych metod z nagłówka BlokDyskryminujacy.
*/

bool BlokDyskryminujacy::WyliczSygnalWyj(const Sygnal& Syg) {
	ZmienSygnalWyj(Syg);
	if (Syg.WezWartoscSyg() > prog) ZmienSygnalWyj(Syg.WezCzas(),1);
	else ZmienSygnalWyj(Syg.WezCzas(),0);
	return true;
}
