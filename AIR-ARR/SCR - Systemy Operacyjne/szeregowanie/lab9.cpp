#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;



//co to jest ile na procku - ile ju� si� wkonywa�
// procesor jest tablic� 10 elementow� zada�
// czy czas to kwant czasu


class Zadanie
{
public:
	int przybycie, trwanie, id, priorytet, pozostalo;
	bool wykonuje_sie, zakonczone;
	int ile_na_procku;

	Zadanie(int t, int i, int p, int r)
	{
		this->przybycie = t;
		this->id = i;
		this->priorytet = p;
		this->trwanie = r;
		this->pozostalo = r;
		this->wykonuje_sie = false;
		this->zakonczone = false;
		this->ile_na_procku = 0;
	}
};


vector<Zadanie*> zadania;	//wektor zada� 
Zadanie* procesor[10];		//procesor jest tablic� zada� z ilo�ci� kom�rek r�wn� ilo�ci rdzeni
int czas_wywlaszczenia = 2; //kwant czasu dla procesu
int ilosc_rdzeni = 1;		//ilo�� rdzeni
int czas = 1; 				//czas wykonywania programu
int algorytm = 6;			//algorytm wykorzystywany przez planer

/*
0fcfs bez        OK
1sjf bez         OK
2SRTF z          OK
3 Round Robin  z - jest problem z wyw�aszczeniem bo nie przerzuca pomi�dzy procesami tylko leci jak lecia� 
4 prirytetowe FCFS wyw�aszaczenie
5.priorytetowe SRTF wyw�aszaczenie
6. proprytetowe bez wyw�aszecznia SRTF  OK

czyta z pliku procesy 
zapisuje do wektora 
procesor[ilo�� rdzeni]
*/


void WczytajZadaniaIncjalizujProcesor()
{
	ifstream in;
	in.open("zadaniaWitold.txt");
	if(!in.is_open()) {cout << "Bledna nazwa pliku z zadaniami\n"; exit(-1);}
	int t, i, pi, ri;
	while(1)
	{
		in >> t; 
		while(!(in.peek() == '\r' || in.peek() == '\n' || in.peek() == EOF))
		{
			in >> i;
			in >> pi;
			in >> ri;
			Zadanie* z = new Zadanie(t,i,pi,ri);
			zadania.push_back(z);
		}
		if(in.peek() == EOF) break;
	}
	in.close();
	for(int i = 0; i < ilosc_rdzeni; i++)
		procesor[i] = NULL;
}

/*
tmp zadania
0  1                                   tego wy�szy
bool CzyWyzszyPriorytet(const tmp, const Zadania) je�eli ok to zamienia
{
	if(rozne priorytet) 
		return zadanie.priorytet > tmp.priorytet;
	else 
		return  zadanie.przybycie < tmp.przybycie;
}
*/
//znajdz pierwszy znajduje pierwszy niewykonujacy sie proces
//i dodaje go 
Zadanie* ZnajdzPierwszy(bool (*fun) (const Zadanie& p1, const Zadanie& p2))
{
	Zadanie* tmp = NULL;
	for(int i = 0; i < zadania.size(); i++)
	{
		if(!zadania[i]->zakonczone && zadania[i]->przybycie <= czas && !zadania[i]->wykonuje_sie)
		{
			if(tmp == NULL) tmp = zadania[i];
			else
			{
				if(fun(*tmp,*zadania[i]))
					tmp = zadania[i];
			}
		}
	}
	return tmp;
}

void UstawProcesy(bool (*fun) (const Zadanie& p1, const Zadanie& p2))
{
	for(int i = 0; i < ilosc_rdzeni; i++)
	{
		if(procesor[i] == NULL)
		{
			Zadanie* z = ZnajdzPierwszy(fun);
			if(z != NULL)
			{
				procesor[i] = z;
				z->wykonuje_sie = true;
				z->ile_na_procku = 0;
			}
		}
	}
}

void Wywlaszcz()
{
	for(int i = 0; i < ilosc_rdzeni; i++)
	{
		if(procesor[i] != NULL)
		{
			if(procesor[i]->ile_na_procku >= czas_wywlaszczenia)
			{
				Zadanie* z = procesor[i];
				procesor[i] = NULL;
				z->wykonuje_sie = false;
				cout<<"\nWywlaszcz\n";
			}
		}
	}
}


////////////////////////////////////////////////////////////////
// NAPISAC RR
////////////////////////////////////////////////////////////////
bool CzyWykonalPrzydzial(const Zadanie& p1, const Zadanie& p2)
{
	return p2.trwanie < p1.trwanie;
}

bool CzyKrotszy(const Zadanie& p1, const Zadanie& p2)
{
	return p2.trwanie < p1.trwanie;
}

bool CzyMniejZostalo(const Zadanie& p1, const Zadanie& p2)
{
	return p2.pozostalo < p1.pozostalo;
}

bool CzyWczesniejszy(const Zadanie& p1, const Zadanie& p2)
{
	return p2.przybycie < p1.przybycie;
}


bool CzyWyzszyPriorytet(const Zadanie& p1, const Zadanie& p2) //realizuje od razu FCFS
{
	if(p1.priorytet != p2.priorytet) 
		return p2.priorytet < p1.priorytet;// by�o > wi�c na odwr�t
	else 
		return  p2.przybycie < p1.przybycie; 
}



int main()
{
	bool koniec=false;

	WczytajZadaniaIncjalizujProcesor();
	while(1)
	{
		switch(algorytm)
		{
			case 0: //fcfs 										OK
				UstawProcesy(CzyWczesniejszy);
			break;
		
			case 1://sjf 										OK
				UstawProcesy(CzyKrotszy);
			break;

			case 2://srtf z 									OK
				Wywlaszcz();
				UstawProcesy(CzyMniejZostalo);
			break;

			case 3:// RR z NIE MA
				Wywlaszcz();
				UstawProcesy(CzyWykonalPrzydzial);
			break;

			case 4: //priorytet te same fcfs z 
				Wywlaszcz();
				UstawProcesy(CzyWczesniejszy);
			break;
			
			case 5://priorytet te same srtf z
				Wywlaszcz();
				UstawProcesy(CzyMniejZostalo);
			break;

			case 6://priorytet te same FCFS BEZ                OK
				Wywlaszcz();
				UstawProcesy(CzyWyzszyPriorytet);
			break;
		}

		cout << czas << ": ";	
		for(int i = 0; i < ilosc_rdzeni; i++)
		{
			if(procesor[i] != NULL) //je�eli co� robi - Update
			{
				cout << procesor[i]->id << " ";
				procesor[i]->pozostalo--;
				procesor[i]->ile_na_procku++;
				if(procesor[i]->pozostalo == 0)
				{
					procesor[i]->zakonczone = true;
					procesor[i]->wykonuje_sie = false;
					procesor[i] = NULL;
				}
			}
			else    // je�eli nie wy�wietla u�peine
			{
				cout << "-1 ";
			}
		}
		cout << "\n";
		czas++;
		koniec = true;
		for(int i = 0; i < zadania.size(); i++)
			if(!zadania[i]->zakonczone) koniec = false;
		if(koniec) break;
	}
}