package algorytmy;

import java.util.ArrayList;
import pamiec.*;
import odwolania.*;

public class Strefa {
	public ArrayList<Odwolanie> kolejka;
	public int iloscBledow, sumaRamek;

	public Strefa(Generator g, Proces [] p, int ilr, PamFiz ramki) {
		kolejka = g.lista;
		iloscBledow = 0;
		sumaRamek = ilr;
		for (int i = 0; i < 10; i++) {
			p[i].ilRamek = p[i].ilStron;
			p[i].ilBledow = 0;
			p[i].tabRamek = new int[p[i].ilRamek];
		}
	}

	public void realizuj(PamWir strony, PamFiz ramki, Proces [] p) {
		for (Odwolanie o:kolejka) {
			boolean umieszczone = false, znalezione = false;
			if (!p[o.nrProcesu].wPamieci) 
				if (ramki.ilePustych() >= p[o.nrProcesu].ilRamek) 
					for (int i = 0; i < p[o.nrProcesu].ilRamek; i++) {
						p[o.nrProcesu].tabRamek[i] = ramki.dajPusta();
						ramki.tab[ramki.dajPusta()].nrprocesu = o.nrProcesu;
						p[o.nrProcesu].wPamieci = true;
					}
				else 
					if (p[o.nrProcesu].ilRamek > sumaRamek) {
						p[o.nrProcesu].ilRamek = sumaRamek;
						while (ramki.ilePustych() < p[o.nrProcesu].ilRamek) {
							int indeks = ramki.wywalNajdawniejUzyta();
							int proces = ramki.tab[indeks].nrprocesu;
							for (int i = 0; i < p[proces].ilRamek; i++)
								ramki.tab[p[proces].tabRamek[i]].nrprocesu = -1;
							p[proces].zeruj(0);
							p[proces].wPamieci = false;
						}
						for (int i = 0; i < p[o.nrProcesu].ilRamek; i++) {
							p[o.nrProcesu].tabRamek[i] = ramki.dajPusta();
							ramki.tab[ramki.dajPusta()].nrprocesu = o.nrProcesu;
							p[o.nrProcesu].wPamieci = true;
						}
					}
					else {
						int indeks = ramki.wywalNajdawniejUzyta();
						if (indeks != -1) {
							int proces = ramki.tab[indeks].nrprocesu;
							for (int i = 0; i < p[proces].ilRamek; i++)
								ramki.tab[p[proces].tabRamek[i]].nrprocesu = -1;
							p[proces].zeruj(0);
							p[proces].wPamieci = false;
							for (int i = 0; i < p[o.nrProcesu].ilRamek; i++) {
								p[o.nrProcesu].tabRamek[i] = ramki.dajPusta();
								ramki.tab[ramki.dajPusta()].nrprocesu = o.nrProcesu;
								p[o.nrProcesu].wPamieci = true;
							}
						}
						else 
							for (int i = 0; i < ramki.tab.length; i++) {
								p[o.nrProcesu].tabRamek[i] = i;
								ramki.tab[i].nrprocesu = o.nrProcesu;
							}
					}
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
