package jeden;

public class BDrzewo {
	public Wezel korzen;
	private int rzad;
	
	public BDrzewo(int m) {
		rzad = m;
		korzen = new Wezel(rzad);
	}
	
	public void dodaj(int x) {
		if (!czyJest(x,korzen)) {
			
		}
	}
	
/*	public Wezel gdzieDodac(int x, Wezel t) {
		if (t.liczba == 0) return t;
		int i;
		for (i = 0; i < t.liczba && t.dane[i] < x; i++);
		if (i == t.liczba) {
			if (t.potomstwo[0] == null) t.potomstwo[0] = new Wezel(rzad);
		}
	} */
	
	public void druk(Wezel t) {
		for (int i = 0; i < t.liczba; i++) {
			if (t.potomstwo[i] != null) druk(t.potomstwo[i]);
			System.out.println(t.dane[i]);
		}
	}
	
	public boolean czyJest(int x, Wezel t) {
		int i = 0;
		while ((i < t.liczba) && (x < t.dane[i])) i++;
		if ((i < t.liczba) && (t.dane[i] == x)) return true;
		if (t.potomstwo[i] == null) return false;
		return czyJest(x,t.potomstwo[i]);
	}
}
