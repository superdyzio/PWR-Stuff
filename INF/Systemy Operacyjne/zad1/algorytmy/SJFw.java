package algorytmy;

import java.util.ArrayList;

import iterators.*;
import kolejki.*;

public class SJFw {
	public ArrayList<Proces> dowyk;
	
	public SJFw(Generator x) {
		dowyk = new ArrayList<Proces>(x.rozmiar);
		int min = 1001;
		int pom = 0;
		int licznik = 0;
		int indeks = 0;
		int [] tab = new int[x.rozmiar];
		Proces dodod = null;
		for (int i = 0; i < x.rozmiar; i++) tab[i] = 0;
		for (int i = 0; i < x.rozmiar; i++) {
			for (Proces p:x.kolejka) {
				if ((tab[licznik] == 0) && (p.czasZgloszenia < min) && (p.czasZgloszenia >= pom)) {
					min = p.czasZgloszenia;
					dodod = p;
					indeks = licznik;
				}
				licznik++;
			}
			if (dodod != null) {
				dowyk.add(i,dodod);
				pom = dodod.czasZgloszenia;
				tab[indeks] = 1;
			}
			min = 1001;
			licznik = 0;
			dodod = null;
		}
	}
	
	public int realizacja() {
		ArrayIterator it = new ArrayIterator(dowyk);
		boolean koniec = false;
		Proces p = null, w = null;
		int min, suma;
		for (int czas = 0; !koniec; czas++) {
			it.first();
			min = 101;
			while (!it.isDone()) {
				p = (Proces) it.current();
				if ((p.czasZgloszenia <= czas) && (p.getCzasP() > 0) && (p.getCzasP() < min)) {
					min = p.getCzasP();
					w = p;
				}
				it.next();
			}
			it.first();
			while (!it.isDone()) {
				p = (Proces) it.current();
				if (p == w) p.setCzasP(w.getCzasP() - 1);
				else if ((p.czasZgloszenia <= czas) && (p.getCzasP() > 0)) p.setCzasO(p.getCzasO() + 1);
				it.next();
			}
			it.first();
			suma = 0;
			while ((!it.isDone()) && (suma == 0)) {
				p = (Proces) it.current();
				suma += p.getCzasP();
				it.next();
			}
			if (suma == 0) koniec = true;
		}
		it.first();
		suma = 0;
		while (!it.isDone()) {
			p = (Proces) it.current();
			suma += p.getCzasO();
			it.next();
		}
		return suma;
	}
}
