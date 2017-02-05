/*!
 * \file 
 * \brief Plik nagłówkowy klasy Wykres.
*/

#ifndef WYKRES_H
#define WYKRES_H

#include <QWidget>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <vector>
#include "qcustomplot.hpp" 
#include "DaneSymulacji.hpp"

/*!
 * \brief Klasa odpowiedzialna za widok wykresu.
 *
 * Klasa Wykres dziedziczy po klasie QCustomPlot i ma za zadanie obsługiwać widok wykresu.
*/
class Wykres : public QCustomPlot {
	Q_OBJECT
public:
	
/*!
 * \brief Konstruktor klasy wykres.
 * \param[in] wRodzic - wskaźnik na obiekt typu QWidget wskazujący rodzica widgetu wykresu, domyślnie NULL
*/
  	Wykres(QWidget* wRodzic = 0L);
/*!
 * \brief Metoda odpowiedzialna za wykreślenie punktu na wykresie.
 * \param[in] czas - zmienna typu double określająca obecny czas
 * \param[in] wartosc - zmienna typu double określająca obecną wartość
 * \return Nic nie jest zwracane.
*/
  	void plotuj(double czas, double wartosc);
/*!
 * \brief Metoda odpowiedzialna za wyczyszczenie pola wykresu.
 * \return Nic nie jest zwracane.
*/
	void zeruj();
public:

	int _aktualnyCzas;
/*!
 * \brief Wektor typu double przechowujący czas.
*/
	vector<double> _wektorCzasu;
/*!
 * \brief Wektor typu double przechowujący wartości.
*/
	vector<double> _wektorWartosci;
public slots:
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \param[in] daneSymulacji - referencja do obiektu klasy DaneSymulacji używanego przy symulacji z pliku z danymi
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta zwiększa czas symulacji i drukuje wykres.
*/
	void plotujSymulacje(DaneSymulacji &daneSymulacji);
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta pobiera odpowiednie wartości i drukuje wykres.
*/
	void plotujOdczyt();
};

#endif 
