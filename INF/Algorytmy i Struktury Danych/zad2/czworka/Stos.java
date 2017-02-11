package czworka;

public class Stos {
	public Pole poc;
	
	public Stos() { 
		poc = null;
	}
	
	public Stos(Pole p) {
		poc = p;
	}
	
	public void push(Pole p) {
		if (poc != null) {
			Pole l = poc;
			while (l.nast != null) l = l.nast;
			l.nast = p;
		}
		else poc = p;
	}
	
	public Pole pop() {
		Pole ret = null;
		if (poc != null) {
			Pole l = poc;
			while (l.nast.nast != null) l = l.nast;
			ret = l.nast;
			l.nast = null;
		}
		return ret;
	}
	
	public void druk() {
		Pole l = poc;
		while (l != null) {
			System.out.println(l.dane);
			l = l.nast;
		}
	}
	
	public void clear() {
		poc = null;
	}
	
	public int size() {
		Pole l = poc;
		int ilosc = 0;
		while (l != null) {
			ilosc++;
			l = l.nast;
		}
		return ilosc;
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
}