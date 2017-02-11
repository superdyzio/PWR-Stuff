package com.example.dawidperdek.androidzadanie2;

import android.app.Activity;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Environment;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.TypedValue;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.Toast;

public class SettingsActivity extends Activity implements SeekBar.OnSeekBarChangeListener {
    SeekBar tloR, tloG, tloB, tekstR, tekstG, tekstB;
    Button bgColor;
    Spinner powitania;
    EditText tekst;
    String[] teksty;
    MySpinnerAdapter spinnerData;
    RadioButton mala, srednia, duza;
    String rozmiar;
    CheckBox wew, zew;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        tloR = (SeekBar) findViewById(R.id.seekBarR);
        tloG = (SeekBar) findViewById(R.id.seekBarG);
        tloB = (SeekBar) findViewById(R.id.seekBarB);
        tekstR = (SeekBar) findViewById(R.id.seekBarTextR);
        tekstG = (SeekBar) findViewById(R.id.seekBarTextG);
        tekstB = (SeekBar) findViewById(R.id.seekBarTextB);
        bgColor = (Button) findViewById(R.id.BackgroundColor);
        powitania = (Spinner) findViewById(R.id.spinnerPowitania);
        tekst = (EditText) findViewById(R.id.editTextPowitanie);
        teksty = new String[5];
        mala = (RadioButton) findViewById(R.id.fontMala);
        srednia = (RadioButton) findViewById(R.id.fontSrednia);
        duza = (RadioButton) findViewById(R.id.fontDuza);
        wew = (CheckBox) findViewById(R.id.checkBoxInternal);
        zew = (CheckBox) findViewById(R.id.checkBoxExternal);
        rozmiar = "";

        tloR.setOnSeekBarChangeListener(this);
        tloG.setOnSeekBarChangeListener(this);
        tloB.setOnSeekBarChangeListener(this);
        tekstR.setOnSeekBarChangeListener(this);
        tekstG.setOnSeekBarChangeListener(this);
        tekstB.setOnSeekBarChangeListener(this);

        SharedPreferences prefs = getSharedPreferences("ustawienia", MODE_PRIVATE);
        if (prefs != null) {
            tloR.setProgress(prefs.getInt("tloR",255));
            tloG.setProgress(prefs.getInt("tloG",255));
            tloB.setProgress(prefs.getInt("tloB",255));
            tekstR.setProgress(prefs.getInt("tekstR",0));
            tekstG.setProgress(prefs.getInt("tekstG",0));
            tekstB.setProgress(prefs.getInt("tekstB",0));
            teksty[0] = prefs.getString("tekst0","Witaj w aplikacji!");
            teksty[1] = prefs.getString("tekst1","Witam serdecznie!");
            teksty[2] = prefs.getString("tekst2","Co tam słychać?");
            teksty[3] = prefs.getString("tekst3","Miło znów Cię widzieć!");
            teksty[4] = prefs.getString("tekst4","Nie lubię cię.");
            wew.setChecked(prefs.getBoolean("wewnetrzna",false));
            zew.setChecked(prefs.getBoolean("zewnetrzna",false));
            Boolean isSDPresent = Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED);
//        Log.d("xyz",isSDPresent.toString());
//        Log.d("xyz",Environment.getExternalStorageState());
//        Log.d("xyz",Environment.MEDIA_MOUNTED);
            if (!isSDPresent && zew.isChecked()) {
                zew.setChecked(false);
                Toast.makeText(this,"Brak karty SD",Toast.LENGTH_SHORT).show();
            }
            rozmiar = prefs.getString("rozmiarczcionki","srednia");
            if (rozmiar.equals("mala")) {
                tekst.setTextSize(TypedValue.COMPLEX_UNIT_DIP,12);
                mala.setChecked(true);
                srednia.setChecked(false);
                duza.setChecked(false);
            }
            else if (rozmiar.equals("srednia")) {
                tekst.setTextSize(TypedValue.COMPLEX_UNIT_DIP,20);
                mala.setChecked(false);
                srednia.setChecked(true);
                duza.setChecked(false);
            }
            else if (rozmiar.equals("duza")) {
                tekst.setTextSize(TypedValue.COMPLEX_UNIT_DIP,28);
                mala.setChecked(false);
                srednia.setChecked(false);
                duza.setChecked(true);
            }
        }
        bgColor.setBackgroundColor(Color.rgb(tloR.getProgress(), tloG.getProgress(), tloB.getProgress()));
        tekst.setTextColor(Color.rgb(tekstR.getProgress(), tekstG.getProgress(), tekstB.getProgress()));

        spinnerData = new MySpinnerAdapter(this, android.R.layout.simple_spinner_item, teksty);
        spinnerData.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        powitania.setAdapter(spinnerData);

        if (prefs != null) {
            powitania.setSelection(prefs.getInt("wybranytekst",0));
            tekst.setText(teksty[powitania.getSelectedItemPosition()]);
        }

        powitania.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                tekst.setText(teksty[position]);
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        tekst.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {
                teksty[powitania.getSelectedItemPosition()] = tekst.getText().toString();
            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                teksty[powitania.getSelectedItemPosition()] = tekst.getText().toString();
            }

            @Override
            public void afterTextChanged(Editable s) {
                teksty[powitania.getSelectedItemPosition()] = tekst.getText().toString();
            }
        });
    }

    public void zatwierdz(View view) {
        tloR = (SeekBar) findViewById(R.id.seekBarR);
        tloG = (SeekBar) findViewById(R.id.seekBarG);
        tloB = (SeekBar) findViewById(R.id.seekBarB);
        tekstR = (SeekBar) findViewById(R.id.seekBarTextR);
        tekstG = (SeekBar) findViewById(R.id.seekBarTextG);
        tekstB = (SeekBar) findViewById(R.id.seekBarTextB);
        powitania = (Spinner) findViewById(R.id.spinnerPowitania);
        tekst = (EditText) findViewById(R.id.editTextPowitanie);

        SharedPreferences.Editor editor = getSharedPreferences("ustawienia", MODE_PRIVATE).edit();
        editor.putInt("tloR", tloR.getProgress());
        editor.putInt("tloG", tloG.getProgress());
        editor.putInt("tloB", tloB.getProgress());
        editor.putInt("tekstR", tekstR.getProgress());
        editor.putInt("tekstG", tekstG.getProgress());
        editor.putInt("tekstB", tekstB.getProgress());
        editor.putString("tekst0", teksty[0]);
        editor.putString("tekst1", teksty[1]);
        editor.putString("tekst2", teksty[2]);
        editor.putString("tekst3", teksty[3]);
        editor.putString("tekst4", teksty[4]);
        editor.putInt("wybranytekst", powitania.getSelectedItemPosition());
        editor.putString("rozmiarczcionki", rozmiar);
        editor.putBoolean("zewnetrzna",zew.isChecked());
        editor.putBoolean("wewnetrzna",wew.isChecked());
        editor.commit();
        onBackPressed();
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        bgColor.setBackgroundColor(Color.rgb(tloR.getProgress(),tloG.getProgress(),tloB.getProgress()));
        tekst.setTextColor(Color.rgb(tekstR.getProgress(), tekstG.getProgress(), tekstB.getProgress()));
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
        bgColor.setBackgroundColor(Color.rgb(tloR.getProgress(),tloG.getProgress(),tloB.getProgress()));
        tekst.setTextColor(Color.rgb(tekstR.getProgress(), tekstG.getProgress(), tekstB.getProgress()));
    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
        bgColor.setBackgroundColor(Color.rgb(tloR.getProgress(), tloG.getProgress(), tloB.getProgress()));
        tekst.setTextColor(Color.rgb(tekstR.getProgress(), tekstG.getProgress(), tekstB.getProgress()));
    }

    public void radioMala(View view) {
        mala = (RadioButton) findViewById(R.id.fontMala);
        srednia = (RadioButton) findViewById(R.id.fontSrednia);
        duza = (RadioButton) findViewById(R.id.fontDuza);
        tekst = (EditText) findViewById(R.id.editTextPowitanie);
        tekst.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 12);
        mala.setChecked(true);
        srednia.setChecked(false);
        duza.setChecked(false);
        rozmiar = "mala";
    }

    public void radioSrednia(View view) {
        mala = (RadioButton) findViewById(R.id.fontMala);
        srednia = (RadioButton) findViewById(R.id.fontSrednia);
        duza = (RadioButton) findViewById(R.id.fontDuza);
        tekst = (EditText) findViewById(R.id.editTextPowitanie);
        tekst.setTextSize(TypedValue.COMPLEX_UNIT_DIP,20);
        mala.setChecked(false);
        srednia.setChecked(true);
        duza.setChecked(false);
        rozmiar = "srednia";
    }

    public void radioDuza(View view) {
        mala = (RadioButton) findViewById(R.id.fontMala);
        srednia = (RadioButton) findViewById(R.id.fontSrednia);
        duza = (RadioButton) findViewById(R.id.fontDuza);
        tekst = (EditText) findViewById(R.id.editTextPowitanie);
        tekst.setTextSize(TypedValue.COMPLEX_UNIT_DIP,28);
        mala.setChecked(false);
        srednia.setChecked(false);
        duza.setChecked(true);
        rozmiar = "duza";
    }

    // jak nie ma pamięci to od razu wyzerować checkboxa, sprawdzać też na głównym ekranie - jeśli true a nie ma karty to coś robić
    public void clickExt(View view) {
        zew = (CheckBox) findViewById(R.id.checkBoxExternal);
        Boolean isSDPresent = Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED);
//        Log.d("xyz",isSDPresent.toString());
//        Log.d("xyz",Environment.getExternalStorageState());
//        Log.d("xyz",Environment.MEDIA_MOUNTED);
        if (!isSDPresent && zew.isChecked()) {
            zew.setChecked(false);
            Toast.makeText(this,"Brak karty SD",Toast.LENGTH_SHORT).show();
        }
    }
}
