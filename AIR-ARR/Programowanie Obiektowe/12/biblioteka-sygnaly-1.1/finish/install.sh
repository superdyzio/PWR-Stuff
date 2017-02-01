#!/bin/sh

TRGDIR="`grep ^prefix= ../config.log | sed 's/prefix=//; s/'"'"'//g'`"

TRGDIR="`eval echo $TRGDIR`"
EXECPREF="`grep ^exec_prefix= ../config.log | sed 's/prefix=//; s/'"'"'//g'`"

if echo "${EXECPREF}" | grep '\$' > /dev/null; then 
  EXECPREF="${TRGDIR}/bin"
fi

echo "    Lokalizacje zainstalowanych komponentow komponenty: "
echo 
echo "     Kartoteka plikow naglowkowych:  BlokSygnalowy.hh, ListaBlokow.hh, Sygnal.hh"
echo "         ${TRGDIR}/include"
echo
echo "     Kartoteka biblioteki libSygnaly.a"
echo "         ${TRGDIR}/lib/"
echo
echo "  =================================================="
echo