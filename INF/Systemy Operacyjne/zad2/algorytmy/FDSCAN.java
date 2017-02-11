package algorytmy;

import iterators.ArrayIterator;

import java.util.ArrayList;
import zad2.*;

public class FDSCAN {
	private ArrayList<Zgloszenie> kolejka, prio, nie;
	private int ilosc, pozycja, czas, rozmiar, liczba;
	
	public FDSCAN(Dysk d) {
		int n = d.getLista().size();
		pozycja = 0;
		rozmiar = d.getRozmiar();
		ilosc = 0;
		czas = d.getCzas();
		kolejka = new ArrayList(n);
		sortuj(d.getLista(),n,liczba);
		prio = new ArrayList<Zgloszenie>(liczba);
		nie = new ArrayList<Zgloszenie>(n-liczba);
	}
	
	private void sortuj(ArrayList<Zgloszenie> lista, int n, int l) {
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
				if (dodod.getPriorytet()) liczba++;
				pom = dodod.getCzas();
				tab[indeks] = 1;
			}
			min = 1 + czas;
			licznik = 0;
			dodod = null;
		}
	}
	
	public void realizuj() {
		ArrayIterator it = new ArrayIterator(kolejka);
		it.last();
		int maxCzas = it.getCurrent().getCzas();
		int min = 0, indeks = 0, licznik = 0;
		for (Zgloszenie z:kolejka) 
			if (z.getPriorytet()) prio.add(z);
			else nie.add(z);
		for (int i = 1; i <= maxCzas; i++) {
			indeks = -1;
			licznik = 0;
			min = rozmiar + 1;
			for (Zgloszenie z:prio) {
				if (z.getCzas() <= i) {
					if (Math.abs(pozycja-z.getPolozenie()) <= min) {
						indeks = licznik;
						min = Math.abs(pozycja-z.getPolozenie());
					}
				}
				licznik++;
			}
			ilosc += min;
			prio.remove(indeks);
			pozycja = min;
		}
		for (int i = 1; i <= maxCzas; i++) {
			min = rozmiar + 1;
			indeks = -1;
			licznik = 0;
			for (Zgloszenie z:nie) {
				if (z.getCzas() <= i) {
					if (Math.abs(pozycja-z.getPolozenie()) <= min) {
						indeks = licznik;
						min = Math.abs(pozycja-z.getPolozenie());
					}
				}
				licznik++;
			}
			pozycja = min;
			ilosc += min;
		nie.remove(indeks);
		}
	}
	
	public int getIlosc() {
		return ilosc;
	}
}
