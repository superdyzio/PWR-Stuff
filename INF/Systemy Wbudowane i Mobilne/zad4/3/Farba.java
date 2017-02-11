package com.example.dawidperdek.farbiarnia;

/**
 * Created by Dawid Perdek on 2016-04-14.
 */
public class Farba {
    public String nazwa;
    public int r, g, b;
    public boolean nowa;
    public String mix1, mix2;
    public double wsp;

    public Farba(String n, int r, int g, int b) {
        nowa = true;
        nazwa = n;
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public Farba(String n, int r, int g, int b, double wsp, String m1, String m2) {
        nowa = false;
        nazwa = n;
        this.r = r;
        this.g = g;
        this.b = b;
        this.wsp = wsp;
        mix1 = m1;
        mix2 = m2;
    }
}
