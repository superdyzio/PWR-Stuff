#ifndef LISTABLOKOW_HH
#define LISTABLOKOW_HH
#ifdef __GNUG__
# pragma interface
#endif
#include <list>
#include "BlokSygnalowy.hh"


/*!
 * \file
 * \brief Zawiera definicję klasy ListaBlokow
 *
 *  Zawiera definicję klasy ListaBlokow, która pozwala
 *  zautomatyzować proces przetwarzania sygnału.
 */

/*!
 * \brief Modeluje listę bloków sygnałowych
 *
 *  Modeluje listę bloków sygnałowych oraz dostarcza podstawowe
 *  funkcjonalności, które pozwalają na zautomatyzowanie procesu
 *  przetwarzania sygnału.
 */
class ListaBlokow: public std::list<BlokSygnalowy*> {

  public:
  /*!
   * \brief Realizuje przeliczenie sygnału dla całej listy bloków
   */
  bool WyliczSygnal();
  /*!
   * \brief Metoda ta inicjalizuje wszystkie bloki sygnałowe z listy
   *
   *  Metoda wykorzystywana jest do zainicjalizowania wszystkich
   *  wszystkich bloków sygnałowych znajdujących się aktualnie
   *  na liście. Dla każdego z tych bloków wywołuje metodę 
   *  BlokSygnalowy::RozpocznijPrace. Jeśli jeden z nich zwróci
   *  wartość \p false, to inicjalizacja zostaje przerwana,
   *  a metoda zwraca wartość \p false.
   *
   *  \retval true - wszystkie bloki zostały zainicjalizowane poprawnie.
   *  \retval false - w przypadku przeciwnym.
   */
  virtual bool RozpocznijPrace();
  /*!
   * \brief Dodaje nowy blok sygnałowy
   *
   * Dodaje nowy blok sygnałowy.
   * \param[in] wBlok - wskaźnik na nowy blok. Musi on być wskazywać
   *                    na obiekt. Nie może to być wskaźnik NULL. 
   */
   void DodajBlokSygnalowy( BlokSygnalowy* wBlok) { push_back(wBlok); }
  /*!
   * \brief Wyświetla typy bloków
   *
   * Wyświetla nazwy typów bloków w liście
   */
   virtual void WyswietlTypBlokowWLiscie() const;

  /*!
   * \brief Wyświetla typy bloków
   *
   * Wyświetla nazwy typów bloków w liście
   */
   virtual void WyswietlOpis() const;

  /*!
   * \brief Usuwa dynamicznie stworzone elementy listy
   */
   virtual ~ListaBlokow();

  /*!
   * \brief Kończy pracę wszystkich bloków
   */
  void ZakonczPrace();
 private:
};

#endif
