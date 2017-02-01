program.out: main.o opcje.o pliki.o przetwarzanie.o
	gcc main.o opcje.o pliki.o przetwarzanie.o -o program

opcje.o: opcje.c opcje.h
	gcc opcje.h -c opcje.c -c

pliki.o: pliki.c pliki.h
	gcc pliki.h -c pliki.c -c

przetwarzanie.o: przetwarzanie.c przetwarzanie.h
	gcc przetwarzanie.h -c przetwarzanie.c -c

main.o: main.c
	gcc main.c -c
