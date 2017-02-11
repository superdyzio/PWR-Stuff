package lista7;

import java.util.LinkedList;
import java.util.Queue;

public class Przetwornik extends Thread {
	Queue<Integer> kolejka;
	int typ;

	public Przetwornik(int typ) {
		super("Przetwornik");
		kolejka = new LinkedList<Integer>();
		this.typ = typ;
	}

	public void run() {
		Konsument konsument = new Konsument();
		if (typ == 1)
			przetworz1(konsument);
		else
			przetworz2(konsument);
	}

	void przetworz1(Konsument konsument) {
		for (int i = 0; i < 10; i++) {
			System.out.println("Przetwornik nr " + typ + " liczba : " + (10 - kolejka.peek()));
			konsument.kolejka.add(10 - kolejka.poll());
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			if (i == 0)
				konsument.start();
			Thread.yield();
		}
	}

	void przetworz2(Konsument konsument) {
		for (int i = 0; i < 10; i++) {
			System.out.println("Przetwornik nr " + typ + " liczba : " + silnia(kolejka.peek()));
			konsument.kolejka.add(silnia(kolejka.poll()));
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

			if (i == 0)
				konsument.start();
			Thread.yield();
		}
	}

	int silnia(int liczba) {
		return liczba > 0 ? liczba * silnia(liczba - 1) : 1;
	}
}