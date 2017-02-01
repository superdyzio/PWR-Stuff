
KOM=g++

__start__: operacje_na_symbolach
	./operacje_na_symbolach

operacje_na_symbolach: obj obj/dzialania.o obj/main.o obj/test.o
	$(KOM) -Wall -o operacje_na_symbolach obj/dzialania.o obj/main.o obj/test.o

obj/dzialania.o: inc/dzialania.hh src/dzialania.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/dzialania.o src/dzialania.cpp

obj/main.o: inc/dzialania.hh src/main.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp

obj/test.o: inc/test.hh src/test.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/test.o src/test.cpp

obj:
	mkdir obj

clean:
	rm -f obj/* operacje_na_symbolach

help:
	@echo
	@echo  " Dostarczony plik Makefile pozwala wywolac polecenie make"
	@echo  " w nastepujacy sposob:"
	@echo  
	@echo  "  make        - powoduje kompilacje, konsolidacje i uruchomienie programu,"
	@echo  "  make clean  - powoduj usuniecie produktow komilacji i konsolidacji."
	@echo
