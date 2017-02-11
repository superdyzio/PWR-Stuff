import java.util.List;
import java.util.ArrayList;

class Makler
{
    List< KontoInwestycyjne > bank = new ArrayList< KontoInwestycyjne >();
    
    public void zalozKontoAkcyjne(double c, int i)
    {
        bank.add(i,new KontoAkcyjne(c));
    }
    
    public void zalozKontoLokata(double p, int i)
    {
        bank.add(i,new Lokata(p));
    }
    
    public void aktualizujKonta()
    {
        for (KontoInwestycyjne konto : bank)
            {
                System.out.println("Stary stan: "+konto.dajStan());
                konto.aktualizuj();
                System.out.println("Nowy stan: "+konto.dajStan());
            }
    }
    
    public static int main()
    {
        int i=0;
        Makler A = new Makler();
        A.zalozKontoAkcyjne(0.5,i++);
        A.zalozKontoLokata(0.04,i++);
        A.zalozKontoLokata(0.1,i++);
        A.zalozKontoAkcyjne(1,i++);
        A.zalozKontoLokata(0.5,i++);
        i=1;
        for (KontoInwestycyjne konto : A.bank)
        {
            konto.wplac(i*1000);
            konto.wyplac(i*100);
            i++;
        }
        A.aktualizujKonta();
        return 0;
    }
}