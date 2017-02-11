package iterators;

import User.User;

public class PredicateCoN implements Predicate {
	int n = 0;
	
	public PredicateCoN(int n) {
		this.n = n;
	}
	
	public boolean accept(User o) {
		return o.index % n == 0;
	}
}
