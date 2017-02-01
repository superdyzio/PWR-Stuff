#!/bin/bash
# inicjujemy domyslna wartosc maski wyszukiwania plikow
maska="*.c"
# inicjujemy domyslna ilosc dni od ostatniej modyfikacji
ilosc_dni=-10
# inicjujemy domyslna nazwe archiwum
nazwa_archiwum="archiwum.tar"
# sprawdzamy opcje wywolania i pobieramy argumenty
while getopts "n:m:a:" option; do
	case $option in
		m )	maska=$OPTARG;;
		n )	ilosc_dni=$OPTARG;;
		a )	nazwa_archiwum=$OPTARG;;
	esac
done
# w przypadku braku argumentow wywolania pobieramy parametry bezposrednio od uzytkownika przy uzyciu okienek dialogowych programu zenity
if [ $# -eq 0 ]
then
	maska=$(zenity --entry --title "Pobieranie maski wyszukiwania" --text "Podaj maske:" --entry-text "*.c")
	ilosc_dni=$(zenity --entry --title "Pobieranie ilosci dni od ostatniej modyfikacji" --text "Podaj ilosc dni od ostatniej modyfikacji (ze znakiem minus):" --entry-text -10)
	nazwa_archiwum=$(zenity --entry --title "Pobieranie nazwy archiwum do utworzenia" --text "Podaj nazwe archiwum:" --entry-text "archiwum.tar")
fi
# wynajdujemy pliki - ich lista jest zapamietana w pliku lista
find $maska -mtime $ilosc_dni > lista
# pakujemy pliki
tar -cvf $nazwa_archiwum -T lista
# usuwamy plik listy
rm lista

