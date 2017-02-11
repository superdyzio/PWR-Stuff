import java.util.*;
import java.io.*;

public class Main {
	
	public static Drzewo odczyt(Drzewo t) {
		Scanner wej = new Scanner(System.in);
		String l, nazwa;
		System.out.printf("Podaj nazwe pliku do otwarcia: ");
		nazwa = wej.next();
		try {
			wej = new Scanner(new FileReader(nazwa));
			if (wej.hasNext()) {
				l = wej.next();
				t = new Drzewo(new Wezel(l));
			}
			while (wej.hasNext()) {
				l = wej.next();
				t.dodaj(t.korzen,new Wezel(l));
			}
		} catch (IOException e) {
			System.out.printf("Nie ma pliku o nazwie '%s'.",nazwa);
		}
		wej.close();
		return t;
	}
	
	public static void zapis(Drzewo t) {
		Scanner wej = new Scanner(System.in);
		PrintWriter wyj = null;
		String nazwa;
		System.out.printf("Podaj nazwe pliku do zapisu: ");
		nazwa = wej.next();
		try {
			wyj = new PrintWriter(nazwa);
			t.zapis(t.korzen,wyj);
			wyj.close();
		} catch (FileNotFoundException e) {
			System.out.printf("Nie ma pliku o nazwie '%s'.",nazwa);
		}
		wej.close();
	}
	
	public static void main(String[] args) {
		Drzewo bst = null;
		bst = odczyt(bst);
		if (bst != null) {
			bst.wypisz(bst.korzen);
			zapis(bst);
			System.out.printf("\n\nDrzewo sk³ada siê z %d wêz³ów i korzenia '%s'.\n",bst.ilosc,bst.korzen.wyraz);
		}
	}

}
