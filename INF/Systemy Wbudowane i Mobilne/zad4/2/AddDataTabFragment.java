package com.example.dawidperdek.zad4app;


import android.app.Activity;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RadioGroup;


/**
 * A simple {@link Fragment} subclass.
 */
public class AddDataTabFragment extends Fragment implements RadioGroup.OnCheckedChangeListener, OnSportChangedListener {
    FragmentTransaction transaction;
    AddBasketballerFragment addBasketballerFragment;
    AddFootballerFragment addFootballerFragment;
    AppCompatActivity activity;

    @Override
    public void onAttach(Activity activity) {
        super.onAttach(activity);
        this.activity = (AppCompatActivity) activity;
        addBasketballerFragment = new AddBasketballerFragment();
        addFootballerFragment = new AddFootballerFragment();
        transaction = getFragmentManager().beginTransaction();
        transaction.add(R.id.addingContainer, addFootballerFragment);
        transaction.detach(addFootballerFragment);
        transaction.add(R.id.addingContainer, addBasketballerFragment);
        transaction.detach(addBasketballerFragment);
        transaction.commit();
    }

    public AddDataTabFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_add_data_tab, container, false);
    }

    @Override
    public void onCheckedChanged(RadioGroup group, int checkedId) {
        switch (checkedId) {
            case R.id.radioButtonBasketballer:
                onSportChanged(1);
                break;
            case R.id.radioButtonFootballer:
                onSportChanged(2);
                break;
        }
    }

    @Override
    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        ((RadioGroup) getActivity().findViewById(R.id.radioGroupSport)).setOnCheckedChangeListener(this);
    }

    @Override
    public void onSportChanged(int sport) {
        transaction = getFragmentManager().beginTransaction();
        transaction.detach(addBasketballerFragment);
        transaction.detach(addFootballerFragment);
        switch (sport) {
            case 1:
                transaction.attach(addBasketballerFragment);
                break;
            case 2:
                transaction.attach(addFootballerFragment);
                break;
        }
        transaction.commit();
    }
}
