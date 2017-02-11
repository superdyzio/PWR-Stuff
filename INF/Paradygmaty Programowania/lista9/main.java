package lista11;

public class main {

	public static void main(String[] args) {
		Proces a = new Proces(1,6);
		Proces b = new Proces(2,4);
		b.start();
		a.start();
	}

}

