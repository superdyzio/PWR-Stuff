#include "symbole.hh"

/*!
 *\file
 *\brief	Plik zawiera implementacje metod z nagłówka 'symbole.hh'.
*/

Symbol operator - (Symbol x) {
	Symbol Tab[ ] = { e, d, c, b, a };
	return Tab[x];
}

Symbol operator + (Symbol x) {
	return x;
}

Symbol operator + (Symbol x, Symbol y) {
	Symbol Tab[5][5] = {
		{ e, a, b, c, d },
		{ a, b, c, d, e },
		{ b, c, d, e, a },
		{ c, d, e, a, b },
	};
	return Tab[x][y];
}

Symbol operator - (Symbol x, Symbol y) {
	y = (-y);
	return x + y;
}

Symbol operator * (Symbol x, Symbol y) {
	Symbol Tab[5][5] = {
		{ e, e, e, e, e },
		{ e, a, b, c, d },
		{ e, b, d, a, c },
		{ e, c, a, d, b },
		{ e, d, c, b, a }
	};
	return Tab[x][y];
}

Symbol operator / (Symbol x, Symbol y) {
	Symbol Tab[ ] = { e, a, c, b, d };
	return x * Tab[y];
}

ostream & operator << (ostream & wyj, Symbol x) {
	wyj << "eabcd"[x];
	return wyj;
}

istream & operator >> (istream & wej, Symbol & x) {
	Symbol Tab[5] = { e, a, b, c, d };
	char znak;
	wej >> znak;
	if (strchr("eabcd",znak)) 
		x = Tab[ (znak-'a'+1) % 5 ];
	else {
		wej.unget(); 
		wej.setstate(ios::failbit); 
	}
	return wej;
}

Symbol Zeruj(Symbol x) {
	x = e;
	return x;
}
