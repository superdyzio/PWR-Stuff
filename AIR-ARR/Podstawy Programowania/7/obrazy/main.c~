#include "opcje.h"
#include "przetwarzanie.h"
#include "pliki.h"

/* Uruchomienie programu bez argumentów uruchamia tryb w którym podajemy polecenia z klawiatury. Muszą być one dokładnie takie jak podane
   poniżej, zatwierdzane klawiszem ENTER.
   Dostępne polecenia: wczytaj_plik, wprowadz_obraz, zapisz_plik, wypisz_obraz, wyswietl, progowanie, konturowanie, negatyw, rozmywanie, 
			wyostrzanie, splot, obracanie.
   Działanie programu można zakończyć wpisując 'koniec'. */

int main(int argc, char **argv) 
{
  w_opcje opcje;
  t_obraz obraz;
  int w=0;   /* zmienna do przechowywania tego co zwróci przetwarzaj_opcje, by nie wywoływać jej kilkukrotnie w programie */
  obraz.piksele=NULL;
  if (argc>1)
  { 
    switch (w = przetwarzaj_opcje(argc,argv,&opcje))
    {
	case -1:
		printf("Podano niepoprawną opcję.\n");
		return w;
	case -2:
		printf("Nie podano nazwy pliku.\n");
		return w;
	case -3:
		printf("Nie podano wartości progu/filtra.\n");
		return w;
	case -4:
		printf("Nie ma takiego pliku.\n");
		return w;
    } 
    if (opcje.plik_we != stdin)
	czytaj(opcje.plik_we,&obraz);
    else wczytaj(&obraz);
    if (opcje.progowanie == 1) progowanie(obraz,opcje.w_progu);
    if (opcje.negatyw == 1) negatyw(obraz);
    if (opcje.konturowanie == 1) 
	if ((obraz.wymx>1) && (obraz.wymy>1)) konturowanie(obraz);
	else printf("Obraz zbyt mały, by wykonać konturowanie.\n");
    if (opcje.rozmywanie == 1) 
	if ((obraz.wymx>2) && (obraz.wymy>2)) rozmywanie(obraz);
	else printf("Obraz zbyt mały, by wykonać rozmywanie.\n");
    if (opcje.wyostrzanie == 1) 
	if ((obraz.wymx>2) && (obraz.wymy>2)) wyostrzanie(obraz);
	else printf("Obraz zbyt mały, by wykonać wyostrzanie.\n");
    if (opcje.splot == 1) 
	if ((obraz.wymx>2) && (obraz.wymy>2)) splot(obraz,opcje);
	else printf("Obraz zbyt mały, by wykonać splot.\n");
    if (opcje.obracanie == 1) obracanie(&obraz);
    if (opcje.plik_wy != stdout)
	zapisz(opcje.plik_wy,obraz,opcje.nazwa_wy);
    else wypisz(obraz);
    if (opcje.wyswietlenie == 1) wyswietl(opcje.nazwa_wy);
  }
  else
  {
    char komenda[]={'\0'};
    char nazwa_we[]={'\0'};
    char nazwa_wy[]={'\0'};
    int poprawnie;
    while (strcmp(komenda,"koniec\n")!=0)
    {
	poprawnie=0;
	fputs("Komenda: ",stdout);
	fgets(komenda,30,stdin);
	if (strcmp(komenda,"\n")==0)       /* służy pomijaniu znaków nowej linii pozostałych po wczytywaniu nazw plików lub wartości progu */
		fgets(komenda,30,stdin);   /* czy macierzy filtru */
        if (strcmp(komenda,"progowanie\n")==0)
	{
		poprawnie=1;
		if (obraz.piksele!=NULL)
			progowanie(obraz,opcje.w_progu);
		else printf("Najpierw wczytaj obraz.\n");
	}
	if (strcmp(komenda,"negatyw\n")==0)
	{
		poprawnie=1;
		if (obraz.piksele!=NULL)
			negatyw(obraz);
		else printf("Najpierw wczytaj obraz.\n");
	}
	if (strcmp(komenda,"konturowanie\n")==0)
	{
		poprawnie=1;
		if (obraz.piksele!=NULL)
			if ((obraz.wymx>1) && (obraz.wymy>1))
				konturowanie(obraz);
			else printf("Obraz zbyt mały, by wykonać podane działanie.\n");
		else printf("Najpierw czytaj obraz.\n");
	}
	if (strcmp(komenda,"rozmywanie\n")==0)
	{
		poprawnie=1;
		if (obraz.piksele!=NULL)
			if ((obraz.wymx>2) && (obraz.wymy>2))
				rozmywanie(obraz);
			else printf("Obraz zbyt mały, by wykonać podane działanie.\n");
		else printf("Najpierw wczytaj obraz.\n");
	}
	if (strcmp(komenda,"wyostrzanie\n")==0)
	{
		poprawnie=1;
		if (obraz.piksele!=NULL)
			if ((obraz.wymx>2) && (obraz.wymy>2))
				wyostrzanie(obraz);
			else printf("Obraz zbyt mały, by wykonać podane działanie.\n");
		else printf("Najpierw wczytaj obraz.\n");
	}
	if (strcmp(komenda,"splot\n")==0)
	{
		poprawnie=1;
		if (obraz.piksele!=NULL)
		{
			if ((obraz.wymx>2) && (obraz.wymy>2))
			{
				int i;
				for (i=0; i<9; i++)
				{
					printf("Podaj %d element macierzy filtru: ",i+1);
					scanf("%d",&opcje.filtr[i]);;
				}		
				splot(obraz,opcje);
			}
			else printf("Obraz zbyt mały, by wykonać podane działanie.\n");
		}
		else printf("Najpierw wczytaj obraz.\n");
	}
	if (strcmp(komenda,"obracanie\n")==0)
	{
		poprawnie=1;
		if (obraz.piksele!=NULL)
			obracanie(&obraz);
		else printf("Najpierw wczytaj obraz.\n");
	}
	if (strcmp(komenda,"wczytaj_plik\n")==0)
	{	
		poprawnie=1;	
		printf("Podaj nazwe pliku: ");
		scanf("%s",nazwa_we);
		opcje.nazwa_we=nazwa_we;
		opcje.plik_we=fopen(opcje.nazwa_we,"r");
		czytaj(opcje.plik_we,&obraz);
	}
	if (strcmp(komenda,"wprowadz_obraz\n")==0)
	{
		poprawnie=1;
		wczytaj(&obraz);
	}
	if (strcmp(komenda,"zapisz_plik\n")==0)
	{
		poprawnie=1;		
		if (obraz.piksele!=NULL)       /* sprawdzenie czy obraz zostal wczytany */		
		{
			printf("Podaj nazwe pliku: ");
			scanf("%s",nazwa_wy);
			opcje.nazwa_wy=nazwa_wy;
			opcje.plik_wy=fopen(opcje.nazwa_wy,"w");
			zapisz(opcje.plik_wy,obraz,opcje.nazwa_wy);
		}
		else printf("Najpierw wczytaj obraz.\n");
	}
	if (strcmp(komenda,"wypisz_obraz\n")==0)
	{
		poprawnie=1;
		if (obraz.piksele!=NULL)     /* sprawdzenie czy obraz zostal wczytany */
			wypisz(obraz);
		else printf("Najpierw wczytaj obraz.\n");
	}	
	if (strcmp(komenda,"wyswietl\n")==0)
	{
		poprawnie=1;
		if (opcje.plik_we!=NULL)
			wyswietl(opcje.nazwa_we);
		else printf("Najpierw wczytaj obraz.\n");
	}
	if (strcmp(komenda,"koniec\n")==0) poprawnie=1;
	if (poprawnie==0) fputs("Niepoprawna komenda.\n",stdout);
    }
  }
  if (obraz.piksele != NULL)
    free(obraz.piksele);
  return 0;
}

/*          SPRAWOZDANIE          Dawid Perdek          13.12.12 r.     PN TP 18:55 - 20:35

Postanowiłem, zgodnie z Pana sugestią podzielić program na cztery moduły: przetwarzanie, pliki, opcje i main.
Od razu również stworzyłem sobie plik Makefile i przy każdej kompilacji z niego korzystałem.

Pracę zacząłem od modułu 'opcje' - właściwie tylko skopiowałem zawartość pliku 'opcje.c' załączonym do treści zadania. Przeanalizowałem jego
treść, sformatowałem tekst zgodnie z moimi preferencjami, tak aby kod był dla mnie w pełni czytelny i opatrzyłem go jeszcze kilkoma
własnymi komentarzami i modyfikacjami. Funkcję main z pliku opcje.c przeniosłem do mojego pliku main.c i dopisałem w niej linijkę wyświetlającą wartości pól opcje->negatyw, opcje-> konturowanie, opcje->wyswietlenie oraz opcje->progowanie, aby móc skontrolować czy wszystko
działa poprawnie.
	1) Komenda: ./program
	   Zgodnie z oczekiwaniami wyświetlone zostało -4 (brak pliku) oraz cztery zera.
	2) Komenda: ./program -w
	   Zgodnie z oczekiwaniami wyświetlone zostało -1 (niepoprawna opcja) oraz cztery zera.
	3) Komenda: ./program -w -k
	   Wszystko jak w przypadku drugim.
	4) Komenda: ./program -k -w
	   Zgodnie z oczekiwanimi, wartość opcje->konturowanie wynosiła 1, a zwrócona przez program wartość to znów -1 (niepoprawna opcja).
	5) Komenda: ./program -i
	   Zgodnie z oczekiwaniami wyświetlone zostało -2 (brak nazwy pliku) oraz cztery zera.
	6) Komenda: ./program -i Lena.pgm -k -n -o
	   Wszystko jak w przypadku piątym (brak nazwy pliku przy -o).
	7) Komenda: ./program -n -i Lena.pgm -o - -n
	   Zgodnie z oczekiwaniami wyświetlone zostało 0 (wyjście ustawione na stdout) oraz 1 jako wartość opcje->negatyw. Przy wielokrotnym
	   wystąpieniu danej opcji wywołania zostaje ona wykonana i tak jednokrotnie. Ten test dowodzi również dowolnej kolejności podawania
	   argumentów.
	8) Komenda: ./program -i Lena.pgm -i
	   Program zwrócił -2 (brak nazwy pliku), co oznacza, że w przypadku argumentów -i oraz -o ich ponowne podanie nadpisuje poprzednie.
	9) Komenda: ./program -i -
	   Zgodnie z oczekiwaniami wypisane zostają same zera, nie ma żadnego błędu. Pobieranie obrazu ze standardowego wejścia jednak nie 
	   odbywa się, ponieważ jeszcze nie istnieje odpowiedzialna za to funkcja.
	10) Po dopisaniu dodatkowych funkcji nie zaobserwowałem żadnych nieprawidłowości przy ich wywołaniu.
	11) Komenda: ./program -i Lena.pgm -f 1,2,3,4,5,6,7,8,9 -n
	    Zgodnie z oczekiwaniami macierz do filtru została wczytana poprawnie. Sprawdziłem również jak program zachowa się przy wpisaniu 
	    więcej niż 10 liczb oraz ich mniejszej ilości. W pierwszym przypadku wszystko, co po dziewiątej liczbie zostaje zignorowane,
	    natomiast w drugim macierz zostaje dopełniona zerami (działanie funkcji wyzeruj_opcje). W przypadku nie podania żadnych liczb
	    zwrócone zostanie -3 (brak wartości).

W module 'pliki' zawarłem funkcje wczytujące z pliku i standardowego strumienia oraz zapisujące do pliku i wypisujące na standardowy strumień.
Do tego doszła jeszcze funkcja wyświetlania. Aby sprawdzić działanie funkcji dotyczących operowania na plikach wpisałem w terminalu './program
-i Lena.pgm -o Lena2.pgm', a w main zawarłem fragment mający wczytać obraz z pliku, zapisać do drugiego (zgodnie z podanymi nazwami), a potem
wyświetlić plik Lena2.pgm. Wszystko zadziałało jak należy. Dla sprawdzenia poprawności działania funkcji 'wczytaj', zapisującej dane pochodzące
od użytkownika, wywołałem program komendą './program -i - -o Lena2.pgm' i wprowadziłem odpowiednie zmiany do 'maina'. Program pilnował 
poprawności wprowadzanych przeze mnie danych, po czym zapisał je w pliku o zadanej nazwie i wyświetlił. Bezpośrednio po tym teście, wpisałem
'./program -i Lena2.pgm -o -', a na terminalu wypisane zostało dokładnie to co przed chwilą sam do pliku zapisałem. Zatem operacje wej/wyj 
można uznać za działające poprawnie. Możliwe jest bezpośrednie nadpisywanie plików - można podać tę samą nazwę po opcjach -i oraz -o.

Sprawdzanie funkcji przetwarzania obrazu należy zacząć od odnotowania faktu, iż kolejność podawania argumentów wywołania jest dowolna i każdy 
jest liczony tylko jednokrotnie, lecz kolejność wywołania określonych funkcji przez program jest sztywna (zgodna z kolejnością wymieniania 
opcji w specyfikacji funkcji przetwarzaj_opcje) i wygląda następująco: określanie strumienia wejściowego -> progowanie -> negatyw ->
konturowanie -> rozmywanie -> wyostrzanie -> splot -> obracanie -> zapisywanie/wypisywanie (stdout) -> wyswietlanie.

Wszystkie funkcje testowałem na obrazku Lena.pgm, a następnie porównywałem z poprawnymi efektami działania programu Przetwarzanie Obrazów 1
(oprócz skalowania, wycinania i obracania - wyostrzanie i rozmywanie mogłem porównać wprowadzając do tamtego kodu odpowiednią macierz filtru).
Efekty każdej próby były prawidłowe. Do rozmywania użyłem filtru uśredniającego, natomiast do wyostrzania filtru górnoprzepustowego "usuń
średnią". Przy testowaniu funkcji splotu stosowałem różne inne macierze filtrów i porównywałem otrzymany obrazek z zamieszczonym w Internecie
przykładem działania danego filtru (przykłady oczywiście były prezentowane na obrazku Lena.pgm). Funkcje filtrujące opatrzone są normalizacją.
Funkcja wyświetlania działa bez zarzutu przy wywołaniu programu z argumentami. Przy obsłudze z poziomu powłoki nieustannie występuje błąd,
mówiący o niemożności wyświetlania obrazka o nazwie 'yswietl' (komenda do wyświetlania brzmi 'wyswietl'). Oprócz tego jednego problemu
wszystkie opcje wywołane z powłoki działają jak przy wywoływaniu przez argumenty programu - bez zarzutu.

Przy funkcjach konturowania i filtrowań (splot, rozmywanie, wyostrzanie) sprawdzany jest rozmiar obrazu, tak by konturowanie miało sens, a przy
filtrowaniu nie dało się wyjść poza obszar obrazka.

Funkcja obracania testowana była tylko dla kwadratowych obrazków i oprócz "zjadania" wartości piksela, który w wyniku obrotu miał się znaleźć 
na pozycji (0,0) działała dobrze. Zbyt późno jednak uświadomiłem sobie, że przecież nie wszystkie obrazki są kwadratowe i nie zdążyłem 
wprowadzić do niej udoskonaleń w tym kierunku. 

Dopiero dzisiaj, w dniu oddaniu programu, odkryłem ciekawą sprawę jaką jest to, że przy używaniu splotu i wyświetlaniu obrazka (program 
uruchamiany z argumentami wywołania) jest on wyświetlany poprawnie, natomiast zapisany plik jest "zepsuty". O dziwo, niemal identyczne funkcje
rozmywania i wyostrzania działają bez zarzutu i zapisują poprawny obrazek. "Zepsuty" plik w którym widać (w trybie tekstowym) ujemne piksele, da się jednak poprawnie nadpisać (nic nie zmieniając) i wyświetlić - komendą: ./program -i Lena2.pgm -o Lena2.pgm -d; gdzie Lena2.pgm to nazwa
uprzednio filtrowanego za pomocą splotu obrazu. W folderze jednak plik Lena2.pgm to wciąż czarny kwadracik, który w trybie tekstowym ukrywa 
całą masę ciekawych pikseli. 
*/
