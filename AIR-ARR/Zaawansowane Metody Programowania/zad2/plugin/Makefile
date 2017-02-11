__start__: obj ../libs/command4move.so ../libs/command4rotate.so ../libs/command4turn.so ../libs/grasper.so
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

../libs/command4rotate.so: obj/command4rotate.o
	g++ ${LDFLAGS} -o ../libs/command4rotate.so obj/command4rotate.o
	@echo
	@echo "  Wtyczka dla polecenia 'Rotate' zostala utworzona."
	@echo

../libs/command4turn.so: obj/command4turn.o
	g++ ${LDFLAGS} -o ../libs/command4turn.so obj/command4turn.o
	@echo
	@echo "  Wtyczka dla polecenia 'Turn' zostala utworzona."
	@echo

../libs/grasper.so: obj/grasper.o
	g++ ${LDFLAGS} -o ../libs/grasper.so obj/grasper.o
	@echo
	@echo "  Wtyczka dla chwtyka zostala utworzona."
	@echo

obj/command4move.o: src/command4move.cpp ../inc/command.hh inc/command4move.hh 
	g++ -c ${CPPFLAGS} -o obj/command4move.o src/command4move.cpp

obj/command4rotate.o: src/command4rotate.cpp ../inc/command.hh inc/command4rotate.hh 
	g++ -c ${CPPFLAGS} -o obj/command4rotate.o src/command4rotate.cpp

obj/command4turn.o: src/command4turn.cpp ../inc/command.hh inc/command4turn.hh 
	g++ -c ${CPPFLAGS} -o obj/command4turn.o src/command4turn.cpp

obj/grasper.o: src/grasper.cpp ../inc/command.hh inc/grasper.hh 
	g++ -c ${CPPFLAGS} -o obj/grasper.o src/grasper.cpp

clean:
	rm -f obj/*

cleanall: clean
	find . -name \*~ -print -exec rm {} \;
