package pamiec;

public class Strona {
	public int czasWprowadzenia, uzycieOst, uzycieNast, bitUzycia, indeks;
	
	public Strona(int i) {
		czasWprowadzenia = uzycieOst = uzycieNast = bitUzycia = 0;
		indeks = i;
	}
	
	public String toString() {
		return String.format("indeks strony: %d",indeks);
	}
}
