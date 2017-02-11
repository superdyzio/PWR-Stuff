package com.example.dawidperdek.zad4app;

/**
 * Created by Dawid Perdek on 2016-05-09.
 */
public class Player {
    public String imie, nazwisko;
    public int waga, wzrost, id;

    public Player(String i, String n, int wg, int w, int id) {
        imie = i;
        nazwisko = n;
        waga = wg;
        wzrost = w;
        this.id = id;
    }
}
