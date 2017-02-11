package com.example.dawidperdek.zad4app;

/**
 * Created by Dawid Perdek on 2016-05-09.
 */
public class Basketballer extends Player {
    int punkty, zbiorki;
    double ocena;

    public Basketballer(String i, String n, int wg, int w, int id, int pkt, int zb, double o) {
        super(i, n, wg, w, id);
        punkty = pkt;
        zbiorki = zb;
        ocena = o;
    }
}
