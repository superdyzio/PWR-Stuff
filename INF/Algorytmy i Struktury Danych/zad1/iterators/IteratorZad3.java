package iterators;
import User.User;

public class IteratorZad3 implements Iterator {
	final ArrayIterator _it;
	final PredicateZad3 _pred;
	
	public IteratorZad3(ArrayIterator it, PredicateZad3 pred) {
		_it = it;
		_pred = pred;
	}
	
	void filterF() {
		User u = (User) current();
		while (!_it.isDone() && !_pred.accept(u)) {
			_it.next();
			u = (User) current();
		}
	}
	
	void filterB() {
		User u = (User) current();
		while (_it._current>0 && !_pred.accept(u)) {
			_it.previous();
			u = (User) current();
		}
	}
	
	public void previous() {
		_it._current--;
		filterB();
	}
	
	public void next() {
		_it._current++;
		filterF();
	}
	
	public void first() {
		_it._current = _it._first;
		filterF();
	}
	
	public void last() {
		_it._current = _it._last;
		filterB();
	}
	
	public boolean isDone() {
		return _it.isDone();
	}
	
	public Object current() {
		return _it.current();
	}
}

