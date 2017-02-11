package com.example.dawidperdek.androidzadanie2;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.Toast;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class DodawanieFarbyActivity extends Activity implements SeekBar.OnSeekBarChangeListener {
    SeekBar rgbR, rgbG, rgbB;
    Button kolor;
    EditText nazwa;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dodawanie_farby);

        rgbR = (SeekBar) findViewById(R.id.nowaFarbaR);
        rgbG = (SeekBar) findViewById(R.id.nowaFarbaG);
        rgbB = (SeekBar) findViewById(R.id.nowaFarbaB);
        kolor = (Button) findViewById(R.id.nowaFarbaKolor);

        rgbR.setOnSeekBarChangeListener(this);
        rgbG.setOnSeekBarChangeListener(this);
        rgbB.setOnSeekBarChangeListener(this);

        kolor.setBackgroundColor(Color.rgb(rgbR.getProgress(),rgbG.getProgress(),rgbB.getProgress()));
    }

    public void dodajNowaFarbe(View view) {
        nazwa = (EditText) findViewById(R.id.nazywanieFarby);
        rgbR = (SeekBar) findViewById(R.id.nowaFarbaR);
        rgbG = (SeekBar) findViewById(R.id.nowaFarbaG);
        rgbB = (SeekBar) findViewById(R.id.nowaFarbaB);
        if (nazwa.getText().length() < 1) {
            Toast.makeText(this,"Nazwa nie może być pusta.",Toast.LENGTH_SHORT).show();
            return;
        }
        try {
            PrintWriter fout = new PrintWriter(openFileOutput("farby",MODE_APPEND));
            fout.append(nazwa.getText()); fout.println();
            fout.append(Integer.toString(rgbR.getProgress())); fout.println();
            fout.append(Integer.toString(rgbG.getProgress())); fout.println();
            fout.append(Integer.toString(rgbB.getProgress())); fout.println();
            fout.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz","Brak pliku.");
        } catch (IOException e) {
            Log.d("xyz","Nieudany zapis do pliku.");
        }
        onBackPressed();
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        rgbR = (SeekBar) findViewById(R.id.nowaFarbaR);
        rgbG = (SeekBar) findViewById(R.id.nowaFarbaG);
        rgbB = (SeekBar) findViewById(R.id.nowaFarbaB);
        kolor = (Button) findViewById(R.id.nowaFarbaKolor);
        kolor.setBackgroundColor(Color.rgb(rgbR.getProgress(),rgbG.getProgress(),rgbB.getProgress()));
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
        rgbR = (SeekBar) findViewById(R.id.nowaFarbaR);
        rgbG = (SeekBar) findViewById(R.id.nowaFarbaG);
        rgbB = (SeekBar) findViewById(R.id.nowaFarbaB);
        kolor = (Button) findViewById(R.id.nowaFarbaKolor);
        kolor.setBackgroundColor(Color.rgb(rgbR.getProgress(),rgbG.getProgress(),rgbB.getProgress()));
    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
        rgbR = (SeekBar) findViewById(R.id.nowaFarbaR);
        rgbG = (SeekBar) findViewById(R.id.nowaFarbaG);
        rgbB = (SeekBar) findViewById(R.id.nowaFarbaB);
        kolor = (Button) findViewById(R.id.nowaFarbaKolor);
        kolor.setBackgroundColor(Color.rgb(rgbR.getProgress(),rgbG.getProgress(),rgbB.getProgress()));
    }
}
