package com.example.dawidperdek.myandroidapp1;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    // wywoływanie poszczególnych aktywności intencjami jawnymi w metodach powiązanych z onClick przycisków

    public void uruchom_eng(View view) {
        final Intent intencja_eng = new Intent(this,AngielskaActivity.class);
        startActivity(intencja_eng);
    }

    public void uruchom_esp(View view) {
        final Intent intencja_esp = new Intent(this,HiszpanskaActivity.class);
        startActivity(intencja_esp);
    }

    public void uruchom_ger(View view) {
        final Intent intencja_ger = new Intent(this,NiemieckaActivity.class);
        startActivity(intencja_ger);
    }

    public void uruchom_but(View view) {
        final Intent intencja_but = new Intent(this,StrzelcyActivity.class);
        startActivity(intencja_but);
    }
}
