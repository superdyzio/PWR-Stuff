package zad2;

import java.util.ArrayList;
import java.util.Random;

public class Generator {
	private ArrayList<Zgloszenie> lista;
	private int rozmiar, czas;
	
	public Generator(int n, int rd, int c) {
		lista = new ArrayList<Zgloszenie>(n);
		rozmiar = n;
		czas = c;
		Random r = new Random();
		for (int i = 0; i < rozmiar; i++) 
			lista.add(new Zgloszenie(r.nextInt(2),r.nextInt(c)+1,r.nextInt(rd)+1,i+1));
	}
	
	public void wypisz() {
		for (Zgloszenie p:lista) System.out.println(p.toString());
	}
	
	public ArrayList<Zgloszenie> getLista() {
		return lista;
	}
	
	public int getCzas() {
		return czas;
	}
}