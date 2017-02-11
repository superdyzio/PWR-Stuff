package iterators;
import User.User;

public class PredicateZad3 implements Predicate {

	public PredicateZad3() {	
	}
	
	public boolean accept(User o) {
		boolean x = o.kolega != null;
		return x ? o.stan<0 || o.kolega.stan<0 : o.stan<0;
	}
}
