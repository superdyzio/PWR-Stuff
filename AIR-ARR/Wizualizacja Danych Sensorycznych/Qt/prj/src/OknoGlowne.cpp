/*!
 * \file 
 * \brief Plik źródłowy klasy OknoGlowne.
*/

#include "OknoGlowne.hpp"

OknoGlowne::OknoGlowne(QMainWindow *wRodzic) : QMainWindow(wRodzic) {  
    	serialWlaczony = 0;
        aktualnyCzas = 0;
        this->setMinimumSize(QSize(670, 607));
    	this->setObjectName(QStringLiteral("Program"));
    	opcjeWidoku = new QTabWidget(this);
    	opcjeWidoku->setObjectName(QStringLiteral("opcjeWidoku"));
    	opcjeWidoku->setGeometry(QRect(40, 20, 551, 431));
    	opcjeWidoku->setFocusPolicy(Qt::NoFocus);
    	opcjeWidoku->setTabShape(QTabWidget::Rounded);
    	klepsydra = new Klepsydra();
    	klepsydra->setObjectName(QStringLiteral("klepsydra"));
    	opcjeWidoku->addTab(klepsydra, QString());
    	poziomica = new Poziomica();
    	poziomica->setObjectName(QStringLiteral("poziomica"));
    	opcjeWidoku->addTab(poziomica, QString());
    	wykres = new Wykres();
    	wykres->setObjectName(QStringLiteral("wykres"));
    	opcjeWidoku->addTab(wykres, QString());
    	opcjeWidoku->setCurrentIndex(0);
    	trybyPracy = new QTabWidget(this);
    	trybyPracy->setObjectName(QStringLiteral("trybyPracy"));
    	trybyPracy->setEnabled(true);
    	trybyPracy->setGeometry(QRect(40, 460, 281, 121));
    	trybyPracy->setFocusPolicy(Qt::NoFocus);
    	trybyPracy->setAcceptDrops(false);
    	trybyPracy->setLayoutDirection(Qt::LeftToRight);
    	trybyPracy->setAutoFillBackground(false);
    	trybyPracy->setTabPosition(QTabWidget::South);
    	trybyPracy->setElideMode(Qt::ElideMiddle);
    	trybyPracy->setMovable(false);
    	reczny = new QWidget();
    	reczny->setObjectName(QStringLiteral("reczny"));
    	pokretlo = new QDial(reczny);
    	pokretlo->setObjectName(QStringLiteral("pokretlo"));
    	pokretlo->setGeometry(QRect(90, 0, 81, 81));
    	pokretlo->setFocusPolicy(Qt::WheelFocus);
    	pokretlo->setWrapping(true);
    	pokretlo->setRange(-180,180);
    	pokretlo->setValue(0);
    	trybRecznyEtykieta = new QLabel(reczny);
    	trybRecznyEtykieta->setObjectName(QStringLiteral("trybRecznyEtykieta"));
    	trybRecznyEtykieta->setGeometry(QRect(10, 0, 81, 21));
    	trybyPracy->addTab(reczny, QString());
    	symulacyjny = new QWidget();
    	symulacyjny->setObjectName(QStringLiteral("symulacyjny"));
    	wyborPliku = new QComboBox(symulacyjny);
    	wyborPliku->setObjectName(QStringLiteral("wyborPliku"));
    	wyborPliku->setGeometry(QRect(70, 30, 121, 27));
    	trybSymulacyjnyEtykieta = new QLabel(symulacyjny);
    	trybSymulacyjnyEtykieta->setObjectName(QStringLiteral("trybSymulacyjnyEtykieta"));
    	trybSymulacyjnyEtykieta->setGeometry(QRect(10, 0, 121, 21));
    	trybyPracy->addTab(symulacyjny, QString());
    	wizualizacyjny = new QWidget();
    	wizualizacyjny->setObjectName(QStringLiteral("wizualizacyjny"));
    	wyborPortu = new QComboBox(wizualizacyjny);
    	wyborPortu->setObjectName(QStringLiteral("wyborPortu"));
    	wyborPortu->setGeometry(QRect(70, 30, 121, 27));
    	trybWizualizacyjnyEtykieta = new QLabel(wizualizacyjny);
    	trybWizualizacyjnyEtykieta->setObjectName(QStringLiteral("trybWizualizacyjnyEtykieta"));
    	trybWizualizacyjnyEtykieta->setGeometry(QRect(10, 0, 131, 21));
    	trybyPracy->addTab(wizualizacyjny, QString());
    	trybyPracy->setCurrentIndex(0);
    	opcjeProgramu = new QFrame(this);
    	opcjeProgramu->setObjectName(QStringLiteral("opcjeProgramu"));
    	opcjeProgramu->setEnabled(true);
    	opcjeProgramu->setGeometry(QRect(370, 460, 221, 121));
    	opcjeProgramu->setCursor(QCursor(Qt::ArrowCursor));
    	opcjeProgramu->setFocusPolicy(Qt::NoFocus);
    	opcjeProgramu->setAcceptDrops(false);
    	opcjeProgramu->setLayoutDirection(Qt::LeftToRight);
    	opcjeProgramu->setAutoFillBackground(false);
    	opcjeProgramu->setFrameShape(QFrame::Panel);
    	opcjeProgramu->setFrameShadow(QFrame::Sunken);
    	opcjeProgramu->setLineWidth(2);
    	ustawienia = new QPushButton(opcjeProgramu);
    	ustawienia->setObjectName(QStringLiteral("ustawienia"));
    	ustawienia->setGeometry(QRect(60, 40, 101, 27));
    	ustawienia->setFocusPolicy(Qt::NoFocus);
    	zakoncz = new QPushButton(opcjeProgramu);
    	zakoncz->setObjectName(QStringLiteral("zakoncz"));
    	zakoncz->setGeometry(QRect(60, 70, 101, 27));
    	zakoncz->setFocusPolicy(Qt::NoFocus);
    	opcjeEtykieta = new QLabel(opcjeProgramu);
    	opcjeEtykieta->setObjectName(QStringLiteral("opcjeEtykieta"));
    	opcjeEtykieta->setGeometry(QRect(10, 0, 111, 21));
    	this->setWindowTitle(QApplication::translate("Klepsydra", "Klepsydra", 0));
    	ustawienia->setText(QApplication::translate("Dialog", "   Ustawienia   ", 0));
    	zakoncz->setText(QApplication::translate("Dialog", "   ZAKO\305\203CZ   ", 0));
    	opcjeEtykieta->setText(QApplication::translate("Dialog", "Opcje programu", 0));
    	opcjeWidoku->setTabText(opcjeWidoku->indexOf(klepsydra), QApplication::translate("Dialog", "     Klepsydra     ", 0));
    	opcjeWidoku->setTabText(opcjeWidoku->indexOf(poziomica), QApplication::translate("Dialog", "     Poziomica     ", 0));
    	opcjeWidoku->setTabText(opcjeWidoku->indexOf(wykres), QApplication::translate("Dialog", "     Wykres     ", 0));
    	trybRecznyEtykieta->setText(QApplication::translate("Dialog", "Tryb r\304\231czny", 0));
    	trybyPracy->setTabText(trybyPracy->indexOf(reczny), QApplication::translate("Dialog", "R\304\231czny", 0));
    	wyborPliku->clear();
    	wyborPliku->insertItems(0, QStringList()<<QApplication::translate("Dialog", "Wyb\303\263r pliku", 0));
    	trybSymulacyjnyEtykieta->setText(QApplication::translate("Dialog", "Tryb symulacyjny", 0));
    	trybyPracy->setTabText(trybyPracy->indexOf(symulacyjny), QApplication::translate("Dialog", "Symulacyjny", 0));
    	wyborPortu->clear();
    	wyborPortu->insertItems(0, QStringList()<<QApplication::translate("Dialog", "Wyb\303\263r portu", 0));
    	trybWizualizacyjnyEtykieta->setText(QApplication::translate("Dialog", "Tryb wizualizacyjny", 0));
    	trybyPracy->setTabText(trybyPracy->indexOf(wizualizacyjny), QApplication::translate("Dialog", "Wizualizacyjny", 0));     
    	this->utworzListePlikow();
	    this->utworzListePortow();
        connect(trybyPracy, SIGNAL(currentChanged(int)), this, SLOT(obslugaZakladek(int)) );                              
    	connect(ustawienia, SIGNAL(clicked()), this, SLOT(utworzOkienko()));  
    	connect(pokretlo, SIGNAL(valueChanged(int)), klepsydra, SLOT(ustawWartosc(int)));
    	connect(pokretlo, SIGNAL(valueChanged(int)), poziomica, SLOT(ustawWartosc(int)));
    	connect(zakoncz, SIGNAL(clicked()), this, SLOT(close()));
    	connect(wyborPliku, SIGNAL(currentIndexChanged(int)), this, SLOT(obslugaWybraniaPliku(int)));
        connect(wyborPortu, SIGNAL(currentIndexChanged(int)), this, SLOT(obslugaWybraniaPortu(int)));
        timer = new QTimer(this);
       	connect(timer, SIGNAL(timeout()), this, SLOT(obslugaTimera()));
      	connect(timer, SIGNAL(timeout()), klepsydra, SLOT(liczWartosci()));
       	timer->start(100);
}

void OknoGlowne::obslugaZakladek(int nrZakladki) {
	if (serialWlaczony) {
		serial->close();
        	disconnect(timer, SIGNAL(timeout()), this, SLOT(dokonajOdczytu()));
        	serialWlaczony=0;
    	}
    	switch (nrZakladki) {
        case 0:
                wykres->zeruj();
                _daneSymulacji._aktualnyCzas = 0;
        break;
        case 1:
               if (wyborPliku->currentIndex() > 0) 
			obslugaWybraniaPliku(wyborPliku->currentIndex());
               this->odpalSymulacje();
        break;
        case 2:
                wykres->_wektorCzasu.clear();
                wykres->_wektorWartosci.clear();
              	if (wyborPortu->currentIndex() > 0) 
			obslugaWybraniaPortu(1);
        break;
    	}
}

void OknoGlowne::obslugaTimera() {
    	_daneSymulacji._aktualnyCzas++;
    	if (trybyPracy->currentIndex() == 1 && _daneSymulacji._plikSymulacji != "")
        	switch (opcjeWidoku->currentIndex()) {
            	case 0:
                	klepsydra->ustawWartosc(_daneSymulacji._wartosci[_daneSymulacji._aktualnyCzas]);
            	break;	
                case 1:
                	poziomica->ustawWartosc(_daneSymulacji._wartosci[_daneSymulacji._aktualnyCzas]);
            	break;
                case 2:
                       	wykres->plotujSymulacje(_daneSymulacji);
                break;
        	}
    	else 
		if (trybyPracy->currentIndex() == 0 && opcjeWidoku->currentIndex() == 2)
       			wykres->plotuj(_daneSymulacji._aktualnyCzas/10, pokretlo->value());
}

void OknoGlowne::odpalSymulacje() {
	if (_daneSymulacji._plikSymulacji != "")
        	_daneSymulacji._aktualnyCzas = 0;
}


void OknoGlowne::obslugaZamknieciaOkienka() {
	disconnect(wyborPliku, SIGNAL(currentIndexChanged(int)), this, SLOT(obslugaWybraniaPliku(int)));
       	disconnect(wyborPortu, SIGNAL(currentIndexChanged(int)), this, SLOT(obslugaWybraniaPortu(int)));
    	for (int i = 1; i < wyborPliku->count(); i++)
        	if (wyborPliku->itemText(i) == okienko->_plik) {       
           		wyborPliku->setCurrentIndex(i);
           		obslugaWybraniaPliku(i);
        	}   
    	for (int i = 1; i < wyborPortu->count(); i++)
        	if (wyborPortu->itemText(i) == okienko->_port) {       
            		wyborPortu->setCurrentIndex(i);
            		_portInfo =wyborPortu->currentText();
            		if (trybyPracy->currentIndex() == 2 && i != wyborPortu->currentIndex())
                		obslugaWybraniaPortu(i);
                }   
        connect(wyborPliku, SIGNAL(currentIndexChanged(int)), this, SLOT(obslugaWybraniaPliku(int)));
        connect(wyborPortu, SIGNAL(currentIndexChanged(int)), this, SLOT(obslugaWybraniaPortu(int)));
}

void OknoGlowne::obslugaWybraniaPliku(int indeks) {
        if (indeks != 0) {
            std::string standardString = wyborPliku->currentText().toUtf8().constData();
            _daneSymulacji.wczytajDane(standardString);
        }
}

void OknoGlowne::utworzListePlikow() {
    	DIR *dir;
    	struct dirent *ent;
    	if ((dir = opendir ("data")) != NULL) {		
        	while ((ent = readdir (dir)) != NULL) {
            		std::string lancuch =(std::string) ent->d_name;
            		std::string rozszerzenie(".dat");	
            		std::size_t znalezione = lancuch.find(rozszerzenie);
            		if (znalezione != std::string::npos) {
                		QString qlancuch = QString::fromUtf8(lancuch.c_str());
                		this->wyborPliku->addItem(qlancuch); 
            		}
        	}
    		closedir(dir);
    	} 
	else
      		qDebug() << "Brak katalogu 'data' w folderze projektu!";
}



void OknoGlowne::utworzOkienko() {
    	okienko = new Okienko;   
        connect(okienko->wyjdz, SIGNAL(clicked()), this, SLOT(obslugaZamknieciaOkienka()));
    	okienko->setAttribute(Qt::WA_DeleteOnClose, true);
    	if (wyborPliku->currentIndex() > 0)
        	okienko->_plik = wyborPliku->currentText();
    	if (wyborPortu->currentIndex() > 0)
        	okienko->_port = wyborPortu->currentText();
    	okienko->exec();  
}

void OknoGlowne::resizeEvent(QResizeEvent* event) {   	
    QMainWindow::resizeEvent(event);
}

Okienko::Okienko() {
    	uruchom();
}

void Okienko::uruchom() {
    	if (this->objectName().isEmpty())
        	this->setObjectName(QStringLiteral("Dialog"));
    	this->resize(424, 234);
    	wczytajUstawieniaDomyslne = new QPushButton(this);
    	wczytajUstawieniaDomyslne->setGeometry(QRect(50, 60, 311, 41));
    	zapiszUstawieniaDomyslne= new QPushButton(this);
    	zapiszUstawieniaDomyslne->setGeometry(QRect(50, 100, 311, 41));
    	wyjdz = new QPushButton(this);
    	wyjdz->setGeometry(QRect(50, 140, 311, 41));
    	stanUstawien = new QLabel(this);
    	stanUstawien->setGeometry(QRect(130, 10, 161, 41));
    	QFont font;
    	font.setPointSize(14);
    	font.setBold(true);
    	font.setWeight(40);
    	stanUstawien->setFont(font);
    	tlumacz();
    	connect(wyjdz, SIGNAL(clicked()), this, SLOT(reject()));
       	connect(zapiszUstawieniaDomyslne, SIGNAL(clicked()), this, SLOT(zapiszUstawienia()));
    	connect(wczytajUstawieniaDomyslne, SIGNAL(clicked()), this, SLOT(wczytajUstawienia()));
} 

void Okienko::tlumacz() {
    	this->setWindowTitle(QApplication::translate("Ustawienia", "Ustawienia", 0));
    	wczytajUstawieniaDomyslne->setText(QApplication::translate("Ustawienia", "Wczytaj ustawienia domy\305\233lne", 0));
    	zapiszUstawieniaDomyslne->setText(QApplication::translate("Ustawienia", "Zapisz bie\305\274\304\205ce ustawienia jako domy\305\233lne",0));
    	wyjdz->setText(QApplication::translate("Ustawienia", "Wyjd\305\272", 0));
} 

void Okienko::zapiszUstawienia() {
    	if (this->_plik != ""  || this->_port != "") {
        	std::string standardStringPlik = this->_plik.toUtf8().constData();
        	std::string standardStringPort = this->_port.toUtf8().constData();
		std::ofstream plik("data/config");
        	plik << standardStringPlik;
        	plik << endl;
        	plik << standardStringPort;
        	plik.close(); 
            	QFont font1;
            	font1.setPointSize(20);
            	stanUstawien->setFont(font1);
        	stanUstawien->setText(QString("   Zapisano!"));
    	}
    	else {
                QFont font1;
                font1.setPointSize(18);
                stanUstawien->setFont(font1);
            	stanUstawien->setText(QString("Brak ustawień!"));

        }
}

void Okienko::wczytajUstawienia() {
  	std::string nazwaPliku, nazwaPortu;
  	std::ifstream plik("data/config");
  	if (plik.is_open()) {
    		std::getline(plik,nazwaPliku);
    		QString qNazwaPliku = QString::fromUtf8(nazwaPliku.c_str());
    		std::getline (plik, nazwaPortu);
    		QString qNazwaPortu = QString::fromUtf8(nazwaPortu.c_str());
    		plik.close();
            	_port = qNazwaPortu;
            	_plik = qNazwaPliku;
            	QFont font1;
            	font1.setPointSize(20);
            	stanUstawien->setFont(font1);
        	stanUstawien->setText("  Wczytano!");
    	}
  	else {
            	QFont font1;
            	font1.setPointSize(21);
            	stanUstawien->setFont(font1);
		stanUstawien->setText(" Brak pliku!");
    	}
}

void OknoGlowne::utworzListePortow() {
    	QList<QSerialPortInfo> dostepne_porty;
    	dostepne_porty = QSerialPortInfo::availablePorts();
     	this->wyborPortu->addItem(dostepne_porty.at(0).portName());
}

void OknoGlowne::wizualizuj() {
    	serialWlaczony = 1;
    	aktualnyCzas = 0;
    	wykres->_wektorWartosci.clear();
    	wykres->_wektorCzasu.clear();
    	serial = new QSerialPort(this);
    	serial->setPortName(_portInfo);
    	if (!serial->open(QIODevice::ReadOnly))
        	qDebug() << serial->errorString();
    	else {
        	serial->setBaudRate(QSerialPort::Baud9600);
        	serial->setDataBits(QSerialPort::Data8);
        	serial->setFlowControl(QSerialPort::HardwareControl);
        	connect(timer, SIGNAL(timeout()), this, SLOT(dokonajOdczytu()));
        	wykres->_aktualnyCzas = 0;
    	}
        serial->close();
}

void OknoGlowne::dokonajOdczytu(){
    	++aktualnyCzas;
    	double czas = (double)aktualnyCzas/10;
    	serial->open(QIODevice::ReadOnly);
    	QString bufor;
    	if (serial->canReadLine()) {
    		bufor = serial->readLine();
    		klepsydra->_kat = -bufor.toInt();
    		if (bufor.length() > 0) {
    			poziomica->ustawWartosc(-bufor.toInt()-90);
    			wykres->_wektorWartosci.push_back(-bufor.toInt());
		}
 		wykres->_wektorCzasu.push_back(czas);
    		wykres->plotujOdczyt();
	}
}

void OknoGlowne::obslugaWybraniaPortu(int indeks) {
    	if (indeks != 0) {
    		_portInfo = wyborPortu->currentText();
    		this->wizualizuj();
    	}
	else {
         	_portInfo ="";
         	serialWlaczony=0;
    	}
}
