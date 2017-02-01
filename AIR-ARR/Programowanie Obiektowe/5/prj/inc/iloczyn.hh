#ifndef ILOCZYN_HH
#define ILOCZYN_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "zespolone.hh"
#include "symbole.hh"
#include "typ.hh"

using namespace std;

/*! 
 * \file
 * \brief Klasa o czterech składowych określonego typu. Służy do przechowywania wektorów. Zawiera przeciążenie operatora indeksowania.
*/
class Wektor {
	TYP u, i, o, p;
	public:
	TYP & operator[] (int Ind) { return Ind == 0 ? u : Ind == 1 ? i : Ind == 2 ? o: p; }
};

/*!
 * \brief Klasa zawierająca tablicę 4x4 służąca do przechowywania macierzy danego typu. Zawiera przeciążenie operatora indeksowania.
*/
class Macierz {
	TYP tab[4][4];
	public:
	TYP & operator( ) (int w, int k) { return tab[w][k]; }
	TYP operator( ) (int w, int k) const { return tab[w][k]; }
};

/*!	
 * \brief Operator wyjścia dla wektora.
 * \param[in] Jako argumenty przyjmuje strumień wyjściowy oraz zmienną typu Wektor, którą wypisuje na zadane wyjście.
 * \return Zwraca podany jako argument strumień wyjściowy.
*/
ostream & operator << (ostream & wy, Wektor & w);

/*!	
 * \brief Operator wejścia dla wektora.
 * \param[in] Jako argumenty przyjmuje strumień wejściowy oraz zmienną typu Wektor, w której zapisany zostanie wczytany wektor (w przypadku 
 *  	poprawnego wczytania danych).
 * \return Zwraca podany jako argument strumień wejściowy lub tenże strumień ze stanem 'fail', gdy wczytywanie nie powiedzie się.
*/
istream & operator >> (istream & we, Wektor & w);

/*!	
 * \brief Operator wyjścia dla macierzy.
 * \param[in] Jako argumenty przyjmuje strumień wyjściowy oraz zmienną typu Macierz, którą wypisuje na zadane wyjście.
 * \return Zwraca podany jako argument strumień wyjściowy.
*/
ostream & operator << (ostream & wy, Macierz & m);

/*!	
 * \brief Operator wejścia dla macierzy.
 * \param[in] Jako argumenty przyjmuje strumień wejściowy oraz zmienną typu Macierz, w której zapisana zostanie wczytana macierz (w przypadku
 *	poprawnego wczytania danych).
 * \return Zwraca podany jako argument strumień wejściowy lub tenże strumień ze stanem 'fail', gdy wczytywanie nie powiedzie się.
*/
istream & operator >> (istream & we,  Macierz & m);

/*!	
 * \brief Operator dwuargumentowy '*'.
 * \param[in] Za argumenty przyjmuje dwie zmienne typu Macierz.
 * \return Zwraca ich iloczyn.
*/
Macierz operator * (Macierz a, Macierz b);

/*!	
 * \brief Operator dwuargumentowy '*'.
 * \param[in] Za argumenty przyjmuje dwie zmienne - pierwszą typu Macierz oraz drugą typu Wektor.
 * \return Zwraca ich iloczyn.
*/
Wektor operator * (Macierz m, Wektor w);

/*!
 * \brief Operator dwuargumntowy '*'.
 * \param[in] Za argumenty przyjmuje dwie zmienne typu Wektor.
 * \return Zwraca ich iloczyn skalarny.
*/
TYP operator * (Wektor a, Wektor b);

/*!
 * \brief Funkcja zerująca zmienną typu double.
 * \param[in] Przyjmuje jako argument zmienną typu double.
 * \return Zwraca tę zmienną ustawioną na 0.
*/
double Zeruj(double x);

/*!
 * \brief Funkcja zerująca zmienną typu Wektor.
 * \param[in] Jako argument przyjmuje zmienną typu Wektor.
 * \return Zwraca tę zmienną, której każde pole zostało wyzerowane za pomocą odpowiedniej dla typu pól funkcji.
*/
Wektor Zeruj(Wektor w);

#endif
