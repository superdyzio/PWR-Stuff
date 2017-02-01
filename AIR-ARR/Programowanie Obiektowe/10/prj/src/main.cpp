#include "zespolone.hh"
#include "stosokalkulator.hh"

int Zespolona::IloscObiektow = 0;
int Zespolona::IloscObiektowAktualnych = 0;
bool Zespolona::NotacjaWykWej = false;
bool Zespolona::NotacjaWykWyj = false;

int main() {
	Stosokalkulator stosik;
	char Znak = '0';
	while (Znak != 'q') {
		cin >> Znak;
		switch (Znak) {
			case 'p': 	stosik.wyswietl(); 	break;
			case '$': 	stosik.duplikuj(); 	break;
			case '&': 	stosik.zamien(); 	break;
			case '+': 	stosik.dodaj(); 	break;
			case '-': 	stosik.odejmij(); 	break;
			case '*': 	stosik.mnoz(); 		break;
			case '/': 	stosik.dziel(); 	break;
			case '#': 	stosik.usun(); 		break;
			case 'e': 	stosik.wyjNotWyk(); 	break;
			case 't': 	stosik.wyjNotTrad(); 	break;
			case 'E': 	stosik.wejNotWyk(); 	break;
			case 'T': 	stosik.wejNotTrad(); 	break;
			case '(': 	cin.unget();
					Zespolona a;
					cin >> a; 
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,' ');
					}
					else {	
						Zespolona *x = new Zespolona(a);
						stosik.push(*x);
						delete x;
					} 
					break;
		}	
	}
	stosik.czysc();
	return 0;
}
