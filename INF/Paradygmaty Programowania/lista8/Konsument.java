package lista7;

import java.util.LinkedList;
import java.util.Queue;

public class Konsument extends Thread {
	Queue<Integer> kolejka;

	public Konsument() {
		super("Konsument");
		kolejka = new LinkedList<Integer>();
	}

	public void run() {
		wyswietl();
	}

	void wyswietl() {
		for (int i = 0; i < 10; i++) {
			System.out.println("Konsument nr " + i + " : " + kolejka.poll());
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			Thread.yield();
		}
	}
}