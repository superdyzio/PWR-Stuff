#include "dzialania.hh"

struct Pytanie {
  char    OperatorDzialania;
  Symbol  WynikDzialania;
};

#define ILOSC_PYTAN   10

Pytanie  ZbiorPytan[ILOSC_PYTAN] = {
             { '+', a }, { '-', c }, { '+', e }, { '-', d }, { '+', b },
             { '-', a }, { '+', c }, { '-', e }, { '+', d }, { '-', b }
          };

