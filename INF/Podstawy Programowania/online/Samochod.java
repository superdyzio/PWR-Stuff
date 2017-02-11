class Samochod
{
    double spalanie;
    double bak;
    
    Samochod(double c)
    {
        spalanie=c;
        bak=0.0;
    }
    
    void zatankuj(double v)
    {
        bak+=v;
    }
    
    boolean czyPrzejedzie(double s)
    {
        return s>(bak/spalanie)?false:true;
    }

    public static int main()
    {
        Samochod auto = new Samochod(7.5);
        auto.zatankuj(75);
        if (auto.czyPrzejedzie(8)) 
            System.out.println("Przejedzie 8 km.");
         else System.out.println("Nie przejedzie 8 km");
        if (auto.czyPrzejedzie(10))
            System.out.println("Przejedzie 10 km");
         else System.out.println("Nie przejedzie 10 km");
        if (auto.czyPrzejedzie(12))
            System.out.println("Przejedzie 12 km");
         else System.out.println("Nie przejedzie 12 km");
        auto.zatankuj(15);
        if (auto.czyPrzejedzie(12))
            System.out.println("Teraz przejedzie");
         else System.out.println("Wciaz nie");
        return 0;
    }
}