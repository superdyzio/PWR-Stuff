package jeden;

public class Element <T> {
	private T dane;
	private Element<T> nast;
	
	public Element(T ob) {
		dane = ob;
		nast = null;
	}
	
	public Element(T ob, Element<T> n) {
		dane = ob;
		nast = n;
	}
	
	public T getDane() {
		return dane;
	}
	
	public void setNast(Element<T> n) {
		nast = n;
	}
	
	public Element<T> getNast() {
		return nast;
	}
}
