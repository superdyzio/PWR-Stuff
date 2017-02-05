/*!
 * \file
 * \brief Plik źródłowy klasy Klepsydra.
*/

#include "Klepsydra.hpp"

Klepsydra::Klepsydra(QWidget* wRodzic) : QWidget(wRodzic) {
  	_skala = 300; 
  	_kat = 0;
  	_wypelnienieGoryProcent = 0; 
  	_wypelnienieDoluProcent = 0;
  	_obraz.load("img/klepsydra.png");
  	_obraz = _obraz.scaled(_skala,_skala,Qt::KeepAspectRatio,Qt::FastTransformation);
  	_rozmiar = _obraz.size(); 
}

void Klepsydra::ustawWartosc(int wartosc) {
  	_kat = wartosc;
  	QWidget::repaint();
}

void Klepsydra::paintEvent(QPaintEvent *) {
  	double pom = _rozmiar.height()/2-70; 	// odległość od środka obrazka klepsydry do środka kółka wypełniającego
  	QPainter Rysownik(this);
  	Rysownik.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform, true);
  	QImage strumien;
  	strumien.load("img/strumien.png");
  	strumien = strumien.scaled(8,_rozmiar.height()/2*cos((double)_kat*2*3.1415/360),Qt::IgnoreAspectRatio,Qt::FastTransformation);
  	QTransform TransformStrumien;
  	TransformStrumien.translate(strumien.size().width()/2,0);
  	Rysownik.translate(width()/2,height()/2);
 	switch (_stanStrumienia) {		// wyrysowanie strumienia
		case 1: 
  			Rysownik.drawImage(QPoint(-strumien.size().width()/2-sin((double)_kat*(2*3.1415/360))*10,
						cos((double)_kat*(2*3.1415/360))*10),strumien);
   		break;
    		case 0:
    		break;
    		case -1:
    			strumien.load("img/strumien.png");
  			strumien = strumien.scaled(8,_rozmiar.height()/2*-cos((double)_kat*2*3.1415/360), 						Qt::IgnoreAspectRatio,Qt::FastTransformation);
  			Rysownik.drawImage(QPoint(-strumien.size().width()/2+sin((double)_kat*(2*3.1415/360))*10,
  					-cos((double)_kat*(2*3.1415/360))*10 ),strumien);
    		break;
	}  
  	QImage gora;		// wyrysowanie górnej połowki klepsydry
  	gora.load("img/polowa.png");
  	gora = gora.scaled(_skala/2.101,_skala/2.101,Qt::KeepAspectRatio,Qt::FastTransformation);
  	QImage wycinekGory;
  	wycinekGory = gora;
  	wycinekGory = wycinekGory.copy(0,wycinekGory.size().height()-_wypelnienieGory,wycinekGory.size().width(),_wypelnienieGory);
  	Rysownik.drawImage(QPoint(-_rozmiar.width()/2+sin((double)_kat*(2*3.1415/360))*pom,
  			-cos((double)_kat*(2*3.1415/360))*pom - _przesuniecieDolu  ),wycinekGory);
  	QImage dol;		// wyrysowanie dolnej połówki klepsydry
  	dol.load("img/polowa.png");
  	dol = dol.scaled(_skala/2.101,_skala/2.101,Qt::KeepAspectRatio,Qt::FastTransformation);
  	QImage wycinekDolu;
  	wycinekDolu = dol;
  	wycinekDolu = wycinekDolu.copy(0,wycinekDolu.size().height()-_wypelnienieDolu,wycinekDolu.size().width(),_wypelnienieDolu);
  	Rysownik.drawImage(QPoint(-_rozmiar.width()/2-sin((double)_kat*(2*3.1415/360))*pom,
  			cos((double)_kat*(2*3.1415/360))*pom + _przesuniecieDolu ),wycinekDolu);
   	Rysownik.rotate(_kat); 
  	Rysownik.drawImage(QPoint(-_rozmiar.width()/2,-_rozmiar.height()/2), _obraz);
}

void Klepsydra::liczWartosci() {
	if (_kat >= -30 && _kat <= 30) {		// wyznaczenie wartości prędkości oraz kierunku przepływu
  		_predkoscPrzeplywu = 2;
  		_stanStrumienia = 1;
	}
	else 
		if ((_kat >= -60 && _kat < -30) || (_kat > 30 &&_kat <= 60)) {
  			_predkoscPrzeplywu = 1;
  			_stanStrumienia = 1;
		}
		else 
			if ((_kat >= -90 && _kat <= -60) || (_kat > 60 &&_kat <= 90)) {
  				_predkoscPrzeplywu = 0;
  				_stanStrumienia = 0;
			}
			else 
				if ((_kat >= -120 && _kat < -90) || (_kat <= 120 && _kat > 90)) {
  					_predkoscPrzeplywu = 0;
  					_stanStrumienia = 0;
				}
				else 
					if (_kat >= -150 && _kat <= 150) {
	 	 				_predkoscPrzeplywu = 1;
  						_stanStrumienia = -1;
					}
					else 
						if (_kat < -150 || _kat > 150) {
  							_predkoscPrzeplywu = 2;
  							_stanStrumienia = -1;
						}
	if (_stanStrumienia > 0) {
    		if (_wypelnienieDoluProcent < 100)
       			_wypelnienieDoluProcent = _wypelnienieDoluProcent + _predkoscPrzeplywu * _stanStrumienia;
	}
	else 
		if (_stanStrumienia) {
   			if (_wypelnienieDoluProcent > 0)
       				_wypelnienieDoluProcent = _wypelnienieDoluProcent + _predkoscPrzeplywu * _stanStrumienia;
		}
  		_wypelnienieGoryProcent = 100 - _wypelnienieDoluProcent;
  		_wypelnienieDolu = _wypelnienieDoluProcent * _rozmiar.width() / 100;
  		_wypelnienieGory = _rozmiar.width() - _wypelnienieDolu;
  		if (_wypelnienieDoluProcent > 50)
      			_przesuniecieDolu = -(_wypelnienieDoluProcent - 50)*_rozmiar.width()/100;
  		else  
			if (_wypelnienieDoluProcent < 50)
      				_przesuniecieDolu = (50 -_wypelnienieDoluProcent)*_rozmiar.width()/100;
  			else 
				if (_wypelnienieDoluProcent == 50)
      					_przesuniecieDolu = 0;
  	QWidget::repaint();	// ponowne wyrysowanie zaktualizowanej klepsydry
}
