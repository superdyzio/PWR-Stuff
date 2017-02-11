package algorytmy;

import java.util.ArrayList;
import zad2.Dysk;
import zad2.Zgloszenie;
import iterators.*;

public class SCAN {
	private ArrayList<Zgloszenie> kolejka;
	private int ilosc, pozycja, czas, rozmiar;
	
	public SCAN(Dysk d) {
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
	
	public int getIlosc() {
		return ilosc;
	}
	
	public void realizuj() {
		int max = -1, min = rozmiar + 1;
		ArrayIterator it = new ArrayIterator(kolejka);
		it.last();
		int maxCzas = it.getCurrent().getCzas();
		for (Zgloszenie z:kolejka) {
			if (z.getCzas() == maxCzas) {
				if (z.getPolozenie() < min) min = z.getPolozenie();
				if (z.getPolozenie() > max) max = z.getPolozenie();
			}
		}
		for (int i = 1; i <= maxCzas; i++) ilosc += rozmiar;
		if (czas % 2 == 0) {
			ilosc -= min;
			pozycja = min;
		}
		else {
			ilosc -= (rozmiar - max);
			pozycja = max;
		}
	}
}
