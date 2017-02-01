/* generated by dia/codegen.py */
class Macierz 
{
public:
	ostream operator << (ostream wy,
	                     Macierz m);
	istream operator >> (istream we,
	                     Macierz m);
	Zespolona operator () (int wiersz,
	                       int kolumna);
	Zespolona Tab[3][3];
};

class Wektor 
{
public:
	ostream operator << (ostream wy,
	                     Wektor w);
	istream operator >> (istream wy,
	                     Wektor w);
	Zespolona operator [] (int ind);
	Zespolona u;
	Zespolona i;
	Zespolona o;
	Zespolona p;
};

class Zespolona 
{
public:
	Zespolona operator + (Zespolona x);
	Zespolona operator + (Zespolona x,
	                      Zespolona y);
	Zespolona operator * (Zespolona x,
	                      Zespolona y);
	ostream operator << (ostream wy,
	                     Zespolona x);
	istream operator >> (istream we,
	                     Zespolona x);
	float Re;
	float Im;
};

class UkladRownan 
{
public:
	void wypisz ();
	Wektor wylicz ();
	void wczytaj ();
	Zespolona operator * (Wektor a,
	                      Wektor b);
	Wektor operator * (Macierz m,
	                   Wektor w);
	Macierz operator * (Macierz a,
	                    Macierz b);
	Macierz MacierzWspolczynnikow;
	Wektor WektorWyrazowWolnych;
	Wektor WektorNieznanychWartosci;
	Wektor blad;
};

