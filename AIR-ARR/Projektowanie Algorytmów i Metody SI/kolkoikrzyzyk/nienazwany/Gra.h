#ifndef GRA_H
#define GRA_H

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include "Funkcje.h"

#define MAX_ROZMIAR 7		// zmienna okreslajaca maksymalny rozmiar planszy do gry

using namespace std;

/*	klasa modelujaca rozgrywke - przechowuje pola odpowiedzialne za uzyteczny rozmiar planszy, wymagana ilosc znakow w rzedzie, sama plansze i wszystkie
    obslugujace rozgrywke metody */
class Gra {
    int rozmiar;		// uzyteczny rozmiar tablicy
    int rzad;			// wymagana ilosc znakow w rzedzie
public:
    char plansza[MAX_ROZMIAR][MAX_ROZMIAR];	// plansza do gry
// konstruktory
    Gra() {}
    Gra(int roz, int rz):rozmiar(roz),rzad(rz) { zeruj(); }
// destruktor
    ~Gra() {}
// metoda zerujaca plansze do gry
    void zeruj() { for (int i = 0; i < rozmiar; i++) for (int j = 0; j < rozmiar; j++) plansza[i][j] = ' '; }
// metoda wypisujaca plansze na standardowe wyjscie
    void getPlansza();
/*	metoda zwracajaca czy gracz o znaku przekazanym jako argument wygral - true jesli tak; argument cisza informuje sluzy do ustalenia czy metoda
    powinna	wypisac koncowa plansze na standardowe wyjscie */
    bool wygrana(char znak, bool cisza);
// metoda zwracajaca true w przypadku remisu (nikt nie wygral i nie ma mozliwosci ruchu); argument cisza jak wyzej
    bool remis(bool cisza);
// metoda losujaca ruch komputera (uzywana na poczatku gry - dlugosc uzycia zalezna od rozmiaru planszy)
    int ksiega_otwarc();
// zwraca ilosc wolnych miejsc na planszy
    int miejsca_wolne();
/*	metoda implementujaca rekurencyjny algorytm MIN-MAX majacy za zadanie podejmowanie decyzji jako wirtualny przeciwnik w grze
    jako argument przyjmuje znak gracza */
    int minimax(char gracz, int poziom);
// metoda wyznaczajaca najblizszy ruch komputera (zaczynamy jej uzywac po wykonaniu paru pierwszych ruchow przez obie strony - zaleznie od rozmiaru)
    int komputer();
/*	metoda pozwalajaca na wykonanie ruchu przez gracza podanego jako argument funkcji (przekazujemy "jego znaczek"), przekazujemy rowniez licznik ruchow
    wykonanych dotychczas przez komputer */
    void ruch(char gracz, int licznik);
};

#endif
