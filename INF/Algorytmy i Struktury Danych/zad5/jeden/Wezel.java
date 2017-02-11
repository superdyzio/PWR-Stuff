package jeden;

public class Wezel {
	public int rozmiar;				// rozmiar = 2 * rzad drzewa - 1
	public int liczba;				// aktualna ilosc kluczy w drzewie
	public int [] dane;				// tablica danych w w�le
	public Wezel [] potomstwo; 		// tablica potomk�w danego w�z�a
	
	public Wezel(int m) {
		rozmiar = 2 * m - 1;
		liczba = 0;
		dane = new int[rozmiar];
		potomstwo = new Wezel[rozmiar+1];
	}
}
