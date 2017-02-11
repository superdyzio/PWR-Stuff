package iterators;

import java.util.ArrayList;

import kolejki.Proces;

public class ArrayIterator implements Iterator {
	public final ArrayList<Proces> _array;
	final int _first;
	final int _last;
	int _current = -1;
	
	public ArrayIterator(ArrayList<Proces> ar, int st, int len) {
		_array = ar;
		_first = st;
		_last = st + len - 1;
	}
	
	public ArrayIterator(ArrayList<Proces> dowyk) {
		_array = dowyk;
		_first = 0;
		_last = dowyk.size() - 1;
	}
	
	public void previous() {
		_current--;
	}
	
	public void next() {
		_current++;
	}
	
	public void first() {
		_current = _first;
	}
	
	public void last() {
		_current = _last;
	}
	
	public boolean isDone() {
		return _current < _first  ||  _current > _last;
	}
	
	public Object current() throws IndexOutOfBoundsException {
		return isDone()?null:_array.get(_current);
	}
}