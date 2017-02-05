/*!
 * \file 
 * \brief Plik nagłówkowy klasy DaneSymulacji.
*/

#ifndef DANE_HH
#define DANE_HH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QFile>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*!
 * \brief Klasa odpowiedzialna za kontrolę trybu symulacji.
 *
 * Klasa DaneSymulacji przechowuje informacje konieczne do poprawnego działania trybu symulacyjnego.
*/
class DaneSymulacji { 
public:
/*!
 * \brief Konstruktor klasy DaneSymulacji.
*/
	DaneSymulacji();
/*!
 * \brief Pole typu double przechowujące aktualny czas symulacji.
*/
	double _aktualnyCzas;
/*!
 * \brief Wektor typu double przechowujący wartości symulacji.
*/
	vector<double> _wartosci;
/*!
 * \brief Wektor typu double przechowujący czasy odpowiadające wartościom.
*/
	vector<double> _czas;
/*!
 * \brief Metoda wczytująca dane do symulacji z pliku.
 * \param[in] plik - łańcuch określający nazwę pliku z danymi
 * \return Nic nie jest zwracane.
 *
 * Metoda pobiera jako argument samą nazwę pliku i szuka go w folderze data wewnątrz katalogu projektu.
*/
	void wczytajDane(string plik);
/*!
 * \brief Pole typu string przechowujące kompletną ścieżkę do pliku z danymi.
*/
	string _plikSymulacji;
};

#endif 
