package algorytmy;

import java.util.ArrayList;

import kolejki.*;

public class RR {
	public FIFO dowyk;
	
	public RR(Generator x) {
		dowyk = new FIFO();
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
				dowyk.enqueue(dodod);
				pom = dodod.czasZgloszenia;
				tab[indeks] = 1;
			}
			min = 1001;
			licznik = 0;
			dodod = null;
		}
	}
	
	public int realizacja() {
		boolean koniec = false;
		Proces p = null;
		int ret = 0, czas = 0, suma = 0;
		while (!koniec) {
			p = dowyk.dequeue();
			suma = 0;
			for (int i = 0; i < dowyk.size(); i++) {
				if ((dowyk._tab[i].czasZgloszenia <= czas) && (dowyk._tab[i].getCzasP() > 0))
					dowyk._tab[i].setCzasO(dowyk._tab[i].getCzasO() + 1);
			}
			p.setCzasP(p.getCzasP() - 1);
			dowyk.enqueue(p);
			czas++;
			for (int i = 0; i < dowyk.size() && suma == 0; i++)
				suma += dowyk._tab[i].getCzasP();
			if (suma == 0) koniec = true;
		}
		for (int i = 0; i < dowyk.size(); i++)
			ret += dowyk._tab[i].getCzasO();
		return ret;
	}
}
