package algorytmy;

import java.util.ArrayList;
import odwolania.*;
import pamiec.*;

public class RAND {
	public ArrayList<Odwolanie> kolejka;
	public int iloscBledow;
	
	public RAND(Generator g) {
		kolejka = g.lista;
		iloscBledow = 0;
	}
	
	public void realizuj(PamFiz ramki, PamWir strony) {
		for (Odwolanie o:kolejka) {
			boolean umieszczone = false, znalezione = false;
			for (int i = 0; i < ramki.tab.length && !znalezione; i++) 
				if (ramki.tab[i].strona == strony.tab[o.indeksStrony]) znalezione = true;
				else
					if (ramki.tab[i].strona == null) {
						ramki.tab[i].strona = strony.tab[o.indeksStrony];
						umieszczone = true;
						i = ramki.tab.length;
					}
			if (!znalezione && !umieszczone) {
				int indeks = ramki.wywalLosowa();
				iloscBledow++;
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
