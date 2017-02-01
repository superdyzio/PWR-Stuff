stos.out: stos.o opcje.o main.o tablica.o
	gcc stos.o opcje.o main.o tablica.o -lm -o stos.out

stos.o: stos.c stos.h
	gcc stos.h -c stos.c -c

opcje.o: opcje.c opcje.h
	gcc opcje.h -c opcje.c -c

main.o: main.c
	gcc main.c -c

tablica.o: tablica.h tablica.c
	gcc tablica.h -c tablica.c -c
