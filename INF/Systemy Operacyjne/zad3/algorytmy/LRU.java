package algorytmy;

import java.util.ArrayList;
import pamiec.*;
import odwolania.*;

public class LRU {
	public ArrayList<Odwolanie> kolejka;
	public int iloscBledow;
	
	public LRU(Generator g) {
		kolejka = g.lista;
		iloscBledow = 0;
	}
	
	public void realizuj(PamFiz ramki, PamWir strony) {
		for (Odwolanie o:kolejka) {
			boolean umieszczone = false, znalezione = false;
			for (int i = 0; i < ramki.tab.length && !znalezione; i++) 
				if (ramki.tab[i].strona == strony.tab[o.indeksStrony]) {
					znalezione = true;
					strony.tab[o.indeksStrony].uzycieOst = o.czasWywolania;
					ramki.tab[i].strona = strony.tab[o.indeksStrony];
				}
				else
					if (ramki.tab[i].strona == null) {
						strony.tab[o.indeksStrony].uzycieOst = o.czasWywolania;
						ramki.tab[i].strona = strony.tab[o.indeksStrony];
						umieszczone = true;
						i = ramki.tab.length;
					}
			if (!znalezione && !umieszczone) {
				int indeks = ramki.wywalNajdawniejUzyta();
				iloscBledow++;
				strony.tab[o.indeksStrony].uzycieOst = o.czasWywolania;
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
