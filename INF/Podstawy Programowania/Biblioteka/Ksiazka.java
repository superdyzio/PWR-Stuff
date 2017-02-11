class Ksiazka
{
    String tytul;
    boolean czyWypozyczona;
    String rodzaj, opis;

    public Ksiazka( String tytul )
    {   
        this.tytul = tytul;
        czyWypozyczona=false;
    }

    public void wypozycz()
    {   
        czyWypozyczona = true;
    }
    
    public void oddaj()
    {   
        czyWypozyczona = false;
    }

    public boolean czyWyp()
    {   
        return czyWypozyczona;
    }

    public String dajTytul()
    {   
        return tytul;
    }

    public String dajRodzaj()
    {   
        return "rodzaj";
    }

    public String dajOpis()
    {   
        return "opis";
    }

    public void main( String[] argumenty ) 
    {   
        Ksiazka przykladowa = new Ksiazka( "Pan Tadeusz" );
        System.out.println( "Tytul: (powinno byc Pan Tadeusz) " + przykladowa.dajTytul() );
        System.out.println( "Czy wypozyczona (powinna byc false)? " + przykladowa.czyWyp() );
        przykladowa.wypozycz();
        System.out.println( "Czy wypozyczona (powinno byc true)? " + przykladowa.czyWyp() );
        przykladowa.oddaj();
        System.out.println( "Czy wypozyczona (powinno byc false)? " + przykladowa.czyWyp() );   

    }
}






