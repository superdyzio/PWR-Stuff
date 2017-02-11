package com.example.dawidperdek.myandroidapp1;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

public class StrzelcyActivity extends AppCompatActivity {
    Boolean eng, ger, esp;  // zmienne przechowujące informacje o wyświetlaniu poszczególnych strzelców
    CheckBox e, g, h;       // zmienne CheckBox'ów
    private Intent intent;  // intencja

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_strzelcy);
        Button powrot_but = (Button) findViewById(R.id.powrot_but);
        // zapamiętanie ustawień okna aktywności w SharedPreferences
        powrot_but.setOnClickListener(new View.OnClickListener() {
            public void onClick(View widok) {
                eng = ((CheckBox) findViewById(R.id.checkBox_eng)).isChecked();
                esp = ((CheckBox) findViewById(R.id.checkBox_esp)).isChecked();
                ger = ((CheckBox) findViewById(R.id.checkBox_ger)).isChecked();
                SharedPreferences.Editor editor = getSharedPreferences("tabela_but", MODE_PRIVATE).edit();
                editor.putBoolean("ANGIELSKA",eng);
                editor.putBoolean("HISZPANSKA",esp);
                editor.putBoolean("NIEMIECKA",ger);
                editor.commit();
                onBackPressed();
            }
        });
    }

    @Override
    public void onResume() {
        super.onResume();

        // przypisanie CheckBox'ów
        e = ((CheckBox) findViewById(R.id.checkBox_eng));
        h = ((CheckBox) findViewById(R.id.checkBox_esp));
        g = ((CheckBox) findViewById(R.id.checkBox_ger));

        // przypisanie pól tekstowych z informacjami
        TextView nazwisko_eng = (TextView) findViewById(R.id.krol_eng);
        TextView nazwisko_esp = (TextView) findViewById(R.id.krol_esp);
        TextView nazwisko_ger = (TextView) findViewById(R.id.krol_ger);
        TextView gole_eng = (TextView) findViewById(R.id.bramki_eng);
        TextView gole_esp = (TextView) findViewById(R.id.bramki_esp);
        TextView gole_ger = (TextView) findViewById(R.id.bramki_ger);

        // wczytanie konfiguracji okna aktywności z Shared Preferences
        SharedPreferences prefs = getSharedPreferences("tabela_but", MODE_PRIVATE);
        e.setChecked(prefs.getBoolean("ANGIELSKA", true));
        h.setChecked(prefs.getBoolean("HISZPANSKA", true));
        g.setChecked(prefs.getBoolean("NIEMIECKA", true));

        // sprawdzenie stanu CheckBox'ów
        eng = ((CheckBox) findViewById(R.id.checkBox_eng)).isChecked();
        esp = ((CheckBox) findViewById(R.id.checkBox_esp)).isChecked();
        ger = ((CheckBox) findViewById(R.id.checkBox_ger)).isChecked();

        // ukrywanie poszczególnych wpisów zależnie od stanu CheckBox'ów
        if (!eng) {
            nazwisko_eng.setVisibility(View.INVISIBLE);
            gole_eng.setVisibility(View.INVISIBLE);
        }
        else {
            nazwisko_eng.setVisibility(View.VISIBLE);
            gole_eng.setVisibility(View.VISIBLE);
        }
        if (!esp) {
            nazwisko_esp.setVisibility(View.INVISIBLE);
            gole_esp.setVisibility(View.INVISIBLE);
        }
        else {
            nazwisko_esp.setVisibility(View.VISIBLE);
            gole_esp.setVisibility(View.VISIBLE);
        }
        if (!ger) {
            nazwisko_ger.setVisibility(View.INVISIBLE);
            gole_ger.setVisibility(View.INVISIBLE);
        }
        else {
            nazwisko_ger.setVisibility(View.VISIBLE);
            gole_ger.setVisibility(View.VISIBLE);
        }
    }

    // odpowiedź na wynik aktywności wywoływanej z poziomu tej aktywności
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == 1 && resultCode == Activity.RESULT_OK) {
            Toast.makeText(this,"Wynik dodawania to: "+Integer.toString(data.getExtras().getInt("wynik")),Toast.LENGTH_SHORT).show();
        }
    }

    // reakcja na zmianę stanu CheckBox'ów
    public void onCheckBoxChanged(View widok) {
        TextView nazwisko_eng = (TextView) findViewById(R.id.krol_eng);
        TextView nazwisko_esp = (TextView) findViewById(R.id.krol_esp);
        TextView nazwisko_ger = (TextView) findViewById(R.id.krol_ger);
        TextView gole_eng = (TextView) findViewById(R.id.bramki_eng);
        TextView gole_esp = (TextView) findViewById(R.id.bramki_esp);
        TextView gole_ger = (TextView) findViewById(R.id.bramki_ger);

        eng = ((CheckBox) findViewById(R.id.checkBox_eng)).isChecked();
        esp = ((CheckBox) findViewById(R.id.checkBox_esp)).isChecked();
        ger = ((CheckBox) findViewById(R.id.checkBox_ger)).isChecked();

        if (!eng) {
            nazwisko_eng.setVisibility(View.INVISIBLE);
            gole_eng.setVisibility(View.INVISIBLE);
        }
        else {
            nazwisko_eng.setVisibility(View.VISIBLE);
            gole_eng.setVisibility(View.VISIBLE);
        }
        if (!esp) {
            nazwisko_esp.setVisibility(View.INVISIBLE);
            gole_esp.setVisibility(View.INVISIBLE);
        }
        else {
            nazwisko_esp.setVisibility(View.VISIBLE);
            gole_esp.setVisibility(View.VISIBLE);
        }
        if (!ger) {
            nazwisko_ger.setVisibility(View.INVISIBLE);
            gole_ger.setVisibility(View.INVISIBLE);
        }
        else {
            nazwisko_ger.setVisibility(View.VISIBLE);
            gole_ger.setVisibility(View.VISIBLE);
        }
    }

    // wyświetlenie komunikatu podsumowującego konfigurację okna aktywności
    public void onPodsumowanie(View widok) {
        String tekst = "Najlepsi strzelcy z lig: ";
        eng = ((CheckBox) findViewById(R.id.checkBox_eng)).isChecked();
        esp = ((CheckBox) findViewById(R.id.checkBox_esp)).isChecked();
        ger = ((CheckBox) findViewById(R.id.checkBox_ger)).isChecked();
        if (eng && esp && ger)
            tekst += "angielskiej, hiszpańskiej i niemieckiej.";
        else if (eng && esp)
            tekst += "angielskiej i hiszpańskiej.";
        else if (eng && ger)
            tekst += "angielskiej i niemieckiej.";
        else if (esp && ger)
            tekst += "hiszpańskiej i niemieckiej.";
        else if (eng)
            tekst = "Najlepszy strzelec z ligi angielskiej.";
        else if (esp)
            tekst = "Najlepszy strzelec z ligi hiszpańskiej.";
        else if (ger)
            tekst = "Najlepszy strzelec z ligi niemieckiej.";
        else
            tekst = "Nie wybrano żadnej z lig.";
        Toast.makeText(this, tekst, Toast.LENGTH_SHORT).show();
    }

    // wywołanie nowej aktywności dodającej dwie liczby - spodziewany zwrot rezultatu
    public void dodaj(View widok) {
        EditText l1 = (EditText) findViewById(R.id.liczba1);
        EditText l2 = (EditText) findViewById(R.id.liczba2);
        int a = Integer.parseInt(l1.getText().toString());
        int b = Integer.parseInt(l2.getText().toString());
        Bundle msg = new Bundle();
        msg.putInt("liczba1",a);
        msg.putInt("liczba2", b);
        Intent nowe = new Intent(this,DodawanieActivity.class);
        nowe.putExtras(msg);
        startActivityForResult(nowe,1);
    }
}
