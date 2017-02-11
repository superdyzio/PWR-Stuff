import java.io.*;

public class Drzewo {
	public final Wezel korzen;
	public int ilosc;
	
	public Drzewo() {
		ilosc = 0;
		korzen = null;
	}
	
	public Drzewo(Wezel poc) {
		ilosc = 0;
		korzen = poc;
	}
	
	public void dodaj(Wezel t, Wezel w) {
		int cmp = w.wyraz.compareTo(t.wyraz);
		if (cmp == 0) t.licznik++;
		else {
			if (cmp < 0)
				if (t.lewy == null) { t.lewy = w; ilosc++; }
				else dodaj(t.lewy,w);
			else 
				if (t.prawy == null) { t.prawy = w; ilosc++; }
				else dodaj(t.prawy,w);
		}
	}
	
	public void wypisz(Wezel k) {
		Wezel pom = k;
		if (pom.lewy != null) wypisz(pom.lewy);
		if (pom.prawy != null) wypisz(pom.prawy);
		System.out.println(pom.wyraz);
	}
	
	public void zapis(Wezel k, PrintWriter w) {
		Wezel pom = k;
		if (pom.lewy!= null) zapis(pom.lewy,w);
		w.println(k.toString());
		if (pom.prawy != null) zapis(pom.prawy,w);
	}
}
