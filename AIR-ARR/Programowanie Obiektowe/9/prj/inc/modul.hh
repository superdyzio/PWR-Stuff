#ifndef MODUL_HH
#define MODUL_HH

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

#include "modul.hh"
#include "DaneUzytkownika.hh"
#include "ListaUzytkownikow.hh"
#include "OpcjeWywolania.hh"

using namespace std;

/*!
 *\file	
 *\brief	Plik zawiera zapowiedź metody służącej do obsługi pliku 'passwd'.
 */

/*!
 *\brief	Funkcja mająca na celu odpowiednie posortowanie oraz wyświetlenie listy użytkowników, zgodnie z wytycznymi zadanymi poprzez
 *		argumenty wywołania programu.Funkcja nic nie zwraca.
 *\param[in]	Zmienna typu OpcjeWywolania zawierająca wytyczne.
 */
void PrzetworzListe_Uzytkownikow_i_Grupy(const OpcjeWywolania & Opcje);

#endif