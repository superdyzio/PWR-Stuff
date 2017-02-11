package com.example.dawidperdek.myapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Aktywnosc1 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_aktywnosc1);
        final Intent intencja1 = new Intent(this,Aktywnosc2.class);
        Button przycisk1 = (Button) findViewById(R.id.button);
        przycisk1.setOnClickListener(new View.OnClickListener()
        {
           public void onClick(View widok) {
               startActivity(intencja1);
           }
        });
    }

    public void uruchomDwa(View view) {
        final Intent intencja2 = new Intent(this,Aktywnosc2.class);
        startActivity(intencja2);
    }
}