package algorytmy;

import java.util.ArrayList;
import pamiec.*;
import odwolania.*;

public class Bledy {
	public ArrayList<Odwolanie> kolejka;
	public int iloscBledow, sumaRamek, minBledow, maxBledow;

	public Bledy(Generator g, Proces [] p, int ilr, PamFiz ramki) {
		kolejka = g.lista;
		iloscBledow = 0;
		sumaRamek = ilr;
		minBledow = 15;
		maxBledow = 30;
		for (int i = 0; i < 10; i++) {
			p[i].ilRamek = ilr / 10;
			p[i].ilBledow = 0;
			p[i].tabRamek = new int[p[i].ilRamek];
		}
	}

	public void realizuj(PamWir strony, PamFiz ramki, Proces [] p) {
		int licznik = 0;
		for (Odwolanie o:kolejka) {
			licznik++;
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
			if (licznik % 250 == 0) {
				for (int i = 0; i <10; i++) { 
					if (p[i].ilBledow > maxBledow) {
						if (ramki.ilePustych() > 0) {
							int indeks = ramki.dajPusta();
							int [] pom = p[o.nrProcesu].tabRamek;
							p[o.nrProcesu].ilRamek++;
							p[o.nrProcesu].tabRamek = new int[p[o.nrProcesu].ilRamek];
							for (int j = 0; j < pom.length; j++) 
								p[o.nrProcesu].tabRamek[j] = pom[j];
							p[o.nrProcesu].tabRamek[pom.length] = indeks;
							ramki.tab[indeks].nrprocesu = o.nrProcesu;
						}
						else {
							int indeks = ramki.wywalNajdawniejUzyta();
							int proces = ramki.tab[indeks].nrprocesu;
							int [] pom = p[proces].tabRamek;
							int dowywalenia = ramki.wywalNajdawniejUzyta(p[proces]);
							p[proces].ilRamek--;
							p[proces].tabRamek = new int[p[proces].ilRamek];
							int it = 0;
							for (int j = 0; j < pom.length; j++)
								if (pom[j] != dowywalenia) {
									p[proces].tabRamek[it] = pom[j];
									it++;
								}
							pom = p[o.nrProcesu].tabRamek;
							p[o.nrProcesu].ilRamek++;
							p[o.nrProcesu].tabRamek = new int[p[o.nrProcesu].ilRamek];
							for (int j = 0; j < pom.length; j++) 
								p[o.nrProcesu].tabRamek[j] = pom[j];
							p[o.nrProcesu].tabRamek[pom.length] = ramki.tab[indeks].indeks;
							ramki.tab[indeks].nrprocesu = o.nrProcesu;
						}
					}
					if (p[i].ilBledow < minBledow && p[i].ilBledow > 0) {
						int indeks = ramki.wywalNajdawniejUzyta(p[o.nrProcesu]);
						ramki.tab[indeks].nrprocesu = -1;
						int [] pom = p[o.nrProcesu].tabRamek;
						p[o.nrProcesu].ilRamek--;
						p[o.nrProcesu].tabRamek = new int[p[o.nrProcesu].ilRamek];
						int it = 0;
						for (int j = 0; j < pom.length; j++)
							if (pom[j] != indeks) {
								p[o.nrProcesu].tabRamek[it] = pom[j];
								it++;
							}
					}
				}
				for (int i = 0; i < 10; i++)
					p[i].ilBledow = 0;
			}
		}
	}
}