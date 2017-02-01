#include <stdio.h>
#include <math.h>
#define STOP 99
#define GRUPA 10
#define MIN -10
#define MAX 10
#define A 2
#define B 3

int main()
{ int x = 0;
  int y = 0;
  int n = 0;
  int p = 0;
  printf("Podaj dane wejsciowe:\n");
  while ( ((x<MIN) || (x>MAX) || (x==0)) && (x!=STOP) )
    { scanf("%i", &x);
      if ( (x>=MIN) && (x<=MAX) )
	if (n+1>GRUPA-1)
	  { if ( (p<A) || (p>B) )
	      printf("Bledna czestotliwosc.\n");
	    n = 0;
	    p = 0;
	  }
	else n++;
    }
  while ( (x!=STOP) && (y!=STOP) )
    { while ( ((y<MIN) || (y>MAX) || (y==0)) && (y!=STOP) )
	{ scanf("%i", &y);
	  if ( (y>=MIN) && (y<=MAX) )
	    if (n+1>GRUPA-1)
	      { if ( (p<A) || (p>B) )
		  printf("Bledna czestotliwosc.\n");
		n = 0;
		p = 0;
		x = 0;
		y = 0;
	      }
	    else n++;
	}
      if ( (y!=STOP) && (x*y<0) ) p++;
      x = y;
      y = 0;
    }
  return 0;  
}


/* na potrzeby testow zmieniam wartosci niektorych stalych symbolicznych
   A = 2    B = 4   GRUPA = 10
   uzywam rowniez funkcji printf na koncu kazdej petli oraz programu, aby wyswietlic
   wartosci poszczegolnych zmmiennych i porownac je z, wyliczonymi metoda recznej symulacji, poprawnymi wartosciami

 1. sprawdzenie czy program konczy dzialanie po wpisaniu liczby okreslonej stala symboliczna STOP (w tej chwili rownej 99)
      a) jako pierwszej danej
      b) jako drugiej danej
           dane wejsciowe: 0,99
      c) jako piatej danej (ogolnie pozniejszej) 
           dane wejsciowe: 0,0,0,0,99
    w kazdym wariancie oczekiwany rezultat to zakonczenie dzialania pracy programu polaczone z wyswietleniem komunikatu o blednej czestotliwosci przeciec
    oraz wyswietleniem wartosci zmiennych n i p, gdzie p=0 w kazdym przypadku, natomiast n:
      a) 0                 b) 1                  c) 4
    rezultat testu byl zgodny z oczekiwaniami, uzyskalem rowniez na tym etapie pewnosc ze liczba okreslona przez stala symboliczna STOP nie jest liczona
    jako poprawna dana

 2. sprawdzenie czy program "pilnuje" licznosci grup danych (czy liczy tylko dane z zadanego przedzialu)
      a) dane wejsciowe: 0,0,0,0,0,0,0,0,0,0,99
         oczekiwany rezultat: wypisanie wartosci zmiennych n=0 p=0 (bo rozpocznie sie nowa grupa), wyswietlenie komunikatu o blednej
                              czestotliwosci przeciec
      b) dane wejsciowe: 1,-1,1,-1,1,-1,1,-1,1,-1,99
         oczekiwany rezultat: wypisanie wartosci zmiennych n=0 p=0 x=0 (bo rozpocznie sie nowa grupa), wyswietlenie komunikatu o blednej
                              czestotliwosci przeciec
      c) dane wejsciowe: 5,10,-1,-45,6,8,1,-5,7,0,99
         oczekiwany rezultat: wypisanie wartosci zmiennych n=9 p=4, brak komunikatu (nie jest sprawdzana, bo grupa nie zostala wypelniona**PS)
      d) dane wejsciowe: 98,0,-4,-5,45,12,-11,5,2,-9,-10,10,88,9,10,1,99
         oczekiwany rezultat: wypisanie wartosci zmiennych n=1 p=0 (nowa grupa), wyswietlenie komunikatu o blednej czestotliwosci przeciec

    rezultaty testow byly zgodne z oczekiwaniami w kazdym podpunkcie

 3. sprawdzenie czy program zeruje zmienne po wypelnieniu grupy (widoczne przy okazji testu nr 2)
      a) przy wpisywaniu pierwszej zmiennej (w pierwszej, zawsze wykonywanej, petli)
         oczekiwany rezultat: wypisanie wartosci zmiennych n=0 p=0 - widoczne przy tescie nr 2a
      b) przy wpisywaniu drugiej zmiennej (w drugiej petli)
         oczekiwany rezultat: wypisanie wartosci zmiennych n=0 p=0 x=0 y=0 (x i y zerowane by uniknac znalezienia przeciecia na granicy grup) - widoczne przy
                              tescie nr 2b 

     rezultaty testow dalo sie wyciagnac z testu nr 2 - byly zgodne z oczekiwaniami

 4. sprawdzenie reakcji programu na bledny format danych wejsciowych
      a) dane wejsciowe: a
      b) dane wejsciowe: 1.4
     w obu tych przypadkach program zawiesza sie i wyswietla w nieskonczonosc
     komunikat o blednej czestotliwosci  
   
 5. sprawdzenie czy program poprawnie liczy liczbe przeciec zera
      a) dane wejsciowe: 1,0,-1,99
         oczekiwany rezultat: wypisanie wartosci zmiennych n=3 p=1
      b) dane wejsciowe: 1,0,0,-1,0,1,0,0,-1,99
         oczekiwany rezultat: wypisanie wartosci zmiennych n=9 p=3
      c) dane wejsciowe: 0,1,-11,10,-9,12,-12,4,0,0,99
         oczekiwany rezultat: wypisanie wartosci zmiennych n=7 p=2
      d) dane wejsciowe: 1,-1,1,-1,0,0,9,9,-7,10,1,-1,99
         oczekiwany rezultat:wyswietlenie komunikatu o blednej czestotliwosci (pierwsza grupa danych - p=5), wypisanie wartosci zmiennych n=2 p=1 (nowa grupa)
      e) dane wejsciowe: 0,0,0,0,0,0,0,0,1,-1,1,99
         oczekiwany rezultat:wyswietlenie komunikatu o blednej czestotliwosci (pierwsza grupa danych - p=1),  wypisanie wartosci zmiennych n=1 p=0 (nowa grupa, nie policzone przeciecie na skraju grup)
      f) dane wejsciowe: 0,-1,99
         oczekiwany rezultat: wypisanie wartosci zmiennych n=2 p=0 (nie liczone przeciecie z liczba STOP)
    
      rezultaty wszystkich testow byly zgodne z oczekiwaniami

Program dziala bardzo dobrze, prawidlowo oblicza wszystkie wartosci i zwraca uzytkownikowi prawdziwe wyniki. Zawiesza sie tylko w sytuacji podania danej
o niepoprawnym formacie. 

PS. zgodnie z pana odpowiedzia na mojego maila, czestotliwosc sprawdzam tylko na koncu kazdej grupy, pomijajac te czynnosc przy zakonczeniu programu
*/
