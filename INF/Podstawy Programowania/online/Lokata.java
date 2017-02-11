class Lokata extends KontoInwestycyjne
{
    double oprocentowanie;
    
    Lokata(double p)
    {
        super();
        oprocentowanie=p;
    }
    
    public void aktualizuj()
    {
        stan *= (oprocentowanie + 1);
    }
}