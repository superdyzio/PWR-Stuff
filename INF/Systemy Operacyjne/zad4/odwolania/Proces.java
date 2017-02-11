package odwolania;

import java.util.Random;
import pamiec.*;

public class Proces {
	public int ilStron, ilBledow, ilRamek;
	public boolean wPamieci;
	public int [] tabStron;
	public int [] tabRamek;
	public int numer;
	
	public Proces(int ils, PamWir pam, int n) {
		Random r = new Random();
		ilStron = ils;
		numer = n;
		wPamieci = false;
		tabStron = new int[ilStron];
		for (int i = 0; i < ilStron; i++) {
			int los = r.nextInt(1000);
			while (pam.tab[los].nrprocesu != -1)
				los = r.nextInt(1000);
			tabStron[i] = los;
			pam.tab[los].nrprocesu = numer;
		}
	}
	
	public void zeruj(int ilr) {
		if (ilr == 0) ilRamek = ilStron;
		else ilRamek = ilr;
		tabRamek = new int[ilRamek];
	}
}
