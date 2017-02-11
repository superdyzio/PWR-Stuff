public abstract class KontoInwestycyjne
{
    protected double stan;
    
    public KontoInwestycyjne()
    {
        stan = 0.0;
    }
    
    public void wplac(double kwota)
    {
        if (kwota>0)
            stan += kwota;
        else
            System.out.println("Nie mozna wplacic takiej kwoty.");
    }
    
    public void wyplac(double kwota)
    {
        if ((kwota>0) && (kwota<=stan))
            stan -= kwota;
        else 
            System.out.println("Nie mozna wyplacic takiej kwoty.");
    }
    
    public double dajStan()
    {
        return stan;
    }
    
    public abstract void aktualizuj();
}