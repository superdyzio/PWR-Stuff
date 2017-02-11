package dwojka;

public class ListM {
	Elem poc, wartownik;
	
	public ListM() {
		poc = null;
		wartownik = new Elem(new Magazyn("Wartownik"));
		wartownik.nast = wartownik;
	}
	
	public Magazyn get(String nazwa) {
		Elem l = poc;
		while (l != wartownik && l.m.nazwa != nazwa) l = l.nast;
		return l.m;
	}
	
	public void dodaj(Magazyn dod) {
		Elem e = new Elem(dod);
		if (poc == null) {
			poc = e;
			poc.nast = wartownik;
			wartownik.nast = poc;
		}
		else {
			Elem l = poc;
			while (l.nast != wartownik) l = l.nast;
			e.nast = wartownik;
			l.nast =  e;
		}
	}
	
	public void usun(String n, String nowy) {
		Magazyn przenies;
		if (poc != null) {
			if (poc.m.nazwa == n) {
				poc = poc.nast;
				wartownik.nast = poc;
			}
			else {
				Elem l = poc;
				while ((l != wartownik) && (l.m.nazwa != nowy)) l = l.nast;
				if (l != wartownik) przenies = l.m;
				else {
					System.out.println("B³êdna nazwa magazynu do przeniesienia towarów.");
					return;
				}
				l = poc;
				while ((l.nast != wartownik) && (l.nast.m.nazwa != n)) l = l.nast;
				if (l.nast != wartownik) {
					przenies.lista.zlozenie(l.nast.m.lista);
					l.nast = l.nast.nast;
				}
			}
		}
	}
	
	public void druk() {
		Elem pom = poc;
		while (pom != wartownik) {
			pom.m.wypisz();
			pom = pom.nast;
		}
	}
		
	public void zlozenie(List x) {
		while (x.poc != x.wartownik) {
			dodaj(poc.m);
			x.poc = x.poc.nast;
		}
	}
}

