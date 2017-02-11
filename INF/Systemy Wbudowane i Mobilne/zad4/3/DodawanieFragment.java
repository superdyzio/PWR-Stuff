package com.example.dawidperdek.farbiarnia;


import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.Toast;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;


/**
 * A simple {@link Fragment} subclass.
 */
public class DodawanieFragment extends Fragment implements SeekBar.OnSeekBarChangeListener {
    SeekBar rgbR, rgbG, rgbB;
    Button kolor;
    EditText nazwa;

    public DodawanieFragment() {
        // Required empty public constructor
    }

    @Override
    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        nazwa = (EditText) getActivity().findViewById(R.id.nazywanieFarby);
        rgbR = (SeekBar) getActivity().findViewById(R.id.nowaFarbaR);
        rgbG = (SeekBar) getActivity().findViewById(R.id.nowaFarbaG);
        rgbB = (SeekBar) getActivity().findViewById(R.id.nowaFarbaB);
        kolor = (Button) getActivity().findViewById(R.id.nowaFarbaKolor);

        rgbR.setOnSeekBarChangeListener(this);
        rgbG.setOnSeekBarChangeListener(this);
        rgbB.setOnSeekBarChangeListener(this);

        kolor.setBackgroundColor(Color.rgb(rgbR.getProgress(), rgbG.getProgress(), rgbB.getProgress()));
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_dodawanie, container, false);
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        kolor.setBackgroundColor(Color.rgb(rgbR.getProgress(),rgbG.getProgress(),rgbB.getProgress()));
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
        kolor.setBackgroundColor(Color.rgb(rgbR.getProgress(),rgbG.getProgress(),rgbB.getProgress()));
    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
        kolor.setBackgroundColor(Color.rgb(rgbR.getProgress(),rgbG.getProgress(),rgbB.getProgress()));
    }
}
