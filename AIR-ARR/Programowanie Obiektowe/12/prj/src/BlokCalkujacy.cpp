#ifdef __GNUG__
# pragma implementation
#endif

#include "BlokCalkujacy.hh"

/*!
 *\file
 *\brief	Plik zawierający definicję wybranych metod z klasy BlokCalkujacy.
*/

bool BlokCalkujacy::WyliczSygnalWyj(const Sygnal& Syg) {
	double wartosc;
	if (Syg.WezCzas() == 0) ZmienSygnalWyj(Syg.WezCzas(),0);
	else {
		wartosc = (Syg.WezCzas() - ostCzas) * Syg.WezWartoscSyg();
		pole += wartosc;
		ostCzas = Syg.WezCzas();	
		ZmienSygnalWyj(Syg.WezCzas(),pole);
	}
	return true;
}
