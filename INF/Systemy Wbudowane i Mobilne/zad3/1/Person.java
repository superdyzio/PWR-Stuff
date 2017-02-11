package com.example.dawidperdek.androidzadanie2;

/**
 * Created by Dawid Perdek on 2016-04-18.
 */
public class Person {
    public String imie, nazwisko, kraj;
    public boolean student, plec;
    public double spryt;
    public int rok;

    public Person(String i, String n, int r, boolean p, String k, boolean st, double sp) {
        imie = i;
        nazwisko = n;
        kraj = k;
        student = st;
        plec = p;
        spryt = sp;
        rok = r;
    }
}
