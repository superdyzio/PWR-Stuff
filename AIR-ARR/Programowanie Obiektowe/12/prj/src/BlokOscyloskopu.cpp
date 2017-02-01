#ifdef __GNUG__
# pragma implementation
#endif

#include <iostream>
#include "BlokOscyloskopu.hh"
#include "lacze_do_gnuplota.hh"

/*!
 *\file
 *\brief	Plik zawierający implementację wybranych metod klasy BlokOscyloskopu.
*/

using namespace std;

BlokOscyloskopu::~BlokOscyloskopu() 
{
  if (_NazwaPlikuZapisuSygnalu.empty()) return;
  remove(_NazwaPlikuZapisuSygnalu.c_str());
}

/*!
 * Inicjalizuje pracę oscyloskopu sygnału poprzez otwarcie
 * pliku, do którego będą zapisywane kolejne wartości sygnału.
 * \retval true - jeśli operacja zakończyła się powodzeniem,
 * \retval false - w przypadku przeciwnym.
 */
bool BlokOscyloskopu::RozpocznijPrace()
{
  remove(_NazwaPlikuZapisuSygnalu.c_str());
  _GNUPlot.DodajNazwePliku(_NazwaPlikuZapisuSygnalu.c_str());
  _GNUPlot.UstawZakresX(_T_min,_T_max);
  _GNUPlot.UstawZakresY(_Syg_min,_Syg_max);
  _GNUPlot.Inicjalizuj();
  if (!_TytulOkienkaOscyloskopu.empty()) {
    string  NazwaOkienka = "Oscyloskop: ";
    NazwaOkienka += _TytulOkienkaOscyloskopu; 
    _GNUPlot.UstawTytulOkna(_TytulOkienkaOscyloskopu.c_str());
  }
  return true;
}


bool BlokOscyloskopu::WyliczSygnalWyj(const Sygnal& Syg)
{ cout << 1;
  ZmienSygnalWyj(Syg);
  ofstream  StrmOscyloskopu;
  cout << 2;
  StrmOscyloskopu.open(_NazwaPlikuZapisuSygnalu.c_str(),ios::app);
  if (StrmOscyloskopu.fail()) return false;
cout << 3;
  StrmOscyloskopu << Syg << endl;
  if (StrmOscyloskopu.fail()) return false;
 cout << 4;  
  StrmOscyloskopu.close();
 cout << 5;
  if (StrmOscyloskopu.fail()) return false;
 cout << 6;
  _GNUPlot.Rysuj();
cout << 7 << endl;
  return true;
}
