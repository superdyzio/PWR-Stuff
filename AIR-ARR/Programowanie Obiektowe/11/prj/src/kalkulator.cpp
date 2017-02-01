#include "kalkulator.hh"

/*!
 *\file
 *\brief 	Plik zawierający definicje metod z klasy Kalkulator. 
*/
void Kalkulator::zamien() {
	if (stosik.czyDwa()) {
		string a = stosik.szczyt();
		stosik.usun();
		string b = stosik.szczyt();
		stosik.usun();
		stosik.doloz(a);
		stosik.doloz(b);
	}
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Kalkulator::duplikuj() {
	if (stosik.rozmiar() > 0) {
		string pom = stosik.szczyt();
		if (pom[0] == ':' && pom[1] == ':') {
			Zespolona x = mapka(pom).getWart();
			pom = mapka.stworzNazwe();
			mapka.dodajDana(pom);
			mapka.przypiszWartosc(pom,x);
			stosik.doloz(pom);
		}
		else {
			stosik.doloz(pom);
			mapka.dodajDana(pom);
		}
	}
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Kalkulator::dodaj() {
	if (stosik.czyDwa()) {
		string a, b;
		a = stosik.szczyt();
		stosik.usun();
		if (mapka(a).getCzyMaWart()) {
			b = stosik.szczyt();
			stosik.usun();
			if (mapka(b).getCzyMaWart()) {
				Zespolona x, y;
				x = mapka(a).getWart();
				y = mapka(b).getWart();
				mapka.usunDana(a);
				mapka.usunDana(b);
				a = mapka.stworzNazwe();
				stosik.doloz(a);
				mapka.dodajDana(a);
				mapka.przypiszWartosc(a,x+y);
				cout << "Wykonano dodawanie." << endl;
			}
			else { cout << "Druga zmienna nie ma przypisanej wartosci." << endl; stosik.doloz(b); stosik.doloz(a); }
		}
		else { cout << "Pierwsza zmienna nie ma przypisanej wartości." << endl;	stosik.doloz(a); }
	}
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Kalkulator::odejmij() {
	if (stosik.czyDwa()) {
		string a, b;
		a = stosik.szczyt();
		stosik.usun();
		if (mapka(a).getCzyMaWart()) {
			b = stosik.szczyt();
			stosik.usun();
			if (mapka(b).getCzyMaWart()) {
				Zespolona x, y;
				x = mapka(a).getWart();
				y = mapka(b).getWart();
				mapka.usunDana(a);
				mapka.usunDana(b);
				a = mapka.stworzNazwe();
				stosik.doloz(a);
				mapka.dodajDana(a);
				mapka.przypiszWartosc(a,x-y);
				cout << "Wykonano odejmowanie." << endl;
			}
			else { cout << "Druga zmienna nie ma przypisanej wartosci." << endl; stosik.doloz(b); stosik.doloz(a); }
		}
		else { cout << "Pierwsza zmienna nie ma przypisanej wartości." << endl;	stosik.doloz(a); }		
	}
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Kalkulator::mnoz() {
	if (stosik.czyDwa()) {
		string a, b;
		a = stosik.szczyt();
		stosik.usun();
		if (mapka(a).getCzyMaWart()) {
			b = stosik.szczyt();
			stosik.usun();
			if (mapka(b).getCzyMaWart()) {
				Zespolona x, y;
				x = mapka(a).getWart();
				y = mapka(b).getWart();
				mapka.usunDana(a);
				mapka.usunDana(b);
				a = mapka.stworzNazwe();
				stosik.doloz(a);
				mapka.dodajDana(a);
				mapka.przypiszWartosc(a,x*y);
				cout << "Wykonano mnożenie." << endl;
			}
			else { cout << "Druga zmienna nie ma przypisanej wartosci." << endl; stosik.doloz(b); stosik.doloz(a); }
		}
		else { cout << "Pierwsza zmienna nie ma przypisanej wartości." << endl;	stosik.doloz(a); }		
	}
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Kalkulator::dziel() {
	if (stosik.czyDwa()) {
		string a, b;
		a = stosik.szczyt();
		stosik.usun();
		if (mapka(a).getCzyMaWart()) {
			b = stosik.szczyt();
			stosik.usun();
			if (mapka(b).getCzyMaWart()) {
				Zespolona x, y;
				x = mapka(a).getWart();
				y = mapka(b).getWart();
				mapka.usunDana(a);
				mapka.usunDana(b);
				a = mapka.stworzNazwe();
				stosik.doloz(a);
				mapka.dodajDana(a);
				mapka.przypiszWartosc(a,x/y);
				cout << "Wykonano dzielenie." << endl;
			}
			else { cout << "Druga zmienna nie ma przypisanej wartosci." << endl; stosik.doloz(b); stosik.doloz(a); }
		}
		else { cout << "Pierwsza zmienna nie ma przypisanej wartości." << endl;	stosik.doloz(a); }		
	}
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Kalkulator::wypiszStos() {
	string pom;
	Stos kopia = stosik;
	cout << endl << "Stos:" << endl;
	while (kopia.rozmiar() > 0) {
		pom = kopia.szczyt();
		kopia.usun();
		if (pom[0] == ':' && pom[1] == ':') 
			cout << mapka.getWartosc(pom) << endl;
		else {
			cout << pom << "          ->   ";
			if (mapka(pom).getCzyMaWart()) cout << mapka(pom).getWart() << endl;
			else cout << "?" << endl;
		}
	}
	cout << "Obiektow na stosie: " << stosik.rozmiar() << endl;
}

void Kalkulator::nadajWartosc() {
	if (stosik.czyDwa()) {
		if (mapka(stosik.szczyt()).getCzyMaWart()) {
			string n = stosik.szczyt();
			stosik.usun();
			Zespolona x = mapka.getWartosc(n);
			mapka.usunDana(n);
			n = stosik.szczyt();
			if (n[0] == ':' && n[1] == ':') cout << "Nie można przypisać wartości stałej." << endl;
			else mapka.przypiszWartosc(n,x);
		}
		else cout << "Brak wartości na szczycie stosu." << endl;	
	}
	else cout << "Na stosie jest za mało elementów." << endl;
}

void Kalkulator::usunDana() {
	if (stosik.rozmiar() > 0) {
		string n = stosik.szczyt();
		stosik.usun();
		mapka.usunDana(n);
	}
}
		
void Kalkulator::uruchom() {
	char Znak = '0';
	while (Znak != 'q') {
		Zespolona a;
		string nazwa;
		cin >> Znak;
		switch (Znak) {
			case 'p': 	wypiszStos(); 		break;
			case '&': 	duplikuj(); 		break;
			case '$': 	zamien();	 	break;
			case '+': 	dodaj(); 		break;
			case '-': 	odejmij(); 		break;
			case '*': 	mnoz(); 		break;
			case '/': 	dziel(); 		break;
			case '#': 	usunDana(); 		break;
			case 'e': 	wyjNotWyk(); 		break;
			case 't': 	wyjNotTrad(); 		break;
			case 'E': 	wejNotWyk(); 		break;
			case 'T': 	wejNotTrad(); 		break;
			case '(': 	cin.unget();
					nazwa = mapka.stworzNazwe();
					cin >> a; 
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,' ');
					}
					else {
						mapka.dodajDana(nazwa);
						stosik.doloz(nazwa);
						mapka.przypiszWartosc(nazwa,a);
					}
					break;
			case '=':	nadajWartosc();		break;
			case 's':	mapka.wypiszSt();	break;
			case 'v':	mapka.wypiszZm();	break;
			default:
				cin.unget();
				cin >> nazwa;
				if (nazwa[0] == '_' || (nazwa[0] >= '0' && nazwa[0] <= 'z')) {
					stosik.doloz(nazwa);
					mapka.dodajDana(nazwa);
				}
				else cout << "Niepoprawne dane." << endl;
		}	
	}
	stosik.czysc();
}
