package algorytmy;

import java.util.ArrayList;
import pamiec.*;
import odwolania.*;

public class Prop {
	public ArrayList<Odwolanie> kolejka;
	public int iloscBledow;
	
	public Prop(Generator g, Proces [] p, int ilr, PamFiz ramki) {
		kolejka = g.lista;
		iloscBledow = 0;
		int sumastron = 0;
		for (int i = 0; i < 10; i++) {
			p[i].ilBledow = 0;
			sumastron += p[i].ilStron;
		}
		for (int i = 0; i < 10; i++) {
			p[i].ilRamek = p[i].ilStron * ilr / sumastron;
			if (p[i].ilRamek == 0) p[i].ilRamek = 1;
			p[i].tabRamek = new int[p[i].ilRamek];
		}
		int licznik = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < p[i].ilRamek; j++) {
				p[i].tabRamek[j] = ramki.tab[licznik].indeks;
				ramki.tab[licznik].nrprocesu = i;
				licznik++;
			}
	}
	
	public void realizuj(PamWir strony, PamFiz ramki, Proces [] p) {
		for (Odwolanie o:kolejka) {
			boolean umieszczone = false, znalezione = false;
			for (int i = 0; i < p[o.nrProcesu].tabRamek.length && !znalezione; i++)
				if (ramki.tab[p[o.nrProcesu].tabRamek[i]].strona == strony.tab[o.indeksStrony]) {
					znalezione = true;
					strony.tab[o.indeksStrony].uzycieOst = o.czasWywolania;
					ramki.tab[p[o.nrProcesu].tabRamek[i]].strona.uzycieOst = o.czasWywolania;
				}
				else
					if (ramki.tab[p[o.nrProcesu].tabRamek[i]].strona == null) {
						strony.tab[o.indeksStrony].uzycieOst = o.czasWywolania;
						ramki.tab[p[o.nrProcesu].tabRamek[i]].strona = strony.tab[o.indeksStrony];
						umieszczone = true;
						i = p[o.nrProcesu].tabRamek.length;
					}
			if (!znalezione && !umieszczone) {
				int indeks = ramki.wywalNajdawniejUzyta(p[o.nrProcesu]);
				iloscBledow++;
				p[o.nrProcesu].ilBledow++;
				strony.tab[o.indeksStrony].uzycieOst = o.czasWywolania;
				ramki.tab[indeks].strona = strony.tab[o.indeksStrony];
			}
		}
	}
}
