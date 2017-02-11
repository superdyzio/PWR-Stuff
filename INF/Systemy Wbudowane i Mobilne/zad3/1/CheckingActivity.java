package com.example.dawidperdek.androidzadanie2;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Spinner;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CheckingActivity extends Activity {
    PersonAdapter adapter;
    ArrayList<Person> lista;
    ListView ekran;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_checking);
        ekran = (ListView) findViewById(R.id.listView);
        lista = new ArrayList<Person>();
        wczytajLudzi();
        adapter = new PersonAdapter(this,lista);
        ekran.setAdapter(adapter);
        ekran.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                lista.remove(position);
                adapter.notifyDataSetChanged();
                for (int i = 0; i < lista.size(); i++) {
                    Person pom = lista.get(i);
                    try {
                        PrintWriter fout = new PrintWriter(openFileOutput("ludzie",MODE_PRIVATE));
                        fout.append(pom.imie); fout.println();
                        fout.append(pom.nazwisko); fout.println();
                        fout.append(Integer.toString(pom.rok)); fout.println();
                        fout.append(Boolean.toString(pom.plec)); fout.println();
                        fout.append(pom.kraj); fout.println();
                        fout.append(Boolean.toString(pom.student)); fout.println();
                        fout.append(Double.toString(pom.spryt)); fout.println();
                        fout.close();
                    } catch (FileNotFoundException e) {
                        Log.d("xyz", "Brak pliku.");
                    } catch (IOException e) {
                        Log.d("xyz","Nieudany zapis do pliku.");
                    }
                }
                return false;
            }
        });
    }

    public void wczytajLudzi() {
        try {
            Scanner in = new Scanner(openFileInput("ludzie"));
            while (in.hasNextLine())
                lista.add(new Person(in.nextLine(), in.nextLine(), Integer.parseInt(in.nextLine()),Boolean.parseBoolean(in.nextLine()),
                        in.nextLine(),Boolean.parseBoolean(in.nextLine()),Double.parseDouble(in.nextLine())));
            in.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz", e.toString());
        } catch (IOException e) {
            Log.d("xyz", e.toString());
        }
    }

    public void onResume() {
        super.onResume();
        ekran = (ListView) findViewById(R.id.listView);
        lista = new ArrayList<Person>();
        wczytajLudzi();
        adapter = new PersonAdapter(this,lista);
        ekran.setAdapter(adapter);
    }
}
