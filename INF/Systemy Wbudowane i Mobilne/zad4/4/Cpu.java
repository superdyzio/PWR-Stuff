package com.example.dawidperdek.kolkoikrzyzyk;

import java.util.Random;

/**
 * Created by Dawid Perdek on 2016-04-18.
 */
public class Cpu {
    public boolean zwyciestwo, krzyzyk;

    public Cpu() {
        krzyzyk = false;
        zwyciestwo = false;
    }

    public int ruch(String[] p) {
        Random generator = new Random();
        int wynik = generator.nextInt(8);
        boolean ok = false;
        while (!ok) {
            if (p[wynik].length() < 1)
                ok = true;
            else
                wynik = generator.nextInt(8);
        }
        return wynik;
    }

    public void sprawdz(String[] p) {
        if (p[0].equals("O") && p[1].equals("O") && p[2].equals("O")) {
            zwyciestwo = true;
            return;
        }
        if (p[0].equals("O") && p[4].equals("O") && p[8].equals("O")) {
            zwyciestwo = true;
            return;
        }
        if (p[0].equals("O") && p[3].equals("O") && p[6].equals("O")) {
            zwyciestwo = true;
            return;
        }
        if (p[1].equals("O") && p[4].equals("O") && p[7].equals("O")) {
            zwyciestwo = true;
            return;
        }
        if (p[2].equals("O") && p[4].equals("O") && p[6].equals("O")) {
            zwyciestwo = true;
            return;
        }
        if (p[2].equals("O") && p[5].equals("O") && p[8].equals("O")) {
            zwyciestwo = true;
            return;
        }
        if (p[3].equals("O") && p[4].equals("O") && p[5].equals("O")) {
            zwyciestwo = true;
            return;
        }
        if (p[6].equals("O") && p[7].equals("O") && p[8].equals("O")) {
            zwyciestwo = true;
            return;
        }
    }
}
