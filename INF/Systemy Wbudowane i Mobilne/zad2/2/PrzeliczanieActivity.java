package com.example.dawidperdek.myandroidapp2;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;

public class PrzeliczanieActivity extends Activity {
    int ILE = 50;
    double l1, l2, krok;
    double[] x = new double[ILE];
    double[] y = new double[ILE];
    RadioButton radio1, radio2, radio3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_przeliczanie);
        radio1 = (RadioButton) findViewById(R.id.f1);
        radio2 = (RadioButton) findViewById(R.id.f2);
        radio3 = (RadioButton) findViewById(R.id.f3);
        radio1.setChecked(true);
        radio2.setChecked(false);
        radio3.setChecked(false);
        Intent intent = getIntent();
        Bundle msg = intent.getExtras();
        l1 = msg.getDouble("pierwsza");
        l2 = msg.getDouble("druga");
        krok = (l2 - l1) / ILE;
        for (int i = 0; i < ILE; i++)
            x[i] = l1 + i*krok;
        for (int i = 0; i < ILE; i++)
            y[i] = Math.sin(x[i]);
        wyswietl();
    }

    public void onRadioButtonClicked(View view) {
        Log.d("XYZ","radio");
        boolean checked = ((RadioButton) view).isChecked();
        switch (view.getId()) {
            case R.id.f1:
                for (int i = 0; i < ILE; i++)
                    y[i] = Math.sin(x[i]);
                radio1.setChecked(true);
                radio2.setChecked(false);
                radio3.setChecked(false);
                break;
            case R.id.f2:
                for (int i = 0; i < ILE; i++)
                    y[i] = Math.cos(x[i]);
                radio1.setChecked(false);
                radio2.setChecked(true);
                radio3.setChecked(false);
                break;
            case R.id.f3:
                for (int i = 0; i < ILE; i++)
                    y[i] = 2 * x[i];
                radio1.setChecked(false);
                radio2.setChecked(false);
                radio3.setChecked(true);
                break;
        }
        wyswietl();
    }

    public void wyswietl() {
        EditText ekran = (EditText) findViewById(R.id.ekran);
        ekran.setText("");
        ekran.append("x          f(x)\n");
        for (int i = 0; i < ILE; i++) {
            String linia = String.format("%.2f       %.2f", x[i], y[i]);
            ekran.append(linia + "\n");
        }
    }
}
