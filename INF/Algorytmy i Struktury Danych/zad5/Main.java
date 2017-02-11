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
			case 1:	System.out.println("Podaj wartoœæ: ");
					b.dodaj(wej.nextInt());
					break;
			case 2:	System.out.println("Podaj wartoœæ: ");
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
			System.out.println("4 - liczba wêz³ów w drzewie");
			System.out.println("5 - liczba wêz³ów wewnêtrznych w drzewie");
			System.out.println("6 - liczba wêz³ów z dwoma potomkami");
			System.out.println("7 - liczba wêz³ów mniejszych od korzenia");
			System.out.println("8 - g³êbokoœæ zadanego wêz³a");
			System.out.println("9 - wysokoœæ zadanego poddrzewa");
			System.out.println("0 - KONIEC");
			wybor = wej.nextInt();
			switch (wybor) {
			case 1:	System.out.println("Podaj wartoœæ");
					a.dodaj(wej.nextInt());
					break;
			case 2: System.out.println("Podaj wartoœæ");
					a.delete(wej.nextInt());
					break;
			case 3: a.wypisz(a.korzen);
					break;
			case 4: System.out.printf("Iloœæ wêz³ów: %d\n",a.liczbaWezlow(a.korzen));
					break;
			case 5: System.out.printf("Iloœæ wêz³ów wewnêtrznych: %d\n",a.liczbaWezlowW(a.korzen));
					break;
			case 6:	System.out.printf("Iloœæ wêz³ów z dwoma potomkami: %d\n",a.liczbaDwochSynow(a.korzen));
					break;
			case 7: System.out.printf("Iloœæ wêz³ów mniejszych od korzenia: %d\n",a.iloscMniejszych());
					break;
			case 8: System.out.println("Podaj wartoœæ: ");
					System.out.printf("G³êbokoœæ zadanego wêz³a: %d\n",a.glebokosc(a.search(wej.nextInt()),a.korzen));
					break;
			case 9:	System.out.println("Podaj wartoœæ: ");
					System.out.printf("Wysokoœæ zadanego poddrzewa: %d\n",a.wysokosc(a.search(wej.nextInt())));
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
