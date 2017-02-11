class Epopeja extends Ksiazka
{
    public Epopeja(String tytul, String opis)
    {
        super(tytul);
        this.opis=opis;
        rodzaj="Epopeja";
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