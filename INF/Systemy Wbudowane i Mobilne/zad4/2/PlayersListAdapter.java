package com.example.dawidperdek.zad4app;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.List;

/**
 * Created by Dawid Perdek on 2016-05-09.
 */
public class PlayersListAdapter extends ArrayAdapter {
    private Context context;
    private int resource;
    private LayoutInflater inflater;

    public PlayersListAdapter(Context context, List<Player> values) {
        super(context,R.layout.player_listview_layout,values);
        this.context = context;
        this.resource = R.layout.player_listview_layout;
        this.inflater = LayoutInflater.from(context);
    }

    public View getView(int position, View convertView, ViewGroup parent) {
        Player item = (Player) getItem(position);
        convertView = inflater.inflate(R.layout.player_listview_layout, parent, false);
        TextView imie = (TextView) convertView.findViewById(R.id.textViewListViewPlayerName);
        TextView nazwisko = (TextView) convertView.findViewById(R.id.textViewListViewPlayerSurname);
        TextView wzrost = (TextView) convertView.findViewById(R.id.textViewListViewPlayerHeight);
        TextView waga = (TextView) convertView.findViewById(R.id.textViewListViewPlayerWeight);
        imie.setText(item.imie);
        nazwisko.setText(item.nazwisko);
        wzrost.setText(item.wzrost);
        waga.setText(item.waga);
        return convertView;
    }
}
