package com.example.dawidperdek.zad4app;

/**
 * Created by Dawid Perdek on 2016-05-09.
 */
public class Footballer extends Player {
    int bramki, asysty;

    public Footballer(String i, String n, int wg, int w, int id, int br, int as) {
        super(i,n,wg,w,id);
        bramki = br;
        asysty = as;
    }
}
