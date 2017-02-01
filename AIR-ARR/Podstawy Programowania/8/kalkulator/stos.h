#ifndef STOS_H
#define STOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {       // struktura elementu stosu
	int liczba;
	struct element *ponizej;
} Stos;


/* PRE: Funkcja przyjmuje jako argument liczbę, która ma stać się wartością w nowym elemencie (wierzchołku) stosu oraz wskaźnik na tenże
	wierzchołek. */

Stos* push(int liczba, Stos *stos);

/* POST: Zwracany jest wskaźnik na nowy wierzchołek, zatem wywołanie funkcji w programie musi mieć charakter podstawienia pod obecny
	 wierzchołek. */


/* PRE: Funkcja przyjmuje jako argument wskaźnik na wskaźnik wierzchołka stosu (aby móc modyfikować jego wartość). Pod wierzchołek zostaje 
	podstawiony "niższy" element, a stary wierzchołek jest zwracany. */

Stos* pop(Stos **stos);

/* POST: Zwracany jest wskaźnik na element, będący starym wierzchołkiem funkcji. Pamięć nie jest zwalniana. */


/* PRE: Funkcja przyjmuje jako argument wskaźnik na wierzchołek stosu. W trakcie jej działania nie jest on zmieniany. */

void print(Stos *s);

/* POST: Funkcja nic nie zwraca, a w wyniku jej działania na wyjściu zostaje wypisana w czytelnej formie zawartość stosu i powiązania między 
	 jego elementami. */


/* PRE: Funkcja przyjmuje jako argument wskaźnik na wskaźnik wierzchołka stosu (aby móc modyfikować jego wartość). Jej zadaniem jest 
	ściągnięcie ze stosu każdego elementu i zwolnienie pamięci. */

void czysc(Stos **s);

/* POST: Funkcja nic nie zwraca, a w wyniku jej działania stos zostaje wyczyszczony, a pamięć zwolniona. */


/* PRE: Funkcja przyjmuje jako argument wskaźnik na wierzchołek stosu i jej zadaniem jest zliczenie elementów na nim się znajdujących. */

int ilosc(Stos *s);

/* POST: Funkcja zwraca liczbę całkowitą równą liczbie elementów znajdujących się w chwili wywołania na stosie. */


#endif
