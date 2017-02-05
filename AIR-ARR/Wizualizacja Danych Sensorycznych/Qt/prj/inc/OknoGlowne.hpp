/*!
 * \file 
 * \brief Plik nagłówkowy klasy OknoGlowne.
*/

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QMetaObject>
#include <QVariant>
#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <iostream>
#include <sstream>
#include <fstream>
#include <QProgressBar>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "qcustomplot.hpp"
#include "Poziomica.hpp"
#include "Wykres.hpp"
#include "Klepsydra.hpp"
#include "DaneSymulacji.hpp"

/*!
 * \brief Klasa odpowiedzialna za wyskakujące okienko z opcjami.
*/
class Okienko : public QDialog {
	Q_OBJECT
public:
/*!
 * \brief Wskaźnik na obiekt typu QPushButton odpowiedzialny za wczytanie ustawień domyślnych.
*/
    	QPushButton *wczytajUstawieniaDomyslne;
/*!
 * \brief Wskaźnik na obiekt typu QPushButton odpowiedzialny za zapisanie obecnych ustawień jako domyślne.
*/
    	QPushButton *zapiszUstawieniaDomyslne;
/*!
 * \brief Wskaźnik na obiekt typu QPushButton odpowiedzialny za wyjście z okienka ustawień.
*/
    	QPushButton *wyjdz;
/*!
 * \brief Wskaźnik na obiekt typu QLabel odpowiedzialny za etykietę okienka ustawień.
*/
    	QLabel *stanUstawien;
/*!
 * \brief Konstruktor klasy Okienko.
*/
    	Okienko();
/*! 
 * \brief Metoda odpowiedzialna za uruchomienie okienka z ustawieniami.
 * \return Nic nie jest zwracane.
*/
    	void uruchom();
/*!
 * \brief Metoda przygotowująca tekst do tłumaczenie na inny język.
 * \return Nic nie jest zwracane.
*/
    	void tlumacz();
/*!
 * \brief Pole typu QString przechowujące nazwę pliku z danymi do trybu symulacji
*/
    	QString _plik;
/*!
 * \brief Pole typu QString przechowujące nazwę portu z którego mają być czytane dane w trybie wizualizacyjnym.
*/
	QString _port;
  
public slots:

/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta zapisuje obecne ustawienia jako domyślne.
*/
    	void zapiszUstawienia();
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta wczytuje domyślne ustawienia.
*/
    	void wczytajUstawienia();
};

/*!
 * \brief Klasa odpowiedzialna za główne okno aplikacji.
 *
 * Klasa OknoGlowne dziedziczy po klasie QMainWindow i ma za zadanie nadzorować działanie całej aplikacji.
*/
class OknoGlowne : public QMainWindow {
    	Q_OBJECT
public:
    int aktualnyCzas;
   QString _portInfo;
   QSerialPort *serial ;
   bool serialWlaczony;
        QTimer *timer ;

/*!
 * \brief Konstruktor klasy OknoGlowne.
 * \param[in] wRodzic - wskaźnik na obiekt typu QWidget wskazujący rodzica widgetu poziomicy, domyślnie NULL
*/
	OknoGlowne(QMainWindow *wRodzic = 0L);
/*!
 * \brief Metoda tworząca listę plików do wyboru w trybie symulacyjnym.
 * \return Nic nie jest zwracane.
*/
    	void utworzListePlikow();
/*!
 * \brief Metoda tworząca listę portów do wyboru w trybie wizualizacyjnym.
 * \return Nic nie jest zwracane.
*/
    	void utworzListePortow();
/*!
 * \brief Przeciążenie odziedziczonej metody resizeEvent pozwalającej na zmianę rozmiaru okienka.
 * \param[in] event - wskaźnik na obiekt typu QResizeEvent
*/
	void resizeEvent(QResizeEvent* event);
/*!
 * \brief Wskaźnik na obiekt typu QTabWidget odpowiedzialny za karty wyboru widoku (Klepsydra / Poziomica / Wykres).
*/
    	QTabWidget *opcjeWidoku;
/*!
 * \brief Wskaźnik na obiekt typu Klepsydra odpowiedzialny za działanie widoku klepsydry.
*/
	Klepsydra *klepsydra;
/*!
 * \brief Wskaźnik na obiekt typu Poziomica odpowiedzialny za działanie widoku poziomicy.
*/
	Poziomica *poziomica;
/*!
 * \brief Wskaźnik na obiekt typu Wykres odpowiedzialny za działanie widoku wykresu.
*/
	Wykres *wykres;
/*! 
 * \brief Wskaźnik na obiekt typu QTabWidget odpowiedzialny za karty wyboru trybu pracy (Ręczny / Symulacyjny / Wizualizacyjny).
*/
    	QTabWidget *trybyPracy;
/*!
 * \brief Wskaźnik na obiekt typu QWidget odpowiedzialny za działanie trybu ręcznego.
*/
    	QWidget *reczny;
/*!
 * \brief Wskaźnik na obiekt typu QLabel odpowiedzialny za etykietę trybu ręcznego. 
*/
    	QLabel *trybRecznyEtykieta;
/*!
 * \brief Wskaźnik na obiekt typu QDial odpowiedzialny za pokrętło używane w trybie ręcznym.
*/
    	QDial *pokretlo;  
/*!
 * \brief Wskaźnik na obiekt typu QWidget odpowiedzialny za działanie trybu symulacyjnego.
*/
    	QWidget *symulacyjny;
/*!
 * \brief Wskaźnik na obiekt typu QComboBox odpowiedzialny za opcję wyboru pliku z danymi do trybu symulacyjnego.
*/
    	QComboBox *wyborPliku;
/*!
 * \brief Wskaźnik na obiekt typu QLabel odpowiedzialny za etykietę trybu symulacyjnego.
*/
    	QLabel *trybSymulacyjnyEtykieta;
/*!
 * \brief Wskaźnik na obiekt typu QWidget odpowiedzialny za działanie trybu wizualizacyjnego.
*/
   	QWidget *wizualizacyjny;
/*!
 * \brief Wskaźnik na obiekt typu QComboBox odpowiedzialny za opcję wyboru portu do czytania danych w trybie wizualizacyjnym.
*/
   	QComboBox *wyborPortu;
/*!
 * \brief Wskaźnik na obiekt typu QLabel odpowiedzialny za etykietę trybu wizualizacyjnego.
*/
   	QLabel *trybWizualizacyjnyEtykieta;
/*!
 * \brief Wskaźnik na obiekt typu QFrame odpowiedzialny za menu z opcjami programu (Ustawienia / ZAKOŃCZ).
*/
	QFrame *opcjeProgramu;
/*!
 * \brief Wskaźnik na obiekt typu QLabel odpowiedzialny za etykietę menu z opcjami programu.
*/
	QLabel *opcjeEtykieta;
/*!
 * \brief Wskaźnik na obiekt typu QPushButton odpowiedzialny za przycisk Ustawienia w menu opcji programu.
*/
	QPushButton *ustawienia;
/*!
 * \brief Wskaźnik na obiekt typu QPushButton odpowiedzialny za przycisk ZAKOŃCZ w menu opcji programu.
*/
	QPushButton *zakoncz;
/*!
 * \brief Wskaźnik na obiekt typu Okienko odpowiedzialny za wyskakujące okienko z opcjami.
*/
    	Okienko *okienko;
/*!
 * \brief Pole typu DaneSymulacji przechowujące obiekt tej klasy odpowiedzialny za kontrolę trybu symulacji.
*/
    	DaneSymulacji _daneSymulacji;
signals:
/*!
 * \brief Sygnał mówiący o tym, że gotowe są dane do odczytu.
*/
	void moznaOdczytac();
public slots:
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta dokonuje odczytu wartości z wybranego portu.
*/
	void dokonajOdczytu();
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta obsługuje wizualizację danych pobranych od urządzenia.
*/
	void wizualizuj();
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta tworzy wyskakujące okienko z opcjami.
*/
    	void utworzOkienko();
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta startuje symulację.
*/
    	void odpalSymulacje();
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \param[in] nrZakladki - zmienna typu int dostarczająca informacji o obecnym trybie
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta przygotowuje widok wykresu oraz symulację.
*/
    	void obslugaZakladek(int nrZakladki);
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta uaktualni stany odczyrtanego pliku i portu.
*/
        void obslugaZamknieciaOkienka();
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \param[in] indeks - zmienna typu int mówiąca o tym, który plik z listy został wybrany do symulacji
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta przygotowuje dane dla trybu symulacji.
*/
    	void obslugaWybraniaPliku(int indeks);
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \param[in] indeks - zmienna typu int mówiąca o tym, który port z listy został wybrany do wizualizacji
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta przygotowuje port dla trybu wizualizacji.
*/
    	void obslugaWybraniaPortu(int indeks);
/*!
 * \brief Slot odbierający sygnał z zewnątrz.
 * \return Nic nie jest zwracane.
 *
 * W odpowiedzi na pojawienie się sygnału w slocie metoda ta wymusza kolejny krok symulacji.
*/
    	void obslugaTimera();
};

#endif
