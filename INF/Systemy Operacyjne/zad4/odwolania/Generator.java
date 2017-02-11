package odwolania;

import java.util.ArrayList;
import java.util.Random;

public class Generator {
	public ArrayList<Odwolanie> lista;
	
	public Generator(Proces [] p) {
		Random r = new Random();
		lista = new ArrayList<Odwolanie>(5000);
		for (int i = 0; i < 5000; i++) {
			int proces = r.nextInt(10);
			int numer = r.nextInt(p[proces].ilStron);
			lista.add(i,new Odwolanie(p[proces].tabStron[numer],i,proces));
			for (int j = 0; i < 5000 && j < 30; j++) {
				int off = (j % 2 == 0 ? r.nextInt(25) : -r.nextInt(25));
				i++;
				if (numer+off < 0 || numer+off >= p[proces].ilStron) off = 0;
				lista.add(i,new Odwolanie(p[proces].tabStron[numer+off],i,proces));
			}
		}
	}
	
	public void wypisz() {
		for (Odwolanie o:lista)
			System.out.println(o.toString());
	}
}
