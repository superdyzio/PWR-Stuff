/*!
 * \file
 * \brief Plik nagłówkowy klasy Poziomica.
*/

#ifndef POZIOMICA_HH
#define POZIOMICA_HH

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
#include <QDebug>
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

/*!
 * \brief Klasa odpowiedzialna za widok poziomicy.
 *
 * Klasa Poziomica dziedziczy po klasie QWidget i ma zadanie obsługiwać widok poziomicy.
*/
class Poziomica : public QWidget { 
	Q_OBJECT
public:
/*!
 * \brief Pole typu QImage przechowujące obraz bąbla wewnątrz poziomicy.
*/
	QImage _babel;
/*!
 * \brief Pole typu int przechowujące wartość przesunięcia (w pikselach) bąbla od środka poziomicy.
*/
	int _przesuniecie;
/*!
 * \brief Pole typu int służące do skalowania rysowanych obiektów.
*/
	int _skala;
/*!
 * \brief Konstruktor klasy Poziomica.
 * \param[in] wRodzic - wskaźnik na obiekt typu QWidget wskazujący rodzica widgetu poziomicy, domyślnie NULL
*/
	Poziomica(QWidget* wRodzic = 0L);
/*!
 * \brief Przeciążenie odziedziczonej metody wirtualnej pozwalającej na rysowanie.
 * \param[in] event - wskaźnik na obiekt typu QPaintEvent
 * \return Nic nie jest zwracane.
*/
	virtual void paintEvent(QPaintEvent* event);
/*!
 * \brief Pole typu QImage przechowujące obraz poziomicy.
*/
        QImage _obraz;
/*!
 * \brief Pole typu QSize przechowujące rozmiar poziomicy.
*/
        QSize _rozmiar;
/*!
 * \brief Pole typu int przechowujące wartość (w stopniach) odchylenia poziomicy od pionu.
*/
        int _kat;
public slots:

/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \param[in] wartosc - wartość wychylenia poziomicy (w stopniach) od pionu podana w stopniach
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ustawia podaną jako argument wartość wychylenia poziomicy i przerysowuje poziomicę 
 * w odpowiednim położeniu.
*/
	void ustawWartosc(int wartosc);
};

#endif
