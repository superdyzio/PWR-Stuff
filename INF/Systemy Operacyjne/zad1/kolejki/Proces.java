package kolejki;

public class Proces {
	private int czasPotrzebny;
	private int czasOczekiwania;
	public int czasZgloszenia;
	public final int index;
	
	public Proces(int i, int cp, int cz) {
		czasZgloszenia = cz;
		czasPotrzebny = cp;
		index = i;
		czasOczekiwania = 0;
	}
	
	public int getCzasP() {
		return czasPotrzebny;
	}
	
	public void setCzasP(int cp) {
		czasPotrzebny = cp;
	}
	
	public int getCzasO() {
		return czasOczekiwania;
	}
	
	public void setCzasO(int co) {
		czasOczekiwania = co;
	}
}
