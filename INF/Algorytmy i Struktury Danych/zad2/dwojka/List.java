package dwojka;

public class List {
	Element poc, wartownik;
	int ilosc;
	double suma;
	
	public List() {
		poc = null;
		wartownik = new Element(new Towar("Wartownik",-1));
		ilosc = 0;
		suma = 0;
		wartownik.nast = wartownik;
	}
	
	public void dodaj(Towar dod) {
		Element e = new Element(dod);
		if (poc == null) {
			poc = e;
			poc.nast = wartownik;
			wartownik.nast = poc;
		}
		else {
			Element l = poc;
			while (l.nast != wartownik) l = l.nast;
			e.nast = wartownik;
			ilosc++;
			suma += e.dane.cena;
			l.nast =  e;
		}
	}
	
	public void usun(String n) {
		if (poc != null) {
			if (poc.dane.nazwa == n) {
				poc = poc.nast;
				wartownik.nast = poc;
			}
			else {
				Element l = poc;
				while ((l.nast != wartownik) && (l.nast.dane.nazwa != n)) l = l.nast;
				if (l.nast != wartownik) { 
					suma -= l.nast.dane.cena; 
					l.nast = l.nast.nast; 
					ilosc--; 
				}
			}
		}
	}
	
	public Towar min() {
		Towar e = null;
		double min = 0;
		if (poc != null) {
			min = poc.dane.cena;
			e = poc.dane;
			for (Element pom = poc; pom != wartownik; pom = pom.nast)
				if (pom.dane.cena < min) { 
					min = pom.dane.cena;
					e = pom.dane;
				}
		}
		return e;
	}
	
	public void druk() {
		Element pom = poc;
		while (pom != wartownik) {
			pom.dane.wypisz();
			pom = pom.nast;
		}
	}
	
	public double srednia() {
		Element pom = poc;
		double suma = 0;;
		int n = 0;
		while (pom != wartownik) {
			n++;
			suma += pom.dane.cena;
			pom = pom.nast;
		}
		return suma/n;
	}
	
	public void zmiencene(String n, double nowa) {
		if (poc != null) {
			if (poc.dane.nazwa == n) {
				poc.dane.cena = nowa;
			}
			else {
				Element l = poc;
				while ((l.nast != wartownik) && (l.dane.nazwa != n)) l = l.nast;
				if (l.nast != wartownik) l.dane.cena = nowa;
			}
		}
	}
	
	public void zlozenie(List x) {
		while (x.poc != x.wartownik) {
			dodaj(poc.dane);
			x.poc = x.poc.nast;
		}
	}
}
