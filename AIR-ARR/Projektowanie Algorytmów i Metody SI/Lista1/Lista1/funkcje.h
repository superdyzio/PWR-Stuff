#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <string>
#include <fstream>
#include "Tablica2W.h"

#define ROZMIAR 10
;
using namespace std;

Tablica2W* tworz();

void menu();

int potega(int x, int p);

int silnia(int x);

bool jestPal(string testStr);

bool zapistxt(string plik, int tab[]);

bool odczyttxt(string plik);

void punkt4();

bool zapisbin(string plik, int tab[]);

bool odczytbin(string plik);

void punkt5();

#endif