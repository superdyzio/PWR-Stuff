#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <fstream>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"

using namespace std;

/*!
 *
 */
#define PLIK__SCIEZKA_ROBOTA "scena/sciezka_ruchu_robota.dat"
/*!
 *
 */
#define PLIK__WZORZEC_KORPUS_ROBOTA        "wzorce/wzorzec-korpus_robota.data"
/*!
 *
 */
#define PLIK__WZORZEC_LEWY_PALEC_CHWYTAKA  "wzorce/wzorzec-lewy_palec_chwytaka"
/*!
 *
 */
#define PLIK__WZORZEC_PRAWY_PALEC_CHWYTAKA "wzorce/wzorzec-prawy_palec_chwytaka"

/*!
 *
 */
#define PLIK__ROBOTA_KORPUS  "scena/robot-korpus.dat"
/*!
 *
 */
#define PLIK__ROBOTA_LEWY_PALEC_CHWYTAKA   "scena/robot-lewy_palec_chwytaka.dat"
/*!
 *
 */
#define PLIK__ROBOTA_PRAWY_PALEC_CHWYTAKA  "scena/robot-prawy_palec_chwytaka.dat"
/*!
 *
 */
#define KROK_ANIMACJI           10
/*!
 *
 */
#define PAUZA_ANIMACJI_us       100000


/*!
 *
 */
class Wektor3D {
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
   double   z;
  /*!
   *
   */
  Wektor3D(): x(), y(), z() {}
  /*!
   *
   */
   Wektor3D& operator += (const Wektor3D& W) 
    {  x += W.x;  y += W.y;  z += W.z; return *this; }
  /*!
   *
   */
   Wektor3D& operator *= (double Num) 
     {  x *= Num;  y *= Num;  z += Num;  return *this; }
  /*!
   *
   */
   double Dlugosc() const { return sqrt(x*x + y*y + z*z); }
};


/*!
 *
 */
istream& operator >> (istream  &IStrm, Wektor3D  &W)
{
  return IStrm >> W.x >> W.y >> W.z;
}

/*!
 *
 */
ostream& operator << (ostream  &OStrm, const Wektor3D  &W)
{
  return OStrm << W.x << " " << W.y << " " << W.z;
}








/*!
 * Przykładowa funkcja przesuwająca pojedynczą bryłę. 
 *
 * \param[in] Trans -  wektor translacji, o który należy przesunąć
 *                     daną bryłę.
 * \param[in] sNazwaPliku_BrylaWzorcowa - nazwa pliku zawierającego współrzędne
 *                      wierzchołków, które są wyrażone w lokalnym układzie
 *                      współrzędnych danej bryły. Z tego pliku są wczytywane
 *                      współrzędne poszczególnych wierzchołków. Traktowane są one
 *                      jako dane wejściowe.
 *
 * \param[in] sNazwaPliku_BrylaWynikowa - nazwa pliku, do którego zapisywane są
 *                      przetransformowane współrzędne wierzchołków bryły.
 *                      Plik ten jest wykorzystywany przez gnuplota do rysowania
 *                      bryły w układzie współrzędnych globalnych.
 * 
 */
void PrzesunBryle( const Wektor3D   &Trans,
                   const char       *sNazwaPliku_BrylaWzorcowa,
                   const char       *sNazwaPliku_BrylaWynikowa
                 )
{
  ifstream  StrmWe(sNazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(sNazwaPliku_BrylaWynikowa);
  Wektor3D  PunktObrysu;

  do {
    if (StrmWe >> PunktObrysu) {
      PunktObrysu += Trans;
      StrmWy << PunktObrysu << endl;
      continue;
    }
    StrmWe.clear();
    StrmWe.ignore(numeric_limits<int>::max(),'\n');  // Przeskakuje linie
    StrmWy << endl;  // Dodaje przejscie do nowej linii,
                     // aby rozdzielic sekcje elementu powierzchni.
  } while (!StrmWe.eof());
}


/*!
 * Przesuwa wszystkie bryły wchodzące w skład robota.
 * \param[in] Trans - wektor translacji, o który należy przesunąć całego
 *                    robota.
 */
void PrzesunRobota( const Wektor3D  &Trans )
{
  PrzesunBryle(Trans,PLIK__WZORZEC_KORPUS_ROBOTA,
	             PLIK__ROBOTA_KORPUS);

  PrzesunBryle(Trans,PLIK__WZORZEC_LEWY_PALEC_CHWYTAKA,
                     PLIK__ROBOTA_LEWY_PALEC_CHWYTAKA);

  PrzesunBryle(Trans,PLIK__WZORZEC_PRAWY_PALEC_CHWYTAKA,
                     PLIK__ROBOTA_PRAWY_PALEC_CHWYTAKA);
}



/*
 *  To jest bardzo prymitywna funkcja, ktora zapisuje do pliku
 *  tylko ostatni odcinek ruchu robota. Dane zawarte w pliku
 *  sa podstawa dla gnuplota, aby narysowac odcinek wizualizujacy
 *  sciezke ruchu robota.
 */
void ZapiszSciezkeRuchuRobota( const Wektor3D  &Poczatek,
                               const Wektor3D  &Koniec
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
                                              Wektor3D             &PozRobota,
                                              Wektor3D             &Trans
                                             )

{
  double    Dlugosc        = Trans.Dlugosc();
  Wektor3D  PojedynczyKrok = Trans;
  Wektor3D  PozPoczatkowa  = PozRobota;
  Wektor3D  PozKoncowa     = PozRobota;
  
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
  PzG::LaczeDoGNUPlota  Lacze;
  char                  Znak;
  Wektor3D              Trans;
  Wektor3D              PozRobota;

  Lacze.DodajNazwePliku(PLIK__ROBOTA_KORPUS);
  Lacze.DodajNazwePliku(PLIK__ROBOTA_LEWY_PALEC_CHWYTAKA );
  Lacze.DodajNazwePliku(PLIK__ROBOTA_PRAWY_PALEC_CHWYTAKA);

  Lacze.DodajNazwePliku(PLIK__SCIEZKA_ROBOTA,PzG::RR_Ciagly,1);
  Lacze.DodajNazwePliku("scena/punkt_A.dat",PzG::RR_Punktowy,1);
  Lacze.DodajNazwePliku("scena/punkt_B.dat",PzG::RR_Punktowy,1);
  Lacze.DodajNazwePliku("scena/punkt_C.dat",PzG::RR_Punktowy,1);

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-100, 2000);
  Lacze.UstawZakresY(-1000, 2000);
  Lacze.UstawZakresZ(-100, 2000);

  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok


  PozRobota.x = 50;  PozRobota.y = 100;  PozRobota.z = 0;

  PrzesunRobota(PozRobota);
  ZapiszSciezkeRuchuRobota(PozRobota,PozRobota);

  Lacze.Rysuj();
   
  cout << "Nacisnij ENTER  aby rozpoczac ..." << flush;
  cin >> noskipws >> Znak;

  Trans.x = 1000;  Trans.y = 0;  Trans.z = 0;
  BardzoBardzoAleBardzoProstaAnimacjaRuchu(Lacze,PozRobota,Trans);

  cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
  cin >> noskipws >> Znak;
}
