#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#define ROZMIAR 8192	// rozmiar bufora czytajacego plik z obrazem 

void main() {
	system("rm -f mapa.png");	// wymuszenie skasowania starego pliku
	system("touch mapa.png");	// stworzenie nowego pliku do mapowania
	int fd, plik;			// deskryptory plikow
	int i, iter, status, licznik;	// zmienne pomocznicze
	char nazwa[30], bufor[ROZMIAR];	// zmienne przechowujace nazwe pliku z obrazem i bufor z jego zawartoscia
	char* mapa;			// zmienna wskazujaca na mape
	struct stat filestat;		// struktura statyczna sluzaca do pobierania informacji o pliku

	int pid = fork();		// klonowanie procesu - tworzenie procesu potomnego
	if (pid == -1) {
		puts("Stworzenie procesu potomnego nie powiodlo sie.");
		return;
	}
	if (pid == 0) {			// jestesmy w dziecku
		do {	// oczekiwanie az w mapie pojawi sie jakis obraz
			sleep(2);
			stat("mapa.png",&filestat);
		} while (filestat.st_size == 0);
		execlp("display","display","-update","2","mapa.png",NULL);	// zamiana procesu potomnego w proces wyswietlajacy obraz
	}
	else {				// jestesmy w rodzicu
		do {
			puts("Podaj nazwe pliku z obrazem:");
			scanf("%s",nazwa);		// pobranie nazwy obrazu do zmapowania i wyswietlenia
			plik = open(nazwa,O_RDONLY);	// otwarcie pliku z obrazem
			if (plik != -1) {
				fstat(plik,&filestat);	// pobranie informacji o pliku z obrazem
				fd = open("mapa.png",O_RDWR);	// otwarcie deskryptora pliku mapujacego
				ftruncate(fd,filestat.st_size);	// dostosowanie rozmiaru pliku mapujacego do pliku mapowanego
				mapa = (char*) mmap(NULL,filestat.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
				iter = 0;	// iterator (na wypadek gdyby caly plik nie miescil sie do jednego bufora)
				while ((licznik = read(plik,bufor,ROZMIAR)) > 0)
					for (i = 0; i < licznik; i++) { 
						mapa[iter] = bufor[i];	// mapowanie pliku z obrazem znak po znaku
						iter++;
					}
				close(plik);	// zamkniecie deskryptorow plikow mapowanego oraz mapujacego
				close(fd);
			}
			else	// reakcja na nieudane otwarcie pliku z obrazem
				if (strcmp("koniec",nazwa) != 0)
					puts("Nie udalo sie otworzyc pliku.");
		} while (strcmp("koniec",nazwa) != 0);
	}
	return;
}
