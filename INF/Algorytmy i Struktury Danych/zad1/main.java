import java.io.IOException;
import java.util.Scanner;

import iterators.*;
import User.User;

public class main {
	
	public static void zad1(ArrayIterator it){
		PredicateCoN pred = new PredicateCoN(4);
		PredicateCoN pred2 = new PredicateCoN(2);
		IteratorCoN con = new IteratorCoN(it,pred);
		IteratorCoN co = new IteratorCoN(con,pred2);
		System.out.printf("Ostatni element ogólnie: %s\n",((User)it.current()).login);
		co.last();
		System.out.printf("Ostatni element wg iteratora: %s\n",((User)co.current()).login);
		User pom;
		while(!co.isDone()) {								
			pom = (User) con.current();
			System.out.println(pom.login);
			co.previous();
		} 
	}
	
	public static void zad2(ArrayIterator it){
		PredicateZad2 pred = new PredicateZad2();
		IteratorZad2 zad = new IteratorZad2(it,pred);
		zad.first();
		User pom;
		while (!zad.isDone()) {									
			pom = (User) zad.current();
			System.out.println(pom.login);
			zad.next();
		} 
	}
	
	public static void zad3(ArrayIterator it){
		PredicateZad3 pred = new PredicateZad3();
		IteratorZad3 zad = new IteratorZad3(it,pred);
		zad.first();
		User pom;
		while (!zad.isDone()) {									
			pom = (User) zad.current();
			System.out.println(pom.login);
			zad.next();
		}
	}
	
	public static void main(final String[] args) throws IOException {
		final int n = 14;
		User[] tab = new User[n];
		Scanner wej = new Scanner(System.in);
		tab[0] = new User("Andrzej",1000,null,0);			tab[1] = new User("Bogdan",-200,tab[0],1);
		tab[2] = new User("Cyprian",-100,null,2);			tab[3] = new User("Dawid",23000,null,3);
		tab[4] = new User("Ebi",500,tab[2],4);				tab[5] = new User("Franek",-60,tab[1],5);
		tab[6] = new User("George",70,null,6);				tab[7] = new User("Henryk",-8,null,7);
		tab[8] = new User("Ignacy",900,null,8);				tab[9] = new User("Ja",900,tab[7],9); 
		tab[10] = new User("Kociao",100,null,10);			tab[11] = new User("Lol",-111,tab[10],11);
		tab[12] = new User("Misiek",120,null,12);			tab[13] = new User("Nowy",1300,tab[6],13);
		ArrayIterator it = new ArrayIterator(tab,0,n);
		it.last();
		System.out.println("Które zadanie chcesz wyœwietliæ?");
		int wybor = wej.nextInt();
		switch (wybor) {
		case 1: zad1(it); break;
		case 2: zad2(it); break;
		case 3: zad3(it);
		}
		wej.close();
	}
}