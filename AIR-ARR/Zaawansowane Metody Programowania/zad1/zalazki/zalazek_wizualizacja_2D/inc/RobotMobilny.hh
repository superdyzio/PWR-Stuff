#ifndef ROBOTMOBILNY_HH
#define ROBOTMOBILNY_HH

#pragma interface

/*!
 * \file
 * \brief Definicja klasy RobotPose
 *
 * Plik zawiera definicję klasy RobotPose
 */

#include "robotpose.hh"
#include "lacze_do_gnuplota.hh"
#include <fstream>

/*!
 * \brief Modeluje zestaw informacji określający pozę robota
 *
 *  Klasa modeluje ...
 */
class RobotMobilny: public RobotPose {
   
  public:
  /*!
   * \brief
   */
   RobotMobilny(PzG::LaczeDoGNUPlota *pPlotter);
 
  /*!
   * \brief Inicjalizuje struktury robota
   */
   bool Init();

  /*!
   * \brief Resetuje pozycję robot i kasuje jego ścieżkę
   */
   bool Reset();
   /*!
    * \brief Współrzędne robota zapisane zostają do pliku
    */
   bool WriteCoord();
   /*!
    *  Metoda wywoływana jest po aktualizacji położenia i orientacji
    *  lub samego położenia.
    *  \retval true - gdy operacja powiodła się,
    *  \retval false - w przypadku przeciwnym.
    */
   virtual bool AfterUpdate();

  private:
   /*!
    * \brief
    */
    PzG::LaczeDoGNUPlota  *_pPlotter;
   /*!
    * \brief W strumieniu zapisywana są kolejne współrzędne robota
    */
    std::ofstream   _Strm4Path;
};


#endif
