package com.example.dawidperdek.farbiarnia;

import android.content.Context;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;

public class MainActivity extends AppCompatActivity {
    FragmentTransaction transaction;
    DodawanieFragment dfrag;
    MieszanieFragment mfrag;
    ListaFragment lfrag;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar myToolbar = (Toolbar) findViewById(R.id.toolbarMain);
        setSupportActionBar(myToolbar);
        dfrag = new DodawanieFragment();
        mfrag = new MieszanieFragment();
        lfrag = new ListaFragment();
        lfrag.czysty = true;
        transaction = getSupportFragmentManager().beginTransaction();
        transaction.add(R.id.mainContainer, dfrag);
        transaction.detach(dfrag);
        transaction.add(R.id.mainContainer, mfrag);
        transaction.detach(mfrag);
        transaction.add(R.id.mainContainer, lfrag);
        transaction.detach(lfrag);
        transaction.commit();


//        try {
//            PrintWriter fout = new PrintWriter(openFileOutput("farby", MODE_PRIVATE));
//            fout.close();
//        } catch (FileNotFoundException e) {
//            e.printStackTrace();
//        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.toolbar_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        transaction = getSupportFragmentManager().beginTransaction();
        transaction.detach(lfrag);
        transaction.detach(dfrag);
        transaction.detach(mfrag);
        switch (item.getItemId()) {
            case R.id.menuTab1:
                transaction.attach(lfrag);
                break;
            case R.id.menuTab2:
                transaction.attach(dfrag);
                czyscKontener();
                break;
            case R.id.menuTab3:
                transaction.attach(mfrag);
                czyscKontener();
                break;
            default:
                transaction.commit();
                return super.onOptionsItemSelected(item);
        }
        transaction.commit();
        return true;
    }

    private void czyscKontener() {
        if (!lfrag.czysty) {
            FragmentTransaction t = lfrag.getChildFragmentManager().beginTransaction();
            t.detach(lfrag.dodana);
            t.detach(lfrag.zmieszana);
            t.commit();
        }
        lfrag.czysty = true;
    }

    public void dodajNowaFarbe(View view) {
        if (dfrag.nazwa.getText().length() < 1) {
            Toast.makeText(this, "Nazwa nie może być pusta.", Toast.LENGTH_SHORT).show();
            return;
        }
        try {
            PrintWriter fout = new PrintWriter(openFileOutput("farby", MODE_APPEND));
            fout.append(Boolean.toString(true)); fout.println();
            fout.append(dfrag.nazwa.getText()); fout.println();
            fout.append(Integer.toString(dfrag.rgbR.getProgress())); fout.println();
            fout.append(Integer.toString(dfrag.rgbG.getProgress())); fout.println();
            fout.append(Integer.toString(dfrag.rgbB.getProgress())); fout.println();
            fout.close();
            Toast.makeText(this, "Farba dodana.", Toast.LENGTH_SHORT).show();
            dfrag.rgbR.setProgress(0);
            dfrag.rgbG.setProgress(0);
            dfrag.rgbB.setProgress(0);
            dfrag.nazwa.setText("");
        } catch (FileNotFoundException e) {
            Log.d("xyz", "Brak pliku.");
        } catch (IOException e) {
            Log.d("xyz", "Nieudany zapis do pliku.");
        }
    }

    public void przyciskDodaj(View view) {
        if (mfrag.nazwa.getText().length() < 1) {
            Toast.makeText(this, "Nazwa nie może być pusta.", Toast.LENGTH_SHORT).show();
            return;
        }
        if (mfrag.nazwa1.getText().length() < 1 || mfrag.nazwa2.getText().length() < 1) {
            Toast.makeText(this, "Wybierz farby składowe.", Toast.LENGTH_SHORT).show();
            return;
        }
        try {
            PrintWriter fout = new PrintWriter(openFileOutput("farby", MODE_APPEND));
            fout.append(Boolean.toString(false)); fout.println();
            fout.append(mfrag.nazwa.getText()); fout.println();
            fout.append(Integer.toString((int) mfrag.r)); fout.println();
            fout.append(Integer.toString((int)mfrag.g)); fout.println();
            fout.append(Integer.toString((int)mfrag.b)); fout.println();
            fout.append(Double.toString(mfrag.wsp)); fout.println();
            fout.append(mfrag.n1); fout.println();
            fout.append(mfrag.n2); fout.println();
            fout.close();
            Toast.makeText(this, "Farba dodana.", Toast.LENGTH_SHORT).show();
            mfrag.nazwa.setText("");
        } catch (FileNotFoundException e) {
            Log.d("xyz", "Brak pliku.");
        } catch (IOException e) {
            Log.d("xyz", "Nieudany zapis do pliku.");
        }
    }

}
