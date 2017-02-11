package iterators;

import java.util.ArrayList;
import zad2.*;

public class ArrayIterator {
	private final ArrayList<Zgloszenie> array;
	private final int first;
	private final int last;
	private int current;
	
	public ArrayIterator(ArrayList<Zgloszenie> a, int f, int l) {
		array = a;
		first = f;
		last = f + l - 1;
		current = -1;
	}
	
	public ArrayIterator(ArrayList<Zgloszenie> a) {
		array = a;
		first = 0;
		current = -1;
		last = a.size() - 1;
	}
	
	public void previous() {
		current--;
	}
	
	public void next() {
		current++;
	}
	
	public void first() {
		current = first;
	}
	
	public void last() {
		current = last;
	}
	
	public boolean isDone() {
		return current < first || current > last;
	}
	
	public Zgloszenie getCurrent() {
		try {
			Zgloszenie o = array.get(current);
			return o;
		}
		catch (Exception e) {
			return null;
		}
	}
}