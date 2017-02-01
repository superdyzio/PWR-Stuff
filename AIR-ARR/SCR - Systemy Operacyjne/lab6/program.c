#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void main() {
	pid_t pid;		// nr PID zwrocony przez funkcje fork()
	int potok_fd[2];	// potok o koncu piszacym i czytajacym
	char bufor[BUFSIZ];
	char nazwa[30];
	int wPliku;		// do odczytywania danych
	int obraz;		// wczytywany obraz

	pipe(potok_fd);

	if ((pid = fork()) == -1)	
		return;
	if( pid != 0 ) {	// jestesmy w rodzicu
		puts("Podaj nazwe pliku: ");	// pobieramy nazwe pliku przed zamknieciem standardowego wyjscia
		scanf("%s", nazwa);
		obraz = open(nazwa, O_RDONLY);	// otworz obraz o podanej nazwie
		if (obraz == -1) {	// otwarcie pliku nie powiodlo sie
		        puts("Plik nie istnieje.");
		        return;
		}
		close(1);			// zamykamy standardowe wyjscie
		dup(potok_fd[1]);		// ustawiamy koniec potoku jako standardowe wyjscie
		close(potok_fd[1]);		// zamykamy piszacy koniec potoku
		close(potok_fd[0]);		// zamykamy czytajacy koniec potoku
		while((wPliku = read(obraz,bufor,BUFSIZ)) > 0)  // sukcesywne przepisywanie zawartosci pliku do potoku	
			write(1,bufor,wPliku);
		close(obraz);	// zamykamy plik
	}
	if( pid == 0 ) {	// jestesmy w dziecku
		close(0);		// zamykamy wejscie standardowe
		dup(potok_fd[0]);	// ustawiamy czytajacy koniec potoku jako wejscie standardowe
		close(potok_fd[0]);	// zamykamy czytajacy koniec potoku
		close(potok_fd[1]);	// zamykamy piszacy koniec potoku
		if(execlp("display", "display", NULL) == -1);  // uruchamiamy program display z wejsciem na wejsciu standardowym
			return;
	}
}

