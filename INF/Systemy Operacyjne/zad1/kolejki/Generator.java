package kolejki;

import java.util.ArrayList;
import java.util.Random;

public class Generator {
	public ArrayList<Proces> kolejka;
	public final int rozmiar;
	
	public Generator(int r) {
		rozmiar = r;
		kolejka = new ArrayList<Proces>(rozmiar);
		for (int i = 0; i < rozmiar; i++) {
			kolejka.add(i, new Proces(i,losuj(3)+1,losuj(3)+1));
		}
	}
	
    public static int losuj(int n) {
        Random rand = new Random();
        return rand.nextInt(n);
    }
}
