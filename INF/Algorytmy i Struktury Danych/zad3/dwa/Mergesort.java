package dwa;

import java.util.Random;

public class Mergesort {
	private int n;
	private int tab[];
	private int t[];
	public int czas, porownania, przepisania;
	
	// 0 dla losowego, -1 dla uporz¹dkowanego, -2 dla uporz¹dkowanego odwrotnie
	public Mergesort(int n, int z) {
		this.n = n;
		tab = new int[n];
		t = new int[n];
		czas = porownania = przepisania = 0;
		switch(z) {
		case -1: 	for (int i = 0; i < n; i++) tab[i] = i; break;
		case -2:	for (int i = 0; i < n; i++) tab[i] = n-i; break;
		default:	for (int i = 0; i < n; i++) tab[i] = losuj(50)+1;
		}
	}
	
	public static int losuj(int n) {
		Random rand = new Random();
	    return rand.nextInt(n);
	}
	
	public void sort() {
		int min = 51, indeks = 0;
		int j = 0;
		int [] pom = new int[n];
		for (int i = 0; i < n; i++) pom[i] = 0;
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++) {
				if (pom[i] == 0) {
					porownania++;
					if (tab[i] < min) {
						przepisania++;
						min = tab[i];
						indeks = i;
					}
				}
			}
		pom[indeks] = 1;
		t[j] = tab[indeks];
		j++;
	}
	
	public void merge(int pocz, int sr, int kon) {
		int i, j, q;
		for (i = pocz; i <= kon; i++) {
			t[i] = tab[i];
			czas++;
		}
		i = pocz; j = sr+1; q = pocz; czas += 3;             
		while (i <= sr && j <= kon) {         
			porownania++;
			if (t[i] < t[j])
				tab[q++] = t[i++];
			else tab[q++] = t[j++];
			przepisania++;
		}
		while (i <= sr) {
			przepisania++;
			tab[q++] = t[i++]; 
		}
	}
	 
	public void mergesort(int pocz, int kon) {
		int sr;
		if (pocz<kon) {
			sr=(pocz+kon)/2;
			mergesort(pocz, sr);    
			mergesort(sr+1, kon);   
			merge(pocz, sr, kon);   
		}
	}  

	public long dwa() {
		int i;
//		System.out.println("Zbior przed sortowaniem:");
//		for (i=0; i<n; i++) System.out.print(tab[i] + " ");
		long start = System.nanoTime();
		mergesort(0,n-1);
//		sort();
		long stop = System.nanoTime();
		return stop-start;
//		System.out.println("\nZbior po sortowaniu:");
//		for (i=0; i<n; i++) System.out.print(tab[i] + " ");
//		System.out.printf("\n\nCzas: %d\nPorównania: %d\nPrzepisania: %d\n\n\n",czas,porownania,przepisania);
	}
}





/* 
 * MergeSort - sortowanie przez scalanie
 * Z³o¿onoœæ obliczeniowa (nlogn)
 * 
 * Jest to algorytm typu "dziel i zwyciê¿aj", stabilny. niewra¿liwy na pocz¹tkowe uporz¹dkowanie elementów.
 * 
 * Wersja wstêpuj¹ca polega na podzieleniu ci¹gu na jednoelementowe podci¹gi i umieszczanie ich w posortowanym ci¹gu zgodnie z kryterium. Jest to 
 * algorytm iteracyjny.
 * 
 * Wersja zstêpuj¹ca polega na dzieleniu ci¹gu na dwie czêœci i rekurencyjne powtarzanie tej czynnoœci, a¿ do uzyskania dwuelementowych podci¹gów, które
 * s¹ sortowane i póŸniejsze scalenie w odpowiedni sposób wszystkich tych podci¹gów. Algorytm ten powinien byæ zdecydowanie szybszy.
 * 
 * Usprawnienie daje wyraŸna poprawê czasu wykonania algorytmu, wykonywane jest œrednio mniej porównañ, lecz zdecydowanie wiêcej przepisañ.
*/