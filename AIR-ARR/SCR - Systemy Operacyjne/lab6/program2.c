#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void main() {
	char bufor[30];	
	char nazwa[30];	
	int wPliku;		// do odczytywania danych
	FILE* plik;		// wczytywany plik

	int fifo;

	system("mkfifo fifo");	// tworzymy potok typu fifo

	do {
		puts("Podaj nazwe pliku: ");	
		scanf("%s", nazwa);
		plik = fopen(nazwa,"r");	// otworz obraz o podanej nazwie
		if (strcmp("koniec",nazwa) != 0 && plik == NULL) {	// nie udalo sie otworzyc pliku
			puts("Nie udalo sie otworzyc pliku.");
			return;
		}
		fifo = open("fifo",O_RDWR);	// otwieramy potok fifo
		if(strcmp("koniec",nazwa) != 0 && fifo == -1) {
			puts("Nie udalo sie utworzyc potoku FIFO.");
			return;
		}
		while (strcmp("koniec",nazwa) != 0 && fscanf(plik,"%s\n",bufor) > 0)
			write(fifo,strcat(bufor,"\n"),strlen(bufor));
		fclose(plik);
		close(fifo);
	} while (strcmp("koniec",nazwa) != 0);
}
