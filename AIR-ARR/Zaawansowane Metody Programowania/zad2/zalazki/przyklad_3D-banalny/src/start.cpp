#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"

using namespace std;


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  char c;

  Lacze.DodajNazwePliku("sciezka_ruchu_robota.dat",PzG::RR_Ciagly,1);
  Lacze.DodajNazwePliku("robot.dat",PzG::RR_Punktowy,3);
  Lacze.DodajNazwePliku("punkt_A.dat",PzG::RR_Punktowy,1);
  Lacze.DodajNazwePliku("punkt_B.dat",PzG::RR_Punktowy,1);
  Lacze.DodajNazwePliku("punkt_C.dat",PzG::RR_Punktowy,1);

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-100, 2000);
  Lacze.UstawZakresY(-1000, 2000);
  Lacze.UstawZakresZ(-100, 2000);


  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian1.dat"
  cout << "Nacisnij ENTER, aby zakonczyc ... " << flush;
  cin >> noskipws >> c;

}
