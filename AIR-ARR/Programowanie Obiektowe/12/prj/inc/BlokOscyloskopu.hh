#ifndef BLOKOSCYLOSKOPU_HH
#define BLOKOSCYLOSKOPU_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

/*! 
 *\file
 *\brief	Plik zawierający definicję klasy Bloku Oscyloskopu.
*/

#include <fstream>
#include <string>
#include "BlokSygnalowy.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \brief Modeluje klasę wizualizacji sygnału
 *
 * Klasa modeluje wizualizator przebiegu sygnału.
 * Do wizualizacji sygnału wykorzystany jest program
 * gnuplot. Rysuje on postaci wykresu czasowego
 * przebieg działania sygnału.
 */
class BlokOscyloskopu: public BlokSygnalowy {
  public:
   /* !
    * \brief Inicjalizuje pustym napisem pole nazwy pliku
    *
    *  Inicjalizuje pustym napisem pole nazwy pliku, do którego
    *  mają być zapisane kolejne wartości sygnału.
    */
   // BlokOscyloskopu() {}
   /*!
    * \brief Inicjalizuje nazwę pliku
    *
    * Inicjalizuje nazwę pliku roboczego, do którego
    *  mają być zapisane kolejne wartości sygnału.
    *
    * \param[in] T_min - lewostronne ograniczenie zakresu czasowego,
    *                    w którym ma być wizualizowany sygnał.
    * \param[in] T_max - prawostronne ograniczenie zakresu czasowego,
    *                    w którym ma być wizualizowany sygnał.
    * \param[in] Syg_min - lewostronne ograniczenie zakresu czasowego,
    *                    w którym ma być wizualizowany sygnał.
    * \param[in] Syg_max - prawostronne ograniczenie zakresu czasowego,
    *                    w którym ma być wizualizowany sygnał.
    * \param[in] sNazwaPlikuZapisuSygnalu - nazwa pliku, w którym zapisane
    *                  są kolejne wartości sygnału obserwowanego
    *                  sygnału. Na podstawie zawartości tego pliku
    *                  rysowany jest odpowiedni wykres.
    */
   BlokOscyloskopu(         float     T_min,
                            float     T_max,
                            float     Syg_min,
                            float     Syg_max,
                       const char*     sNazwaPlikuZapisuSygnalu
                  ): _NazwaPlikuZapisuSygnalu(sNazwaPlikuZapisuSygnalu) 
      {
	ZmienZakresCzasu(T_min,T_max);
        ZmienZakresSyg(Syg_min,Syg_max);
      }
   /*!
    * \brief Usuwa plik tymczasowy
    */
   ~BlokOscyloskopu();
   /*!
    * \brief Umożliwia zmianę tytuły okienka
    *
    * Umożliwia zmianę tytule okienka.
    * \param[in] sTytul - nowy tytuł okienka. Wartością parametru nie może
    *                     wskaźnik NULL.
    */
   void ZmienTytulOkienka( const char *sTytul )
                    { _TytulOkienkaOscyloskopu = sTytul; }
   /*!
    * \brief Udostępnia nazwę typu bloku
    *
    *  Udostępnia nazwę typu bloku. Jest to napis 
    *  "Blok Oscyloskopu".
    */
    virtual const char* NazwaBloku() const { return "Blok Oscyloskopu"; }
   /*!
    * \brief Inicjalizuje pracę bloku
    */
    virtual bool RozpocznijPrace();
  /*!
   * \brief Zapisuje koleją wartość do pliku
   *
   *  Zapisuje kolejną wartość sygnału do pliku i zapamiętują ją
   *  jako wartość wyjściową bloku.
   *
   *  \param[in] Syg - wartość tego parametru w ogóle nie jest 
   *                   brana pod uwagę.
   */
  virtual bool WyliczSygnalWyj(const Sygnal& Syg);

  /*!
   * \brief Zmienia zakres czasu, w którym ma być wizualizowany sygnał
   *
   * Zmienia zakres czasu, w którym ma być wizualizowany sygnał.
   * \param[in] T_min - lewostronne ograniczenie zakresu czasowego,
   *                    w którym ma być wizualizowany sygnał.
   * \param[in] T_max - prawostronne ograniczenie zakresu czasowego,
   *                    w którym ma być wizualizowany sygnał.
   */
  void ZmienZakresCzasu( float T_min, float T_max )
      {  _T_min = T_min;  _T_max = T_max; }

  /*!
   * \brief Zmienia zakres czasu, w którym ma być wizualizowany sygnał
   *
   * Zmienia zakres wartości sygnału, w przedziale którym ma być 
   * rysowany dany sygnał.
   * \param[in] Syg_min - lewostronne ograniczenie zakresu czasowego,
   *                    w którym ma być wizualizowany sygnał.
   * \param[in] Syg_max - prawostronne ograniczenie zakresu czasowego,
   *                    w którym ma być wizualizowany sygnał.
   */
  void ZmienZakresSyg( float Syg_min, float Syg_max )
      {  _Syg_min = Syg_min;  _Syg_max = Syg_max; }

 private:
   /*!
    * \brief Przechowuje nazwę pliku 
    *
    * W polu przechowuje się nazwę pliku, w którym mają być
    * zapisane kolejne wartości sygnału.
    */
    std::string  _NazwaPlikuZapisuSygnalu;
   /*!
    * \brief Minimalna wartość sygnału, od której wizualizowany jest sygnał
    *
    * Przechowuje minimalną wartość sygnału, od której
    * wizualizowany jest sygnał
    */
   float   _Syg_min;
   /*!
    * \brief Maksymalna wartość sygnału, do której wizualizowany jest sygnał
    *
    * Przechowuje maksymalną wartość sygnału, do której
    * wizualizowany jest sygnał
    */
   float   _Syg_max;
   /*!
    * \brief Chwila czasowa, od której ma być rysowany przebieg sygnału
    *
    *  Pole przechowuje wartość czasu określającą chwilę czasową, od
    *  której rysowany ma być przebieg sygnału.
    */
   float   _T_min;
   /*!
    * \brief Chwila czasowa, do której ma być rysowany przebieg sygnału
    *
    *  Pole przechowuje wartość czasu określającą chwilę czasową, do
    *  której rysowany ma być przebieg sygnału.
    */
   float   _T_max;
   /*!
    * \brief Organizuje komunikację z programem gnuplot
    *
    * Umożliwia uruchomienie programu gnuplot i nawiązanie z nim
    * komunikacji. To z kolei pozwala przesłać do tego programu
    * polecenia umożliwiające odpowiednie rysowanie wykresu.
    */
   PzG::LaczeDoGNUPlota    _GNUPlot;
   /*!
    * \brief Przechowuje tytuł okienka rysowanego wykresu
    *
    * Przechowuje tytuł okienka rysowanego wykresu.
    * Tytuł ten będzie zawsze poprzedzony przedrostkiem "Oscyloskop: ".
    */
   std::string    _TytulOkienkaOscyloskopu;
};

#endif
