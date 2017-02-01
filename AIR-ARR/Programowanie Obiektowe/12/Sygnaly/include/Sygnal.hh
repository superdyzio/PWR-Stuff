#ifndef SYGNAL_HH
#define SYGNAL_HH
#include <iostream>

using namespace std;

/*!
 * \file 
 * \brief Zawiera definicję klasy Sygnal
 *
 * Zawiera definicję klasy Sygnal. Wiąże ona z sobą wartość
 * sygnału oraz chwilę czasową, której odpowiada dany sygnał.
 * Z tym plikiem nagłówkowym nie jest skojarzony żaden moduł,
 * gdyż metody klasy Sygnal są elementarne i wszystkie
 * zdefiniowane są w ciele definicji klasy.
 */


/*!
 * \brief Modeluje wartość sygnału w powiązaniu z czasem
 *
 * Klasa modeluje wartość sygnału w danej chwili czasowej.
 */
class Sygnal {
   /*!
    * \brief Przechowuje wartość sygnału
    *
    *  Pole zawiera wartość sygnału.
    */
   double  _WartoscSyg;
  /*!
   * \brief Przechowuje czas skojarzony z wartością sygnału
   *
   *  Pole przechowuje czas skojarzony z wartością sygnału.
   *  O interpretacji jednostki czasu decyduje konwencja
   *  przyjęta w danym programie.
   */
   double _Czas;
  public:
   /*!
    * \brief Inicjalizuje wartościami zerowymi
    *
    *  Inicjalizuje wartościami zerowymi zarówno pole
    *  wartości sygnału, jak też pole czasu. 
    */
   Sygnal(): _WartoscSyg(0), _Czas(0) {}
   /*!
    * \brief Udostępnia czas
    *
    *  Udostępnia czas pamiętany w polu \link Sygnal::_Czas _Czas\endlink.
    */ 
   double WezCzas() const { return _Czas; }
   /*!
    * \brief Udostępnia wartość
    *
    *  Udostępnia czas pamiętany w polu 
    *  \link Sygnal::_WartoscSyg _WartoscSyg\endlink.
    */ 
   double WezWartoscSyg() const { return _WartoscSyg; }
   /*!
    * \brief Zmienia wartość czasu
    *  
    * Zmienia wartość czasu.
    * \warning  Czas powinien być zmieniany TYLKO w bloku
    *           generatora sygnału.
    * \param[in] Czas - nowa wartość czas
    */
   void ZmienCzas(double Czas)  { _Czas = Czas; }
   /*!
    * \brief Zmienia wartość sygnału
    *  
    * Zmienia wartość sygnału.
    * \warning  Czas powinien być zmieniany TYLKO w bloku
    *           generatora sygnału.
    *
    * \param[in] WartoscSyg - nowa wartość sygnału
    */
   void ZmienWartoscSyg(double WartoscSyg) { _WartoscSyg = WartoscSyg; }
   /*!
    * \brief Zmienia wartość sygnału i chwili czasowej
    *
    * Zmienia wartość sygnału i powiązanej z nim chwili czasowej.
    * \warning  Czas powinien być zmieniany TYLKO w bloku
    *           generatora sygnału.
    *
    * \param[in] Czas - nowa wartość czas,
    * \param[in] WartoscSyg - nowa wartość sygnału    .

    */
   void ZmienSyg(double Czas, double WartoscSyg)
          {  ZmienCzas(Czas);  ZmienWartoscSyg(WartoscSyg); }
};

/*!
 *  \brief Umożliwia wczytanie czasu i wartości sygnału
 *
 *  Umożliwia wczytanie czasu i wartości sygnału.
 *  Zakłada się, że liczby reprezentujące czas i wartość sygnału
 *  są oddzielone dowolną ilością znaków białych.
 *  \param[in,out] StrmWe - strumień, z którego mają być wczytane
 *                      liczby reprezentujące czas i wartość sygnału.
 *  \param[out] Syg - do tego parametru zapisywane są wczytane
 *                    dane.
 *  \return Zwracana jest referencja do strumienia, na którym
 *          wykonana została operacja wczytania, tzn. \e StrmWe.
 */
std::istream& operator >> (std::istream &StrmWe, Sygnal &Syg);
/*!
 *  \brief Umożliwia zapis czasu i wartości sygnału
 *
 *  Umożliwia zapisanie czasu i wartości sygnału.
 *  W zapisie tym liczby reprezentujące odpowiednio czas i
 *  wartość sygnału oddzielone są pojedynczą spacją.
 *  \param[in,out] StrmWy - strumień, do którego mają być zapisane
 *                      liczby reprezentujące czas i wartość sygnału.
 *  \param[out] Syg - z tego parametru wartości czasu i sygnału
 *                   zapisywane są wczytane do strumienia wyjściowego.
 *
 *  \return Zwracana jest referencja do strumienia, na którym
 *          wykonana została operacja zapisu, tzn. \e StrmWy.
 */
std::ostream& operator << (std::ostream &StrmWy, const Sygnal &Syg);
#endif
