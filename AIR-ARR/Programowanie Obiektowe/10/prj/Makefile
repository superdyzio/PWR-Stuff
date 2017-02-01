CPPFLAGS=-pedantic -Wall -Iinc -I/home/Dokumenty/obiektowe/10/prj/inc

__start__: obj kalkulator
	./kalkulator

obj:
	mkdir obj

kalkulator: obj/zespolone.o obj/stosokalkulator.o obj/main.o
	g++ -Wall -o kalkulator obj/zespolone.o obj/stosokalkulator.o obj/main.o

obj/zespolone.o: src/zespolone.cpp inc/zespolone.hh
	g++ -c ${CPPFLAGS} -o obj/zespolone.o  src/zespolone.cpp

obj/stosokalkulator.o: src/stosokalkulator.cpp inc/stosokalkulator.hh inc/zespolone.hh
	g++ -c ${CPPFLAGS} -o obj/stosokalkulator.o  src/stosokalkulator.cpp
	
obj/main.o: src/main.cpp inc/zespolone.hh inc/stosokalkulator.hh
	g++ -c ${CPPFLAGS} -o obj/main.o  src/main.cpp
	
clean:
	rm -f kalkulator core obj/*
