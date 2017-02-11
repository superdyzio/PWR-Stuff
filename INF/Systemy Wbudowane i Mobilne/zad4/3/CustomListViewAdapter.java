package com.example.dawidperdek.farbiarnia;

import android.content.Context;
import android.graphics.Color;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import java.util.List;

/**
 * Created by Dawid Perdek on 2016-04-14.
 */
public class CustomListViewAdapter extends ArrayAdapter {
    private Context context;
    private int resource;
    private LayoutInflater inflater;

    public CustomListViewAdapter(Context context, List<Farba> values) {
        super(context,R.layout.customlistviewfarby,values);
        this.context = context;
        this.resource = R.layout.customlistviewfarby;
        this.inflater = LayoutInflater.from(context);
    }

    public View getView(int position, View convertView, ViewGroup parent) {
        convertView = inflater.inflate(R.layout.customlistviewfarby, parent, false);
        Farba item = (Farba) getItem(position);
        TextView nazwa = (TextView) convertView.findViewById(R.id.textViewListaNazwa);
        TextView textR = (TextView) convertView.findViewById(R.id.textViewListaR);
        TextView textG = (TextView) convertView.findViewById(R.id.textViewListaG);
        TextView textB = (TextView) convertView.findViewById(R.id.textViewListaB);
        nazwa.setText(item.nazwa);
        textR.setText(Integer.toString(item.r));
        textG.setText(Integer.toString(item.g));
        textB.setText(Integer.toString(item.b));
        Button kolor = (Button) convertView.findViewById(R.id.buttonListaKolor);
        kolor.setBackgroundColor(Color.rgb(item.r, item.g, item.b));
        TextView mixnazwa1 = (TextView) convertView.findViewById(R.id.textViewListaMix1);
        TextView mixnazwa2 = (TextView) convertView.findViewById(R.id.textViewListaMix2);
        TextView wsp = (TextView) convertView.findViewById(R.id.textViewListaWsp);
        if (!item.nowa) {
            mixnazwa1.setText(item.mix1);
            mixnazwa2.setText(item.mix2);
            wsp.setText(Double.toString(item.wsp));
        }
        else {
            mixnazwa1.setText("");
            mixnazwa2.setText("");
            wsp.setText("");
        }
        return convertView;
    }
}
