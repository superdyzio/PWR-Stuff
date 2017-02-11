package jeden;

public class Stos <R> {
	public Element<R> wierzcholek;
	
	public Stos() {
		wierzcholek = null;
	}
	
	public Element<R> getW() {
		return wierzcholek;
	}
	
	public void push(R e) {
		Element<R> pom = new Element<R>(e,wierzcholek);
		wierzcholek = pom;
	}
	
	public Element<R> pop() {
		Element<R> pom = null;
		if (wierzcholek != null) {
			pom = wierzcholek;
			wierzcholek = wierzcholek.getNast();
		}
		else System.out.println("Stos jest pusty.");
		return pom;
	}
}