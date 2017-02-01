#include "stos.hh"

/*!
 *\file
 *\brief	Plik zawierający definicje metody z klasy Stos.
*/

void Stos::drukuj() {
	if (rozmiar() > 0) {
		cout << endl << "Stos:" << endl;
		Stos pom = (*this);
		while (pom.rozmiar() > 0) {
			cout << pom.szczyt() << endl;
			pom.usun();
		}
	}
	else cout << "Stos jest pusty." << endl;
}
