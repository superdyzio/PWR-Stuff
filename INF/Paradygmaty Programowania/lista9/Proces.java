package lista11;

public class Proces extends Thread {
	int numer;

	public Proces(int liczba, int prior) {
		numer = liczba;
		setPriority(prior);
	}

	public synchronized void run() {
		for (int i = 0; i < 3; i++) {
			System.out.println("Watek nr : " + numer + ". Iteracja nr : " + i);
			Thread.yield();
		}
	}
}
