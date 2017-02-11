package dwa;

public class Node {
	public int dane;
	public Node lewy, prawy;
	public boolean kolor;
	
	public Node(int x) {
		dane = x;
		lewy = prawy = null;
		kolor = true;
	}
}
