/*!
 * \file
 * \brief Plik źródłowy klasy Wykres.
*/

#include "Wykres.hpp"

Wykres::Wykres(QWidget *wRodzic) : QCustomPlot(wRodzic) {
	_wektorCzasu.clear();		// zerowanie wektorów czasu i wartości
	_wektorWartosci.clear();
}

void Wykres::zeruj() {
	_wektorCzasu.clear();		// zerowanie wektorów czasu i wartości
	_wektorWartosci.clear();
}

void Wykres::plotuj(double czas, double wartosc) {
	_wektorCzasu.push_back(czas);		// dodanie obecnego czasu do wektora czasu
	_wektorWartosci.push_back(wartosc);	// dodanie obecnej wartości do wektora wartości
	QVector<double> qczas = QVector<double>::fromStdVector(_wektorCzasu);
	QVector<double> qwartosci = QVector<double>::fromStdVector(_wektorWartosci);
	this->addGraph();	// dodanie wykresu
	this->graph(0)->setData(qczas,qwartosci);	// wyznaczenie danych do wykresu
	this->xAxis->setRange(czas-10,czas);	// wyznaczenie zakresów osi
	this->yAxis->setRange(-180, 180);
	this->replot();  	// wyrysowanie zaktualizowanego wykresu
}

void Wykres::plotujSymulacje(DaneSymulacji &daneSymulacji) {
	daneSymulacji._aktualnyCzas++;		// inkrementacja aktualnego czasu symulacji
	this->addGraph();		// dodanie wykresu
	QVector<double> czas = QVector<double>::fromStdVector(daneSymulacji._czas);
	QVector<double> wartosci = QVector<double>::fromStdVector(daneSymulacji._wartosci);
	this->graph(0)->setData(czas,wartosci);		// wyznaczenie danych do wykresu
	this->xAxis->setRange((double)daneSymulacji._aktualnyCzas/10-10,(double)daneSymulacji._aktualnyCzas/10);
	this->yAxis->setRange(-180, 180);	// wyznaczenie zakresów osi
	this->replot();		// wyrysowanie zaktualizowanego wykresu
}

void Wykres::plotujOdczyt() {
	this->addGraph();		// dodanie wykresu
	QVector<double> czas = QVector<double>::fromStdVector(_wektorCzasu);
	QVector<double> wartosci = QVector<double>::fromStdVector(_wektorWartosci);
	this->graph(0)->setData(czas,wartosci);		// wyznaczenie danych do wykresu
	double teraz = _wektorCzasu[_wektorCzasu.size()-1];
	this->xAxis->setRange(teraz-10,teraz+1);
	this->yAxis->setRange(-180, 180);	// wyznaczenie zakresów osi
	this->replot();		// wyrysowanie zaktualizowanego wykresu
}
