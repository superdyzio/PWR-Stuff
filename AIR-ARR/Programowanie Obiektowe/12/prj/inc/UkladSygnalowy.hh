#ifndef UKLADSYGNALOWU_HH
#define UKLADSYGNALOWY_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

/*!
 *\file
 *\brief	Plik zawierający definicję klasy UkladSygnalowy. 
*/

#include "ListaBlokow.hh"
#include "BlokGeneratora.hh"
#include "BlokRejestratora.hh"
#include "BlokOscyloskopu.hh"
#include "BlokPotegujacy.hh"
#include "BlokProstujacy.hh"
#include "BlokPrzesuwajacy.hh"
#include "BlokWzmacniajacy.hh"
#include "BlokDyskryminujacy.hh"
#include "BlokCalkujacy.hh"

class BlokOscyloskopu;
class BlokGeneratora;
class BlokRejestratora;
class BlokPotegujacy;
class BlokProstujacy;
class BlokPrzesuwajacy;
class BlokWzmacniajacy;
class BlokDyskryminujacy;
class BlokCalkujacy;

/*!
 * \brief Modeluje układ przetwarzający sygnał
 *
 * Modeluj układ przetwarzający sygnał. Zakład się,
 * że układ ten składa się z szeregowo połączonych
 * ze sobą pojedynczych bloczków przetwarzających sygnał. 
 */
class UkladSygnalowy: public ListaBlokow {
  public:
   /*!
    * \brief Dodaje blok generatora sygnału
    */
   BlokGeneratora* DodajGenerator( const char* NazwaPlikuSygnalu );

   /*!
    * \brief Dodaje blok rejestratora sygnału
    */
   BlokRejestratora* DodajRejestrator( const char* NazwaPlikuRejestru );

   /*!
    * \brief Dodaje blok rejestratora sygnału
    */
   BlokOscyloskopu* DodajOscyloskop( 
                         double      T_min,
                         double      T_max,
                         double      Syg_min,
			 double      Syg_max,
                         const char* NazwaPliku
                       );

    /*!
     * \brief Dodaje blok potęgujący sygnał.
     */
    BlokPotegujacy* DodajBlokPotegujacy();

    /*!
     * \brief Dodaje blok prostujący sygnał.
     */
    BlokProstujacy* DodajBlokProstujacy();

    /*!
     * \brief Dodaje blok przesuwający sygnał o zadaną wartość.
     * 	Wartość przesunięcia jest podawana jako c-string (char*).
     */
    BlokPrzesuwajacy* DodajBlokPrzesuwajacy(const char* Przesuniecie);

    /*!
     * \brief Dodaje blok przesuwający sygnał o zadaną wartość.
     * Wartość przesunięcia jest podawana jako double.
     */
    BlokPrzesuwajacy* DodajBlokPrzesuwajacy(const double Przesuniecie);

    /*!
     * \brief Dodaje blok wzmacniający sygnał k-krotnie.
     * Wartość wzmocnienia jest podawana jako c-string (char*).
     */
    BlokWzmacniajacy* DodajBlokWzmacniajacy(const char* Wzmocnienie);

    /*!
     * \brief Dodaje blok wzmacniający sygnał k-krotnie.
     * Wartość wzmocnienia jest podawana jako double.
     */
    BlokWzmacniajacy* DodajBlokWzmacniajacy(const double Wzmocnienie);

    /*!
     * \brief Dodaje blok dyskryminujący sygnał.
     * Wartość progu dyskryminacji jest podawana jako c-string (char*).
     */
    BlokDyskryminujacy* DodajBlokDyskryminujacy(const char* Prog);

    /*!
     * \brief Dodaje blok dyskryminujący sygnał.
     * Wartość progu dyskryminacji jest podawana jako double.
     */
    BlokDyskryminujacy* DodajBlokDyskryminujacy(const double Prog);

    /*!
     * \brief Dodaje blok całkujący sygnał.
     */
    BlokCalkujacy* DodajBlokCalkujacy();
};


#endif
