import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import jeden.*;
import dwa.*;

public class Main {
	static Stos<Integer> op = new Stos<Integer>();
	static Stos<Integer> arg = new Stos<Integer>();
	
	public static void konwersja() throws IOException {
		BufferedReader wej = new BufferedReader(new InputStreamReader(System.in));
		char znak;
		int pom;
		znak = (char) wej.read();
		if (((znak >= 'a') && (znak <= 'z')) || ((znak >= '0') && (znak <= '9'))) {
			System.out.print(znak);
			arg.push((int)znak);
		}
		else {
			switch (znak) {
			case '(': 	op.push((int)znak); 
						break;
			case ')': 	while ((op.wierzcholek != null) && (op.getW().getDane() != (int)'(')) {
							pom = op.pop().getDane();
							System.out.println((char)pom);
						}
						if (op.wierzcholek != null) op.pop();
						break;
			case '*': case '/': 	if ((op.wierzcholek == null) || ((op.getW().getDane() != (int)'*') && (op.getW().getDane() != (int)'/'))) {
										op.push((int)znak);
										break;
									}
									while ((op.wierzcholek != null) && ((op.getW().getDane() == (int)'*') || (op.getW().getDane() == (int)'/'))) {
										pom = op.pop().getDane();
										System.out.print((char)pom);
									}
									op.push((int)znak);
									break;
			case '+': case '-':		if ((op.wierzcholek != null) && (op.getW().getDane() == (int)'(')) {
										op.push((int)znak);
										break;
									}
									while ((op.wierzcholek != null) && (op.getW().getDane() != (int)'(')) {
										pom = op.pop().getDane();
										System.out.print((char)pom);
									}
									op.push((int)znak);
									break;
			}
		}
		while (wej.ready()) {
			znak = (char) wej.read();
			if (((znak >= 'a') && (znak <= 'z')) || ((znak >= '0') && (znak <= '9'))) {
				System.out.print(znak);
				arg.push((int)znak);
			}
			else {
				switch (znak) {
				case '(': 	op.push((int)znak); 
							break;
				case ')': 	while ((op.wierzcholek != null) && (op.getW().getDane() != (int)'(')) {
								pom = op.pop().getDane();
								System.out.print((char)pom);
							}
							if (op.wierzcholek != null) op.pop();
							break;
				case '*': case '/': 	if ((op.wierzcholek == null) || ((op.getW().getDane() != (int)'*') && (op.getW().getDane() != (int)'/'))) {
											op.push((int)znak);
											break;
										}
										while ((op.wierzcholek != null) && ((op.getW().getDane() == (int)'*') || (op.getW().getDane() == (int)'/'))) {
											pom = op.pop().getDane();
											System.out.print((char)pom);
										}
										op.push((int)znak);
										break;
				case '+': case '-':		if ((op.wierzcholek == null) || (op.getW().getDane() == (int)'(')) {
											op.push((int)znak);
											break;
										}
										while ((op.wierzcholek != null) && (op.getW().getDane() != (int)'(')) {
											pom = op.pop().getDane();
											System.out.print((char)pom);
										}
										op.push((int)znak);
										break;
				}		
			}
		}
		while (op.wierzcholek != null) {
			pom = op.pop().getDane();
			System.out.print((char)pom);
		}
	}

	public static void main(String[] args) throws IOException {
//		konwersja();
		int N = 1;
		ArrayList<Mergesort> sortuj = new ArrayList<Mergesort>();
		double sumac = 0;
		double sumapo = 0, sumaprze = 0;
		for (int i = 0; i < N; i++) sortuj.add(new Mergesort(10000,-1));
		for (Mergesort p:sortuj) {
			sumac += p.dwa();
			sumapo += p.porownania; sumaprze += p.przepisania;
		}
		System.out.printf("\n\n\nCzas œredni: %f [ns]\nŒrednia porównañ: %f\nŒrednia przepisañ: %f\n",sumac/N,sumapo/N,sumaprze/N);
	}
}
