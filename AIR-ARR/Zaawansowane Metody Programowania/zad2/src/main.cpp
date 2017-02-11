/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/src/main.cpp $
$Author: dperdek $
$Date: 2015-12-06 20:40:26 +0100 (nie) $
$Revision: 5 $
*/

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

#include <iostream>
#include <list>
#include "scene.hh"
#include "xmlparser4scene.hh"

using namespace xercesc;

#include "menu.hh"

using namespace std;

/*!
 * \file
 * \brief Plik zawierający funkcję main() programu.
 */



/*!
 * Czyta z pliku opis sceny i zapisuje stan sceny do parametru,
 * który ją reprezentuje.
 * \param sFileName - (\b we.) nazwa pliku z opisem poleceń.
 * \param Scn - (\b we.) reprezentuje scenę, na której ma działać robot.
 * \retval true - jeśli wczytanie zostało zrealizowane poprawnie,
 * \retval false - w przeciwnym przypadku.
 */
bool ReadFile(const char* sFileName, Scene& Scn)
{
   try {
            XMLPlatformUtils::Initialize();
   }
   catch (const XMLException& toCatch) {
            char* message = XMLString::transcode(toCatch.getMessage());
            cerr << "Error during initialization! :\n";
            cerr << "Exception message is: \n"
                 << message << "\n";
            XMLString::release(&message);
            return 1;
   }

   SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();

   pParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
   pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
   pParser->setFeature(XMLUni::fgXercesDynamic, false);
   pParser->setFeature(XMLUni::fgXercesSchema, true);
   pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

   pParser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

   DefaultHandler* pHandler = new XMLParser4Scene(Scn);
   pParser->setContentHandler(pHandler);
   pParser->setErrorHandler(pHandler);

   try {
     
     if (!pParser->loadGrammar("grammar/opis_sceny.xsd",
                              xercesc::Grammar::SchemaGrammarType,true)) {
       cerr << "!!! Plik grammar/opis_sceny.xsd, '" << endl
            << "!!! ktory zawiera opis gramatyki, nie moze zostac wczytany."
            << endl;
       return false;
     }
     pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse,true);
     pParser->parse(sFileName);
   }
   catch (const XMLException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            cerr << "Informacja o wyjatku: \n"
                 << "   " << sMessage << "\n";
            XMLString::release(&sMessage);
            return false;
   }
   catch (const SAXParseException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

            cerr << "Blad! " << endl
                 << "    Plik:  " << sSystemId << endl
                 << "   Linia: " << Exception.getLineNumber() << endl
                 << " Kolumna: " << Exception.getColumnNumber() << endl
                 << " Informacja: " << sMessage 
                 << endl;

            XMLString::release(&sMessage);
            XMLString::release(&sSystemId);
            return false;
   }
   catch (...) {
            cout << "Zgloszony zostal nieoczekiwany wyjatek!\n" ;
            return false;
   }

   delete pParser;
   delete pHandler;
   return true;
}

int main() {
	int wybor = -1;
	istringstream dane;
	Menu menu;
	Scene scena;
	if (!ReadFile("opis_sceny.xml",scena)) 
		return 1;
  scena.lacze.DodajNazwePliku("sciezka_robota.dat",PzG::RR_Ciagly,1);
  scena.lacze.DodajNazwePliku("pozycja_robota.dat",PzG::RR_Punktowy,3);
	for (unsigned int i = 0; i < scena.obiekty.size(); i++) {
		char nazwa[20] = "punkt";
		char lancuch[15];
		sprintf(lancuch,"%d",i+1);
		strcat(nazwa,lancuch);
		scena.lacze.DodajNazwePliku(nazwa,PzG::RR_Punktowy,1);
	}
	scena.lacze.Inicjalizuj();
	scena.lacze.ZmienTrybRys(PzG::TR_2D);
  scena.lacze.UstawZakresY(-100,2000);
  scena.lacze.UstawZakresX(-100,2000);
	scena.robot->Init();
	ofstream skrypt;
	skrypt.open("plik.cmd");

	Punkt a = scena.obiekty[0];
	Punkt b = scena.obiekty[1];
	Punkt c = scena.obiekty[2];

	skrypt << "Move 500 " << a.x << endl
	<< "Rotate 180 90" << endl
	<< "Move 1000 " << a.y - 100 << endl
	<< "Grasper 1" << endl
	<< "Move 1000 500" << endl
	<< "Grasper 0" << endl
	<< "Rotate 180 180" << endl
	<< "Move 1000 " << a.y + 400 << endl
	<< "Rotate 180 90" << endl
	<< "Move 1000 " << b.x - a.x << endl
	
	<< "Rotate 180 90" << endl
	<< "Move 1000 " << b.y - 100 << endl
	<< "Grasper 1" << endl
	<< "Move 1000 500" << endl
	<< "Rotate 180 180" << endl
	<< "Move 1000 " << b.y + 400 << endl
	<< "Rotate 180 90" << endl
	<< "Move 1000 " << c.x - b.x << endl

	<< "Rotate 180 90" << endl
	<< "Move 1000 " << c.y - 100 << endl
	<< "Grasper 1" << endl
	<< "Rotate 180 180" << endl
	<< "Move 1000 " << c.y - 100 << endl
	<< "Rotate 180 270" << endl
 	<< "Move 1000 " << c.x - b.x << endl

	<< "Rotate 180 270" << endl
	<< "Move 1000 400" << endl
	<< "Grasper 0" << endl
	<< "Rotate 180 180" << endl
	<< "Move 1000 400" << endl
	<< "Rotate 180 270" << endl
	<< "Move 1000 500" << endl
	<< "Rotate 180 270" << endl
	<< "Move 1000 900" << endl
	<< "Grasper 1" << endl
	<< "Rotate 180 180" << endl
	<< "Move 1000 900" << endl
	<< "Rotate 180 90" << endl
	<< "Move 1000 1500" << endl;

	skrypt.close();
	if (!menu.wczytajPlik(dane,"plik.cmd"))
		cout << "Błąd wczytywania pliku." << endl;
	if (!menu.wczytajKomendy(dane))
		cout << "Błąd wczytywania komend." << endl;
	menu.wyswietlKomendy();
	menu.wykonajSekwencje(*(scena.robot));  
cout << "ruch wykonany" << endl;
	scena.lacze.Rysuj();
	cin >> wybor;
	return 0;
}
