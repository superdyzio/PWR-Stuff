import java.util.Scanner;
import odwolania.Generator;
import algorytmy.*;
import pamiec.*;

public class Main {

	private static double srednia(int tab[]) {
		double wynik = 0;
		for (int i = 0; i < tab.length; i++)
			wynik += tab[i];
		return wynik / tab.length;
	}
	
	public static void main(String[] args) {
		int tab1[] = new int[1];
		int tab2[] = new int[1];
		int tab3[] = new int[1];
		int tab4[] = new int[1];
		int tab5[] = new int[1];
		Scanner wej = new Scanner(System.in);
		System.out.printf("Podaj ilosc ramek: ");
		PamFiz rameczki = new PamFiz(wej.nextInt());
		PamWir stronki = new PamWir();
		for (int i = 0; i < 1; i++) {
			Generator g = new Generator();
			g.wypisz();
			FIFO a = new FIFO(g);
			a.realizuj(rameczki,stronki);
			tab1[i] = a.iloscBledow;
			a.wypisz(rameczki);
			rameczki.zeruj();
			OPT b = new OPT(g);
			b.realizuj(rameczki,stronki);
			tab2[i] = b.iloscBledow;
			b.wypisz(rameczki);
			rameczki.zeruj();
			LRU c = new LRU(g);
			c.realizuj(rameczki,stronki);
			tab3[i] = c.iloscBledow;
			c.wypisz(rameczki);
			rameczki.zeruj();
			ALRU d = new ALRU(g);
			d.realizuj(rameczki,stronki);
			tab4[i] = d.iloscBledow;
			d.wypisz(rameczki);
			rameczki.zeruj();
			RAND e = new RAND(g);
			e.realizuj(rameczki,stronki);
			tab5[i] = e.iloscBledow;
			e.wypisz(rameczki);
		}
		System.out.printf("FIFO:  %4.1f\n",srednia(tab1));
		System.out.printf("OPT:   %4.1f\n",srednia(tab2));
		System.out.printf("LRU:   %4.1f\n",srednia(tab3));
		System.out.printf("ALRU:  %4.1f\n",srednia(tab4));
		System.out.printf("RAND:  %4.1f\n",srednia(tab5));
		wej.close();
	}
}
