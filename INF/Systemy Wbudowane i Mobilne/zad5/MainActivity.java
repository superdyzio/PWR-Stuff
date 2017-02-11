package com.example.dawidperdek.zad5app;

import android.content.Intent;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    int r, g, b;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        registerForContextMenu(findViewById(R.id.editTextName));
        registerForContextMenu(findViewById(R.id.editTextSurname));
        registerForContextMenu(findViewById(R.id.buttonColor));
        ustawKolor();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_toolbar, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        TextView lname = (TextView) findViewById(R.id.textViewName);
        TextView lsurname = (TextView) findViewById(R.id.textViewSurname);
        EditText name = (EditText) findViewById(R.id.editTextName);
        EditText surname = (EditText) findViewById(R.id.editTextSurname);
        switch (item.getItemId()) {
            case R.id.menuFontS:
                name.setTextSize(11);
                surname.setTextSize(11);
                lname.setTextSize(11);
                lsurname.setTextSize(11);
                return true;
            case R.id.menuFontM:
                name.setTextSize(15);
                surname.setTextSize(15);
                lname.setTextSize(15);
                lsurname.setTextSize(15);
                return true;
            case R.id.menuFontL:
                name.setTextSize(19);
                surname.setTextSize(19);
                lname.setTextSize(19);
                lsurname.setTextSize(19);
                return true;
            case R.id.menuFontR:
                name.setTextColor(Color.RED);
                surname.setTextColor(Color.RED);
                lname.setTextColor(Color.RED);
                lsurname.setTextColor(Color.RED);
                return true;
            case R.id.menuFontG:
                name.setTextColor(Color.GREEN);
                surname.setTextColor(Color.GREEN);
                lname.setTextColor(Color.GREEN);
                lsurname.setTextColor(Color.GREEN);
                return true;
            case R.id.menuFontB:
                name.setTextColor(Color.BLUE);
                surname.setTextColor(Color.BLUE);
                lname.setTextColor(Color.BLUE);
                lsurname.setTextColor(Color.BLUE);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);
        MenuInflater inflater = getMenuInflater();
        if (v.getId() == R.id.editTextName)
            inflater.inflate(R.menu.context_color, menu);
        if (v.getId() == R.id.editTextSurname)
            inflater.inflate(R.menu.context_size, menu);
        if (v.getId() == R.id.buttonColor) {
            inflater.inflate(R.menu.context_checkable, menu);
            menu.getItem(0).setChecked(r == 255);
            menu.getItem(1).setChecked(g == 255);
            menu.getItem(2).setChecked(b == 255);
        }
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {
        EditText name = (EditText) findViewById(R.id.editTextName);
        EditText surname = (EditText) findViewById(R.id.editTextSurname);
        AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) item.getMenuInfo();
        switch (item.getItemId()) {
            case R.id.contextFontS:
                surname.setTextSize(11);
                return true;
            case R.id.contextFontM:
                surname.setTextSize(15);
                return true;
            case R.id.contextFontL:
                surname.setTextSize(19);
                return true;
            case R.id.contextFontR:
                name.setTextColor(Color.RED);
                return true;
            case R.id.contextFontG:
                name.setTextColor(Color.GREEN);
                return true;
            case R.id.contextFontB:
                name.setTextColor(Color.BLUE);
                return true;
            case R.id.checkableR:
                item.setChecked(!item.isChecked());
                if (item.isChecked())
                    r = 255;
                else
                    r = 0;
                ustawKolor();
                return true;
            case R.id.checkableG:
                item.setChecked(!item.isChecked());
                if (item.isChecked())
                    g = 255;
                else
                    g = 0;
                ustawKolor();
                return true;
            case R.id.checkableB:
                item.setChecked(!item.isChecked());
                if (item.isChecked())
                    b = 255;
                else
                    b = 0;
                ustawKolor();
                return true;
            default:
                return super.onContextItemSelected(item);
        }
    }

    public void ustawKolor() {
        Button color = (Button) findViewById(R.id.buttonColor);
        color.setBackgroundColor(Color.rgb(r,g,b));
    }

    public void secondActivity(View view) {
        final Intent intencja = new Intent(this,Main2Activity.class);
        startActivity(intencja);
    }
}
