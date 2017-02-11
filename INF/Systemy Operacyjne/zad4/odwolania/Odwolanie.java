package odwolania;

public class Odwolanie {
	public int indeksStrony, czasWywolania, nrProcesu;
	
	public Odwolanie(int ind, int czas, int proces) {
		indeksStrony = ind;
		czasWywolania = czas;
		nrProcesu = proces;
	}
	
	public String toString() {
		return String.format("Nr %d: %d   %d",czasWywolania,nrProcesu,indeksStrony);
	}
}
