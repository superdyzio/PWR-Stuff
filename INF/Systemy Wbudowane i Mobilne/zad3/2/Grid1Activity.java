package com.example.dawidperdek.myandroidapp3;

import android.app.Activity;
import android.os.Bundle;
import android.widget.GridView;

public class Grid1Activity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_grid1);
        GridView gridView = (GridView) findViewById(R.id.gridView);
        gridView.setAdapter(new myAdapter(this));
    }
}
