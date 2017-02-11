import java.util.Scanner;

import jedynka.*;
import dwojka.*;
import trojka.*;
import czworka.*;

public class main {

	public static void jeden() {
		Scanner wej = new Scanner(System.in);
		double a, b = 0, wynik;
		System.out.println("Podaj x: ");
		a = wej.nextDouble();
		while (b <= 0) {
			System.out.println("\nPodaj e: ");
			b = wej.nextDouble();
		}
		Szeregi nowy = new Szeregi(a,b);
		wynik = nowy.sinus();
		System.out.printf("\nSinus: %f",wynik);
		wynik = nowy.cosinus();
		System.out.printf("\nCosinus: %f",wynik);
		wynik = nowy.exp();
		System.out.printf("\nExp: %f",wynik);
		wynik = nowy.pierwiastek();
		System.out.printf("\nPierwiastek: %f",wynik);
		wynik = nowy.evaluateSin();
		System.out.printf("\nSinus: %f",wynik);
		wynik = nowy.evaluateCos();
		System.out.printf("\nCosinus: %f",wynik);
		wynik = nowy.evaluateExp();
		System.out.printf("\nExp: %f",wynik);
		wynik = nowy.evaluateCubeRoot();
		System.out.printf("\nPierwiastek: %f",wynik);
		wej.close();
	}
	
	public static void dwa() {
		int wybor = -1, wybor2 = -1;
		Scanner wej = new Scanner(System.in);
		Firma f = new Firma();
		while (wybor != 0) {
			System.out.println("----------MENU----------");
			System.out.println("1 - dodawanie magazynu");
			System.out.println("2 - usuwanie magazynu");
			System.out.println("3 - wyœwietlanie magazynów");
			System.out.println("4 - edytowanie magazynu");
			wybor = wej.nextInt();
			switch (wybor) {
			case 1: System.out.println("Podaj nazwe");
					f.firma.dodaj(new Magazyn(wej.next()));
					break;
			case 2: System.out.println("Podaj nazwe magazynu do usuniecia i przeniesienia towarow");
					f.firma.usun(wej.next(),wej.next());
					break;
			case 3: f.firma.druk();
					break;
			case 4: System.out.println("Który magazyn chcesz edytowaæ?");
					wybor2 = -1;
					Magazyn edit = f.firma.get(wej.next());
					while (wybor2 != 0) {
						System.out.println("1 - dodawanie towaru");
						System.out.println("2 - usuwanie towaru");
						System.out.println("3 - szukanie najtanszego");
						System.out.println("4 - wyswietlanie");
						System.out.println("5 - zmiana ceny towaru");
						System.out.println("6 - obliczanie sredniej ceny");
						wybor2 = wej.nextInt();
						switch (wybor2) {
						case 1: System.out.println("Podaj nazwe i cene");
								edit.lista.dodaj(new Towar(wej.next(),wej.nextDouble()));
								break;
						case 2: System.out.println("Podaj nazwe");
								edit.lista.usun(wej.next());
								break;
						case 3: System.out.println(edit.lista.min().nazwa);
								break;
						case 4: edit.lista.druk();
								break;
						case 5: System.out.println("Podaj nazwe i nowa cene");
								edit.lista.zmiencene(wej.next(),wej.nextDouble());
								break;
						case 6: System.out.println(edit.lista.srednia());
								break;
						case 0: break;
						default: System.out.println("Nie ma takiej opcji."); break;
						}
					}
			case 0: break;
			default: System.out.println("Nie ma takiego wariantu.");
			}
		}
	}
	
	public static void trzy() {
		Lista x = null;
		int opcja = -1;
		Scanner wej = new Scanner(System.in);
		while (opcja != 0) {
			System.out.println("1 - tworzenie pustej kolejki");
			System.out.println("2 - dodawanie elementu");
			System.out.println("3 - œciaganie elementu");
			System.out.println("4 - wyœwietlanie elementów");
			System.out.println("5 - czyszczenie kolejki");
			opcja = wej.nextInt();
			switch (opcja) {
			case 1: x = new Lista(); break;
			case 2: System.out.println("Podaj liczbe");
					x.enqueue(new Elemen(wej.nextInt()));
					break;
			case 3: Elemen s = x.dequeue();
					System.out.println(s.dane);
					break;
			case 4: if (!x.isEmpty()) x.druk();
					else System.out.println("Kolejka jest pusta.");
					break;
			case 5: x.clear(); break;
			case 0: break;
			default: System.out.println("Nie ma takiej opcji.");
			}
		}
	}
	
	public static void cztery() {
		Stos x = null;
		int opcja2 = -1;
		Scanner wej = new Scanner(System.in);
		while (opcja2 != 0) {
			System.out.println("1 - tworzenie pustego stosu");
			System.out.println("2 - dodawanie elementu");
			System.out.println("3 - œciaganie elementu");
			System.out.println("4 - wyœwietlanie elementów");
			System.out.println("5 - czyszczenie stosu");
			opcja2 = wej.nextInt();
			switch (opcja2) {
			case 1: x = new Stos(); break;
			case 2: System.out.println("Podaj liczbe");
					x.push(new Pole(wej.nextInt()));
					break;
			case 3: Pole s = x.pop();
					System.out.println(s.dane);
					break;
			case 4: if (!x.isEmpty()) x.druk();
					else System.out.println("Stos jest pusty.");
					break;
			case 5: x.clear(); break;
			case 0: break;
			default: System.out.println("Nie ma takiej opcji.");
			}
		}
	}
	
	public static void main(final String[] args) {
		Scanner wej = new Scanner(System.in);
		System.out.println("Które zadanie?");
		int wybor = wej.nextInt();
		switch (wybor) {
		case 1: jeden(); break;
		case 2: dwa(); break;
		case 3: trzy(); break;
		case 4: cztery(); break;
		default: System.out.println("Nie ma takiego zadania.");
		}
		wej.close();
	}
}
