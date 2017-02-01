/*	Wartosci zwracane przez main:
	0 - poprawne zakonczenie dzialania
	1 - blad przy otwieraniu pliku z haslami
	2 - blad przy otwieraniu pliku slownika		*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <openssl/md5.h>

#define ILOSC_HASEL 1000
#define ILOSC_SLOWNIK 349900

/*	Struktura przeznaczona do komunikacji między wątkami oraz przechowywania zweryfikowanych kluczy.
	mutex - mutex
	wyniki - tablica zweryfikowanych kluczy
	wyn - tablica zlamanych hasel
	nput - zmienna informujaca o ilosci znalezionych kluczy		*/
struct {
	pthread_mutex_t	mutex;
	char	wyniki[ILOSC_HASEL][33], wyn[ILOSC_HASEL][33];
	int	nput;
} shared = { PTHREAD_MUTEX_INITIALIZER };

char *tab = NULL;		// Tablica słownika
char tabMD5[ILOSC_HASEL][32];	// Tablica kluczów do sprawdzenia

// Deklaracja wątków producenta i konsumenta
void *Prod1(void *), *Prod2(void *), *Prod3(void *), *Prod4(void *), *Prod5(void *), *Prod6(void *), *Kons(void *);	

// Wątek główny (nadzorujący) main
int main() {
	tab = (char*) malloc(ILOSC_SLOWNIK * 32);
	FILE *plik_MD5;		// otwierany plik haseł
	FILE *plik;		// otwierany plik słownika
   	char w_slownika[32];	// wyraz w słowniku
   	int i = 0;		// pomocnicza zmienna indeksujaca
   	char nazwa_pliku[20];	// nazwa pobieranego pliku haseł
   	char mdString[32];	// zmienna przechowująca jeden klucz
   	pthread_t produce[6], consume;	// deklaracja wątków

   	printf("Podaj nazwe pliku z haslami: ");
	scanf("%s", nazwa_pliku);
   	plik_MD5 = fopen(nazwa_pliku,"r");	// otwieranie pliku z hasłami
   	if (plik_MD5 == NULL) {
      		printf("Blad otwarcia pliku z haslami.\n");
      		return 1;
   	}
   	while (!feof(plik_MD5))	{			// czytamy, az dojdziemy do konca pliku
      		fscanf(plik_MD5, "%s", mdString);
      		strcpy(tabMD5[i], mdString);		// kopiuj string do tablicy globalnej
      		i++;
   	}
   	fclose(plik_MD5);	// zamknięcie pliku z hasłami
	i = 0;
   	plik = fopen("dictionary.txt","r");	// otwarcie pliku słownika
	if (plik == NULL) {
		printf("Blad otwarcia pliku slownika.\n");
	      	return 2;
	}
	while(!feof(plik)) {		// czytamy, az dojdziemy do konca pliku
		fscanf(plik, "%s", w_slownika);
	      	strcpy(&tab[i*32], w_slownika);
	      	i++;
              	if(i == ILOSC_SLOWNIK) 
			break;
	}
   	fclose(plik);	// zamknięcie pliku słownika

   	pthread_create(&consume, NULL, Kons, NULL);	// rozpoczęcie wątku konsumenta
   	pthread_create(&produce[0], NULL, Prod1, NULL);	// rozpoczęcie wątku producenta1
   	pthread_create(&produce[1], NULL, Prod2, NULL);	// rozpoczęcie wątku producenta2
   	pthread_create(&produce[2], NULL, Prod3, NULL);	// rozpoczęcie wątku producenta3
   	pthread_create(&produce[3], NULL, Prod4, NULL);	// rozpoczęcie wątku producenta4
   	pthread_create(&produce[4], NULL, Prod5, NULL);	// rozpoczęcie wątku producenta5
   	pthread_create(&produce[5], NULL, Prod6, NULL);	// rozpoczęcie wątku producenta6
   	pthread_join(produce[0], NULL);		// oczekiwanie na zakończenie wątku producentów
   	pthread_join(produce[1], NULL);
   	pthread_join(produce[2], NULL);
   	pthread_join(produce[3], NULL);
   	pthread_join(produce[4], NULL);
   	pthread_join(produce[5], NULL);
   	pthread_join(consume, NULL);			// oczekiwanie na zakończenie wątku konsumenta

	free(tab);
	return 0;
}


/*	Producent 1 - Hasło1Hasło	*/
void *Prod1(void *arg) {
	int i = 0, j, k;
	char tablica_i[32];
	char tablica_j[32];
	char polaczony[64];	// połączone hasło
	unsigned char digest[16];	// zmienne do transformacji stringa na klucz MD5
	char mdString[32],pom[32];

	for (i = 0; i < ILOSC_SLOWNIK; i++) {
		strcpy(tablica_i, &tab[i*32]);
		for (j = 0; j < ILOSC_SLOWNIK; j++) {
			strcpy(tablica_j, &tab[j*32]);
			tablica_i[0] = toupper(tablica_i[0]);
			tablica_j[0] = toupper(tablica_j[0]);
			strcpy(polaczony, tablica_i);
			strcat(polaczony, "1");
			strcat(polaczony, tablica_j);
	        	MD5_CTX ctx;	// zmienna MD5
	           	MD5_Init(&ctx);	// inicjalizacja generowania MD5
	           	MD5_Update(&ctx, polaczony, strlen(polaczony));
	           	MD5_Final(digest, &ctx);	// wygenerowanie MD5
	           	for (k = 0; k < 16; k++) {
	        		sprintf(&mdString[k*2], "%02x", (unsigned int)digest[k]); // zamiana wygenerowanej funkcji na ciąg znaków
	           	}
			strcpy(pom,polaczony);
	           	strcpy(polaczony, mdString);
	    	   	for (k = 0; k < ILOSC_HASEL; k++) { 
	    	   		if (strcmp(polaczony, tabMD5[k]) == 0) {
	    	   			printf("Znaleziono takie same klucze dla pozycji %i!\n", k);
	    	   			strcpy(shared.wyniki[shared.nput], tabMD5[k]);	// skopiowanie otrzymanego wyniku do tablicy
					strcpy(shared.wyn[shared.nput], pom);		// skopiowanie oryginalnego hasla
	    	   			shared.nput++;	// zwiększenie ilości znalezionych wyników
	    	   		}
	    	   	}
		}
	}
}

/*	Producent 2 - hasło#hasło	*/
void *Prod2(void *arg) {
	int i = 0, j, k;
	char tablica_i[32];
	char tablica_j[32];
	char polaczony[64];
	unsigned char digest[16];
	char mdString[32],pom[32];

	for (i = 0; i < ILOSC_SLOWNIK; i++) {
		strcpy(tablica_i, &tab[i*32]);
		for (j = 0; j < ILOSC_SLOWNIK; j++) {
			strcpy(tablica_j, &tab[j*32]);
			tablica_i[0] = tolower(tablica_i[0]);
			tablica_j[0] = tolower(tablica_j[0]);
			strcpy(polaczony, tablica_i);
		   	strcat(polaczony, "#");
			strcat(polaczony, tablica_j);
	           	MD5_CTX ctx;	// zmienna MD5
	           	MD5_Init(&ctx);	// inicjalizacja generowania MD5
	           	MD5_Update(&ctx, polaczony, strlen(polaczony));
	           	MD5_Final(digest, &ctx);	// wygenerowanie MD5
	           	for (k = 0; k < 16; k++) {
	        		sprintf(&mdString[k*2], "%02x", (unsigned int)digest[k]); // zamiana wygenerowanej funkcji na ciąg znaków
	           	}
			strcpy(pom,polaczony);
	           	strcpy(polaczony, mdString);
	    	   	for (k = 0; k < ILOSC_HASEL; k++) {
	    	   		if (strcmp(polaczony, tabMD5[k]) == 0) {
	    	   			printf("Znaleziono takie same klucze dla pozycji %i!\n", k);
	    	   			strcpy(shared.wyniki[shared.nput], tabMD5[k]);	// skopiowanie otrzymanego wyniku do tablicy
					strcpy(shared.wyn[shared.nput], pom);		// skopiowanie oryginalnego hasla
	    	   			shared.nput++;	// zwiększenie ilości znalezionych wyników
	    	   		}
	    	   	}
		}
	}
}

/*	Producent 3 - HasłoHasło	*/
void *Prod3(void *arg) {
	int i = 0, j, k;
	char tablica_i[32];
	char tablica_j[32];
	char polaczony[64];
	unsigned char digest[16];
	char mdString[32], pom[32];

	for (i = 0; i < ILOSC_SLOWNIK; i++) {
		strcpy(tablica_i, &tab[i*32]);
		for (j = 0; j < ILOSC_SLOWNIK; j++) {
			strcpy(tablica_j, &tab[j*32]);
			tablica_i[0] = toupper(tablica_i[0]);
			tablica_j[0] = toupper(tablica_j[0]);
			strcpy(polaczony, tablica_i);
			strcat(polaczony, tablica_j);
	           	MD5_CTX ctx;	// zmienna MD5
	           	MD5_Init(&ctx);	// inicjalizacja generowania MD5
	           	MD5_Update(&ctx, polaczony, strlen(polaczony));
	           	MD5_Final(digest, &ctx);	// wygenerowanie MD5
	           	for (k = 0; k < 16; k++) {
	        		sprintf(&mdString[k*2], "%02x", (unsigned int)digest[k]); // zamiana wygenerowanej funkcji na ciąg znaków
	           	}
			strcpy(pom,polaczony);
	           	strcpy(polaczony, mdString);
	    	   	for (k = 0; k < ILOSC_HASEL; k++) {
	    	   		if (strcmp(polaczony, tabMD5[k]) == 0) {
	    	   			printf("Znaleziono takie same klucze dla pozycji %i!\n", k);
	    	   			strcpy(shared.wyniki[shared.nput], tabMD5[k]);	// skopiowanie otrzymanego wyniku do tablicy
					strcpy(shared.wyn[shared.nput], pom);		// skopiowanie oryginalnego hasla
	    	   			shared.nput++;	// zwiększenie ilości znalezionych wyników
	    	   		}
	    	   	}
		}
	}
}

/*	Producent 4 - hasło+liczba	*/
void *Prod4(void *arg) {
	int i = 0, j, k, liczba;
	char liczba_str[32];	// liczba w stringu
	char tablica_i[32];
	char polaczony[64];	// połączone hasło
	unsigned char digest[16];	// zmienne do transformacji stringa na klucz MD5
	char mdString[32], pom[32];

	while (1) {	// nieskończona pętla
		for (i = 0; i < ILOSC_SLOWNIK; i++) {	// dla każdego hasła w słowniku
	   		strcpy(tablica_i, &tab[i*32]);
	   		for (j = 0; j < strlen(tablica_i); j++)	// zamień wszystkie litery na małe
	   			tablica_i[j] = tolower(tablica_i[j]);
	   		strcpy(polaczony, tablica_i);
	  		sprintf(liczba_str, "%i", liczba);	// dodaj do hasła liczbę
	   		strcat(polaczony, liczba_str);	
	   	   	MD5_CTX ctx;	// zmienna MD5
	   		MD5_Init(&ctx);	// inicjalizacja generowania MD5
	   		MD5_Update(&ctx, polaczony, strlen(polaczony));
	   		MD5_Final(digest, &ctx);	// wygenerowanie MD5
	   		for (k = 0; k < 16; k++) {
	   			sprintf(&mdString[k*2], "%02x", (unsigned int)digest[k]); // zamiana wygenerowanej funkcji na ciąg znaków
	   		}
			strcpy(pom,polaczony);
	   		strcpy(polaczony, mdString);
	   		for (k = 0; k < ILOSC_HASEL; k++) {
	   			if (strcmp(polaczony, tabMD5[k]) == 0) {
	   		    		printf("Znaleziono takie same klucze dla pozycji %i!\n", k);
	   		    		strcpy(shared.wyniki[shared.nput], tabMD5[k]);	// skopiowanie otrzymanego wyniku do tablicy
					strcpy(shared.wyn[shared.nput], pom);		// skopiowanie oryginalnego hasla
	   		    		shared.nput++;	// zwiększenie ilości znalezionych wyników
	   		   	}
			}	   		   
		}
		liczba++;
	}
}

/*	Producent 5 - Hasło+liczba	*/
void *Prod5(void *arg) {
	int i = 0, j, k, liczba;
	char liczba_str[32];
	char tablica_i[32];
	char polaczony[64];
	unsigned char digest[16];
	char mdString[32], pom[32];

	while (1) {
		for (i = 0; i < ILOSC_SLOWNIK; i++) {
	   		strcpy(tablica_i, &tab[i*32]);
			tablica_i[0] = toupper(tablica_i[0]);
	   		for (j = 1; j < strlen(tablica_i); j++)
	   			tablica_i[j] = tolower(tablica_i[j]);	   
	   		strcpy(polaczony, tablica_i);
	   		sprintf(liczba_str, "%i", liczba);
	   		strcat(polaczony, liczba_str);		   
	   	   	MD5_CTX ctx;	// zmienna MD5
	   		MD5_Init(&ctx);	// inicjalizacja generowania MD5
	   		MD5_Update(&ctx, polaczony, strlen(polaczony));
	   		MD5_Final(digest, &ctx);	// wygenerowanie MD5
	   		for (k = 0; k < 16; k++) {
	   			sprintf(&mdString[k*2], "%02x", (unsigned int)digest[k]); // zamiana wygenerowanej funkcji na ciąg znaków
	   		}
			strcpy(pom,polaczony);
	   		strcpy(polaczony, mdString);
	   		for (k = 0; k < ILOSC_HASEL; k++) {
	   			if (strcmp(polaczony, tabMD5[k]) == 0) {
	   		    		printf("Znaleziono takie same klucze dla pozycji %i!\n", k);
	   		    		strcpy(shared.wyniki[shared.nput], tabMD5[k]);	// skopiowanie otrzymanego wyniku do tablicy
					strcpy(shared.wyn[shared.nput], pom);		// skopiowanie oryginalnego hasla
	   		    		shared.nput++;	// zwiększenie ilości znalezionych wyników
	   		    	}
	   		}
		}
	   	liczba++;
	}
}

/*	Producent 6 - HASŁO+liczba	*/
void *Prod6(void *arg) {
	int i = 0, j, k, liczba;
	char liczba_str[32];
	char tablica_i[32];
	char polaczony[64];
	unsigned char digest[16];
	char mdString[32], pom[32];

	while (1) {
		for (i = 0; i < ILOSC_SLOWNIK; i++) {
	   		strcpy(tablica_i, &tab[i*32]);
	   		for (j = 0; j < strlen(tablica_i); j++)
	   			tablica_i[j] = toupper(tablica_i[j]);
			strcpy(polaczony, tablica_i);
	   		sprintf(liczba_str, "%i", liczba);
	   		strcat(polaczony, liczba_str);
	   	   	MD5_CTX ctx;	// zmienna MD5
	   		MD5_Init(&ctx);	// inicjalizacja generowania MD5
	   		MD5_Update(&ctx, polaczony, strlen(polaczony));
	   		MD5_Final(digest, &ctx);	// wygenerowanie MD5
	   		for (k = 0; k < 16; k++) {
	   			sprintf(&mdString[k*2], "%02x", (unsigned int)digest[k]); // zamiana wygenerowanej funkcji na ciąg znaków
	   		}
			strcpy(pom,polaczony);
	   		strcpy(polaczony, mdString);
	   		for (k = 0; k < ILOSC_HASEL; k++) {
	   			if (strcmp(polaczony, tabMD5[k]) == 0) {
	   				printf("Znaleziono takie same klucze dla pozycji %i!\n", k);
	   		    		strcpy(shared.wyniki[shared.nput], tabMD5[k]);	// skopiowanie otrzymanego wyniku do tablicy
					strcpy(shared.wyn[shared.nput], pom);		// skopiowanie oryginalnego hasla
	   		    		shared.nput++;	// zwiększenie ilości znalezionych wyników
	   			}
	   		}
		}
	   	liczba++;
	}
}

/*	Funkcja mutexowa używana do czekania na pozytywny wynik		*/
void consume_wait(int i) {
	for ( ; ; ) {
		pthread_mutex_lock(&shared.mutex);
		if (i < shared.nput) {
			pthread_mutex_unlock(&shared.mutex);
			return;
		}
		pthread_mutex_unlock(&shared.mutex);
	}
}

/*	Funkcja sygnału SIGHUP używana do wyświetlenia wyników		*/
void sygnal(int sig) {
	int i;
	printf("\n\nUzyskane wyniki:\n"); 
  	for (i = 0; i < shared.nput; i++)
      		printf("%i: %s\n", i, shared.wyniki[i]);
  	printf("\n\n"); 
}

/*	Funkcja konsumenta	*/
void *Kons(void *arg) {
	struct sigaction syg;		// deklaracja sygnału 
	syg.sa_handler = sygnal;
  	sigemptyset(&syg.sa_mask);
  	syg.sa_flags = 0;
  	sigaction(SIGHUP, &syg, NULL);  // funkcja odpowiedzi na sygnał
	int i;
	for (i = 0; i < ILOSC_HASEL; i++) {
		consume_wait(i);	// poczekaj na pozytywny wynik
		if (shared.wyniki[i] != "") {
			printf("Wyniki[%i] = %s\n", i, shared.wyniki[i]);	// wyświetl wynik
			printf("Oryginalne haslo[%i] = %s\n", i, shared.wyn[i]);
		}
	}
	return(NULL);
}
