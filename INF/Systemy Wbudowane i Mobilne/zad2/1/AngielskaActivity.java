package com.example.dawidperdek.myandroidapp1;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.net.Uri;
import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Toast;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.common.api.GoogleApiClient;

public class AngielskaActivity extends Activity {
    // pola edycji tekstu dla nazw drużyn, liczby ich meczów oraz punktów
    EditText team1_eng, team1_m, team1_pkt, team2_eng, team2_m, team2_pkt, team3_eng, team3_m, team3_pkt,
                team4_eng, team4_m, team4_pkt, team5_eng, team5_m, team5_pkt;
    // zmienna do przechowywania obecnego koloru tła aktywności
    String kolor = "blue";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // przypisanie wszystkich pól edycji tekstu
        team1_eng = (EditText) findViewById(R.id.druzyna1_eng);
        team1_m = (EditText) findViewById(R.id.m1_eng);
        team1_pkt = (EditText) findViewById(R.id.pkt1_eng);
        team2_eng = (EditText) findViewById(R.id.druzyna2_eng);
        team2_m = (EditText) findViewById(R.id.m2_eng);
        team2_pkt = (EditText) findViewById(R.id.pkt2_eng);
        team3_eng = (EditText) findViewById(R.id.druzyna3_eng);
        team3_m = (EditText) findViewById(R.id.m3_eng);
        team3_pkt = (EditText) findViewById(R.id.pkt3_eng);
        team4_eng = (EditText) findViewById(R.id.druzyna4_eng);
        team4_m = (EditText) findViewById(R.id.m4_eng);
        team4_pkt = (EditText) findViewById(R.id.pkt4_eng);
        team5_eng = (EditText) findViewById(R.id.druzyna5_eng);
        team5_m = (EditText) findViewById(R.id.m5_eng);
        team5_pkt = (EditText) findViewById(R.id.pkt5_eng);

        setContentView(R.layout.activity_angielska);
        // ustalenie koloru
        getWindow().getDecorView().setBackgroundColor(Color.BLUE);
        Button powrot_eng = (Button) findViewById(R.id.powrot_eng);
        // zaznaczenie domyślnego koloru
        RadioButton radio = (RadioButton) findViewById(R.id.tlo1_eng);
        radio.setChecked(true);
        // zapamiętanie obecnej konfiguracji okna aktywności w SharedPreferences
        powrot_eng.setOnClickListener(new View.OnClickListener() {
            public void onClick(View widok) {
                SharedPreferences.Editor editor = getSharedPreferences("tabela_eng", MODE_PRIVATE).edit();
                editor.putString("TEAM1ENG", team1_eng.getText().toString());
                editor.putString("TEAM1M",team1_m.getText().toString());
                editor.putString("TEAM1PKT",team1_pkt.getText().toString());
                editor.putString("TEAM2ENG", team2_eng.getText().toString());
                editor.putString("TEAM2M",team2_m.getText().toString());
                editor.putString("TEAM2PKT",team2_pkt.getText().toString());
                editor.putString("TEAM3ENG", team3_eng.getText().toString());
                editor.putString("TEAM3M",team3_m.getText().toString());
                editor.putString("TEAM3PKT",team3_pkt.getText().toString());
                editor.putString("TEAM4ENG", team4_eng.getText().toString());
                editor.putString("TEAM4M",team4_m.getText().toString());
                editor.putString("TEAM4PKT",team4_pkt.getText().toString());
                editor.putString("TEAM5ENG", team5_eng.getText().toString());
                editor.putString("TEAM5M",team5_m.getText().toString());
                editor.putString("TEAM5PKT",team5_pkt.getText().toString());
                editor.putString("KOLOR",kolor);
                editor.commit();
                onBackPressed();
            }
        });
    }

    // reakcja na żądanie zmiany koloru
    public void onRadioButtonClicked(View view) {
        boolean checked = ((RadioButton) view).isChecked();
        switch (view.getId()) {
            case R.id.tlo1_eng:
                if (checked) {
                    getWindow().getDecorView().setBackgroundColor(Color.BLUE);
                    kolor = "blue";
                }
                break;
            case R.id.tlo2_eng:
                if (checked) {
                    getWindow().getDecorView().setBackgroundColor(Color.RED);
                    kolor = "red";
                }
                break;
        }
    }

    @Override
    public void onResume() {
        super.onResume();

        // przypisanie wszystkich pól edycji tekstu
        team1_eng = (EditText) findViewById(R.id.druzyna1_eng);
        team1_m = (EditText) findViewById(R.id.m1_eng);
        team1_pkt = (EditText) findViewById(R.id.pkt1_eng);
        team2_eng = (EditText) findViewById(R.id.druzyna2_eng);
        team2_m = (EditText) findViewById(R.id.m2_eng);
        team2_pkt = (EditText) findViewById(R.id.pkt2_eng);
        team3_eng = (EditText) findViewById(R.id.druzyna3_eng);
        team3_m = (EditText) findViewById(R.id.m3_eng);
        team3_pkt = (EditText) findViewById(R.id.pkt3_eng);
        team4_eng = (EditText) findViewById(R.id.druzyna4_eng);
        team4_m = (EditText) findViewById(R.id.m4_eng);
        team4_pkt = (EditText) findViewById(R.id.pkt4_eng);
        team5_eng = (EditText) findViewById(R.id.druzyna5_eng);
        team5_m = (EditText) findViewById(R.id.m5_eng);
        team5_pkt = (EditText) findViewById(R.id.pkt5_eng);

        // wczytanie konfiguracji okna z SharedPreferences
        SharedPreferences prefs = getSharedPreferences("tabela_eng", MODE_PRIVATE);
        String restoredText = prefs.getString("TEAM1ENG", null);
        if (restoredText != null) {
            team1_eng.setText(prefs.getString("TEAM1ENG", null));
            team1_m.setText(prefs.getString("TEAM1M", null));
            team1_pkt.setText(prefs.getString("TEAM1PKT", null));
            team2_eng.setText(prefs.getString("TEAM2ENG", null));
            team2_m.setText(prefs.getString("TEAM2M", null));
            team2_pkt.setText(prefs.getString("TEAM2PKT", null));
            team3_eng.setText(prefs.getString("TEAM3ENG", null));
            team3_m.setText(prefs.getString("TEAM3M", null));
            team3_pkt.setText(prefs.getString("TEAM3PKT", null));
            team4_eng.setText(prefs.getString("TEAM4ENG", null));
            team4_m.setText(prefs.getString("TEAM4M", null));
            team4_pkt.setText(prefs.getString("TEAM4PKT", null));
            team5_eng.setText(prefs.getString("TEAM5ENG", null));
            team5_m.setText(prefs.getString("TEAM5M", null));
            team5_pkt.setText(prefs.getString("TEAM5PKT", null));
            if (prefs.getString("KOLOR",null) == "red") {
                getWindow().getDecorView().setBackgroundColor(Color.RED);
                RadioButton radio = (RadioButton) findViewById(R.id.tlo2_eng);
                radio.setChecked(true);
                kolor = "red";
            }
            else {
                getWindow().getDecorView().setBackgroundColor(Color.BLUE);
                RadioButton radio = (RadioButton) findViewById(R.id.tlo1_eng);
                radio.setChecked(true);
                kolor = "blue";
            }
        }
    }

    // wyświetlenie komunikatu z podsumowaniem ustawień okna aktywności
    public void onPodsumowanie(View widok) {
        String tekst = "Tabela ligi angielskiej.";
        if (kolor == "blue")
            tekst += " Niebieskie tło.";
        else
            tekst += " Czerwone tło.";
        Toast.makeText(this, tekst, Toast.LENGTH_SHORT).show();
    }
}