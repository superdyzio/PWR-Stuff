package com.example.dawidperdek.myandroidapp3;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class ListaProstaActivity extends Activity implements AdapterView.OnItemClickListener {
    String[] druzyny = new String[16];
    ListView lista;
    ArrayAdapter<String> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lista_prosta);
        adapter = new ArrayAdapter<String>(this,android.R.layout.simple_list_item_1,druzyny);
        druzyny[0] = "MKP Wołów";
        druzyny[1] = "Zjednoczeni Łowęcice";
        druzyny[2] = "Wiwa Goszcz";
        druzyny[3] = "Orzeł Sadowice";
        druzyny[4] = "Czarni Jelcz-Laskowice";
        druzyny[5] = "Strzelinianka Strzelin";
        druzyny[6] = "Widawa Bierutów";
        druzyny[7] = "Sokół Marcinkowice";
        druzyny[8] = "LKS Brożec";
        druzyny[9] = "Czarni Kondratowice";
        druzyny[10] = "GKS Mirków/Długołęka";
        druzyny[11] = "Polonia Środa Śląska";
        druzyny[12] = "Wratislavia Wrocław";
        druzyny[13] = "Bumerang Wrocław";
        druzyny[14] = "KS Łozina";
        druzyny[15] = "Burza Chwalibożyce";
        lista = (ListView) findViewById(R.id.listaprosta);
        lista.setAdapter(adapter);
        lista.setOnItemClickListener(this);
    }

    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Toast.makeText(this,druzyny[position],Toast.LENGTH_SHORT).show();
    }
}