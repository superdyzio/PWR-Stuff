package iterators;
import User.User;

public class IteratorCoN implements Iterator{
	 ArrayIterator _it;
	 PredicateCoN _pred;
	
	public IteratorCoN(ArrayIterator it, PredicateCoN pred) {
		_it = it;
		_pred = pred;
	}
	
	public IteratorCoN(IteratorCoN it, PredicateCoN pred) {
		_it = it._it;
		int n = it._pred.n * pred.n;
		_pred = new PredicateCoN(n);
	}
	
	void filterF() {
		User pom = (User) _it.current();
		while (!_it.isDone() && !_pred.accept(pom)) {
			_it.next();
			pom = (User) _it.current();
		}
	}
	
	void filterB() {
		User pom = (User) _it.current();
		while (_it._current>0 && !_pred.accept(pom)) {
			_it.previous();
			pom = (User) _it.current();
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
	
	public Object current() throws IndexOutOfBoundsException {
		return _it.current();
	}
}
