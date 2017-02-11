package com.example.dawidperdek.myandroidapp3;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void uruchomProsta(View view) {
        final Intent intencja = new Intent(this,ListaProstaActivity.class);
        startActivity(intencja);
    }

    public void uruchomMulti(View view) {
        final Intent intencja = new Intent(this,ListaMultiActivity.class);
        startActivity(intencja);
    }

    public void uruchomGrid(View view) {
        final Intent intencja = new Intent(this,Grid1Activity.class);
        startActivity(intencja);
    }
}
