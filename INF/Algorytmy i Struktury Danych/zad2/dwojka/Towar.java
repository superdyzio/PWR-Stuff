package dwojka;

public class Towar {
	public String nazwa;
	double cena;
	
	public Towar(String n, double c) {
		nazwa = n;
		cena = c;
	}
	
	public void wypisz() {
		System.out.printf("%s %f\n",nazwa,cena);
	}
}
