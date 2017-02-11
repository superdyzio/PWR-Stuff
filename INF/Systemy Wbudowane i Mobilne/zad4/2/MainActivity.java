package com.example.dawidperdek.zad4app;

import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.RatingBar;
import android.widget.SeekBar;
import android.widget.Toast;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainActivity extends AppCompatActivity {
    FragmentTransaction transaction;
    AddDataTabFragment addDataFragment;
    InfoTabFragment infoFragment;
    ListTabFragment listFragment;
    ArrayList<Player> players;
    ArrayList<Basketballer> basketballers;
    ArrayList<Footballer> footballers;
    PlayersListAdapter adapter;
    ListView lista;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar myToolbar = (Toolbar) findViewById(R.id.toolbarMain);
        setSupportActionBar(myToolbar);
        addDataFragment = new AddDataTabFragment();
        infoFragment = new InfoTabFragment();
        listFragment = new ListTabFragment();
        transaction = getSupportFragmentManager().beginTransaction();
        transaction.add(R.id.mainContainer, infoFragment);
        transaction.detach(infoFragment);
        transaction.add(R.id.mainContainer, addDataFragment);
        transaction.detach(addDataFragment);
        transaction.add(R.id.mainContainer, listFragment);
        transaction.detach(listFragment);
        transaction.commit();
        players = new ArrayList<Player>();
        footballers = new ArrayList<Footballer>();
        basketballers = new ArrayList<Basketballer>();
        lista = (ListView) findViewById(R.id.listViewPlayers);
        loadLists();
        adapter = new PlayersListAdapter(this, players);
        lista.setAdapter(adapter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.toolbar_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        transaction = getSupportFragmentManager().beginTransaction();
        transaction.detach(infoFragment);
        transaction.detach(addDataFragment);
        transaction.detach(listFragment);
        switch (item.getItemId()) {
            case R.id.menuTab1:
                transaction.attach(infoFragment);
                break;
            case R.id.menuTab2:
                transaction.attach(addDataFragment);
                break;
            case R.id.menuTab3:
                transaction.attach(listFragment);
                break;
            default:
                transaction.commit();
                return super.onOptionsItemSelected(item);
        }
        transaction.commit();
        return true;
    }

    public void SaveNewFootballer(View view) {
        String imie = ((EditText) findViewById(R.id.editTextNewFootballerName)).getText().toString();
        String nazwisko = ((EditText) findViewById(R.id.editTextNewFootballerSurname)).getText().toString();
        int wzrost = ((SeekBar) findViewById(R.id.seekBarNewFootballerHeight)).getProgress() + 160;
        int waga = ((SeekBar) findViewById(R.id.seekBarNewFootballerWeight)).getProgress() + 60;
        int bramki = 0, asysty = 0;
        try {
            bramki = Integer.parseInt(((EditText) findViewById(R.id.editTextNewFootballerGoals)).getText().toString());
        }
        catch (Exception e) {
            Toast.makeText(this, "Bramki muszą być liczbą!", Toast.LENGTH_SHORT).show();
        }
        try {
            asysty = Integer.parseInt(((EditText) findViewById(R.id.editTextNewFootballerAssists)).getText().toString());
        }
        catch (Exception e) {
            Toast.makeText(this, "Asysty muszą być liczbą!", Toast.LENGTH_SHORT).show();
        }

        try {
            PrintWriter fout = new PrintWriter(openFileOutput("pilkarze",MODE_APPEND));
            fout.append(Integer.toString(players.size()+1)); fout.println();
            fout.append("F"); fout.println();
            fout.append(imie); fout.println();
            fout.append(nazwisko); fout.println();
            fout.append(Integer.toString(wzrost)); fout.println();
            fout.append(Integer.toString(waga)); fout.println();
            fout.append(Integer.toString(bramki)); fout.println();
            fout.append(Integer.toString(asysty)); fout.println();
            fout.close();
            Toast.makeText(this, "Piłkarz zapisany!", Toast.LENGTH_SHORT).show();
        } catch (FileNotFoundException e) {
            Log.d("xyz", "Brak pliku.");
        } catch (IOException e) {
            Log.d("xyz", "Nieudany zapis do pliku.");
        }
        loadLists();
    }

    public void SaveNewBasketballer(View view) {
        String imie = ((EditText) findViewById(R.id.editTextNewBasketballerName)).getText().toString();
        String nazwisko = ((EditText) findViewById(R.id.editTextNewBasketballerSurname)).getText().toString();
        int wzrost = ((SeekBar) findViewById(R.id.seekBarNewBasketballerHeight)).getProgress() + 160;
        int waga = ((SeekBar) findViewById(R.id.seekBarNewBasketballerWeight)).getProgress() + 60;
        double ocena = ((RatingBar) findViewById(R.id.ratingBarNewBasketballerRating)).getRating();
        int punkty = 0, zbiorki = 0;
        try {
            punkty = Integer.parseInt(((EditText) findViewById(R.id.editTextNewBasketballerPoints)).getText().toString());
        }
        catch (Exception e) {
            Toast.makeText(this, "Bramki muszą być liczbą!", Toast.LENGTH_SHORT).show();
        }
        try {
            zbiorki = Integer.parseInt(((EditText) findViewById(R.id.editTextNewBasketballerRebounds)).getText().toString());
        }
        catch (Exception e) {
            Toast.makeText(this, "Asysty muszą być liczbą!", Toast.LENGTH_SHORT).show();
        }

        try {
            PrintWriter fout = new PrintWriter(openFileOutput("koszykarze",MODE_APPEND));
            fout.append(Integer.toString(players.size()+1)); fout.println();
            fout.append("K"); fout.println();
            fout.append(imie); fout.println();
            fout.append(nazwisko); fout.println();
            fout.append(Integer.toString(wzrost)); fout.println();
            fout.append(Integer.toString(waga)); fout.println();
            fout.append(Double.toString(ocena)); fout.println();
            fout.append(Integer.toString(punkty)); fout.println();
            fout.append(Integer.toString(zbiorki)); fout.println();
            fout.close();
            Toast.makeText(this, "Koszykarz zapisany!", Toast.LENGTH_SHORT).show();
        } catch (FileNotFoundException e) {
            Log.d("xyz", "Brak pliku.");
        } catch (IOException e) {
            Log.d("xyz", "Nieudany zapis do pliku.");
        }
        loadLists();
    }

    public void loadLists() {
        try {
            Scanner in = new Scanner(openFileInput("pilkarze"));
            while (in.hasNextLine())
                footballers.add(new Footballer(in.nextLine(), in.nextLine(), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine())));
            in.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz", e.toString());
        } catch (IOException e) {
            Log.d("xyz", e.toString());
        }
        try {
            Scanner in = new Scanner(openFileInput("koszykarze"));
            while (in.hasNextLine())
                basketballers.add(new Basketballer(in.nextLine(), in.nextLine(), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Double.parseDouble(in.nextLine())));
            in.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz", e.toString());
        } catch (IOException e) {
            Log.d("xyz", e.toString());
        }

        for (int i = 0; i < footballers.size(); i++)
            players.add((Player)footballers.get(i));
        for (int i = 0; i < basketballers.size(); i++)
            players.add((Player)basketballers.get(i));
    }

    public void fillInfoTab() {

    }
}
