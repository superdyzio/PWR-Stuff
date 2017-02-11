package com.example.dawidperdek.farbiarnia;


import android.graphics.Color;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


/**
 * A simple {@link Fragment} subclass.
 */
public class MieszanieFragment extends Fragment {
    EditText nazwa;
    TextView nazwa1, nazwa2;
    SeekBar wspolczynnik;
    Button kolor;
    CustomListViewAdapter adapter;
    ArrayList<Farba> farby;
    ListView listafarb1, listafarb2;
    Farba f1, f2;
    double r, g, b, wsp;
    String n1, n2;

    public MieszanieFragment() {
        // Required empty public constructor
    }

    public void wczytajFarby() {
        try {
            Scanner in = new Scanner(getContext().openFileInput("farby"));
            while (in.hasNextLine())
                if (Boolean.parseBoolean(in.nextLine()))
                    farby.add(new Farba(in.nextLine(),Integer.parseInt(in.nextLine()),Integer.parseInt(in.nextLine()),Integer.parseInt(in.nextLine())));
                else
                    farby.add(new Farba(in.nextLine(), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Double.parseDouble(in.nextLine()), in.nextLine(), in.nextLine()));
            in.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz", e.toString());
        } catch (IOException e) {
            Log.d("xyz", e.toString());
        }
    }

    @Override
    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        nazwa = (EditText) getActivity().findViewById(R.id.editTextMieszanieNazwa);
        wspolczynnik = (SeekBar) getActivity().findViewById(R.id.seekBarWspolczynnik);
        kolor = (Button) getActivity().findViewById(R.id.buttonKolorZmieszany);
        nazwa1 = (TextView) getActivity().findViewById(R.id.textViewMieszanieNazwa1);
        nazwa2 = (TextView) getActivity().findViewById(R.id.textViewMieszanieNazwa2);
        farby = new ArrayList<Farba>(20);
        adapter = new CustomListViewAdapter(getContext(), farby);
        wczytajFarby();
        listafarb1 = (ListView) getActivity().findViewById(R.id.listViewMieszanieFarba1);
        listafarb1.setAdapter(adapter);
        listafarb2 = (ListView) getActivity().findViewById(R.id.listViewMieszanieFarba2);
        listafarb2.setAdapter(adapter);
        listafarb1.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                listafarb1 = (ListView) getActivity().findViewById(R.id.listViewMieszanieFarba1);
                listafarb1.setSelection(position);
                nazwa1 = (TextView) getActivity().findViewById(R.id.textViewMieszanieNazwa1);
                f1 = farby.get(position);
                nazwa1.setText(f1.nazwa);
                n1 = f1.nazwa;
            }
        });
        listafarb2.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                listafarb2 = (ListView) getActivity().findViewById(R.id.listViewMieszanieFarba2);
                listafarb2.setSelection(position);
                nazwa2 = (TextView) getActivity().findViewById(R.id.textViewMieszanieNazwa2);
                f2 = farby.get(position);
                nazwa2.setText(f2.nazwa);
                n2 = f2.nazwa;
            }
        });
        wspolczynnik.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                kolor = (Button) getActivity().findViewById(R.id.buttonKolorZmieszany);
                wsp = progress;
                if (f1 != null && f2 != null) {
                    r = f2.r * wsp / wspolczynnik.getMax() + f1.r * (1 - wsp / wspolczynnik.getMax());
                    g = f2.g * wsp / wspolczynnik.getMax() + f1.g * (1 - wsp / wspolczynnik.getMax());
                    b = f2.b * wsp / wspolczynnik.getMax() + f1.b * (1 - wsp / wspolczynnik.getMax());
                    kolor.setBackgroundColor(Color.rgb((int) r, (int) g, (int) b));
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {}
        });
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_mieszanie, container, false);
    }

}
