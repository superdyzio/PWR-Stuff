/*!
 * \file
 * \brief Plik źródłowy klasy Poziomica.
*/

#include "Poziomica.hpp"

Poziomica::Poziomica(QWidget* wRodzic) : QWidget(wRodzic) {
	_skala = 300; 
  	_kat = 0;
  	_obraz.load("img/poziomica.png");	// wczytanie obrazu poziomicy
  	_obraz = _obraz.scaled(_skala,_skala,Qt::KeepAspectRatio,Qt::FastTransformation);
  	_rozmiar = _obraz.size(); 
  	_babel.load("img/babel.png");		// wczytanie obrazu bąbelka
  	_babel = _babel.scaled(_skala/10,_skala/10,Qt::KeepAspectRatio,Qt::FastTransformation);
  	 
}

void Poziomica::ustawWartosc(int wartosc) {
  	_kat = wartosc;
	if (_kat <= -45)		// sprawdzenie poprawności kąta wychylenia
		_kat = -45;
	if (_kat >= 45)
		_kat = 45;
    	_przesuniecie = (_kat * (_obraz.size().width() - _babel.size().width() * 3) / 90);		// obliczenie pozycji bąbelka
	QWidget::repaint();
}

void Poziomica::paintEvent(QPaintEvent *) {
  	QPainter Rysownik(this);
  	Rysownik.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform, true);
  	Rysownik.translate(width()/2,height()/2);	// ustawienie się na środku pola do rysowania
  	Rysownik.rotate(_kat);				// rotacja o zadany kąt
  	Rysownik.translate(-_przesuniecie,-_obraz.size().height()/2+_babel.size().height()*3); 	// ustawienie się na górze poziomicy 
  	Rysownik.drawImage(QPoint(-_babel.size().width()/2,-_babel.size().height()/2), _babel);	// rysowanie bąbelka
  	Rysownik.translate(_przesuniecie,_obraz.size().height()/2-_babel.size().height()*3); 	// powrót do środka poziomicy
  	Rysownik.drawImage(QPoint(-_rozmiar.width()/2,-_rozmiar.height()/2), _obraz); 		// obrót poziomicy
}
