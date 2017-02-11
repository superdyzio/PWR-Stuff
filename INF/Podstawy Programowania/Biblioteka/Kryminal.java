class Kryminal extends Ksiazka
{
    public Kryminal(String tytul, String opis)
    {
        super(tytul);
        this.opis=opis;
        rodzaj="Kryminal";
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
