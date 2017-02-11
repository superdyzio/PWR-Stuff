package brrr;

import java.util.*;

public class Bank {
	ArrayList<Konto> konta;
	int suma;
	
	public Bank(int iloscKont, int saldaPoczatkowe){
		suma = iloscKont * saldaPoczatkowe;
		konta = new ArrayList<Konto>();
		for(int i=0; i < iloscKont; i++){
			konta.add(new Konto(saldaPoczatkowe));
		}
	}
	
	public int zliczSalda(){
		int wynik = 0;
		ListIterator<Konto> it = konta.listIterator();
		while(it.hasNext()){
			wynik += ((Konto)it.next()).dajSaldo();
		}
		return wynik;
	}
	
	public int dajSume(){
		return suma;
	}
	
	private Konto dajLosoweKonto(){
		return (Konto)konta.get( (int)(Math.random() * konta.size()) );
	}
	
	//wykonuje przelew 100 zl z losowego konta na losowe konto
	public synchronized void przelewLosowy(){
		Konto konto1 = dajLosoweKonto();
		Konto konto2 = dajLosoweKonto();
		while(konto1 == konto2)
			konto2 = dajLosoweKonto();		
		int saldo1 = konto1.dajSaldo() - 100;
		int saldo2 = konto2.dajSaldo() + 100;
		konto1.ustawSaldo( saldo1 );
		Thread.yield();
		konto2.ustawSaldo( saldo2 );
	}
		
	public void podsumowanie(){
		System.out.println("\nwyliczone   : " + zliczSalda());
		System.out.println("poprawne    : " + dajSume());		
		System.out.println("\nsalda kont  : " + konta);
		if( zliczSalda() != dajSume() ){
			System.out.println("\n\nAWARIA SYSTEMU !!");
		}
	}
}
