#ifdef __GNUG__
# pragma implementation
#endif
#include "ListaBlokow.hh"
#include <iostream>

using namespace std;

/*!
 * Usuwa dynamicznie stworzone elementy listy
 */
ListaBlokow::~ListaBlokow()
{
  ZakonczPrace();
  for (iterator Iter = begin(); Iter != end(); ++Iter) {
    delete *Iter;
  } 
}


bool ListaBlokow::RozpocznijPrace()
{
   for (iterator Iter = begin(); Iter != end(); ++Iter) { 
     if (!(*Iter)->RozpocznijPrace()) return false;
   }
   return true;
}


/*!
 *
 */
void ListaBlokow::WyswietlTypBlokowWLiscie() const
{
   for (const_iterator Iter = begin(); Iter != end(); ++Iter) { 
     cout << (*Iter)->NazwaBloku() << endl;
   }
}


/*!
 *
 */
void ListaBlokow::WyswietlOpis() const
{
   for (const_iterator Iter = begin(); Iter != end(); ++Iter) { 
     cout << (*Iter)->OpisBloku() << endl;
   }
}


/*!
 * Realizuje pojedynczy krok propagacji sygnału.
 *
 * \retval true - jeśli któryś blok zgłosił chęć zakończenia pracy lub
 *                jeśli megoda 
 *                \link BlokSygnalowy::WyliczSygnalWyj WyliczSygnalWyj\endlink
 *               lub też
 *                \link BlokSygnalowy::WyliczSygnalWyj WyliczSygnalWyj\endlink
 *                zwróci \p false.
 * \retval false - w przypadku przeciwnym.
 */
bool ListaBlokow::WyliczSygnal()
{
  Sygnal   SygWe, SygWy;
  iterator Iter = begin();

   for (; Iter != end(); ++Iter) { 
     if ((*Iter)->CzyZakonczycPrace()) break;
     if (!(*Iter)->WyliczSygnalWej(SygWe,SygWy)) break;
     if (!(*Iter)->WyliczSygnalWyj(SygWy)) break;
     SygWe = (*Iter)->WezSygnalWyj(); 
   }
   if (Iter == end()) return false;
   ZakonczPrace();
   return true;
}


/*!
 *  Kończy pracę wszystkich bloków wywołując dla każdego
 *  z nich metodę BlokSygnalowy::ZakonczPrace.\n
 *
 *  Oprócz tego niniejsza metoda wywoływana jest także 
 *  w destruktorze całej listy.
 */
void ListaBlokow::ZakonczPrace()
{
   for (iterator Iter = begin(); Iter != end(); ++Iter) { 
     (*Iter)->ZakonczPrace();
   }
}
