package com.example.dawidperdek.androidzadanie2;

import android.app.Activity;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RatingBar;
import android.widget.Switch;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;

public class AddingActivity extends Activity {
    EditText imie, nazwisko, rokur;
    RadioButton pan, pani;
    ListView pochodzenie;
    String kraj;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_adding);

        imie = (EditText) findViewById(R.id.imie);
        nazwisko = (EditText) findViewById(R.id.nazwisko);
        rokur = (EditText) findViewById(R.id.rokUrodzenia);
        pan = (RadioButton) findViewById(R.id.radioM);
        pani = (RadioButton) findViewById(R.id.radioK);
        pochodzenie = (ListView) findViewById(R.id.pochodzenie);

        pochodzenie.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                kraj = pochodzenie.getItemAtPosition(position).toString();
            }
        });
        pan.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                pani.setChecked(false);
                pan.setChecked(true);
            }
        });
        pani.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                pan.setChecked(false);
                pani.setChecked(true);
            }
        });

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,android.R.layout.simple_list_item_1,getResources().getStringArray(R.array.kraje));
        pochodzenie.setAdapter(adapter);
    }

    public void osobaAnuluj(View view) {
        onBackPressed();
    }

    public void osobaDodaj(View view) {
        String imie = this.imie.getText().toString();
        String nazwisko = this.nazwisko.getText().toString();
        int rok = Integer.parseInt(rokur.getText().toString());
        boolean plec = true;
        if (pan.isChecked() && !pani.isChecked())
            plec = true;
        if (pani.isChecked() && pan.isChecked())
            plec = false;
        boolean student = ((Switch) findViewById(R.id.switchStudent)).isChecked();
        double spryt = ((RatingBar) findViewById(R.id.ratingBarSpryt)).getRating();
        try {
            PrintWriter fout = new PrintWriter(openFileOutput("ludzie",MODE_APPEND));
            fout.append(imie); fout.println();
            fout.append(nazwisko); fout.println();
            fout.append(Integer.toString(rok)); fout.println();
            fout.append(Boolean.toString(plec)); fout.println();
            fout.append(kraj); fout.println();
            fout.append(Boolean.toString(student)); fout.println();
            fout.append(Double.toString(spryt)); fout.println();
            fout.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz", "Brak pliku.");
        } catch (IOException e) {
            Log.d("xyz","Nieudany zapis do pliku.");
        }
        onBackPressed();
    }
}
