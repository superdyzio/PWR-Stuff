package com.example.dawidperdek.myandroidapp2;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import java.util.List;

public class GlownaActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_glowna);

        // wyświetlanie listy wszystkich pakietów
        final PackageManager pm = getPackageManager();
        List<ApplicationInfo> packages = pm.getInstalledApplications(PackageManager.GET_META_DATA);
        for (ApplicationInfo packageInfo : packages) {
            Log.d("XYZ", "Installed package :" + packageInfo.packageName);
            Log.d("XYZ", "Source dir : " + packageInfo.sourceDir);
            Log.d("XYZ", "Launch Activity :" + pm.getLaunchIntentForPackage(packageInfo.packageName));
        }
    }

    public void uruchomAplikacje(View widok) {
        // uruchomienie drugiej aplikacji za pomocą intencji niejawnej
        Intent launchIntent = new Intent("com.example.dawidperdek.myandroidapp1.ANOTHER_ACTIVITY");
        startActivity(launchIntent);
    }

    // aplikacje systemowe uruchomiane z wykorzystaniem mechanizmu wyszukującego odpowiednią intencję
    // na podstawie nazwy pakietu
    public void przycisk1OnClick(View widok) {
        Intent launchIntent = getPackageManager().getLaunchIntentForPackage("com.lge.fmradio");
        startActivity(launchIntent);
    }

    public void przycisk2OnClick(View widok) {
        Intent launchIntent = getPackageManager().getLaunchIntentForPackage("com.lge.camera");
        startActivity(launchIntent);
    }

    public void przycisk3OnClick(View widok) {
        Intent launchIntent = getPackageManager().getLaunchIntentForPackage("com.android.calendar");
        startActivity(launchIntent);
    }

    @Override
    public void onRestart() {
        super.onRestart();
        // przy restarcie aplikacji (powrocie z innej aplikacji) wyświetl komunikat
        Toast.makeText(this,"Znów jestem!",Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onPause() {
        super.onPause();
        // przy pauzowaniu aplikacji (przy wyjściu do innej aplikacji) wyświetl komunikat
        Toast.makeText(this,"Jeszcze tu wrócę!!!",Toast.LENGTH_SHORT).show();
    }

    public void uruchomZadLab(View widok) {
        Intent launch = new Intent(this,LabGlownaActivity.class);
        startActivity(launch);
    }
}