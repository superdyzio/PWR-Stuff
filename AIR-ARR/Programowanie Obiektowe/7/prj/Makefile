PROG=Rozwiazanie


__start__: obj ${PROG} 
	./${PROG} < row_liniowe_format1.dat

obj:
	mkdir obj

${PROG}: obj/zespolone.o obj/symbole.o obj/liczba.o obj/macierz.o obj/wektor.o obj/uklad.o obj/main.o
	g++ -Wall -o ${PROG} obj/zespolone.o obj/symbole.o obj/liczba.o obj/macierz.o obj/wektor.o obj/uklad.o obj/main.o

obj/uklad.o: inc/uklad.hh inc/wektor.hh inc/macierz.hh inc/typ.hh inc/symbole.hh inc/zespolone.hh inc/liczba.hh src/uklad.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/uklad.o src/uklad.cpp

obj/wektor.o: inc/wektor.hh inc/macierz.hh inc/typ.hh inc/symbole.hh inc/zespolone.hh inc/liczba.hh src/wektor.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/wektor.o src/wektor.cpp

obj/macierz.o: inc/wektor.hh inc/macierz.hh inc/typ.hh inc/symbole.hh inc/zespolone.hh inc/liczba.hh src/macierz.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/macierz.o src/macierz.cpp

obj/liczba.o: inc/liczba.hh src/liczba.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/liczba.o src/liczba.cpp

obj/symbole.o: inc/symbole.hh inc/typ.hh src/symbole.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/symbole.o src/symbole.cpp

obj/zespolone.o: inc/zespolone.hh inc/typ.hh src/zespolone.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/zespolone.o src/zespolone.cpp

obj/main.o: inc/zespolone.hh inc/symbole.hh inc/liczba.hh inc/typ.hh inc/wektor.hh inc/macierz.hh inc/uklad.hh src/main.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp



#^^^^^^^^^^                                 ^^^^^^^^^^^^^^^#
# Powyzej  jest miejsce na wlasne wpisy dla nowych modulow #
############################################################

clean:
	rm -f ${PROG} obj/*

help:
	@echo "\n\
 Ten plik pozwala wywolac polecenie make z nastepujacymi\n\
 podcelami:                                             \n\
                                                        \n\
   make            - kompilacja, konsolidacja i uruchomienie\n\
                     programu z aktualnym typem danych.\n\
   make double     - wymuszenie zmiany typu danych na double oraz\n\
                     kompilacja, konsolidacja i uruchomienie programu.\n\
   make Symbol     - wymuszenie zmiany typu danych na Symbol oraz\n\
                     kompilacja, konsolidacja i uruchomienie programu.\n\
   make Zespolona - wymuszenie zmiany typu danych na\n\
                     liczbaaZespolona oraz kompilacja, konsolidacja\n\
                     i uruchomienie programu.\n\
   make clean      - usuwa produkcji kompilacji i sam program.\n\
   make help       - wyswietla te inforacje.\n\
\n\
"

############################################################
#   Tego co jest ponizej nie nalezy modyfikowac.           #
#                                                          #

double: __utworz_typ_double__ clean __start__

Symbol: __utworz_typ_symbol__ clean __start__

Zespolona: __utworz_typ_lzespolona__ clean __start__

__utworz_typ_double__:
	@echo \
"\n\
#ifndef TYP_HH\n\
#define TYP_HH\n\
#define TYP double\n\
#define NAZWA_TYPU  \"double\"\n\
#endif\n\
" > inc/typ.hh
	cp dane/rownanie_liniowe_double.dat row_liniowe_format1.dat


__utworz_typ_symbol__:
	@echo \
"\n\
#ifndef TYP_HH\n\
#define TYP_HH\n\
#define TYP Symbol\n\
#define NAZWA_TYPU  \"Symbol\"\n\
#endif\n\
" > inc/typ.hh
	cp dane/rownanie_liniowe_Symbol.dat row_liniowe_format1.dat



__utworz_typ_lzespolona__:
	@echo \
"\n\
#ifndef TYP_HH\n\
#define TYP_HH\n\
#define TYP Zespolona\n\
#define NAZWA_TYPU  \"Zespolona\"\n\
#endif\n\
" > inc/typ.hh
	cp dane/rownanie_liniowe_LiczbyZespolone.dat row_liniowe_format1.dat


