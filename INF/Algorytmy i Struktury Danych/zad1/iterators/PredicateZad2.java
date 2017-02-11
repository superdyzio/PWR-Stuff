package iterators;

import User.User;

public class PredicateZad2 implements Predicate{
	
	public PredicateZad2(){
	}

	public boolean accept(User o) {
		return o.stan < 0  &&  o.kolega != null;
	}
}
