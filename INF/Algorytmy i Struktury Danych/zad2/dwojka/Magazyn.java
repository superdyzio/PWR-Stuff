package dwojka;

public class Magazyn {
	String nazwa;
	public List lista;
	
	public Magazyn(String n) {
		nazwa = n;
		lista = new List();
	}
	
	public void wypisz() {
		System.out.println(nazwa);
		System.out.printf("Towar�w: %d   Cena: %f",lista.ilosc,lista.suma);
	}
}
