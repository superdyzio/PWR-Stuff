#include "przeciazenia.hh"

Symbol Dodaj[5][5] = {	{e, a, b, c, d},
			{a, b, c, d, e},
		     	{b, c, d, e, a},
			{c, d, e, a, b},
			{d, e, a, b, c}
};

Symbol Pomnoz[5][5] = {	{e, e, e, e, e},
			{e, a, b, c, d},
			{e, b, d, a, c},
			{e, c, a, d, b},
			{e, d, c, b, a}
};

Symbol operator - (Symbol x){
	Symbol Tab[] = {e, d, c, b, a};
	return Tab[x];
}

//Przeciazenia operatorow matematycznych

Symbol operator + (Symbol x, Symbol y){
  return Dodaj[x][y];
}

Symbol operator * (Symbol x, Symbol y){
  return Pomnoz[x][y];
}

Symbol operator - (Symbol x, Symbol y){
  return Dodaj[x][-y];
}

Symbol operator / (Symbol x, Symbol y){
	Symbol Tab[] = {e, a, c, b, d}; 
	return Pomnoz[x][Tab[y]];
}

//Przeciazenia operatorow wejscia / wyjscia

ostream & operator << (ostream& wy, Symbol x){
  return wy << ("eabcd"[x]);
}

istream & operator >> (istream& we, Symbol &sym){
  Symbol Tab[] = {a,b,c,d,e};
  char znak;
  we >> znak;
  if ( strchr("eabcd",znak) ) {sym = Tab[znak-'a'];}
  else { we.unget(); we.setstate(ios::failbit); }
  return we;
}
