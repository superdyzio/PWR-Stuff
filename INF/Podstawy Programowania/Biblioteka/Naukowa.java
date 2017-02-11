class Naukowa extends Ksiazka
{
    public Naukowa(String tytul, String opis)
    {
        super(tytul);
        this.opis=opis;
        rodzaj="Naukowa";
    }
    
    public String dajRodzaj()
    {
        return rodzaj;
    }
    
    public String dajOpis()
    {
        return opis;
    }
}