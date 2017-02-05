/*!
 * \file
 * \brief Główny plik aplikacji.
*/

#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <iostream>
#include <sstream>
#include <QMainWindow>
#include <QSpinBox>
#include <QProgressBar>
#include <QLCDNumber>
#include "OknoGlowne.hpp"

using namespace std;

int main( int argc, char * argv[] ) {
	QApplication App(argc,argv);
	OknoGlowne Okno;
	Okno.show();
	return App.exec();
}
