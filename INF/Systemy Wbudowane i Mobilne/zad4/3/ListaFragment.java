package com.example.dawidperdek.farbiarnia;


import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.Toast;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


/**
 * A simple {@link Fragment} subclass.
 */
public class ListaFragment extends Fragment {
    ListView listakolorow;
    ArrayList<Farba> farby;
    CustomListViewAdapter adapter;
    FragmentTransaction transaction;
    DodanaFragment dodana;
    ZmieszanaFragment zmieszana;
    boolean czysty;

    public ListaFragment() {
        // Required empty public constructor
    }

    public void wczytajFarby() {
        try {
            Scanner in = new Scanner(getContext().openFileInput("farby"));
            while (in.hasNextLine()) {
                if (Boolean.parseBoolean(in.nextLine()))
                    farby.add(new Farba(in.nextLine(), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine())));
                else
                    farby.add(new Farba(in.nextLine(), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), Double.parseDouble(in.nextLine()), in.nextLine(), in.nextLine()));
            }
            in.close();
        } catch (FileNotFoundException e) {
            Log.d("xyz",e.toString());
        } catch (IOException e) {
            Log.d("xyz", e.toString());
        }
    }

    @Override
    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        czysty = true;
        farby = new ArrayList<Farba>(20);
        adapter = new CustomListViewAdapter(getContext(), farby);
        wczytajFarby();
        listakolorow = (ListView) getActivity().findViewById(R.id.listaKolorow);
        listakolorow.setAdapter(adapter);

        dodana = new DodanaFragment();
        zmieszana = new ZmieszanaFragment();
        transaction = getChildFragmentManager().beginTransaction();
        transaction.add(R.id.listContainer, dodana);
        transaction.detach(dodana);
        transaction.add(R.id.listContainer, zmieszana);
        transaction.detach(zmieszana);
        transaction.commit();

        // zarządzanie fragmentami
        listakolorow.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                transaction = getChildFragmentManager().beginTransaction();
                transaction.detach(dodana);
                transaction.detach(zmieszana);
                if ((farby.get(position)).nowa)
                    transaction.attach(dodana);
                else
                    transaction.attach(zmieszana);
                transaction.commit();
                czysty = false;
            }
        });

        // usuwanie farby
        listakolorow.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                farby.remove(position);
                adapter.notifyDataSetChanged();
                try {
                    PrintWriter fout = new PrintWriter(getActivity().openFileOutput("farby", Context.MODE_PRIVATE));
                    for (int i = 0; i < farby.size(); i++) {
                        Farba pom = farby.get(i);
                        fout.append(Boolean.toString(pom.nowa)); fout.println();
                        fout.append(pom.nazwa); fout.println();
                        fout.append(Integer.toString(pom.r)); fout.println();
                        fout.append(Integer.toString(pom.g)); fout.println();
                        fout.append(Integer.toString(pom.b)); fout.println();
                        if (!pom.nowa) {
                            fout.append(Double.toString(pom.wsp)); fout.println();
                            fout.append(pom.mix1); fout.println();
                            fout.append(pom.mix2); fout.println();
                        }
                    }
                    fout.close();
                    Toast.makeText(getActivity(), "Farba usunięta.", Toast.LENGTH_SHORT).show();
                } catch (FileNotFoundException e) {
                    Log.d("xyz", e.toString());
                }
                return false;
            }
        });
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return  inflater.inflate(R.layout.fragment_lista, container, false);
    }

}
