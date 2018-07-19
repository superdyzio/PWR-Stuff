//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*

*/
Serwer.gotowosc --> Serwer.odpowiedz

/*

*/
Sesja(1).otwarta --> Sesja(1).zamknieta

/*

*/
A[] forall (i : int[1,2]) forall (j: int[1,2]) Klient(i).polaczony && Klient(j).polaczony imply i == j

/*

*/
E[]Klient(1).polaczony imply Sesja(1).otwarta

/*

*/
E<>deadlock

/*

*/
E<> forall (i: int[1,2]) forall (j : int[1,2]) Klient(i).polaczony && Klient(j).polaczony imply i == j

/*

*/
E<>Klient(1).laczenie and Klient(2).laczenie
