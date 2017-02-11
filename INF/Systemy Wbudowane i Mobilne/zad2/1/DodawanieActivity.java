package com.example.dawidperdek.myandroidapp1;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.TextView;

public class DodawanieActivity extends AppCompatActivity {
    int a, b, wynik;            // zmienne przechowujące dwie liczby oraz wynik ich dodawania
    Intent intent;              // intencja do pobrania liczb
    private TextView status;    // pole wyświetlające status odsyłania odpowiedzi
    private Switch mySwitch;    // pole Switcha - określa czy wysyłać rezultat działania

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dodawanie);
        // pobranie intencji i przekazanych z intencji wywołującej liczb
        intent = getIntent();
        a = intent.getExtras().getInt("liczba1", 0);
        b = intent.getExtras().getInt("liczba2",0);
        wynik = a + b;
        TextView w = (TextView) findViewById(R.id.wynik);
        w.setText(Integer.toString(wynik));
        status = (TextView) findViewById(R.id.status);
        mySwitch = (Switch) findViewById(R.id.switch1);
        // domyślne ustawienie switcha
        mySwitch.setChecked(false);
        status.setText("Wyłączony");
        // ustawienie akcji dla zmiany stanu switcha
        mySwitch.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked) {
                    status.setText("Włączony");
                } else {
                    status.setText("Wyłączony");
                }

            }
        });
    }

    // metoda powrotu do aktywności wywołującej
    public void wracaj(View widok) {
        if (mySwitch.isChecked()) {
            intent = new Intent();
            // dodanie wyniku działania do intencji
            Bundle msg = new Bundle();
            msg.putInt("wynik",wynik);
            intent.putExtras(msg);
            // zwrócenie rezultatu
            setResult(Activity.RESULT_OK, intent);
        }
        finish();
    }
}
