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

public class HiszpanskaActivity extends Activity {
    // pola edycji tekstu dla nazw drużyn, liczby ich meczów oraz punktów
    EditText team1_esp, team1_m, team1_pkt, team2_esp, team2_m, team2_pkt, team3_esp, team3_m, team3_pkt,
            team4_esp, team4_m, team4_pkt, team5_esp, team5_m, team5_pkt;
    // zmienna do przechowywania obecnego koloru tła aktywności
    String kolor = "green";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // przypisanie wszystkich pól edycji tekstu
        team1_esp = (EditText) findViewById(R.id.druzyna1_esp);
        team1_m = (EditText) findViewById(R.id.m1_esp);
        team1_pkt = (EditText) findViewById(R.id.pkt1_esp);
        team2_esp = (EditText) findViewById(R.id.druzyna2_esp);
        team2_m = (EditText) findViewById(R.id.m2_esp);
        team2_pkt = (EditText) findViewById(R.id.pkt2_esp);
        team3_esp = (EditText) findViewById(R.id.druzyna3_esp);
        team3_m = (EditText) findViewById(R.id.m3_esp);
        team3_pkt = (EditText) findViewById(R.id.pkt3_esp);
        team4_esp = (EditText) findViewById(R.id.druzyna4_esp);
        team4_m = (EditText) findViewById(R.id.m4_esp);
        team4_pkt = (EditText) findViewById(R.id.pkt4_esp);
        team5_esp = (EditText) findViewById(R.id.druzyna5_esp);
        team5_m = (EditText) findViewById(R.id.m5_esp);
        team5_pkt = (EditText) findViewById(R.id.pkt5_esp);

        setContentView(R.layout.activity_hiszpanska);
        // ustalenie koloru
        getWindow().getDecorView().setBackgroundColor(Color.GREEN);
        Button powrot_esp = (Button) findViewById(R.id.powrot_esp);
        // zaznaczenie domyślnego koloru
        RadioButton radio = (RadioButton) findViewById(R.id.tlo1_esp);
        radio.setChecked(true);
        // zapamiętanie obecnej konfiguracji okna aktywności w SharedPreferences
        powrot_esp.setOnClickListener(new View.OnClickListener() {
            public void onClick(View widok) {
                SharedPreferences.Editor editor = getSharedPreferences("tabela_esp", MODE_PRIVATE).edit();
                editor.putString("TEAM1ESP", team1_esp.getText().toString());
                editor.putString("TEAM1M",team1_m.getText().toString());
                editor.putString("TEAM1PKT",team1_pkt.getText().toString());
                editor.putString("TEAM2ESP", team2_esp.getText().toString());
                editor.putString("TEAM2M",team2_m.getText().toString());
                editor.putString("TEAM2PKT",team2_pkt.getText().toString());
                editor.putString("TEAM3ESP", team3_esp.getText().toString());
                editor.putString("TEAM3M",team3_m.getText().toString());
                editor.putString("TEAM3PKT",team3_pkt.getText().toString());
                editor.putString("TEAM4ESP", team4_esp.getText().toString());
                editor.putString("TEAM4M",team4_m.getText().toString());
                editor.putString("TEAM4PKT",team4_pkt.getText().toString());
                editor.putString("TEAM5ESP", team5_esp.getText().toString());
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
            case R.id.tlo1_esp:
                if (checked) {
                    getWindow().getDecorView().setBackgroundColor(Color.GREEN);
                    kolor = "green";
                }
                break;
            case R.id.tlo2_esp:
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
        team1_esp = (EditText) findViewById(R.id.druzyna1_esp);
        team1_m = (EditText) findViewById(R.id.m1_esp);
        team1_pkt = (EditText) findViewById(R.id.pkt1_esp);
        team2_esp = (EditText) findViewById(R.id.druzyna2_esp);
        team2_m = (EditText) findViewById(R.id.m2_esp);
        team2_pkt = (EditText) findViewById(R.id.pkt2_esp);
        team3_esp = (EditText) findViewById(R.id.druzyna3_esp);
        team3_m = (EditText) findViewById(R.id.m3_esp);
        team3_pkt = (EditText) findViewById(R.id.pkt3_esp);
        team4_esp = (EditText) findViewById(R.id.druzyna4_esp);
        team4_m = (EditText) findViewById(R.id.m4_esp);
        team4_pkt = (EditText) findViewById(R.id.pkt4_esp);
        team5_esp = (EditText) findViewById(R.id.druzyna5_esp);
        team5_m = (EditText) findViewById(R.id.m5_esp);
        team5_pkt = (EditText) findViewById(R.id.pkt5_esp);

        // wczytanie konfiguracji okna z SharedPreferences
        SharedPreferences prefs = getSharedPreferences("tabela_esp", MODE_PRIVATE);
        String restoredText = prefs.getString("TEAM1ESP", null);
        if (restoredText != null) {
            team1_esp.setText(prefs.getString("TEAM1ESP", null));
            team1_m.setText(prefs.getString("TEAM1M", null));
            team1_pkt.setText(prefs.getString("TEAM1PKT", null));
            team2_esp.setText(prefs.getString("TEAM2ESP", null));
            team2_m.setText(prefs.getString("TEAM2M", null));
            team2_pkt.setText(prefs.getString("TEAM2PKT", null));
            team3_esp.setText(prefs.getString("TEAM3ESP", null));
            team3_m.setText(prefs.getString("TEAM3M", null));
            team3_pkt.setText(prefs.getString("TEAM3PKT", null));
            team4_esp.setText(prefs.getString("TEAM4ESP", null));
            team4_m.setText(prefs.getString("TEAM4M", null));
            team4_pkt.setText(prefs.getString("TEAM4PKT", null));
            team5_esp.setText(prefs.getString("TEAM5ESP", null));
            team5_m.setText(prefs.getString("TEAM5M", null));
            team5_pkt.setText(prefs.getString("TEAM5PKT", null));
            if (prefs.getString("KOLOR",null) == "red") {
                getWindow().getDecorView().setBackgroundColor(Color.RED);
                RadioButton radio = (RadioButton) findViewById(R.id.tlo2_esp);
                radio.setChecked(true);
                kolor = "red";
            }
            else {
                getWindow().getDecorView().setBackgroundColor(Color.GREEN);
                RadioButton radio = (RadioButton) findViewById(R.id.tlo1_esp);
                radio.setChecked(true);
                kolor = "green";
            }
        }
    }

    // wyświetlenie komunikatu z podsumowaniem ustawień okna aktywności
    public void onPodsumowanie(View widok) {
        String tekst = "Tabela ligi hiszpańskiej.";
        if (kolor == "green")
            tekst += " Zielone tło.";
        else
            tekst += " Czerwone tło.";
        Toast.makeText(this, tekst, Toast.LENGTH_SHORT).show();
    }
}