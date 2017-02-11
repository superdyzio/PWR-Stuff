package odwolania;

public class Odwolanie {
	public int indeksStrony, czasWywolania;
	
	public Odwolanie(int ind, int czas) {
		indeksStrony = ind;
		czasWywolania = czas;
	}
	
	public String toString() {
		return String.format("Indeks strony: %d				Czas wywolania: %d",indeksStrony,czasWywolania);
	}
}
