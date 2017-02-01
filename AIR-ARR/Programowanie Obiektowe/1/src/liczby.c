#include <malloc.h>
#include <stdio.h>
#include "liczby.h"

const int maks = 50;

int utworzTab( int *rozmiar,  int **liczby ){
  printf("\nWprowadz ilosc liczb calkowitych, ktore nalezy wczytac:\n");
  scanf("%d",rozmiar);
  while (*rozmiar <= 0 || *rozmiar > maks) {
    printf("\nWprowadziles niepoprawna wartosc.\n");     
    printf("Ilosc liczb musi byc wieksza od 0 i mniejsza od 51.\n\n");
    printf("Wprowadz ilosc liczb calkowitych, ktore nalezy wczytac:\n");
    scanf("%d",rozmiar);
  }
  *liczby = (int*) malloc(*rozmiar * sizeof(int));
  return liczby ? 0 : -1;
}

void pobieranie(int *rozmiar, int **liczby){
  int i;
  for(i = 0; i < (*rozmiar); i++){
    printf("Podaj %d liczbe:\n", i+1);
    scanf("%d", *liczby+i);
  }
}

void sortowanie(int *rozmiar, int **liczby ){
  int i, j, temp;
  for (i = 0; i < (*rozmiar); i++)
    for (j = 0; j < (*rozmiar)-1-i; j++)
      if ( *(*liczby+j) > *(*liczby+(j+1)) ){
        temp = *(*liczby+(j+1));
        *(*liczby+(j+1)) = *(*liczby+j);
        *(*liczby+j) = temp;
      }
}

void wyswietl(int *rozmiar, int **liczby){
  int i;
  printf("Liczby posortowane:\n");
  for(i = 0; i < (*rozmiar); i++)
    printf("%d\n", *(*liczby+i));
}

