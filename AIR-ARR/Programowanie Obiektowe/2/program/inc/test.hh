#ifndef TEST_HH
#define TEST_HH

#include <cstdlib>
#include <iostream>
#include "dzialania.hh"

using namespace std;

// struktura do przechowywania pojedynczych pytań
struct Pytanie {
  char    OperatorDzialania;
  Symbol  WynikDzialania;
};

#define ILOSC_PYTAN   10

/* PRE: Funkcja przyjmuje jako argument jedno z pytań ze zbioru i ma na celu wypisanie go na standardowe wyjście w formie zrozumiałej dla
	użytkownika.
  POST: Funkcja nic nie zwraca i w wyniku jej działania w terminalu pojawia się pytanie do użytkownika. */
void Zapytaj(Pytanie pyt);

/* PRE: Funkcja przyjmuje jako parametr aktualnie zadane pytanie i jej zadaniem jest pobranie odpowiedzi użytkownika i przeanalizowanie jej
	pod kątem poprawności.
  POST: Funkcja zwraca liczbę całkowitą 1 lub 0, gdzie 0 oznacza, że odpowiedź użytkownika była błędna, a 1, że była ona poprawna. */
int Odpowiedz(Pytanie pyt);

/* PRE: Jest to funkcja bezparametrowa mająca na celu zadanie wszystkich możliwych 10 pytań użytkownikowi w losowej kolejności oraz zliczenie
	ilości dobrych i złych odpowiedzi, a na koniec procentowe przedstawienie poprawnych rozwiązań.
  POST: Funkcja nic nie zwraca, a w wyniku jej działania wyświetlony zostaje rezultat testu jakiemu poddany był użytkownik. */
void Konkurs();

#endif