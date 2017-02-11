package com.example.dawidperdek.androidzadanie2;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.util.TypedValue;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;

public class MainActivity extends Activity {
    TextView powitanie, pamiec;
    Boolean internal, external;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        powitanie = (TextView) findViewById(R.id.textViewWelcome);
        pamiec = (TextView) findViewById(R.id.textViewPamiec);

//        SharedPreferences.Editor editor = getSharedPreferences("ustawienia", MODE_PRIVATE).edit();
//        editor.clear();
//        editor.commit();

        SharedPreferences prefs = getSharedPreferences("ustawienia", MODE_PRIVATE);
        if (prefs != null) {
            getWindow().getDecorView().setBackgroundColor(Color.rgb(prefs.getInt("tloR", 255), prefs.getInt("tloG", 255), prefs.getInt("tloB", 255)));
            powitanie.setText(prefs.getString("tekst" + Integer.toString(prefs.getInt("wybranytekst", 0)), "Coś się nie udało."));
            powitanie.setTextColor(Color.rgb(prefs.getInt("tekstR", 0), prefs.getInt("tekstG", 0), prefs.getInt("tekstB", 0)));
            pamiec.setTextColor(Color.rgb(prefs.getInt("tekstR", 0), prefs.getInt("tekstG", 0), prefs.getInt("tekstB", 0)));
            internal = prefs.getBoolean("wewnetrzna",false);
            external = prefs.getBoolean("zewnetrzna",false);
            String rozmiar = prefs.getString("rozmiarczcionki","srednia");
            if (rozmiar == "mala")
                powitanie.setTextSize(TypedValue.COMPLEX_UNIT_DIP,12);
            else if (rozmiar == "srednia")
                powitanie.setTextSize(TypedValue.COMPLEX_UNIT_DIP,20);
            else if (rozmiar == "duza")
                powitanie.setTextSize(TypedValue.COMPLEX_UNIT_DIP,28);
        }
        if (internal && external)
            pamiec.setText("Dane będą zapisywanie w pamięci wewnętrznej oraz na karcie SD.");
        else if (internal && !external)
            pamiec.setText("Dane będą zapisywane tylko w pamięci wewnętrznej.");
        else if (!internal && external)
            pamiec.setText("Dane będą zapisywane tylko na karcie SD.");
        else
            pamiec.setText("Nie wybrano miejsca do zapisywania danych!");
    }

    public void onResume() {
        super.onResume();
        powitanie = (TextView) findViewById(R.id.textViewWelcome);
        pamiec = (TextView) findViewById(R.id.textViewPamiec);

        SharedPreferences prefs = getSharedPreferences("ustawienia", MODE_PRIVATE);
        if (prefs != null) {
            getWindow().getDecorView().setBackgroundColor(Color.rgb(prefs.getInt("tloR", 255), prefs.getInt("tloG", 255), prefs.getInt("tloB", 255)));
            powitanie.setText(prefs.getString("tekst" + Integer.toString(prefs.getInt("wybranytekst", 0)), "Coś się nie udało."));
            powitanie.setTextColor(Color.rgb(prefs.getInt("tekstR", 0), prefs.getInt("tekstG", 0), prefs.getInt("tekstB", 0)));
            pamiec.setTextColor(Color.rgb(prefs.getInt("tekstR", 0), prefs.getInt("tekstG", 0), prefs.getInt("tekstB", 0)));
            internal = prefs.getBoolean("wewnetrzna",false);
            external = prefs.getBoolean("zewnetrzna",false);
            String rozmiar = prefs.getString("rozmiarczcionki","srednia");
            if (rozmiar.equals("mala"))
                powitanie.setTextSize(TypedValue.COMPLEX_UNIT_DIP,12);
            else if (rozmiar.equals("srednia"))
                powitanie.setTextSize(TypedValue.COMPLEX_UNIT_DIP,20);
            else if (rozmiar.equals("duza"))
                powitanie.setTextSize(TypedValue.COMPLEX_UNIT_DIP,28);
        }
        Boolean isSDPresent = Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED);
//        Log.d("xyz",isSDPresent.toString());
//        Log.d("xyz",Environment.getExternalStorageState());
//        Log.d("xyz",Environment.MEDIA_MOUNTED);
        if (!isSDPresent && internal) {
            internal = false;
            Toast.makeText(this, "Brak karty SD", Toast.LENGTH_SHORT).show();
        }
        if (internal && external)
            pamiec.setText("Dane będą zapisywanie w pamięci wewnętrznej oraz na karcie SD.");
        else if (internal && !external)
            pamiec.setText("Dane będą zapisywane tylko w pamięci wewnętrznej.");
        else if (!internal && external)
            pamiec.setText("Dane będą zapisywane tylko na karcie SD.");
        else
            pamiec.setText("Nie wybrano miejsca do zapisywania danych!");
    }

    public void ustawieniaStart(View view) {
        final Intent intencja = new Intent(this,SettingsActivity.class);
        startActivity(intencja);
    }

    public void dodawanieStart(View view) {
        final Intent intencja = new Intent(this,AddingActivity.class);
        startActivity(intencja);
    }

    public void przegladanieStart(View view) {
        final Intent intencja = new Intent(this,CheckingActivity.class);
        startActivity(intencja);
    }

    public void farbyStart(View view) {
        final Intent intencja = new Intent(this,FarbyActivity.class);
        startActivity(intencja);
    }
}
