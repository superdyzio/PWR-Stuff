package com.example.dawidperdek.androidzadanie2;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class FarbyActivity extends Activity {
    ListView listakolorow;
    CustomListViewAdapter adapter;
    ArrayList<Farba> farby;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_farby);
        listakolorow = (ListView) findViewById(R.id.listaKolorow);
        farby = new ArrayList<Farba>(20);
        wczytajFarby();
        adapter = new CustomListViewAdapter(this,farby);
        listakolorow.setAdapter(adapter);
        listakolorow.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                farby.remove(position);
                adapter.notifyDataSetChanged();
                try {
                    PrintWriter fout = new PrintWriter(openFileOutput("farby",MODE_PRIVATE));
                    for (int i = 0; i < farby.size(); i++) {
                        Farba pom = farby.get(i);
                        fout.append(pom.nazwa); fout.println();
                        fout.append(Integer.toString(pom.r)); fout.println();
                        fout.append(Integer.toString(pom.g)); fout.println();
                        fout.append(Integer.toString(pom.b)); fout.println();
                    }
                    fout.close();
                } catch (FileNotFoundException e) {
                    Log.d("xyz",e.toString());
                }
                return false;
            }
        });
    }

    public void wczytajFarby() {
        try {
            Scanner in = new Scanner(openFileInput("farby"));
            while (in.hasNextLine())
                farby.add(new Farba(in.nextLine(),Integer.parseInt(in.nextLine()),Integer.parseInt(in.nextLine()),Integer.parseInt(in.nextLine())));
            in.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz",e.toString());
        } catch (IOException e) {
            Log.d("xyz", e.toString());
        }
    }

    public void onResume() {
        super.onResume();
        listakolorow = (ListView) findViewById(R.id.listaKolorow);
        farby = new ArrayList<Farba>(20);
        wczytajFarby();
        adapter = new CustomListViewAdapter(this,farby);
        listakolorow.setAdapter(adapter);
    }

    public void uruchomDodawanie(View view) {
        final Intent intencja = new Intent(this,DodawanieFarbyActivity.class);
        startActivity(intencja);
    }

    public void uruchomMieszanie(View view) {
        final Intent intencja = new Intent(this,MieszanieActivity.class);
        startActivity(intencja);
    }
}
