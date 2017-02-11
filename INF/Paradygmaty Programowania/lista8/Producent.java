package lista7;

import java.util.Random;

public class Producent extends Thread {
	int liczba = 0;

	public Producent() {
		super("Producent");
		start();
	}

	@Override
	public void run() {
		Przetwornik przetwornik1 = new Przetwornik(1);
		Przetwornik przetwornik2 = new Przetwornik(2);
		produkuj(przetwornik1, przetwornik2);
	}

	synchronized void produkuj(Przetwornik przetwornik1,
			Przetwornik przetwornik2) {
		for (int i = 0; i < 10; i++) {
			Random r = new Random();
			liczba = r.nextInt(10) + 1;
			System.out.println("Producent nr " + i + " : " + liczba);
			przetwornik1.kolejka.add(liczba);
			przetwornik2.kolejka.add(liczba);
			try {
				Thread.sleep(333);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			if (i == 0) {
				przetwornik1.start();
				przetwornik2.start();
			}
			Thread.yield();
		}
	}
}