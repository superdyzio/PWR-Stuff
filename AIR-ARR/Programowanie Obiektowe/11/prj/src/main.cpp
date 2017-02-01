#include "zespolona.hh"
#include "stos.hh"
#include "kalkulator.hh"
#include "mapa.hh"
#include "dana.hh"


/*! 
 *\file
 *\brief	Plik główny programu. Zawiera funkcję main w ramach której tworzony jest obiekt typu Kalkulator oraz uruchamiana jego funkcja
 *		interakcji z użytkownikiem.
*/

bool Zespolona::NotacjaWykWej = false;
bool Zespolona::NotacjaWykWyj = false;

int main() {
	Kalkulator rpn;
	rpn.uruchom();
	return 0;
}
