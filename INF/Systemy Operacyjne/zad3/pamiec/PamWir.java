package pamiec;

public class PamWir {
	public Strona tab[];
	
	public PamWir() {
		tab = new Strona[5];
		for (int i = 0; i < tab.length; i++)
			tab[i] = new Strona(i);
	}
}