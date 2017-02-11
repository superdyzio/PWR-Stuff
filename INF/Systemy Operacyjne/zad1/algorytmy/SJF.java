package algorytmy;

import iterators.ArrayIterator;
import java.util.ArrayList;

import kolejki.*;

public class SJF {
	public ArrayList<Proces> dowyk;
	public ArrayList<Proces> wyk;
	
	public SJF(Generator x) {
		dowyk = new ArrayList<Proces>(x.rozmiar);
		wyk = new ArrayList<Proces>(x.rozmiar);
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
		int zwroc = 0, przekaz = 0;
		Proces p = (Proces) it.current();
		Proces [] tab = new Proces[dowyk.size()];
		for (int czas = 0; czas < 1000; czas++) {
			int licznik = 0;
			it.first();
			while (!it.isDone()) {							// procesy posortowane wg czasow zgloszenia sa dzielone na grupy o tym samym czasie
				if (p.czasZgloszenia == czas) {				// liczone sa opoznienia jak w FCFS wewnatrz grupy, a dalsze jest przekazywane na poczatek  
					tab[licznik] = p;						// kolejnej grupy
					licznik++;
				}
				it.next();
				p = (Proces) it.current();
	
			}
			it.first();
			p = (Proces) it.current();
			sort(tab,licznik,przekaz);
			przekaz = zrobTab(wyk,czas);						// wartoœæ do przekazania na opóŸnienie kolejnej grupy procesów
		}
		for (Proces k:wyk) zwroc += k.getCzasO();
		return zwroc;
	}
	
	public int zrobTab(ArrayList<Proces> wyk, int czas) {
		ArrayIterator at = new ArrayIterator(wyk);
		int ret = 0;
		Proces p = null, pom = null;
		at.first();
		while (!at.isDone()) {
			p = (Proces) at.current();
			at.next();
			if ((!at.isDone()) && (p.czasZgloszenia == czas)) {
				pom = (Proces) at.current();
				pom.setCzasO(pom.getCzasO() + p.getCzasP() + p.getCzasO());
				ret = pom.czasZgloszenia + pom.getCzasO() + pom.getCzasP();
			}
		}
		return ret;
	}
	
    public void sort(Proces[] a, int x, int p) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x - 1; j++) {
                if (a[j].getCzasP() > a[j + 1].getCzasP()) {
                    Proces temp = a[j];                    
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < x; i++)
        	if (i != 0) wyk.add(a[i]);
        	else {
        		if (p - a[i].czasZgloszenia > 0) a[i].setCzasO(p - a[i].czasZgloszenia);
        		else a[i].setCzasO(0);
        		wyk.add(a[i]);
        	}
    }
}
