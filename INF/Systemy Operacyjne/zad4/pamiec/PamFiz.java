package pamiec;

import odwolania.*;

public class PamFiz {
	public Ramka tab[];

	public PamFiz(int rozmiar) {
		tab = new Ramka[rozmiar];
		for (int i = 0; i < rozmiar; i++) 
			tab[i] = new Ramka(i);
	}	

	public void zeruj() {
		for (int i = 0; i < tab.length; i++) {
			tab[i].strona = null;
			tab[i].nrprocesu = -1;
		}
	}

	public int wywalNajdawniejUzyta(Proces p) {
		int najdawniej = 100000, indeks = p.tabRamek[0];
		for (int i = 0; i < p.ilRamek; i++)
			if (tab[p.tabRamek[i]].strona != null && tab[p.tabRamek[i]].strona.uzycieOst < najdawniej) {
				najdawniej = tab[p.tabRamek[i]].strona.uzycieOst;
				indeks = p.tabRamek[i];
			}
		return indeks;
	}

	public int wywalNajdawniejUzyta() {
		int najdawniej = 100000, indeks = -1;
		for (int i = 0; i < tab.length; i++) {
			if (tab[i].nrprocesu != -1 && tab[i].strona != null && tab[i].strona.uzycieOst < najdawniej) {
				najdawniej = tab[i].strona.uzycieOst;
				indeks = i;
			}
		}
		return indeks;
	}

	public int ilePustych() {
		int wynik = 0;
		for (int i = 0; i < tab.length; i++)
			if (tab[i].nrprocesu == -1)
				wynik++;
		return wynik;
	}

	public int dajPusta() {
		for (int i = 0; i < tab.length; i++)
			if (tab[i].nrprocesu == -1)
				return i;
		return wywalNajdawniejUzyta();
	}
}
