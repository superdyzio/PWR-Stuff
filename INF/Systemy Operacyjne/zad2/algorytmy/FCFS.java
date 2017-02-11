package algorytmy;

import java.util.ArrayList;
import zad2.*;

public class FCFS {
	private ArrayList<Zgloszenie> kolejka;
	private int ilosc, pozycja, czas;
	
	public FCFS(Dysk d) {
		int n = d.getLista().size();
		pozycja = 0;
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
		for (Zgloszenie z:kolejka) {
			ilosc += Math.abs(z.getPolozenie() - pozycja);
			pozycja = z.getPolozenie();
		}
	}
	
	public int getIlosc() {
		return ilosc;
	}
}
