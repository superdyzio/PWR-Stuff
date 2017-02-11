package brrr;

public class main {
	public static void main(String[] args) {
		int iloscWatkow = 10;
		
		Bank bank = new Bank(10, 1000);
		Watek tablicaWatkow[] = new Watek[iloscWatkow];
		for(int i=0; i < tablicaWatkow.length; i++){
			tablicaWatkow[i] = new Watek(bank,i+1);
			System.out.println("Pocz¹tek w¹tku " + (i+1));
		}
		for(int i=0; i < tablicaWatkow.length; i++){
			try{
				tablicaWatkow[i].join();
			}catch(Exception e){
				throw new RuntimeException();
			}
		}
		bank.podsumowanie();
	}
}
