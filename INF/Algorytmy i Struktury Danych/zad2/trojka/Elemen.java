package trojka;

public class Elemen {
	public int dane;
	public Elemen nast;
	
	public Elemen(int x) {
		dane = x;
		nast = null;
	}
	
	public Elemen(int x, Elemen n) {
		dane = x;
		nast = n;
	}
}
