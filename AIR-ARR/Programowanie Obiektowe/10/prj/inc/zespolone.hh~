#ifndef ZESPOLONE_HH
#define ZESPOLONE_HH

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>

#define PI 3.14159265

/*!
 *\file		
 *\brief	Plik zawierający definicję klasy Zespolona oraz przeciążenia potrzebnych operatorów.
*/

using namespace std;

/*!
 *\brief	Definicja klasy Zespolona.
*/
class Zespolona {
private:
/*! \brief Pole statyczne przechowujące ilość obiektów tej klasy powstałych przez cały czas działania programu. */
	static int IloscObiektow;
/*! \brief Pole statyczne przechowujące ilość obiektów tej klasy aktualnie znajdujących się na stosie. */	
	static int IloscObiektowAktualnych;
public:
/*! \brief Pole odpowiadające części rzeczywistej liczby zespolonej. */
	float Re;
/*! \brief Pole odpowiadające części urojonej liczby zespolonej. */
	float Im;
/*! \brief Pole odpowiadające modułowi liczby zespolonej. */
	float modul;
/*! \brief Pole odpowiadające wykładnikowi w postaci wyjkładniczej liczby zespolonej. */
	float fi;
/*! \brief Zmienna przechowująca informację o tym, czy przez daną liczbę można dzielić. */
	bool OK; 
/*! \brief Pole statyczne przechowujące informację o tym czy liczby zespolone mają być wczytywane w notacji wykładniczej czy nie. */
	static bool NotacjaWykWej;
/*! \brief Pole statyczne przechowujące informację o tym czy liczby zespolone mają być wypisywane w notacji wykładniczej czy nie. */
	static bool NotacjaWykWyj;
/*! \brief Konstruktor bezparametrowy, tworzy wyzerowany obiekt. Wylicza dla niego postać wykładniczą. */
	Zespolona() { IloscObiektow++; IloscObiektowAktualnych++; }
/*! \brief Konstruktor kopiujący. \param[in] Jako argument przyjmuje obiekt tej klasy. */
	Zespolona(const Zespolona &x) {  
		Re = x.Re; Im = x.Im; IloscObiektow++; OK = x.OK; modul = x.modul; fi = x.fi; IloscObiektowAktualnych++; 
	}
/*! \brief Destruktor dla klasy Zespolona. Zmniejsza ilość obiektów na stosie o 1, wywoływany tylko przy funkcji pop(). */
	~Zespolona() { IloscObiektowAktualnych--; }
/*! \brief Operator dodawania.
 *\param[in] Jako argument przyjmuje liczbę zespoloną, która ma być dodana do obecnego obiektu.
 *\return Zwraca wynik działania.
*/
	Zespolona operator + (Zespolona a) { a.Re += Re; a.Im += Im; IloscObiektowAktualnych--; return a; }
/*! \brief Operator odejmowania.
 *\param[in] Jako argument przyjmuje liczbę zespoloną, która ma być odjęta od obecnego obiektu.
 *\return Zwraca wynik działania.
*/
	Zespolona operator - (Zespolona a) { a.Re -= Re; a.Im -= Im; IloscObiektowAktualnych--; return a; }
/*! \brief Operator mnożenia.
 *\param[in] Jako argument przyjmuje liczbę zespoloną, która ma być przemnożona przez obecny obiekt.
 *\return Zwraca wynik działania.
*/
	Zespolona operator * (Zespolona a);
/*! \brief Operator dzielenia.
 *\param[in] Jako argument przyjmuje liczbę zespoloną, przez którą ma być podzielony obecny obiekt.
 *\return Zwraca wynik działania.
*/
	Zespolona operator / (Zespolona a);
/*! \brief Operator porównania.
 *\param[in] Jako argument przyjmuje liczbę zespoloną, która ma być porównana z obecnym obiektem.
 *\return True jeśli liczby są równe, false w przeciwnym wypadku.
*/
	bool operator == (Zespolona a) { return ((Re == a.Re) && (Im == a.Im)); }
/*! \brief Funkcja wyliczająca sprzężenie liczby zespolonej. */
	void Sprzezenie () { Im = -Im; }
/*! \brief Funkcja wyliczająca postać wykładniczą liczby zespolonej na podstawie postaci normalnej. */
	void wykladnicza();
/*! \brief Getter dla statycznego pola IloscObiektow. */
	static int getIlosc() { return IloscObiektow; }
/*! \brief Getter dla statycznego pola IloscObiektowAktualnych. */
	static int getIloscA() { return IloscObiektowAktualnych; }
};

/*!
 *\brief	Funkcja zerująca zmienną typu Zespolona.
 *\param[in]	Jako argument przyjmuje wskaźnik na zmienną typu Zespolona.
*/
void Zeruj(Zespolona &x);

/*!
 *\brief	Przeciążenie operatora wypisywania dla typu Zespolona.
 *\param[in]	Jako argumenty przyjmuje wskaźnik na strumień wyjściowy oraz zmienną typu Zespolona, która ma zostać wypisana.
 *\return	Zwraca podany jako argument strumień wyjściowy.
*/
ostream & operator << (ostream & wyj, Zespolona x);

/*!
 *\brief	Przeciążenie operatora wczytywania dla typu Zespolona.
 *\param[in]	Jako argumenty przyjmuje wskaźniki na strumień wejściowy oraz zmienną typu Zespolona, do której zapisane mają być dane.
 *\return	Zwraca podany jako argumenty strumień wejściowy.
*/
istream & operator >> (istream & wej, Zespolona & x);

#endif
