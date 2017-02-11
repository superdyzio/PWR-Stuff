__start__: obj ../libs/command4move.so 
	@echo "  Tworzenie wtyczki zakonczone."
	@echo

obj:
	mkdir obj

CPPFLAGS=-Wall -fPIC -pedantic -Iinc -I../inc
LDFLAGS=-Wall -shared


../libs/command4move.so: obj/command4move.o
	g++ ${LDFLAGS} -o ../libs/command4move.so obj/command4move.o
	@echo
	@echo "  Wtyczka dla polecenia 'Move' zostala utworzona."
	@echo


obj/command4move.o: src/command4move.cpp ../inc/command.hh\
                        inc/command4move.hh 
	g++ -c ${CPPFLAGS} -o obj/command4move.o src/command4move.cpp


clean:
	rm -f obj/*

cleanall: clean
	find . -name \*~ -print -exec rm {} \;
