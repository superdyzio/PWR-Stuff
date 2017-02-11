__start__: obj interp __plugin__
	export LD_LIBRARY_PATH="./libs"; ./interp

obj:
	mkdir obj

__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -pedantic -Iinc -std=c++11 -lreadline
LDFLAGS=-Wall

interp: obj/main.o obj/lacze_do_gnuplota.o obj/RobotMobilny.o obj/Biblioteka.o obj/ListaBibliotek.o obj/Menu.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/lacze_do_gnuplota.o obj/Biblioteka.o obj/ListaBibliotek.o obj/RobotMobilny.o obj/Menu.o -ldl

obj/main.o: src/main.cpp inc/command.hh inc/robotpose.hh inc/RobotMobilny.hh 
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/RobotMobilny.o: src/RobotMobilny.cpp inc/RobotMobilny.hh inc/robotpose.hh inc/command.hh
	g++  -c ${CPPFLAGS} -o obj/RobotMobilny.o src/RobotMobilny.cpp

obj/Biblioteka.o: src/Biblioteka.cpp inc/Biblioteka.hh inc/command.hh
	g++  -c ${CPPFLAGS} -o obj/Biblioteka.o src/Biblioteka.cpp

obj/ListaBibliotek.o: src/ListaBibliotek.cpp inc/ListaBibliotek.hh inc/command.hh
	g++  -c ${CPPFLAGS} -o obj/ListaBibliotek.o src/ListaBibliotek.cpp

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hh
	g++  -c ${CPPFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/Menu.o: src/menu.cpp inc/menu.hh inc/command.hh inc/robotpose.hh
	g++  -c ${CPPFLAGS} -o obj/Menu.o src/menu.cpp

clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
