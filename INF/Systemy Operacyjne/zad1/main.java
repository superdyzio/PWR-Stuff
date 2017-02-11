import java.util.Scanner;

import kolejki.*;
import algorytmy.*;

public class main {
	
	public static void main(final String[] args) {
		Generator g = new Generator(15000);
		RR lista = new RR(g);
//		SJF lista = new SJF(g);
//		FCFS lista = new FCFS(g);
//		SJFw lista = new SJFw(g);
		for (Proces p:g.kolejka)
			System.out.printf("%d, %d, %d, %d\n", p.index,p.czasZgloszenia,p.getCzasP(),p.getCzasO());
		int suma = lista.realizacja();
		double srednia = (double) suma / g.rozmiar;
		System.out.printf("\n%f\n\n", srednia);
//		for (Proces k:lista.dowyk)
//			System.out.printf("%d, %d, %d, %d\n",k.index,k.czasZgloszenia,k.getCzasP(),k.getCzasO());
		lista.dowyk.druk();
	}
}
