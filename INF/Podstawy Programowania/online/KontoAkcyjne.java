import java.util.Random;

public class KontoAkcyjne extends KontoInwestycyjne
{
    double agresja;
    
    KontoAkcyjne(double a)
    {
        super();
        agresja=a;
    }
    
    public void aktualizuj()
    {
        double r = (new Random()).nextDouble() * 2.0 - 1.0;
        stan *= (agresja*r + 1);
    }
}
        