package zad2;

import java.util.ArrayList;

public class Dysk {
	private int rozmiar;
	private Generator gen;
	
	public Dysk(int n, Generator g) {
		rozmiar = n;
		gen = g;
	}
	
	public int getRozmiar() {
		return rozmiar;
	}
	
	public ArrayList<Zgloszenie> getLista() {
		return gen.getLista();
	}
	
	public int getCzas() {
		return gen.getCzas();
	}
}