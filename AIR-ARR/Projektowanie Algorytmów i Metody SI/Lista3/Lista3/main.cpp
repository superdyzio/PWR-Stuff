#include "Stos.h"
#include "StosStat.h"
#include "StosDym.h"
;

void hanoi(int n, char A, char B, char C, Stos x, Stos y, Stos z) {
  if (n > 0) {
    hanoi(n-1, A, C, B, x, z, y);
    cout << A << " -> " << C << endl;
	if (!x.pusta() && !z.pusta()) {
		z.dodaj(x.top());
		x.usun();
	}
    hanoi(n-1, B, A, C, y, x, z);
  }
}

#define ROZMIAR 500000  // stala okreslajaca rozmiar aktualnie testowanych danych wejsciowych

int main() {
	srand(time(NULL));
	Stos stos1;
	StosStat stos2;
	StosDym stos3;
	stack<int> stos4;
	clock_t t1, t2;
/*
	t1 = clock();
	for (int i = 0; i < ROZMIAR; i++)
		stos1.dodaj(rand() % 10);
	t2 = clock();
	cout << "Sredni czas dodawania elementu do stosu wskaznikowego: " << (double)(t2-t1) * 1000 / (CLOCKS_PER_SEC * ROZMIAR) << " [ms]" << endl;

	t1 = clock();
	for (int i = 0; i < ROZMIAR; i++)
		stos2.push(rand() % 10);
	t2 = clock();
	cout << "Sredni czas dodawania elementu do stosu z tablica statyczna: " << (double)(t2-t1) * 1000 / (CLOCKS_PER_SEC * ROZMIAR) << " [ms]" << endl;
	
	t1 = clock();
	for (int i = 0; i < ROZMIAR; i++)
		stos3.push(rand() % 10);
	t2 = clock();
	cout << "Sredni czas dodawania elementu do stosu z tablica dynamiczna: " << (double)(t2-t1) * 1000 / (CLOCKS_PER_SEC * ROZMIAR) << " [ms]" << endl;
	
	t1 = clock();
	for (int i = 0; i < ROZMIAR; i++)
		stos4.push(rand() % 10);
	t2 = clock();
	cout << "Sredni czas dodawania elementu do stosu z biblioteki STL: " << (double)(t2-t1) * 1000 / (CLOCKS_PER_SEC * ROZMIAR) << " [ms]" << endl;
*/
	int n;
	Stos a, b, c;
	cout << "Podaj liczbe elementow na pierwszej wiezy: ";
	cin >> n;
	for (int i = n; i > 0; i--)
		a.dodaj(i);
	a.wyswietl();
	b.wyswietl();
	c.wyswietl();
	//cout << a.top() << endl;
	cout << "Oto twoj algorytm:" << endl;
	hanoi(n,'A','B','C', a, b, c);
	a.wyswietl();
	b.wyswietl();
	c.wyswietl();
	cin.get();
	cin.get();
	return 0;
}