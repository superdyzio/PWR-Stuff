#!/bin/bash
# inicjujemy domyslna wartosc maski do wyszukiwania plikow
maska="*.c"
# inicjujemy domyslna ilosc dni od ostatniej modyfikacji
ilosc_dni=-10
# inicjujemy domyslna nazwe archiwum do utworzenia
nazwa_archiwum="archiwum.tar"
# sprawdzenie opcji wywolania skryptu
while getopts "n:m:a:" option; do
	case $option in
		m )	maska=$OPTARG;;
		n )	ilosc_dni=$OPTARG;;
		a )	nazwa_archiwum=$OPTARG;;
	esac
done
# w przypadku wywolania bez argumentow bezposrednio pobieramy parametry od uzytkownika
if [ $# -eq 0 ]
then
	echo "Podaj maske: "
	read maska
	echo "Podaj ilosc dni (ze znakiem minus): "
	read ilosc_dni
	echo "Podaj nazwe archiwum: "
	read nazwa_archiwum
fi
# znajdujemy pliki - nazwy przechowywane w pliku lista
find $maska -mtime $ilosc_dni > lista
# pakujemy znalezione pliki
tar -cvf $nazwa_archiwum -T lista
# usuwamy plik listy
rm lista
