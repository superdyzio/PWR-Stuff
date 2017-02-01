#include "test.hh"
#include "przeciazenia.hh"

void Zapytaj(Pytanie pyt){
	cout<<":? Podaj operacje ";
	switch (pyt.OperatorDzialania){
		case '+': cout<<"dodawania"; break;
		case '-': cout<<"odejmowania"; break;
		case '*': cout<<"mnozenia"; break;
		case '/': cout<<"dzielenia";
	}
	cout<<", ktorej wynikiem jest: ";
	switch (pyt.WynikDzialania){
		case e: cout<<"e"<<endl; break;
		case a: cout<<"a"<<endl; break;
		case b: cout<<"b"<<endl; break;
		case c: cout<<"c"<<endl; break;
		case d: cout<<"d"<<endl; break;
	}
}

int Odpowiedz(Pytanie pyt, int proby) {
	cout<<"Twoja odpowiedz: ";
	Symbol x, y, wynik;
	char znak;
	int ok, odp, i;
	for (i=0; i<proby && odp!=1; i++){
		cin>>x>>znak>>y;
		while (cin.fail()){
			cout<<"Blad, wpisz ponownie."<<endl;
			cin.clear();
			cin.ignore(10000,'\n');
			cin>>x>>znak>>y;
		}
		ok = 0;
		odp = 0;
		switch (znak){
			case '+': wynik = x + y; ok = 1; break;
			case '-': wynik = x - y; ok = 1; break;
			case '*': wynik = x * y; ok = 1; break;
			case '/': if (y != e) { wynik = x / y; ok = 1; }
				  else { cout<<"Nie mozna dzielic przez e!"<<endl; ok = 0; } break;
			default: cout<<"Bledny operator."<<endl;
		}
		if (ok == 1 && wynik == pyt.WynikDzialania){
			cout<<"Poprawna odpowiedz!"<<endl;
			odp = 1;
		}
		else {
			if (ok != 0) {
				cout<<"Bledna odpowiedz, wynik podanego dzialania to "<<wynik<<endl;
				odp = 0;
			}
		}
	}
	if (odp==1) odp += i;
	return odp;
}

void Konkurs() {
	Pytanie ZbiorPytan[ILOSC_PYTAN] = {
             { '+', a }, { '-', c }, { '+', e }, { '-', d }, { '+', b },
             { '-', a }, { '*', c }, { '/', e }, { '*', d }, { '/', b },
	     { '*', b }, { '/', c }
          };
	int ok=0, zle=0;
	int i, proby=0, pom;
	float p;
	int sumaprob=0;
	while (proby<=0 || proby>5){
		cout<<"Ile szans na odpowiedz chcesz miec?"<<endl;
		cin>>proby;
	}	
	for (i=0; i<ILOSC_PYTAN; i++){
		Zapytaj(ZbiorPytan[i]);
		pom = Odpowiedz(ZbiorPytan[i],proby);
		if (pom > 0) { ok++; sumaprob += (pom - 1); }
		else zle++;
	}
	p=(ok*100)/ILOSC_PYTAN;
	cout<<"Koniec testu."<<endl<<endl;
	cout<<"Ilosc dobrych odpowiedzi: "<<ok<<endl;
	cout<<"Ilosc blednych odpowiedzi: "<<zle<<endl;
	cout<<"Wynik procentowy poprawnych odpowiedzi: "<<p<<" %"<<endl;
	if (ok > 0) cout<<"Srednia ilosc prob wynosi: "<<((float)sumaprob/(float)ok)<<endl;
}
