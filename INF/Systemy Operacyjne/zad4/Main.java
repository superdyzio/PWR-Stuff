import java.util.Random;
import java.util.Scanner;

import algorytmy.*;
import odwolania.*;
import pamiec.*;

public class Main {

	public static void main(String[] args) {
		Random rand = new Random();
		Scanner wej = new Scanner(System.in);
		int iloscramek = -1;
		while (iloscramek < 10) {
			System.out.printf("Podaj iloœæ ramek (wiêcej ni¿ 10): ");
			iloscramek = wej.nextInt();
		}
		Proces [] procesy = new Proces[10];
		PamWir stronki = new PamWir();
		PamFiz rameczki = new PamFiz(iloscramek);
		for (int i = 0; i < 10; i++)
			procesy[i] = new Proces(rand.nextInt(100)+1,stronki,i);
		Generator g = new Generator(procesy);
//		g.wypisz();
		Rowny rowny = new Rowny(g,procesy,iloscramek,rameczki);
		rowny.realizuj(stronki,rameczki,procesy);
		System.out.printf("Przydzia³ równy: %d\n",rowny.iloscBledow);
		for (int i = 0; i < 10; i++) 
		System.out.println(procesy[i].ilBledow);
		for (int i = 0; i < 10; i++)
			procesy[i].zeruj(0);
		rameczki.zeruj();
		Prop prop = new Prop(g,procesy,iloscramek,rameczki);
		prop.realizuj(stronki,rameczki,procesy);
		System.out.printf("Przydzia³ proporcjonalny: %d\n",prop.iloscBledow);
		for (int i = 0; i < 10; i++) 
		System.out.println(procesy[i].ilBledow);
		for (int i = 0; i < 10; i++)
			procesy[i].zeruj(0);
		rameczki.zeruj();
		Strefa strefowy = new Strefa(g,procesy,iloscramek,rameczki);
		strefowy.realizuj(stronki,rameczki,procesy);
		System.out.printf("Przydzia³ strefowy: %d\n",strefowy.iloscBledow);
		for (int i = 0; i < 10; i++) 
		System.out.println(procesy[i].ilBledow);
		for (int i = 0; i < 10; i++)
			procesy[i].zeruj(iloscramek/10);
		rameczki.zeruj();
		Bledy bledy = new Bledy(g,procesy,iloscramek,rameczki);
		bledy.realizuj(stronki,rameczki,procesy);
		System.out.printf("Sterowanie czêstoœci¹ b³êdów: %d\n",bledy.iloscBledow);
//		for (int i = 0; i < 10; i++) 
//			System.out.println(procesy[i].ilBledow);
		wej.close();
	}
}