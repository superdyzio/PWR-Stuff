package com.example.dawidperdek.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class Aktywnosc2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_aktywnosc2);
        View mojeokno2 = (View) findViewById(R.id.mojeokno2);
        mojeokno2.setOnLongClickListener(new View.OnLongClickListener()
        {
           public boolean onLongClick(View v) {
               finish();
               return false;
           }
        });
    }
}
