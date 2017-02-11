package com.example.dawidperdek.androidzadanie2;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ExpandableListView;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class MieszanieActivity extends Activity {
    ListView listafarb1, listafarb2;
    CustomListViewAdapter adapter;
    ArrayList<Farba> farby;
    TextView nazwa1, nazwa2;
    SeekBar wspolczynnik;
    EditText nazwa;
    Farba f1, f2;
    double r, g, b, wsp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mieszanie);
        listafarb1 = (ListView) findViewById(R.id.listViewMieszanieFarba1);
        listafarb2 = (ListView) findViewById(R.id.listViewMieszanieFarba2);
        wspolczynnik = (SeekBar) findViewById(R.id.seekBarWspolczynnik);
        farby = new ArrayList<Farba>(20);
        f1 = f2 = null;
        wczytajFarby();
        adapter = new CustomListViewAdapter(this,farby);
        listafarb1.setAdapter(adapter);
        listafarb2.setAdapter(adapter);
        listafarb1.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                listafarb1 = (ListView) findViewById(R.id.listViewMieszanieFarba1);
                listafarb1.setSelection(position);
                nazwa1 = (TextView) findViewById(R.id.textViewMieszanieNazwa1);
                f1 = farby.get(position);
                nazwa1.setText(f1.nazwa);
            }
        });
        listafarb2.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                listafarb2 = (ListView) findViewById(R.id.listViewMieszanieFarba2);
                listafarb2.setSelection(position);
                nazwa2 = (TextView) findViewById(R.id.textViewMieszanieNazwa2);
                f2 = farby.get(position);
                nazwa2.setText(f2.nazwa);
            }
        });
        wspolczynnik.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                Button kolor = (Button) findViewById(R.id.buttonKolorZmieszany);
                wsp = progress;
                if (f1 != null && f2 != null) {
                    r = f2.r * wsp / wspolczynnik.getMax() + f1.r * (1 - wsp / wspolczynnik.getMax());
                    g = f2.g * wsp / wspolczynnik.getMax() + f1.g * (1 - wsp / wspolczynnik.getMax());
                    b = f2.b * wsp / wspolczynnik.getMax() + f1.b * (1 - wsp / wspolczynnik.getMax());
                    kolor.setBackgroundColor(Color.rgb((int) r, (int) g, (int) b));
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {}
        });
    }

    public void wczytajFarby() {
        try {
            Scanner in = new Scanner(openFileInput("farby"));
            while (in.hasNextLine())
                farby.add(new Farba(in.nextLine(),Integer.parseInt(in.nextLine()),Integer.parseInt(in.nextLine()),Integer.parseInt(in.nextLine())));
            in.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz", e.toString());
        } catch (IOException e) {
            Log.d("xyz", e.toString());
        }
    }

    public void przyciskAnuluj(View view) {
        Toast.makeText(this,"Kolor został odrzucony.",Toast.LENGTH_SHORT).show();
        onBackPressed();
        return;
    }

    public void przyciskDodaj(View view) {
        nazwa = (EditText) findViewById(R.id.editTextMieszanieNazwa);
        if (nazwa.getText().length() < 1) {
            Toast.makeText(this,"Nazwa nie może być pusta.",Toast.LENGTH_SHORT).show();
            return;
        }
        try {
            PrintWriter fout = new PrintWriter(openFileOutput("farby",MODE_APPEND));
            fout.append(nazwa.getText()); fout.println();
            fout.append(Integer.toString((int)r)); fout.println();
            fout.append(Integer.toString((int)g)); fout.println();
            fout.append(Integer.toString((int)b)); fout.println();
            fout.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz","Brak pliku.");
        } catch (IOException e) {
            Log.d("xyz","Nieudany zapis do pliku.");
        }
        onBackPressed();
    }
}
