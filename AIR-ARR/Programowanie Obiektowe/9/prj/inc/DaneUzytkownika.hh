#ifndef DANEUZYTKOWNIKA_HH
#define DANEUZYTKOWNIKA_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>

#include "OpcjeWywolania.hh"

/*! 
 *\file
 *\brief	Plik zawierający definicję klasy DaneUzytkownika oraz zapowiedzi potrzebnych metod. 
 */

using namespace std;

/*!
 *\brief	Definicja klasy DaneUzytkownika.
 */
class DaneUzytkownika {
	/*! \brief Pole przechowujące login. */
	string Login;			
	/*! \brief Pole przechowujące imie. */
	string Imie;
	/*! \brief Pole przechowujące nazwisko. */
	string Nazwisko;
	/*! \brief Pole przechowujące dane o użytkowniku. */
	string Dane;
	/*! \brief Pole przechowujące id użytkownika. */
	int ID;
	/*! \brief Pole przechowujące informację czy dany użytkownik jest normalny czy systemowy. */
	bool CzyNormalny;
public:
	/*! \brief Konstruktor bezparametrowy, tworzy pusty obiekt klasy DaneUzytkownika, z wyzerowanymi wszystkimi polami. */
	DaneUzytkownika();
	/*! \brief Funkcja zapewniająca dostęp do pola CzyNormalny.
	 *  \return Zwraca wartość pola CzyNormalny.
         */
	bool getNorm();
	/*! \brief Funkcja zapewniająca dostęp do pola Dane. Nic nie zwraca.
	 * \param[in] Jako parametr przyjmuje strumień wyjściowy, na który wypisane mają zostać dane. 
	 */
	void getDane(ostream & wyj);
	/*! \brief Funkcja zapewniająca dostęp do pola Login.
	 * \return Zwraca wartość pola Login.
	 */
	string getLogin();
	/*! \brief Funkcja zapewniająca dostęp do pola ID.
	 * \return Zwraca wartość pola ID.
	 */
	int getID();
	friend ostream & operator << (ostream & wyj, DaneUzytkownika & D);
	friend istream & operator >> (istream & wej, DaneUzytkownika & D);
	friend class ListaUzytkownikow;
	friend bool Idy(DaneUzytkownika x, DaneUzytkownika y);
	friend bool Nazwiska(DaneUzytkownika x, DaneUzytkownika y);
	friend bool Loginy(DaneUzytkownika x, DaneUzytkownika y);
};

/*!
 *\brief	Przeciążenie operatora wyjścia dla klasy DaneUzytkownika.
 *\param[in]	Jako argumenty przyjmuje strumień wyjściowy oraz zmienną, które zawartość ma zostać wypisana.
 *\return	Zwraca uprzednio podany strumień wyjściowy.
*/
ostream & operator << (ostream & wyj, DaneUzytkownika & D);

/*!
 *\brief	Przeciążenie operatora wejścia dla klasy DaneUzytkownika. Dzieli ona wczytane z pliku linie w odpowiedni sposób na fragmenty
 *		stopniowo wypełniając nimi odpowiednie pola obiektu.
 *\param[in]	Jako argumenty przyjmuje strumień wejściowy oraz zmienną, do której zapisana ma być wczytana zawartość.
 *\return	Zwraca uprzednio podany strumień wejściowy.
*/
istream & operator >> (istream & wej, DaneUzytkownika &D);

#endif
