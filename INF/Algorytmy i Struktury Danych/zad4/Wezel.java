public class Wezel {
	public final String wyraz;
	public int licznik;
	public Wezel lewy, prawy;
	
	public Wezel(String w) {
		wyraz = w;
		licznik = 1;
		lewy = prawy = null;
	}
	
	public String toString() {
		return String.format("%s %d", wyraz, licznik);
	}
}
