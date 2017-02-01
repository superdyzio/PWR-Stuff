#include "stos.h"
#include "opcje.h"
//#include "tablica.h"


/* Program wyposażony jest w dwa przeciwstawne mechanizmy działania - rozwiązanie statyczne (tablica) oraz dynamiczne (stosy). Aby uruchomić te
   pierwsze należy odkomentować 3. i 13. linijkę oraz zakomentować linie 2. i 12.. Aby uruchomić dynamiczną wersję należy wykonać działania
   odwrotne. */ 

void main()
{
  kalkulator();
  //tablice()
}



/*          Dawid Perdek         PN TP 18.55 - 20.35
data utworzenia programu: 21.01.2013
nazwa programu i wersja: Kalkulator RNP v. 1
brak modyfikacji i zmian

Do efektywnego korzystania z programu wymagana jest znajomość odwrotnej notacji polskiej. 

Możliwe do wprowadzania komendy:
	+, -, /, *	odpowiednio komendy dodawania, odejmowania, dzielenia całkowitoliczbowego, mnożenia
	?		wyświetlenie stosu
	#		usunięcie elementu z wierzchu stosu
	$		zamienienie miejscami dwóch wierzchnich elementów
	&		zdublowanie wierzchniego elementu
	m		przeniesienie wierzchniego elementu na dodatkowy stos pamięci
	r		usuwanie elementu z wierzchu stosu pamięci
	d		przeniesienie wierzchniego elementu ze stosu pamięci na wierzch stosu głównego
	t		wyświetlenie stosu pamięci
	^		podnoszenie przedostatniej liczby ze stosu do potęgi wierzchołka stosu
	p		wyciąganie pierwiastka drugiego stopnia z wierzchołka stosu
	q		wyłączenie programu

Oprócz komend można wprowadzać liczby całkowite: dodatnie bez znaku, ujemne z minusem bezpośrednio przed liczbą.

Komendy mogą być podawane w jednej linii, oddzielane spacją.

Testy:

1) Komenda: 3 2 - 4 + 2 ^ p ?
	Spodziewanym wynikiem działania jest 5 i wyświetlenie stosu. Wyświetla się 5 -> NULL, więc efekt jest zgodny z oczekiwaniem.

2) Komenda: 5 6 * / ?
	Spodziewanym wynikiem działania jest 30, wypisanie komunikatu o za małej liczbie elementów, aby wykonać dzielenie oraz wyświetlenie
	stosu w postaci 30 -> NULL. Wszystko zgodnie z planem.

3) Komenda: 6 3 / ? # ? #
	Spodziewanym wynikiem jest 2 i wyświetlenie stosu w postaci 2 -> NULL, po czym usunięty powinien zostać ostatni element i wyświetlić
	się pusty stos. Potem spodziewany jest jeszcze komunikat o tym, że stos jest pusty (nie ma co z niego usunąć). Wszystko poszło
	zgodnie z planem.

4) Komenda: 4 2 ? $ ? & ?
	Spodziewanym wynikiem jest wyświetlenie stosu postaci 2 -> 4 -> NULL, zamienienie liczb miejscami, ponowne wyświetlenie, a na koniec
	wyświetlenie stosu postaci 4 -> 4 -> 2 -> NULL. Efekt zgodny z planem.

5) Komenda: r 4 m t d ? t
	Spodziewane jest wyświetlenie komunikatu, że drugi stos jest pusty, potem przeniesienie na drugi stos liczby 4 i wyświetlenie go,
	potem wrócenie tejże 4 na pierwszy stos i wyświetlenie obu stosów - pierwszego z liczbą 4, drugiego pustego. Efekt zgodny z planem.

Po każdym z testów wyłączałem program komendą 'q'.
*/
