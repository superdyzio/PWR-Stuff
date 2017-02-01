/* generated by dia/codegen.py */
class Macierz 
{
public:
	Zespolona &operator () (int Wiersz,
	                        int Kolumna);
	Macierz operator * (Macierz Arg1,
	                    Macierz Arg2);
	istream operator >> (istream &StrmWe,
	                     Macierz &M);
	ostream &operator<< (ostream &StrmWy,
	                     Macierz &M);
	Zespolona Tab[4][4];
};

class Wektor 
{
public:
	Zespolona &operator (int Index);
	istream operator >> (istream &StrmWe,
	                     Wektor &W);
	ostream &operator << (ostream &StrmWy,
	                      &Wektor &W);
	Zespolona operator* (Wektor Arg1,
	                     Wektor Arg2);
	Zespolona x;
	Zespolona y;
	Zespolona z;
};

/*klasa definiujaca liczbe zespolona*/
class Zespolona 
{
public:
	Zespolona sprzezenie (Zespolona Arg);
	Zespolona operator + (Zespolona Arg);
	Zespolona operator - (Zespolona Arg);
	Zespolona operator+ (Zespolona Arg1,
	                     Zespolona Arg2);
	Zespolona operator - (Zespolona Arg1,
	                      Zespolona Arg2);
	Zespolona operator * (Zespolona Arg1,
	                      Zespolona Arg2);
	double re;
	double im;
};

/*(NULL)*/
class Uklad_Rownan 
{
public:
	Wektor Roznice (Uklad_Rownan Uklad);
	Wektor Wylicz (Uklad_Rownan Uklad);
	 operator >> (istream &StrWe,
	              Uklad_Rownan &U);
	ostream operator << (ostream StrWy,
	                     Uklad_Rownan U);
	Wektor operator * (Macierz M,
	                   Wektor W);
	Macierz Parametry;
	Wektor Szukane;
	Wektor WyrazyWolne;
};

