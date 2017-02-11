package zad2;

public class Zgloszenie {
	private boolean priorytet;
	private int czas, polozenie, numer;
	
	public Zgloszenie(int pri, int c, int p, int i) {
		priorytet = pri == 1;
		czas = c;
		polozenie = p;
		numer = i;
	}
	
	public boolean getPriorytet() {
		return priorytet;
	}
	
	public int getCzas() {
		return czas;
	}
	
	public int getPolozenie() {
		return polozenie;
	}
	
	public String toString() {
		return String.format("Nr %4d:   %4d   %4d   %4b",numer,czas,polozenie,priorytet);
	}
}
