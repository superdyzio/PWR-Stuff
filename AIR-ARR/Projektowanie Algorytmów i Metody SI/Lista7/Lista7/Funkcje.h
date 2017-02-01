#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <cstdio>

#define GRACZ "X"		// znaczek gracza
#define SI "O"			// znaczek komputera
// naglowki poszczegolnych rozmiarow planszy, wyswietlane po dokonaniu wyboru, przed rozpoczeciem gry
#define NAGLOWEK3 "\nkolko i krzyzyk 3x3\n1 | 2 | 3\n---+---+---\n4 | 5 | 6\n---+---+---\n7 | 8 | 9\n=======================\n"
#define NAGLOWEK4 "\nkolko i krzyzyk 4x4\n1  | 2  | 3  | 4\n---+----+----+----\n5  | 6  | 7  | 8\n---+----+----+----\n9  | 10 | 11 | 12\n---+----+----+----\n13 | 14 | 15 | 16\n=======================\n"
#define NAGLOWEK5 "\nkolko i krzyzyk 5x5\n1  | 2  | 3  | 4  | 5\n---+----+----+----+----\n6  | 7  | 8  | 9  | 10\n---+----+----+----+----\n11 | 12 | 13 | 14 | 15\n---+----+----+----+----\n16 | 17 | 18 | 19 | 20\n---+----+----+----+----\n21 | 22 | 23 | 24 | 25\n=======================\n"
#define NAGLOWEK6 "\nkolko i krzyzyk 6x6\n1  | 2  | 3  | 4  | 5  | 6\n---+----+----+----+----+----\n7  | 8  | 9  | 10 | 11 | 12\n---+----+----+----+----+----\n13 | 14 | 15 | 16 | 17 | 18\n---+----+----+----+----+----\n19 | 20 | 21 | 22 | 23 | 24\n---+----+----+----+----+----\n25 | 26 | 27 | 28 | 29 | 30\n---+----+----+----+----+----\n31 | 32 | 33 | 34 | 35 | 36\n================================\n"
#define NAGLOWEK7 "\nkolko i krzyzyk 7x7\n1  | 2  | 3  | 4  | 5  | 6  | 7\n---+----+----+----+----+----+----\n8  | 9  | 10 | 11 | 12 | 13 | 14\n---+----+----+----+----+----+----\n15 | 16 | 17 | 18 | 19 | 20 | 21\n---+----+----+----+----+----+----\n22 | 23 | 24 | 25 | 26 | 27 | 28\n---+----+----+----+----+----+----\n29 | 30 | 31 | 32 | 33 | 34 | 35\n---+----+----+----+----+----+----\n36 | 37 | 38 | 39 | 40 | 41 | 42\n---+----+----+----+----+----+----\n43 | 44 | 45 | 46 | 47 | 48 | 49\n========================================\n"
;
using namespace std;

/*	funkcja wyswietlajaca menu i zwracajaca pare ustalonych przez uzytkownika parametrow - pierwszy to rozmiar planszy, a drugi to wymagana ilosc 
	znakow w rzedzie do wygrania gry */
pair<int,int> menu();

#endif