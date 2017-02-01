#include "funkcje.h"

string listPal[ROZMIAR_TAB];
int ilosc = 0;

int main() {
	char wybor = 'a';
	char linia[256];
	while (wybor != '0') {
		menu();
		cin.getline(linia,256);
		wybor = linia[0];
		switch(wybor) {
		case '1': zadanie1(listPal,ilosc); cin.ignore(); break;
		case '2': zadanie2(); cin.ignore(); break;
		case '3': zadanie3(); cin.ignore(); break;
		case '4': zadanie5(); cin.ignore(); break;
		}
		while (!cin) cin.get();
	}
	return 0;
}

/*	Gdy demonstrowalem Panu dzialanie programu na zajeciach to po wybraniu zadania pierwszego i wprowadzeniu lancucha znakowego ("123321") program
	wysypywal sie (jednak dzialal bez zarzutu dla przykladow takich jak "pamsi", "kajak", "aa", "ab"). Gdy w domu usiad³em do komputerka, by to naprawic
	okazalo sie, ze wszystko dziala bezblednie. Aby moc wprowadzac dluzsze lancuchy trzeba dostosowac wartosc stalej ROZMIAR_TAB w pliku funkcje.h. 
	Na wypadek, gdyby jakos magicznie znow sie wszystko posypalo, dolacze nawet zrzut ekranu jak ladnie dziala dla lancucha "123321"! Co prawda nie 
	widac tam wszystkiego idealnie, ale widac, ze wygenerowane, wypisane, usuniete duplikaty i nie wysypalo programu!
*/