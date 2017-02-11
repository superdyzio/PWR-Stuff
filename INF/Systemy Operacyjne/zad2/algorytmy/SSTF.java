package algorytmy;

import java.util.ArrayList;
import zad2.*;

public class SSTF {
	private ArrayList<Zgloszenie> kolejka;
	private int ilosc, pozycja, czas, rozmiar;
	
	public SSTF(Dysk d) {
		int n = d.getLista().size();
		pozycja = 0;
		rozmiar = d.getRozmiar();
		ilosc = 0;
		czas = d.getCzas();
		kolejka = new ArrayList<Zgloszenie>(n);
		sortuj(d.getLista(),n);
	}
	
	private void sortuj(ArrayList<Zgloszenie> lista, int n) {
		int min = 1 + czas, pom = 0, licznik = 0, indeks = 0;
		int [] tab = new int[n];
		Zgloszenie dodod = null;
		for (int i = 0; i < n; i++) tab[i] = 0;
		for (int i = 0; i < n; i++) {
			for (Zgloszenie z:lista) {
				if ((tab[licznik] == 0) && (z.getCzas() < min) && (z.getCzas() >= pom)) {
					min = z.getCzas();
					dodod = z;
					indeks = licznik;
				}
				licznik++;
			}
			if (dodod != null) {
				kolejka.add(dodod);
				pom = dodod.getCzas();
				tab[indeks] = 1;
			}
			min = 1 + czas;
			licznik = 0;
			dodod = null;
		}
	}
	
	public void wypisz() {
		for (Zgloszenie z:kolejka) System.out.println(z.toString());
	}
	
	public void realizuj() {
		Zgloszenie [] tab = new Zgloszenie[kolejka.size()];
		int licznik = 0, min = rozmiar + 1, indeks = -1;
		int [] pom;
		for (int i = 1; i <= czas; i++) {
			for (Zgloszenie z:kolejka) 
				if (z.getCzas() == i) {
					tab[licznik] = z;
					licznik++;
				}
			pom = new int[licznik];
			for (int j = 0; j < licznik; j++) pom[j] = 0;
			for (int k = 0; k < licznik; k++) {
				for (int j = 0; j < licznik; j++) {
					if ((pom[j] == 0) && (Math.abs(tab[j].getPolozenie() - pozycja) <= min)) {
						min = Math.abs(tab[j].getPolozenie() - pozycja);
						indeks = j;
					}
				}
				ilosc += Math.abs(tab[indeks].getPolozenie() - pozycja);
				pom[indeks] = 1;
				min = rozmiar + 1;
				pozycja = tab[indeks].getPolozenie();
			}
			licznik = 0;
		}
	}
	
	public int getIlosc() {
		return ilosc;
	}
}
