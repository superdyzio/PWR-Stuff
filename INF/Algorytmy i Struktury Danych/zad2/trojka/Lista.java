package trojka;

public class Lista {
	public Elemen poc;
	
	public Lista(Elemen e) {
		poc = e;
		poc.nast = poc;
	}
	
	public Lista() {
		poc = null;
	}
	
	public void enqueue(Elemen e) {
		if (poc != null) {
			e.nast = poc;
			Elemen l = poc;
			while (l.nast != poc) l = l.nast;
			l.nast = e;
			poc = e;
		}
		else { 
			poc = e;
			poc.nast = poc;
		}
	}
	
	public Elemen dequeue() {
		Elemen l = poc, ret = null;
		while (l.nast.nast != poc) l = l.nast;
		ret = l.nast;
		l.nast = poc;
		return ret;
	}
	
	public void clear() {
		poc = null;
	}
	
	public int size() {
		int ilosc = 0;
		Elemen pom = poc;
		if (pom!= null) ilosc++;
		while ((pom != null) && (pom.nast != poc)) {
			ilosc++;
			pom = pom.nast;
		}
		
		return ilosc;
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public void druk() {
		Elemen l = poc;
		if (l != null) {
			System.out.println(l.dane);
			l = l.nast;
			while (l != poc) {
				System.out.println(l.dane);
				l = l.nast;	
			}
		}
	}
}
