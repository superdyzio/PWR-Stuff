package com.example.dawidperdek.kolkoikrzyzyk;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
    User gracz;
    Cpu komp;
    Button p1, p2, p3, p4, p5, p6, p7, p8, p9;
    String[] plansza;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        plansza = new String[9];
        for (int i = 0; i < 9; i++)
            plansza[i] = "";

        komp = new Cpu();
        gracz = new User();
        p1 = (Button) findViewById(R.id.button1);
        p2 = (Button) findViewById(R.id.button2);
        p3 = (Button) findViewById(R.id.button3);
        p4 = (Button) findViewById(R.id.button4);
        p5 = (Button) findViewById(R.id.button5);
        p6 = (Button) findViewById(R.id.button6);
        p7 = (Button) findViewById(R.id.button7);
        p8 = (Button) findViewById(R.id.button8);
        p9 = (Button) findViewById(R.id.button9);
    }

    public void planszaRuch(View view) {
        if (czyKoniec() || gracz.zwyciestwo || komp.zwyciestwo)
            return;
        boolean odp = false;
        Button klikniety, komputera;
        int indeks = -1;
        Log.d("xyz",Integer.toString(view.getId()));
        switch (view.getId()) {
            case R.id.button1:
                klikniety = (Button) findViewById(R.id.button1);
                indeks = 1;
                break;
            case R.id.button2:
                klikniety = (Button) findViewById(R.id.button2);
                indeks = 2;
                break;
            case R.id.button3:
                klikniety = (Button) findViewById(R.id.button3);
                indeks = 3;
                break;
            case R.id.button4:
                klikniety = (Button) findViewById(R.id.button4);
                indeks = 4;
                break;
            case R.id.button5:
                klikniety = (Button) findViewById(R.id.button5);
                indeks = 5;
                break;
            case R.id.button6:
                klikniety = (Button) findViewById(R.id.button6);
                indeks = 6;
                break;
            case R.id.button7:
                klikniety = (Button) findViewById(R.id.button7);
                indeks = 7;
                break;
            case R.id.button8:
                klikniety = (Button) findViewById(R.id.button8);
                indeks = 8;
                break;
            case R.id.button9:
                klikniety = (Button) findViewById(R.id.button9);
                indeks = 9;
                break;
            default:
                klikniety = null;
                break;
        }

        if (klikniety.getText().length() < 1) {
            klikniety.setText("X");
            plansza[indeks-1] = "X";
            odp = true;
        }
        else {
            Toast.makeText(this,"Pole zajęte!",Toast.LENGTH_SHORT).show();
            return;
        }
        gracz.sprawdz(plansza);
        if (odp && !gracz.zwyciestwo) {
            int ruch = komp.ruch(plansza);
//            if (ruch == -1) {
//                if (!gracz.zwyciestwo && !komp.zwyciestwo)
//                    Toast.makeText(this, "Remis!", Toast.LENGTH_SHORT).show();
//                else if (gracz.zwyciestwo)
//                    Toast.makeText(this, "Wygrałeś!", Toast.LENGTH_SHORT).show();
//                else if (komp.zwyciestwo)
//                    Toast.makeText(this, "Przegrałeś!", Toast.LENGTH_SHORT).show();
//            }
//            else {
                plansza[ruch] = "O";
                switch (ruch) {
                    case 0:
                        komputera = (Button) findViewById(R.id.button1);
                        break;
                    case 1:
                        komputera= (Button) findViewById(R.id.button2);
                        break;
                    case 2:
                        komputera = (Button) findViewById(R.id.button3);
                        break;
                    case 3:
                        komputera = (Button) findViewById(R.id.button4);
                        break;
                    case 4:
                        komputera = (Button) findViewById(R.id.button5);
                        break;
                    case 5:
                        komputera = (Button) findViewById(R.id.button6);
                        break;
                    case 6:
                        komputera = (Button) findViewById(R.id.button7);
                        break;
                    case 7:
                        komputera = (Button) findViewById(R.id.button8);
                        break;
                    case 8:
                        komputera = (Button) findViewById(R.id.button9);
                        break;
                    default:
                        komputera = null;
                        break;
                }
                komputera.setText("O");
            }
//        }
        komp.sprawdz(plansza);
        if (czyKoniec() || gracz.zwyciestwo || komp.zwyciestwo) {
            if (!gracz.zwyciestwo && !komp.zwyciestwo)
                Toast.makeText(this, "Remis!", Toast.LENGTH_SHORT).show();
            else if (gracz.zwyciestwo)
                Toast.makeText(this, "Wygrałeś!", Toast.LENGTH_SHORT).show();
            else if (komp.zwyciestwo)
                Toast.makeText(this, "Przegrałeś!", Toast.LENGTH_SHORT).show();
        }
    }

    public boolean czyKoniec() {
        for (int i = 0; i < 9; i++)
            if (plansza[i].length() < 1)
                return false;
        return true;
    }

    public void reset(View view) {
        for (int i = 0; i < 9; i++)
            plansza[i] = "";
        komp.zwyciestwo = false;
        gracz.zwyciestwo = false;
        p1 = (Button) findViewById(R.id.button1);
        p2 = (Button) findViewById(R.id.button2);
        p3 = (Button) findViewById(R.id.button3);
        p4 = (Button) findViewById(R.id.button4);
        p5 = (Button) findViewById(R.id.button5);
        p6 = (Button) findViewById(R.id.button6);
        p7 = (Button) findViewById(R.id.button7);
        p8 = (Button) findViewById(R.id.button8);
        p9 = (Button) findViewById(R.id.button9);
        p1.setText("");
        p2.setText("");
        p3.setText("");
        p4.setText("");
        p5.setText("");
        p6.setText("");
        p7.setText("");
        p8.setText("");
        p9.setText("");
    }
}
