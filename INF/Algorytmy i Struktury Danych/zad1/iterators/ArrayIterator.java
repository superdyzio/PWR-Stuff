package iterators;

public class ArrayIterator implements Iterator {
	final Object [] _array;
	final int _first;
	final int _last;
	int _current = -1;
	
	public ArrayIterator(Object [] ar, int st, int len) {
		_array = ar;
		_first = st;
		_last = st + len - 1;
	}
	
	public ArrayIterator(Object [] ar) {
		_array = ar;
		_first = 0;
		_last = ar.length - 1;
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
		return isDone()?null:_array[_current];
	}
}