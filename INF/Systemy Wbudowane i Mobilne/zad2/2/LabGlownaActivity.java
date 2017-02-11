package com.example.dawidperdek.myandroidapp2;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class LabGlownaActivity extends Activity {
    EditText l1, l2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lab_glowna);

        l1 = (EditText) findViewById(R.id.liczba1);
        l2 = (EditText) findViewById(R.id.liczba2);
    }


    public void klikJeden(View widok) {
        if (l1.hasFocus())
            l1.append("1");
        if (l2.hasFocus())
            l2.append("1");
    }

    public void klikDwa(View widok) {
        if (l1.hasFocus())
            l1.append("2");
        if (l2.hasFocus())
            l2.append("2");
    }

    public void klikTrzy(View widok) {
        if (l1.hasFocus())
            l1.append("3");
        if (l2.hasFocus())
            l2.append("3");
    }

    public void klikCztery(View widok) {
        if (l1.hasFocus())
            l1.append("4");
        if (l2.hasFocus())
            l2.append("4");
    }

    public void klikPiec(View widok) {
        if (l1.hasFocus())
            l1.append("5");
        if (l2.hasFocus())
            l2.append("5");
    }

    public void klikSzesc(View widok) {
        if (l1.hasFocus())
            l1.append("6");
        if (l2.hasFocus())
            l2.append("6");
    }

    public void klikSiedem(View widok) {
        if (l1.hasFocus())
            l1.append("7");
        if (l2.hasFocus())
            l2.append("7");
    }

    public void klikOsiem(View widok) {
        if (l1.hasFocus())
            l1.append("8");
        if (l2.hasFocus())
            l2.append("8");
    }

    public void klikDziewiec(View widok) {
        if (l1.hasFocus())
            l1.append("9");
        if (l2.hasFocus())
            l2.append("9");
    }

    public void klikZero(View widok) {
        if (l1.hasFocus())
            l1.append("0");
        if (l2.hasFocus())
            l2.append("0");
    }

    public void klikKropka(View widok) {
        if (l1.hasFocus())
            l1.append(".");
        if (l2.hasFocus())
            l2.append(".");
    }

    public void klikKasuj(View widok) {
        if (l1.hasFocus()) {
            String tekst = l1.getText().toString();
            if (l1.length() > 0)
                l1.setText(tekst.substring(0,tekst.length()-1));
        }
        if (l2.hasFocus()) {
            String tekst = l2.getText().toString();
            if (l2.length() > 0)
                l2.setText(tekst.substring(0,tekst.length()-1));
        }
    }

    public void zamknij(View widok) {
        finish();
    }

    public void przelicz(View widok) {
        Intent launch = new Intent(this,PrzeliczanieActivity.class);
        Bundle msg = new Bundle();
        if (l1.getText().toString().equals("") || l2.getText().toString().equals(""))
            Toast.makeText(this,"Wprowadź przedział argumentów funkcji!",Toast.LENGTH_SHORT).show();
        else {
            msg.putDouble("pierwsza", Double.parseDouble(l1.getText().toString()));
            msg.putDouble("druga", Double.parseDouble(l2.getText().toString()));
            launch.putExtras(msg);
            startActivity(launch);
        }
    }
}
