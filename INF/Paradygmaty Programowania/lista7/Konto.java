package brrr;

public class Konto {

	int saldo;
	
	public Konto(int pinionszki){
		saldo = pinionszki;
	}
	
	void ustawSaldo(int kwota){
		saldo = kwota;
	}
	
	int dajSaldo(){
		return saldo;
	}
	
	public String toString(){
		return "" + saldo;
	}
}
