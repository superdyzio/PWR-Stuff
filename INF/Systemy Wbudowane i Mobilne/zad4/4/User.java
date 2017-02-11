package com.example.dawidperdek.kolkoikrzyzyk;

/**
 * Created by Dawid Perdek on 2016-04-18.
 */
public class User {
    public boolean zwyciestwo;

    public User() {
        zwyciestwo = false;
    }

    public void sprawdz(String[] p) {
        if (p[0].equals("X") && p[1].equals("X") && p[2].equals("X")) {
            zwyciestwo = true;
            return;
        }
        if (p[0].equals("X") && p[4].equals("X") && p[8].equals("X")) {
            zwyciestwo = true;
            return;
        }
        if (p[0].equals("X") && p[3].equals("X") && p[6].equals("X")) {
            zwyciestwo = true;
            return;
        }
        if (p[1].equals("X") && p[4].equals("X") && p[7].equals("X")) {
            zwyciestwo = true;
            return;
        }
        if (p[2].equals("X") && p[4].equals("X") && p[6].equals("X")) {
            zwyciestwo = true;
            return;
        }
        if (p[2].equals("X") && p[5].equals("X") && p[8].equals("X")) {
            zwyciestwo = true;
            return;
        }
        if (p[3].equals("X") && p[4].equals("X") && p[5].equals("X")) {
            zwyciestwo = true;
            return;
        }
        if (p[6].equals("X") && p[7].equals("X") && p[8].equals("X")) {
            zwyciestwo = true;
            return;
        }
    }
}
