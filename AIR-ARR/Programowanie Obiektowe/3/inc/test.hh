#ifndef TEST_HH
#define TEST_HH

#include "przeciazenia.hh"
#include <iostream>
#include <cstdlib>
#define ILOSC_PYTAN 12

using namespace std;

// struktura do przechowywania pojedynczych pytań
struct Pytanie {
  char    OperatorDzialania;
  Symbol  WynikDzialania;
};

/* PRE: Funkcja przyjmuje jako argument jedno z pytań ze zbioru i ma na celu wypisanie go na standardowe wyjście w formie zrozumiałej dla
	użytkownika.
  POST: Funkcja nic nie zwraca i w wyniku jej działania w terminalu pojawia się pytanie do użytkownika. */
void Zapytaj(Pytanie pyt);

/* PRE: Funkcja przyjmuje jako parametr aktualnie zadane pytanie oraz zdefiniowaną wcześniej ilość prób jakie użytkownik będzie miał na 
	podanie prawidłowej odpowiedzi, a jej zadaniem jest pobranie odpowiedzi użytkownika i przeanalizowanie jej pod kątem poprawności.
  POST: Funkcja zwraca liczbę całkowitą 1 lub 0, gdzie 0 oznacza, że odpowiedź użytkownika była błędna, a 1, że była ona poprawna. */
int Odpowiedz(Pytanie pyt, int proby);

/* PRE: Jest to funkcja bezparametrowa mająca na celu zadanie wszystkich możliwych 10 pytań użytkownikowi w losowej kolejności oraz zliczenie
	ilości dobrych i złych odpowiedzi, a na koniec procentowe przedstawienie poprawnych rozwiązań. W trakcie jej działania ustalana jest
	ilość prób jakie będzie miał do wykorzystania użytkownik przy odpowiedzi na każde z pytań.
  POST: Funkcja nic nie zwraca, a w wyniku jej działania wyświetlony zostaje rezultat testu jakiemu poddany był użytkownik. */
void Konkurs();

#endif
