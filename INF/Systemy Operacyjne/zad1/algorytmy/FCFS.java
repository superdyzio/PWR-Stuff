package algorytmy;

import java.util.ArrayList;

import kolejki.*;
import iterators.*;

public class FCFS {
	public ArrayList<Proces> dowyk;
	
	public FCFS(Generator x) {
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
		it.first();
		int zwroc = 0;
		Proces pom = null;
		Proces pop = null;
		int stary = 0;								// procesy sa posortowane wg czasu zgloszenia
		while (!it.isDone()) {						// przesuwamy czas zgloszenia kazdego procesu o czas wykonania poprzedniego
			pom = (Proces) it.current();
			stary = pom.czasZgloszenia;
			if (pop!= null)
				if (pop.czasZgloszenia + pop.getCzasP() > stary)
					pom.czasZgloszenia = pop.czasZgloszenia + pop.getCzasP();
			if (pom.czasZgloszenia - stary > 0) pom.setCzasO(pom.czasZgloszenia-stary);
			else pom.setCzasO(0);
			zwroc += pom.getCzasO();
			pop = pom;
			it.next();
		}
		return zwroc;
	}
}
