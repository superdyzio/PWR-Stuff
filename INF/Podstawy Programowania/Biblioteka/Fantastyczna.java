class Fantastyczna extends Ksiazka
{
    public Fantastyczna(String tytul, String opis)
    {
        super(tytul);
        this.opis=opis;
        rodzaj="Fantastyczna";
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