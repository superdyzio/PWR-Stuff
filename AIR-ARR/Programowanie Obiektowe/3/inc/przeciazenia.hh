#ifndef PRZECIAZENIA_HH
#define PRZECIAZENIA_HH
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
enum Symbol {e, a, b, c, d};  // deklaracja typu wyliczeniowego

Symbol operator + (Symbol x, Symbol y);  
Symbol operator - (Symbol x, Symbol y);
Symbol operator * (Symbol x, Symbol y);
Symbol operator / (Symbol x, Symbol y);//drugi element musi być różny od e, warunek ten jest sprawdzany w funkcji Odpowiedz(...) modułu test.hh
Symbol operator - (Symbol x);

ostream & operator << (ostream& str, Symbol x);
istream & operator >> (istream& str, Symbol &x);   // przeciążenia operatorów wejścia/wyjścia

#endif
