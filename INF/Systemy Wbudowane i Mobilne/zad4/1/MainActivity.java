package com.example.dawidperdek.zad4prepare;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentTransaction;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements OnWyborOpcjiListener {
    Fragment11 f11;
    Fragment12 f12;
    Fragment13 f13;
    FragmentTransaction transakcja;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        f11 = new Fragment11();
        f12 = new Fragment12();
        f13 = new Fragment13();
        transakcja = getSupportFragmentManager().beginTransaction();
        transakcja.add(R.id.Kontener, f11);
        transakcja.detach(f11);
        transakcja.add(R.id.Kontener, f12);
        transakcja.detach(f12);
        transakcja.add(R.id.Kontener, f13);
        transakcja.detach(f13);
        transakcja.commit();
    }

    @Override
    public void onWyborOpcji(int opcja) {
        transakcja = getSupportFragmentManager().beginTransaction();
        transakcja.detach(f11);
        transakcja.detach(f12);
        transakcja.detach(f13);
        switch (opcja) {
            case 1:
                transakcja.attach(f11);
                break;
            case 2:
                transakcja.attach(f12);
                break;
            case 3:
                transakcja.attach(f13);
                break;
        }
        transakcja.commit();
    }
}
