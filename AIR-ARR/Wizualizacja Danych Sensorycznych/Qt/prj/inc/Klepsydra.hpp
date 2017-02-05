/*!
 * \file
 * \brief Plik nagłówkowy klasy Klepsydra.
*/

#ifndef KLEPSYDRA_HH
#define KLEPSYDRA_HH

#include <QMainWindow>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <QDebug>
#include <QPainter>
#include <QPixmap> 
#include <QImage>
#include <cmath>
#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QMainWindow>
#include <QProgressBar>
#include <QBrush>
#include <QPalette>
#include <QGraphicsColorizeEffect>
#include <math.h>

/*!
 * \brief Klasa odpowiedzialna za widok klepsydry.
 * 
 * Klasa Klepsydra dziedziczy po klasie QWidget i ma za zadanie obsługiwać widok klepsydry.
*/
class Klepsydra : public QWidget { 
	Q_OBJECT
public:
/*!
 * \brief Pole typu int przechowujące informację o kierunku przepływu strumienia (1 / 0 / -1).
*/
	int _stanStrumienia;
/*!
 * \brief Pole typu int przechowujące informację o poziomie prędkości przepływu (zależne od kąta wychylenia).
*/
	int _predkoscPrzeplywu;
/*!
 * \brief Pole typu int przechowujące informację o procencie wypełnienia górnej połowy klepsydry.
*/
	int _wypelnienieGory;
/*!
 * \brief Pole typu int przechowujące informację o procencie wypełnienia dolnej połowy klepsydry.
*/
	int _wypelnienieDolu;
/*!
 * \brief Pole typu int przechowujące procentowe wypełnienie górnej połowy klepsydry.
*/
	int _wypelnienieGoryProcent;
/*!
 * \brief Pole typu int przechowujące procentowe wypłenienie dolnej połowy klepsydry.
*/
	int _wypelnienieDoluProcent;
/*!
 * \brief Pole typu int przechowujące pomocniczą wartość do rysowania wypełnienia klepsydry.
*/
	int _przesuniecieDolu;
/*!
 * \brief Pole typu int służące do skalowania rysowanych obiektów.
*/
	int _skala;
/*!
 * \brief Konstruktor klasy Klepsydra.
 * \param[in] wRodzic - wskaźnik na obiekt typu QWidget wskazujący rodzica widgetu klepsydry, domyślnie NULL
*/
	Klepsydra(QWidget* wRodzic = 0L);
/*!
 * \brief Przeciążenie odziedziczonej metody wirtualnej pozwalającej na rysowanie.
 * \param[in] event - wskaźnik na obiekt typu QPaintEvent
 * \return Nic nie jest zwracane.
*/
	virtual void paintEvent(QPaintEvent* event);
/*!
 * \brief Pole typu QImage przechowujące obraz klepsydry.
*/
        QImage _obraz;
/*!
 * \brief Pole typu QSize przechowujące rozmiar klepsydry.
*/
        QSize _rozmiar;
/*!
 * \brief Pole typu int przechowujące wartość (w stopniach) odchylenia klepsydry od pionu.
*/
        int _kat;
public slots:
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \param[in] wartosc - wartość wychylenia klepsydry (w stopniach) od pionu podana w stopniach
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ustawia podaną jako argument wartość wychylenia klepsydry i przerysowuje klepsydrę 
 * w odpowiednim położeniu.
*/
	void ustawWartosc(int wartosc);
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda aktualizuje wartości wypełnienia obu części klepsydry oraz kierunek odmierzania
 * czasu.
*/
    	void liczWartosci();
};

#endif 
