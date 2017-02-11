#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"


using namespace std;



int main() 
{
  char  Opcja;
  PzG::LaczeDoGNUPlota  Lacze;


  Lacze.DodajNazwePliku("sciezka_ruchu_robota.dat",PzG::RR_Ciagly,1);
  Lacze.DodajNazwePliku("robot.dat",PzG::RR_Punktowy,3);
  Lacze.DodajNazwePliku("punkt_A.dat",PzG::RR_Punktowy,1);
  Lacze.DodajNazwePliku("punkt_B.dat",PzG::RR_Punktowy,1);
  Lacze.DodajNazwePliku("punkt_C.dat",PzG::RR_Punktowy,1);

  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresY(-100,2000);
  Lacze.UstawZakresX(-100,2000);
  Lacze.Rysuj(); 
   
  cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
  cin >> noskipws >> Opcja;
}
