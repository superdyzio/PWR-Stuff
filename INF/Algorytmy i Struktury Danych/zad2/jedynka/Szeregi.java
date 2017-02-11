package jedynka;

public class Szeregi {
	double x, e;
	
	public Szeregi(double x, double e) {
		this.x = x;
		this.e = e;
	}
	
	public double abs(double x) {
		return x > 0 ? x : -x;
	}
	
	public int silnia(double x) {
		int wynik = 1;
		for (int i = 1; i <= x; i++) {
			wynik *= i;
		}
		return wynik;
	}
	
	public double sinus() {
		double sk = 1;
		double ti = 1;
		double znak = 0;
		for (int i = 1; abs(ti) >= e*abs(sk); i += 2) {
			ti = 1;
			for (int j = 0; j < i; j++) ti *= x;
			ti /= silnia(i);
			if (znak % 2 != 0) ti *= -1;
			sk += ti;
			znak++;
		}
		return sk;
	}
	
	public double cosinus() {
		double sk = 1;
		double ti = 1;
		double znak = 0;
		for (int i = 0; abs(ti) >= e*abs(sk); i += 2) {
			ti = 1;
			for (int j = 0; j < i; j++) ti *= x;
			ti /= silnia(i);
			if (znak % 2 != 0) ti *= -1;
			sk += ti;
			znak++;
		}
		return sk;
	}
	
	public double exp() {
		double sk = 1;
		double ti = 1;
		for (int i = 0; abs(ti) >= e*abs(sk); i++) {
			ti = 1;
			for (int j = 0; j < i; j++) ti *= x;
			ti /= silnia(i);
			sk += ti;
		}
		return sk;
	}
	
	public double pierwiastek() {
		double t;
		if (x < 1) t = x;
		else t = x/3;
		while (abs((t*t*t)-x) > x*e) t = t + (((x/(t*t))-t)/3);
		return t;
	}

	public double evaluateSin(){
        double ti = x, si = x;
        int  j = 2, minusOne = 1;
        long silnia = 1;
        double xx = x;
        while(Math.abs(ti)>=e*Math.abs(si)){
            xx *= x;
            xx *= x;
            silnia *= j;
            silnia *= j+1;
            j+=2;
            minusOne *= -1;
            ti = minusOne * xx/silnia;
            si += ti;  
        }
        return si;
    }

	public double evaluateCos(){
        double ti = 1, si = 1;
        int  j = 2, minusOne = 1;
        long silnia = 1;
        double xx = x;
        while(Math.abs(ti)>=e*Math.abs(si)){
            xx *= x;
            silnia *= j;
            minusOne *= -1;
            ti = minusOne * xx/silnia;
            si += ti;
            silnia *= j+1;
            xx *= x;  
            j+=2;
        }
        return si;
	}
    
	public double evaluateExp(){
        double ti = 1, si = 1;
        int  j = 2;
        long silnia = 1;
        double xx = x;
        while(Math.abs(ti)>=e*Math.abs(si)){
            ti =  xx/silnia;
            si += ti;
            xx *= x;
            silnia *= j;
            j +=1;
        }
        return si;
    }
    
	public double evaluateCubeRoot(){
        double ti; int i=0; 
        double jt = 4/3; 
        if(x>=1){
            ti = x/3;
        }
        else{ 
            ti = x;
        }
        while(Math.abs(Math.pow(ti,3)-x)>e*x ){
            ti = ti +  (x/(ti*ti)-ti)/3;
        }
        return ti;
    }
}
