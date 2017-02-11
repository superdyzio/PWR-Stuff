package czworka;

public class Pole {
	public int dane;
	Pole nast;
	
	public Pole(int x) {
		dane = x;
		nast = null;
	}
	
	public Pole(int x, Pole n) {
		dane = x;
		nast = n;
	}
}
