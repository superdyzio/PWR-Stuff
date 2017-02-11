package com.example.dawidperdek.androidzadanie2;

import android.content.Context;
import android.util.Log;
import android.widget.ArrayAdapter;

/**
 * Created by Dawid Perdek on 2016-04-10.
 */
public class MySpinnerAdapter extends ArrayAdapter<String> {
    private Context context;
    String[] data = null;

    public MySpinnerAdapter(Context context, int resource, String[] objects) {
        super(context, resource, objects);
        this.context = context;
        data = objects;
    }
}
