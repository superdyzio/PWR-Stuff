package odwolania;

import java.util.ArrayList;
import java.util.Random;

public class Generator {
	public ArrayList<Odwolanie> lista;
	
	public Generator() {
		Random r = new Random();
		lista = new ArrayList<Odwolanie>(10);
		for (int i = 0; i < 10; i++) {
			int numer = r.nextInt(5);
			lista.add(i,new Odwolanie(numer,i));
			for (int j = 0; i < 10 && j < 3; j++) {
				int off = (j % 2 == 0 ? r.nextInt(2) : r.nextInt(2));
				i++;
				if (numer+off < 0 || numer+off >= 5) off *= -1;
				lista.add(i,new Odwolanie(numer+off,i));
			}
		}
	}
	
	public void wypisz() {
		for (Odwolanie o:lista) 
			System.out.println(o.toString());
	}
}
