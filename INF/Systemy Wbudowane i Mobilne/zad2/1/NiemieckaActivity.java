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

public class NiemieckaActivity extends Activity {
    // pola edycji tekstu dla nazw drużyn, liczby ich meczów oraz punktów
    EditText team1_ger, team1_m, team1_pkt, team2_ger, team2_m, team2_pkt, team3_ger, team3_m, team3_pkt,
            team4_ger, team4_m, team4_pkt, team5_ger, team5_m, team5_pkt;
    // zmienna do przechowywania obecnego koloru tła aktywności
    String kolor = "blue";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // przypisanie wszystkich pól edycji tekstu
        team1_ger = (EditText) findViewById(R.id.druzyna1_ger);
        team1_m = (EditText) findViewById(R.id.m1_ger);
        team1_pkt = (EditText) findViewById(R.id.pkt1_ger);
        team2_ger = (EditText) findViewById(R.id.druzyna2_ger);
        team2_m = (EditText) findViewById(R.id.m2_ger);
        team2_pkt = (EditText) findViewById(R.id.pkt2_ger);
        team3_ger = (EditText) findViewById(R.id.druzyna3_ger);
        team3_m = (EditText) findViewById(R.id.m3_ger);
        team3_pkt = (EditText) findViewById(R.id.pkt3_ger);
        team4_ger = (EditText) findViewById(R.id.druzyna4_ger);
        team4_m = (EditText) findViewById(R.id.m4_ger);
        team4_pkt = (EditText) findViewById(R.id.pkt4_ger);
        team5_ger = (EditText) findViewById(R.id.druzyna5_ger);
        team5_m = (EditText) findViewById(R.id.m5_ger);
        team5_pkt = (EditText) findViewById(R.id.pkt5_ger);

        setContentView(R.layout.activity_niemiecka);
        // ustalenie koloru
        getWindow().getDecorView().setBackgroundColor(Color.BLUE);
        Button powrot_ger = (Button) findViewById(R.id.powrot_ger);
        // zaznaczenie domyślnego koloru
        RadioButton radio = (RadioButton) findViewById(R.id.tlo1_ger);
        radio.setChecked(true);
        // zapamiętanie obecnej konfiguracji okna aktywności w SharedPreferences
        powrot_ger.setOnClickListener(new View.OnClickListener() {
            public void onClick(View widok) {
                SharedPreferences.Editor editor = getSharedPreferences("tabela_ger", MODE_PRIVATE).edit();
                editor.putString("TEAM1GER", team1_ger.getText().toString());
                editor.putString("TEAM1M",team1_m.getText().toString());
                editor.putString("TEAM1PKT",team1_pkt.getText().toString());
                editor.putString("TEAM2GER", team2_ger.getText().toString());
                editor.putString("TEAM2M",team2_m.getText().toString());
                editor.putString("TEAM2PKT",team2_pkt.getText().toString());
                editor.putString("TEAM3GER", team3_ger.getText().toString());
                editor.putString("TEAM3M",team3_m.getText().toString());
                editor.putString("TEAM3PKT",team3_pkt.getText().toString());
                editor.putString("TEAM4GER", team4_ger.getText().toString());
                editor.putString("TEAM4M",team4_m.getText().toString());
                editor.putString("TEAM4PKT",team4_pkt.getText().toString());
                editor.putString("TEAM5GER", team5_ger.getText().toString());
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
            case R.id.tlo1_ger:
                if (checked) {
                    getWindow().getDecorView().setBackgroundColor(Color.BLUE);
                    kolor = "blue";
                }
                break;
            case R.id.tlo2_ger:
                if (checked) {
                    getWindow().getDecorView().setBackgroundColor(Color.GREEN);
                    kolor = "green";
                }
                break;
        }
    }

    @Override
    public void onResume() {
        super.onResume();

        // przypisanie wszystkich pól edycji tekstu
        team1_ger = (EditText) findViewById(R.id.druzyna1_ger);
        team1_m = (EditText) findViewById(R.id.m1_ger);
        team1_pkt = (EditText) findViewById(R.id.pkt1_ger);
        team2_ger = (EditText) findViewById(R.id.druzyna2_ger);
        team2_m = (EditText) findViewById(R.id.m2_ger);
        team2_pkt = (EditText) findViewById(R.id.pkt2_ger);
        team3_ger = (EditText) findViewById(R.id.druzyna3_ger);
        team3_m = (EditText) findViewById(R.id.m3_ger);
        team3_pkt = (EditText) findViewById(R.id.pkt3_ger);
        team4_ger = (EditText) findViewById(R.id.druzyna4_ger);
        team4_m = (EditText) findViewById(R.id.m4_ger);
        team4_pkt = (EditText) findViewById(R.id.pkt4_ger);
        team5_ger = (EditText) findViewById(R.id.druzyna5_ger);
        team5_m = (EditText) findViewById(R.id.m5_ger);
        team5_pkt = (EditText) findViewById(R.id.pkt5_ger);

        // wczytanie konfiguracji okna z SharedPreferences
        SharedPreferences prefs = getSharedPreferences("tabela_ger", MODE_PRIVATE);
        String restoredText = prefs.getString("TEAM1GER", null);
        if (restoredText != null) {
            team1_ger.setText(prefs.getString("TEAM1GER", null));
            team1_m.setText(prefs.getString("TEAM1M", null));
            team1_pkt.setText(prefs.getString("TEAM1PKT", null));
            team2_ger.setText(prefs.getString("TEAM2GER", null));
            team2_m.setText(prefs.getString("TEAM2M", null));
            team2_pkt.setText(prefs.getString("TEAM2PKT", null));
            team3_ger.setText(prefs.getString("TEAM3GER", null));
            team3_m.setText(prefs.getString("TEAM3M", null));
            team3_pkt.setText(prefs.getString("TEAM3PKT", null));
            team4_ger.setText(prefs.getString("TEAM4GER", null));
            team4_m.setText(prefs.getString("TEAM4M", null));
            team4_pkt.setText(prefs.getString("TEAM4PKT", null));
            team5_ger.setText(prefs.getString("TEAM5GER", null));
            team5_m.setText(prefs.getString("TEAM5M", null));
            team5_pkt.setText(prefs.getString("TEAM5PKT", null));
            if (prefs.getString("KOLOR",null) == "green") {
                getWindow().getDecorView().setBackgroundColor(Color.GREEN);
                RadioButton radio = (RadioButton) findViewById(R.id.tlo2_ger);
                radio.setChecked(true);
                kolor = "green";
            }
            else {
                getWindow().getDecorView().setBackgroundColor(Color.BLUE);
                RadioButton radio = (RadioButton) findViewById(R.id.tlo1_ger);
                radio.setChecked(true);
                kolor = "blue";
            }
        }
    }

    // wyświetlenie komunikatu z podsumowaniem ustawień okna aktywności
    public void onPodsumowanie(View widok) {
        String tekst = "Tabela ligi niemieckiej.";
        if (kolor == "blue")
            tekst += " Niebieskie tło.";
        else
            tekst += " Zielone tło.";
        Toast.makeText(this, tekst, Toast.LENGTH_SHORT).show();
    }
}