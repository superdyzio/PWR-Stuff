
KOM=gcc

__start__: sortowanie_liczb
	./sortowanie_liczb

sortowanie_liczb: obj obj/liczby.o obj/main.o
	$(KOM) -Wall -o sortowanie_liczb obj/liczby.o obj/main.o

obj/liczby.o: inc/liczby.h src/liczby.c
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/liczby.o src/liczby.c

obj/main.o: inc/liczby.h src/main.c
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/main.o src/main.c

obj:
	mkdir obj

clean:
	rm -f obj/* sortowanie_liczb

help:
	@echo
	@echo  " Dostarczony plik Makefile pozwala wywolac polecenie make"
	@echo  " w nastepujacy sposob:"
	@echo  
	@echo  "  make        - powoduje kompilacje, konsolidacje i uruchomienie programu,"
	@echo  "  make clean  - powoduj usuniecie produktow komilacji i konsolidacji."
	@echo
