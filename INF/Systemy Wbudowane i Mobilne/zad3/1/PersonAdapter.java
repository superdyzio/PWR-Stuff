package com.example.dawidperdek.androidzadanie2;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;
import java.util.List;

/**
 * Created by Dawid Perdek on 2016-04-18.
 */
public class PersonAdapter extends ArrayAdapter {
    private Context context;
    private int resource;
    private LayoutInflater inflater;

    public PersonAdapter(Context context, List<Person> values) {
        super(context,R.layout.customviewperson,values);
        this.context = context;
        this.resource = R.layout.customviewperson;
        this.inflater = LayoutInflater.from(context);
    }

    public View getView(int position, View convertView, ViewGroup parent) {
        convertView = inflater.inflate(R.layout.customviewperson, parent, false);
        TextView imie, nazwisko, rok, kraj, plec, spryt, student;

        imie = (TextView) convertView.findViewById(R.id.osobaImie);
        nazwisko = (TextView) convertView.findViewById(R.id.osobaNazwisko);
        rok = (TextView) convertView.findViewById(R.id.osobaRok);
        kraj = (TextView) convertView.findViewById(R.id.osobaKraj);
        plec = (TextView) convertView.findViewById(R.id.osobaPlec);
        spryt = (TextView) convertView.findViewById(R.id.osobaSpryt);
        student = (TextView) convertView.findViewById(R.id.osobaStudent);

        Person osoba = (Person) getItem(position);

        imie.setText(osoba.imie);
        nazwisko.setText(osoba.nazwisko);
        rok.setText(Integer.toString(osoba.rok));
        kraj.setText(osoba.kraj);
        if (osoba.plec)
            plec.setText("M");
        else
            plec.setText("K");
        spryt.setText(Double.toString(osoba.spryt));
        if (osoba.student)
            student.setText("Student");
        else
            student.setText("niestudent");

        return convertView;
    }
}
