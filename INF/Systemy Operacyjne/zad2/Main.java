import java.util.Scanner;
import zad2.*;
import algorytmy.*;

public class Main {
	static int rozmiarDysku, iloscZgloszen, zakresCzasu;
	
	public static void main(String[] args) {
		Scanner wej = new Scanner(System.in);
		System.out.printf("Podaj rozmiar dysku: ");
		rozmiarDysku = wej.nextInt();
		System.out.printf("Podaj iloœæ zg³oszeñ: ");
		iloscZgloszen = wej.nextInt();
		System.out.printf("Podaj zakres czasu: ");
		zakresCzasu = wej.nextInt();
		Generator g = new Generator(iloscZgloszen,rozmiarDysku,zakresCzasu);
		Dysk d = new Dysk(rozmiarDysku,g);
//		g.wypisz();
		FCFS f = new FCFS(d);
		f.realizuj();
		System.out.printf("FCFS:   %d\n",f.getIlosc());
		SSTF s = new SSTF(d);
		s.realizuj();
		System.out.printf("SSTF:   %d\n",s.getIlosc());
		SCAN a = new SCAN(d);
		a.realizuj();
		System.out.printf("SCAN:   %d\n",a.getIlosc());
		CSCAN c = new CSCAN(d);
		c.realizuj();
		System.out.printf("C-SCAN: %d\n",c.getIlosc());
		EDF e = new EDF(d);
		e.realizuj();
		System.out.printf("EDF:    %d\n",e.getIlosc());
		wej.close();
	}

}
