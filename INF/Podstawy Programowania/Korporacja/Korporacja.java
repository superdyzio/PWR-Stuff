public class Korporacja
{
 public static double oblicz(double x, int y)
 {
     if (x<9.375) 
        {   System.out.println("Stawka za niska.");
            return 0;
        }
     if (y>60)
        {   System.out.println("Liczba godzin zbyt duża.");
            return 0;
        }
     if (y>40)
            return 40*x+(y-40)*1.5*x;
     else   return y*x;
    }

 public static void main()
 {
     double a, j, m, pa = 8.25, pj = 10.00, pm = 15.22;
     int ha = 45, hj = 47, hm = 73;
    
     a=oblicz(pa,ha);
     if (a!=0) System.out.println(a);
     j=oblicz(pj,hj);
     if (j!=0) System.out.println(j);
     m=oblicz(pm,hm);
     if (m!=0) System.out.println(m);
    }
}
     