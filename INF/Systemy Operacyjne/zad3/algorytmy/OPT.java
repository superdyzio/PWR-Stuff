package algorytmy;

import java.util.ArrayList;
import pamiec.*;
import odwolania.*;

public class OPT {
	public ArrayList<Odwolanie> kolejka;
	public int iloscBledow;
	
	public OPT(Generator g) {
		kolejka = g.lista;
		iloscBledow = 0;
	}
	
	public void realizuj(PamFiz ramki, PamWir strony) {
		Odwolanie o = null;
		for (int i = 0; i < kolejka.size(); i++) {
			o = kolejka.get(i);
			boolean umieszczone = false, znalezione = false;
			for (int j = 0; j < ramki.tab.length && !znalezione; j++) 
				if (ramki.tab[j].strona == strony.tab[o.indeksStrony]) {
					znalezione = true;
					strony.tab[o.indeksStrony].uzycieNast = 100000;
					boolean jest = false;
					for (int k = i+1; k < kolejka.size() && !jest; k++) {
						if (kolejka.get(k).indeksStrony == o.indeksStrony) {
							strony.tab[o.indeksStrony].uzycieNast = kolejka.get(k).indeksStrony;
							jest = true;
						}
					}
					ramki.tab[j].strona = strony.tab[o.indeksStrony];
				}
				else
					if (ramki.tab[j].strona == null) {
						umieszczone = true;
						strony.tab[o.indeksStrony].uzycieNast = 100000;
						boolean jest = false;
						for (int k = i+1; k < kolejka.size() && !jest; k++) {
							if (kolejka.get(k).indeksStrony == o.indeksStrony) {
								strony.tab[o.indeksStrony].uzycieNast = kolejka.get(k).indeksStrony;
								jest = true;
							}
						}
						ramki.tab[j].strona = strony.tab[o.indeksStrony];
						j = ramki.tab.length;
					}
			if (!znalezione && !umieszczone) {
				int indeks = ramki.wywalNieuzywana();
				iloscBledow++;
				strony.tab[o.indeksStrony].uzycieNast = 100000;
				boolean jest = false;
				for (int k = i+1; k < kolejka.size() && !jest; k++) {
					if (kolejka.get(k).indeksStrony == o.indeksStrony) {
						strony.tab[o.indeksStrony].uzycieNast = kolejka.get(k).indeksStrony;
						jest = true;
					}
				}
				ramki.tab[indeks].strona = strony.tab[o.indeksStrony];
			}
		}
	}
	
	public void wypisz(PamFiz ramki) {
		System.out.println();
		for (int i = 0; i < ramki.tab.length; i++)
			if (ramki.tab[i].strona != null) System.out.println(ramki.tab[i].strona.toString());
			else System.out.println("Ramka pusta.");
		System.out.println();
	}
}
