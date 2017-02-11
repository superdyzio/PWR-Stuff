package com.example.dawidperdek.androidzadanie2;

/**
 * Created by Dawid Perdek on 2016-04-14.
 */
public class Farba {
    public String nazwa;
    public boolean nowa;
    public int r, g, b;
    public Farba mix1, mix2;
    public double wsp;

    public Farba(String n, int r, int g, int b) {
        nowa = true;
        nazwa = n;
        this.r = r;
        this.g = g;
        this.b = b;
    }
}
