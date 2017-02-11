package pamiec;

import java.util.Random;

public class PamFiz {
	public Ramka tab[];
	
	public PamFiz(int rozmiar) {
		tab = new Ramka[rozmiar];
		for (int i = 0; i < rozmiar; i++) 
			tab[i] = new Ramka();
	}
	
	public void zeruj() {
		for (int i = 0; i < tab.length; i++)
			tab[i].strona = null;
	}
	
	public int wywalNajstarsza() {
		int najstarsza = 100000, indeks = -1;
		for (int i = 0; i < tab.length; i++)
			if (tab[i].strona.czasWprowadzenia < najstarsza) {
				najstarsza = tab[i].strona.czasWprowadzenia;
				indeks = i;
			}
		return indeks;
	}
	
	public int wywalLosowa() {
		Random r = new Random();
		return r.nextInt(tab.length);
	}
	
	public int wywalNajdawniejUzyta() {
		int najdawniej = 100000, indeks = -1;
		for (int i = 0; i < tab.length; i++)
			if (tab[i].strona.uzycieOst < najdawniej) {
				najdawniej = tab[i].strona.uzycieOst;
				indeks = i;
			}
		return indeks;
	}
	
	public int wywalwgBitu() {
		int najdawniej = 100000, indeks = -1;
		for (int i = 0; i < tab.length; i++)
			if (tab[i].strona.bitUzycia == 0 && tab[i].strona.uzycieOst < najdawniej) {
				najdawniej = tab[i].strona.uzycieOst;
				indeks = i;
			}
		return indeks == -1 ? wywalLosowa() : indeks;
	}
	
	public int wywalNieuzywana() {
		int najpozniej = -1, indeks = -1;
		for (int i = 0; i < tab.length; i++)
			if (tab[i].strona.uzycieNast > najpozniej) {
				najpozniej = tab[i].strona.uzycieNast;
				indeks = i;
			}
		return indeks;
	}
}
