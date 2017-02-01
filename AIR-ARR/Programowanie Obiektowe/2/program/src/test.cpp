#include "test.hh"


void Zapytaj(Pytanie pyt){
	cout<<":? Podaj operacje ";
	if (pyt.OperatorDzialania=='+') cout<<"dodawania";
	else cout<<"odejmowania";
	cout<<",ktorej wynikiem jest: ";
	switch (pyt.WynikDzialania){
		case e: cout<<"e"<<endl; break;
		case a: cout<<"a"<<endl; break;
		case b: cout<<"b"<<endl; break;
		case c: cout<<"c"<<endl; break;
		case d: cout<<"d"<<endl; break;
	}
}

int Odpowiedz(Pytanie pyt) {
	cout<<"Twoja odpowiedz: ";
	char x, znak, y;
	Symbol z, zz, wynik;
	int ok=0;
	do{
	cin>>x;
	if ((x>='a') && (x<='e')){
		cin>>znak;
		if (znak=='+' || znak=='-'){
			cin>>y;
			if ((y>='a') && (y<='e')) ok=1;
			else cout<<"Wprowadzony zostal bledny symbol '"<<y<<"'."<<endl;
		}
		else cout<<"Wprowadzony zostal bledny symbol '"<<znak<<"'."<<endl;
	}
	else cout<<"Wprowadzony zostal bledny symbol '"<<x<<"'."<<endl;
	} while (ok==0);
	x=(x-96)%5;
	y=(y-96)%5;
	switch (x){
		case 0: z=e; break;
		case 1: z=a; break;
		case 2: z=b; break;
		case 3: z=c; break;
		case 4: z=d; break;
	}     
	switch (y){
		case 0: zz=e; break;
		case 1: zz=a; break;
		case 2: zz=b; break;
		case 3: zz=c; break;
		case 4: zz=d; break;
	}
	if (znak=='+') {
		wynik=Dodaj(z, zz);
		if(pyt.WynikDzialania==wynik){
			cout<<":) Odpowiedz poprawna"<<endl<<endl;
			return 1;
		}
		else{
			switch (wynik){
				case 0: znak='e'; break;
				case 1: znak='a'; break;
				case 2: znak='b'; break;
				case 3: znak='c'; break;
				case 4: znak='d'; break;
			}
			cout<<":( Blad. Wynikiem tej operacji jest: "<<znak<<endl<<endl;
			return 0;
		}
	}
	else {
		wynik=Odejmij(z, zz);
		if(pyt.WynikDzialania==wynik){
			cout<<":) Odpowiedz poprawna"<<endl<<endl;
			return 1;
		}
		else{
			switch (wynik){
				case 0: znak='e'; break;
				case 1: znak='a'; break;
				case 2: znak='b'; break;
				case 3: znak='c'; break;
				case 4: znak='d'; break;
			}
			cout<<":( Blad. Wynikiem tej operacji jest: "<<znak<<endl<<endl;
			return 0;
		}
	}
}

void Konkurs() {
	Pytanie ZbiorPytan[ILOSC_PYTAN] = {
             { '+', a }, { '-', c }, { '+', e }, { '-', d }, { '+', b },
             { '-', a }, { '+', c }, { '-', e }, { '+', d }, { '-', b }
          };
	int ok=0, zle=0;
	int i, x;
	float p;
	for (i=0; i<ILOSC_PYTAN; i++){
		x=rand()%10;
		Zapytaj(ZbiorPytan[x]);
		if (Odpowiedz(ZbiorPytan[x])==1) ok++;
		else zle++;
	}
	p=ok*10;
	cout<<"Koniec testu."<<endl<<endl;
	cout<<"Ilosc dobrych odpowiedzi: "<<ok<<endl;
	cout<<"Ilosc blednych odpowiedzi: "<<zle<<endl;
	cout<<"Wynik procentowy poprawnych odpowiedzi: "<<p<<" %"<<endl;
}
