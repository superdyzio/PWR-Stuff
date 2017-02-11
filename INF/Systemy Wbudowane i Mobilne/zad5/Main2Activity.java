package com.example.dawidperdek.zad5app;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.SubMenu;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class Main2Activity extends AppCompatActivity {
    private static final int menuSmallFont = 0, menuMediumFont = 1, menuLargeFont = 2,
        menuRedFont = 3, menuGreenFont = 4, menuBlueFont = 5,
        contextSmallFont = 6, contextMediumFont = 7, contextLargeFont = 8,
        contextRedFont = 9, contextGreenFont = 10, contextBlueFont = 11,
        checkableGroup = 12, colorR = 13, colorG = 14, colorB = 15;
    int r, g, b;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        registerForContextMenu(findViewById(R.id.editTextName2));
        registerForContextMenu(findViewById(R.id.editTextSurname2));
        registerForContextMenu(findViewById(R.id.buttonColor2));
        ustawKolor();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_toolbar2, menu);
        menu.add(Menu.NONE, menuSmallFont, 1, "Mała czcionka");
        menu.add(Menu.NONE, menuMediumFont, 1, "Średnia czcionka");
        menu.add(Menu.NONE, menuLargeFont, 1, "Duża czcionka");
        SubMenu sm = menu.addSubMenu("Kolory");
        sm.add(Menu.NONE, menuRedFont, 1, "Czerwony");
        sm.add(Menu.NONE, menuGreenFont, 1, "Zielony");
        sm.add(Menu.NONE, menuBlueFont, 1, "Niebieski");
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        TextView lname = (TextView) findViewById(R.id.textViewName2);
        TextView lsurname = (TextView) findViewById(R.id.textViewSurname2);
        EditText name = (EditText) findViewById(R.id.editTextName2);
        EditText surname = (EditText) findViewById(R.id.editTextSurname2);
        switch (item.getItemId()) {
            case menuSmallFont:
                name.setTextSize(11);
                surname.setTextSize(11);
                lname.setTextSize(11);
                lsurname.setTextSize(11);
                return true;
            case menuMediumFont:
                name.setTextSize(15);
                surname.setTextSize(15);
                lname.setTextSize(15);
                lsurname.setTextSize(15);
                return true;
            case menuLargeFont:
                name.setTextSize(19);
                surname.setTextSize(19);
                lname.setTextSize(19);
                lsurname.setTextSize(19);
                return true;
            case menuRedFont:
                name.setTextColor(Color.RED);
                surname.setTextColor(Color.RED);
                lname.setTextColor(Color.RED);
                lsurname.setTextColor(Color.RED);
                return true;
            case menuGreenFont:
                name.setTextColor(Color.GREEN);
                surname.setTextColor(Color.GREEN);
                lname.setTextColor(Color.GREEN);
                lsurname.setTextColor(Color.GREEN);
                return true;
            case menuBlueFont:
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
        if (v.getId() == R.id.editTextName2) {
            inflater.inflate(R.menu.context_color2, menu);
            menu.add(Menu.NONE, contextSmallFont, 1, "Mała czcionka");
            menu.add(Menu.NONE, contextMediumFont, 1, "Średnia czcionka");
            menu.add(Menu.NONE, contextLargeFont, 1, "Duża czcionka");
        }
        if (v.getId() == R.id.editTextSurname2) {
            inflater.inflate(R.menu.context_size2, menu);
            menu.add(Menu.NONE, contextRedFont, 1, "Czerwona czcionka");
            menu.add(Menu.NONE, contextGreenFont, 1, "Zielona czcionka");
            menu.add(Menu.NONE, contextBlueFont, 1, "Niebieska czcionka");
        }
        if (v.getId() == R.id.buttonColor2) {
            inflater.inflate(R.menu.context_checkable2, menu);
            menu.add(checkableGroup, colorR, 1, "Czerwony");
            menu.add(checkableGroup, colorG, 1, "Zielony");
            menu.add(checkableGroup, colorB, 1, "Niebieskie");
            menu.setGroupCheckable(checkableGroup, true, false);
            menu.getItem(0).setChecked(r == 255);
            menu.getItem(1).setChecked(g == 255);
            menu.getItem(2).setChecked(b == 255);
        }
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {
        EditText name = (EditText) findViewById(R.id.editTextName2);
        EditText surname = (EditText) findViewById(R.id.editTextSurname2);
        AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) item.getMenuInfo();
        switch (item.getItemId()) {
            case contextSmallFont:
                name.setTextSize(11);
                return true;
            case contextMediumFont:
                name.setTextSize(15);
                return true;
            case contextLargeFont:
                name.setTextSize(19);
                return true;
            case contextRedFont:
                surname.setTextColor(Color.RED);
                return true;
            case contextGreenFont:
                surname.setTextColor(Color.GREEN);
                return true;
            case contextBlueFont:
                surname.setTextColor(Color.BLUE);
                return true;
            case colorR:
                item.setChecked(!item.isChecked());
                if (item.isChecked())
                    r = 255;
                else
                    r = 0;
                ustawKolor();
                return true;
            case colorG:
                item.setChecked(!item.isChecked());
                if (item.isChecked())
                    g = 255;
                else
                    g = 0;
                ustawKolor();
                return true;
            case colorB:
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
        Button color = (Button) findViewById(R.id.buttonColor2);
        color.setBackgroundColor(Color.rgb(r,g,b));
    }
}
