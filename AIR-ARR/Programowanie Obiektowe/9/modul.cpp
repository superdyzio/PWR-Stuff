#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>

#include "OpcjeWywolania.hh"

using namespace std;
/*DANE UZYTKOWNIKA DANE UZYTKOWNIKA DANE UZYTKOWNIKA DANE UZYTKOWNIKA*/

/*klasa DaneUzytkownika:
	metody:
		kostruktor,
		bool Norm(); <-zwraca czy normalny uzytkownik
		int RozmID(); <-zwraca jak wysokie jest ID;
		void DajDane(); <-wypisuje na zadany strumien Dane uzytkownika;
		
		~'>>'
		~'<<'
		*/
class DaneUzytkownika{
		string Login;/*login uzytkownika*/
		string Imie;/*imie uzytkownika*/
		string Nazwisko;/*nazwisko uzytkownika*/
		string Dane;/*dodatkowe dane uzytkownika*/
		unsigned int Id;/*ID uzytkownika*/
		bool CzyNormalny;/*zmienna wyrazajaca kategorie uzytkownika*/

	
	public:
		/*konstruktor*/
			DaneUzytkownika(){
				Login="";
				Imie="";
				Nazwisko="";
				Dane="";
				Id=0;
				CzyNormalny=false;
			}
		/*konstruktor #2*/
		/*	DaneUzytkownika(string L="", string I="", string N="", string D="", unsigned int X=0){
				Login=L;
				Imie=I;
				Nazwisko=N;
				Dane=D;
				Id=X;
				if (Id>=1000) CzyNormalny=true;
				else CzyNormalny=false;
			}*/
			
		bool Norm(){
			return CzyNormalny;
		}
		
		int RozmID(){
			return Id;
		}
		
		void DajDane(ostream &StrmWy){
			StrmWy<<Dane;
		}
		
		/*zaprzyjazniona funkcja wypisujaca co trzeba*/
			friend ostream & operator << (ostream & StrmWy, DaneUzytkownika & DaneU);
		/*zaprzyjazniona funkcja pobierajaca co trzeba*/
			friend istream & operator >> (istream &StrmWe,  DaneUzytkownika &D);
			
};

ostream & operator << (ostream & StrmWy, DaneUzytkownika & DaneU){
	StrmWy.width(8);
	StrmWy<<DaneU.Login<<" ";
	StrmWy.width(6);
	StrmWy<<DaneU.Id<<" ";
	StrmWy.width(10);
	StrmWy<<DaneU.Imie<<" ";
	StrmWy<<DaneU.Nazwisko<<" ";
		
	return StrmWy;
}

istream & operator >> (istream &StrmWe,  DaneUzytkownika &D){
	string lalka;
	unsigned L, M;
	StrmWe>>lalka;
	if (StrmWe.fail()) return StrmWe;
	else{
		L=lalka.length();
		
		/*LOGIN LOGIN LOGIN LOGIN LOGIN LOGIN LOGIN*/
		M=lalka.find(":");/*znajdujemy login- do pierwszego ':'*/
		D.Login=lalka.substr(0, M);/*pobieramy login*/
		
		lalka=lalka.substr(M+3, L);/*odcinamy login, oraz 'x' i towarzyszace ':'*/
		
		/*ID ID ID ID ID ID ID ID ID ID ID ID ID ID*/
		M=lalka.find(":");/*znajdujemy Id- do pierwszego ':'*/
		D.Id=atoi(lalka.c_str());/*wczytujemy wartosc Id*/
		
		lalka=lalka.substr(M+1, L);/*odcinamy Id*/
		
		/*GRUPA GRUPA GRUPA GRUPA GRUPA GRUPA GRUPA*/
		M=lalka.find(":");/*znajdujemy grupe do pierwszego ':'*/
		
		lalka=lalka.substr(M+1, L);/*odcinamy grupe wraz z ':'*/
		
		/*IMIE IMIE IMIE IMIE IMIE IMIE IMIE IMIE IMIE IMIE IMIE*/
		D.Imie=lalka.substr(0, L);/*pobieramy imie*/
		
		if (D.Imie[0]>='A' && D.Imie[0]<='Z' && D.Id>=1000){
			D.CzyNormalny=true;
			StrmWe>>lalka;
			if (StrmWe.fail()) return StrmWe;
			else{	
				
				/*NAZWISKO NAZWISKO NAZWISKO NAZWISKO NAZWISKO NAZWISKO*/	
				M=lalka.find(",");/*znajdujemy nazwisko do ','*/
				/*cout<<"przecinek: "<<M<<endl;*/
				if (M!=string::npos){
					D.Nazwisko=lalka.substr(0, M);
			
					lalka=lalka.substr(M+1, L);/*odcinamy nazwisko wraz z ','*/
		
					M=lalka.find(":");/*znajdujemy DANE do pierwszego ':'*/
			
					/*DANE DANE DANE DANE DANE DANE DANE DANE DANE DANE DANE DANE*/
					D.Dane=lalka.substr(0, M);
					if ((D.Dane).compare(",,")==0) D.Dane="";
				}
				else{
					D.Nazwisko="";
					D.Dane="";
				}
		
				if (D.Id>=1000 && D.Nazwisko!="") D.CzyNormalny=true;
				else D.CzyNormalny=false;
			}
		
		}
		else D.CzyNormalny=false;
	}
	return StrmWe;
}
/*DANE UZYTKOWNIKA DANE UZYTKOWNIKA DANE UZYTKOWNIKA DANE UZYTKOWNIKA DANE UZYTKOWNIKA*/




/*LISTA UZYTKOWNIKOW LISTA UZYTKOWNIKOW LISTA UZYTKOWNIKOW LISTA UZYTKOWNIUKOW*/
class ListaUzytkownikow{
	public:
	list<DaneUzytkownika> Lista;
/*	
	SortowanieNazwiska(){
	}*/
/*	
	bool Znajdz( DaneUzytkownika& ) const{}
	bool Znajdz( const char* sPoczatekLoginu, DaneUzytkownika& ){}
	bool Znajdz( int Id, DaneUzytkownika& ) const{}	
*/
};





/*PRZETWARZANIE*/
void PrzetworzListe_Uzytkownikow_i_Grupy(const OpcjeWywolania& Opcje){
  	DaneUzytkownika DaneDane, Maksownik;
  	ListaUzytkownikow Baza;
	ifstream fin;
	fin.open("passwd");
	if (fin.is_open()){
		cout<<"     Czyta plik passwd ..."<<endl<<"          operacja zakonczona powodzeniem."<<endl<<endl;
		
		/*wczytywanie danych (normalni uzytkownicy)*/
		do{
			fin>>DaneDane;
			if (DaneDane.Norm()==true) (Baza.Lista).push_front(DaneDane);
		} while (!fin.eof());
		(Baza.Lista).pop_front();
		
/*fajne!!!!*/
		for (list<DaneUzytkownika>::iterator iter=(Baza.Lista).begin(); iter!=(Baza.Lista).end(); ++iter){
			DaneDane=(Baza.Lista).front();
			(Baza.Lista).pop_front();
			cout<<DaneDane<<endl;
			if(DaneDane.RozmID()>Maksownik.RozmID()) Maksownik=DaneDane;
		}
	
		
		cout<<endl<<"----------------------------------------------------------------------"<<endl;
		cout<<Maksownik;
		Maksownik.DajDane(cout);
		cout<<endl;
		
	}	
/*	
		
		if (DaneDane.Norm()==true){
			cout<<DaneDane<<endl;
			if(DaneDane.RozmID()>Maksownik.RozmID()) Maksownik=DaneDane;
		}
	}
	
	cout<<endl<<"----------------------------------------------------------------------"<<endl;
	cout<<Maksownik;
	Maksownik.DajDane(cout);
*/
	fin.close();
}
