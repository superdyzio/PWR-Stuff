package brrr;

public class Watek extends Thread{
	Bank naszBank;	
	int iloscPrzelewow;
	int nrWatku;
	
	public Watek(Bank bank,int i){
		iloscPrzelewow = 0;
		naszBank = bank;
		nrWatku = i;
		start();
	}
	
	public void run(){
		while(iloscPrzelewow < 100){
			naszBank.przelewLosowy();
			iloscPrzelewow++;
		}
		System.out.println("koniec w¹tku nr "+nrWatku);
	}
}
