import java.util.Scanner;
import jeden.*;
import dwa.*;

public class Main {
	
	public static void jeden(BDrzewo b) {
		int wybor = -1;
		Scanner wej = new Scanner(System.in);
		while (wybor != 0) {
			System.out.println("ZADANIE PIERWSZE");
			System.out.println("1 - dodawanie elementu");
			System.out.println("2 - wyszukiwanie elementu");
			System.out.println("3 - wypisywanie drzewa");
			System.out.println("0 - KONIEC");
			wybor = wej.nextInt();
			switch (wybor) {
			case 1:	System.out.println("Podaj warto��: ");
					b.dodaj(wej.nextInt());
					break;
			case 2:	System.out.println("Podaj warto��: ");
					b.czyJest(wej.nextInt(),b.korzen);
					break;
			case 3:	b.druk(b.korzen);
					break;
			}
		}
	}
	
	public static void dwa(Tree a) {
		int wybor = -1;
		Scanner wej = new Scanner(System.in);
		while (wybor != 0) {
			System.out.println("ZADANIE DRUGIE");
			System.out.println("1 - dodawanie elementu");
			System.out.println("2 - usuwanie elementu");
			System.out.println("3 - wypisywanie drzewa");
			System.out.println("4 - liczba w�z��w w drzewie");
			System.out.println("5 - liczba w�z��w wewn�trznych w drzewie");
			System.out.println("6 - liczba w�z��w z dwoma potomkami");
			System.out.println("7 - liczba w�z��w mniejszych od korzenia");
			System.out.println("8 - g��boko�� zadanego w�z�a");
			System.out.println("9 - wysoko�� zadanego poddrzewa");
			System.out.println("0 - KONIEC");
			wybor = wej.nextInt();
			switch (wybor) {
			case 1:	System.out.println("Podaj warto��");
					a.dodaj(wej.nextInt());
					break;
			case 2: System.out.println("Podaj warto��");
					a.delete(wej.nextInt());
					break;
			case 3: a.wypisz(a.korzen);
					break;
			case 4: System.out.printf("Ilo�� w�z��w: %d\n",a.liczbaWezlow(a.korzen));
					break;
			case 5: System.out.printf("Ilo�� w�z��w wewn�trznych: %d\n",a.liczbaWezlowW(a.korzen));
					break;
			case 6:	System.out.printf("Ilo�� w�z��w z dwoma potomkami: %d\n",a.liczbaDwochSynow(a.korzen));
					break;
			case 7: System.out.printf("Ilo�� w�z��w mniejszych od korzenia: %d\n",a.iloscMniejszych());
					break;
			case 8: System.out.println("Podaj warto��: ");
					System.out.printf("G��boko�� zadanego w�z�a: %d\n",a.glebokosc(a.search(wej.nextInt()),a.korzen));
					break;
			case 9:	System.out.println("Podaj warto��: ");
					System.out.printf("Wysoko�� zadanego poddrzewa: %d\n",a.wysokosc(a.search(wej.nextInt())));
					break;
			}
		}
	}

	public static void main(String[] args) {
		Tree a = new Tree();
		BDrzewo b;
		Scanner wej = new Scanner(System.in);
		int wybor = -1;
		while (wybor != 0) {
			System.out.println("----------MENU---------");
			System.out.println("1 - zadanie pierwsze");
			System.out.println("2 - zadanie drugie");
			System.out.println("0 - KONIEC");
			wybor = wej.nextInt();
			switch (wybor) {
			case 1: System.out.println("Podaj rzad BDrzewa: ");
					b = new BDrzewo(wej.nextInt());
					jeden(b); 
					break;
			case 2: dwa(a); 
					break;
			}
		}
	}
}
