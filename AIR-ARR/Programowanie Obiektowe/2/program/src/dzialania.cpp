#include "dzialania.hh"

Symbol Dodaj(Symbol x, Symbol y) {
	Symbol Tab[5][5] = {
  		{ e, a, b, c, d },
  		{ a, b, c, d, e },
 		{ b, c, d, e, a },
  		{ c, d, e, a, b },
  		{ d, e, a, b, a }
	};
	return Tab[x][y];
}

Symbol Odejmij(Symbol x, Symbol y) {
	Symbol Tab[5][5] = {
		{ e, a, b, c, d },
		{ a, b, c, d, e },
		{ b, c, d, e, a },
		{ c, d, e, a, b },
		{ d, e, a, b, c }
	};
	Symbol Arg = y;
	switch (Arg){
		case e: y = e; break;
		case a: y = d; break;
		case b: y = c; break;
		case c: y = b; break;
		case d: y = a; 
	}
	return Tab[x][y];
}
		 

