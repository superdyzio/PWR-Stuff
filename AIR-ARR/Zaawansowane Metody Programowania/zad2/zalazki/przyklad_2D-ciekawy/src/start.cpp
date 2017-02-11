#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cmath>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"

/*!
 *
 */
#define PLIK__SCIEZKA_ROBOTA "sciezka_ruchu_robota.dat"
/*!
 *
 */
#define PLIK__WZORZEC_OBRYSU  "obrys_robota.dat"
/*!
 *
 */
#define PLIK__OBRYS_ROBOTA     "robot.dat"
/*!
 *
 */
#define KROK_ANIMACJI           10
/*!
 *
 */
#define PAUZA_ANIMACJI_us       100000

using namespace std;

/*!
 *
 */
class Wektor2D {
 public:
  /*!
   *
   */
   double   x;
  /*!
   *
   */
   double   y;
  /*!
   *
   */
   Wektor2D(): x(), y() {}
  /*!
   *
   */
   Wektor2D& operator += (const Wektor2D& W) 
       {  x += W.x;  y += W.y;  return *this; }
  /*!
   *
   */
   Wektor2D& operator *= (double Num) 
       {  x *= Num;  y *= Num;  return *this; }
  /*!
   *
   */
  double Dlugosc() const { return sqrt(x*x + y*y); }
};


/*!
 *
 */
istream& operator >> (istream  &IStrm, Wektor2D  &W)
{
  return IStrm >> W.x >> W.y;
}

/*!
 *
 */
ostream& operator << (ostream  &OStrm, const Wektor2D  &W)
{
  return OStrm << W.x << " " << W.y;
}


/*!
 * Przykładowa funkcja przesuwająca robota o 
 * zadany wektor.
 */
void PrzesunRobota( const Wektor2D&  Trans )
{
  ifstream  StrmWe(PLIK__WZORZEC_OBRYSU);
  ofstream  StrmWy(PLIK__OBRYS_ROBOTA);
  Wektor2D  PunktObrysu;

  do {
    if (StrmWe >> PunktObrysu) {
      PunktObrysu += Trans;
      StrmWy << PunktObrysu << endl;
      continue;
    }
    StrmWe.clear();
    StrmWe.ignore(numeric_limits<int>::max(),'\n');  // Przeskakuje linie
  } while (!StrmWe.eof());
}


/*
 *  To jest bardzo prymitywna funkcja, ktora zapisuje do pliku
 *  tylko ostatni odcinek ruchu robota. Dane zawarte w pliku
 *  sa podstawa dla gnuplota, aby narysowac odcinek wizualizujacy
 *  sciezke ruchu robota.
 */
void ZapiszSciezkeRuchuRobota( const Wektor2D  &Poczatek,
                               const Wektor2D  &Koniec
                             )
{
  ofstream  StrmWy(PLIK__SCIEZKA_ROBOTA);
  StrmWy << Poczatek << endl;
  StrmWy << Koniec << endl;
}

/*!
 * Uwaga: Zamiast PozRobota powinien byc obiekt klasy wektor zawierajacy 
 * posture robota.
 *
 */
void BardzoBardzoAleBardzoProstaAnimacjaRuchu(PzG::LaczeDoGNUPlota &Lacze,
                                              Wektor2D             &PozRobota,
                                              Wektor2D             &Trans
                                             )

{
  double    Dlugosc        = Trans.Dlugosc();
  Wektor2D  PojedynczyKrok = Trans;
  Wektor2D  PozPoczatkowa  = PozRobota;
  Wektor2D  PozKoncowa     = PozRobota;
  
  PojedynczyKrok *= KROK_ANIMACJI/Dlugosc;
  PozKoncowa += Trans;

  usleep(PAUZA_ANIMACJI_us);
  while ((Dlugosc -= KROK_ANIMACJI) > 0) {
    PozRobota += PojedynczyKrok; 
    PrzesunRobota(PozRobota);
    ZapiszSciezkeRuchuRobota(PozPoczatkowa,PozRobota);
    Lacze.Rysuj();
    usleep(PAUZA_ANIMACJI_us);
  }
  PozRobota = PozKoncowa;
  PrzesunRobota(PozRobota);
  ZapiszSciezkeRuchuRobota(PozPoczatkowa,PozRobota);
  Lacze.Rysuj();
  usleep(PAUZA_ANIMACJI_us);  
}



int main() 
{
  char  Opcja;
  PzG::LaczeDoGNUPlota  Lacze;
  Wektor2D              Trans;
  Wektor2D              PozRobota;

  Trans.x = 1000;  Trans.y = 0;

  Lacze.DodajNazwePliku(PLIK__SCIEZKA_ROBOTA,PzG::RR_Ciagly,1);
  Lacze.DodajNazwePliku("robot.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("punkt_A.dat",PzG::RR_Punktowy,1);
  Lacze.DodajNazwePliku("punkt_B.dat",PzG::RR_Punktowy,1);
  Lacze.DodajNazwePliku("punkt_C.dat",PzG::RR_Punktowy,1);

  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresY(-100,2000);
  Lacze.UstawZakresX(-100,2000);

  PozRobota.x = 50;  PozRobota.y = 100;

  PrzesunRobota(PozRobota);
  ZapiszSciezkeRuchuRobota(PozRobota,PozRobota);

  Lacze.Rysuj(); 

   
  cout << "Nacisnij ENTER  aby rozpoczac ..." << flush;
  cin >> noskipws >> Opcja;


  BardzoBardzoAleBardzoProstaAnimacjaRuchu(Lacze,PozRobota,Trans);
   
  cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
  cin >> noskipws >> Opcja;
}
