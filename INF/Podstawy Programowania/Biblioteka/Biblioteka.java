class Biblioteka
{
    String adres;
    Ksiazka [] spis;
    int iloscksiazek;
    
    public Biblioteka(String adres)
    { 
        this.adres = adres;
        spis = new Ksiazka[100];
        iloscksiazek = 0;
    }
    
    public void dodajKsiazke(Ksiazka nowa)
    {
        spis[iloscksiazek] = nowa;
        iloscksiazek++;
    }
    
    public static void wypiszGodzinyOtwarcia()
    {
        System.out.println("Biblioteki sa otwarte codziennie od 9:00 do 17:00.");
    }
    
    public void wypiszAdres()
    {
        System.out.println(adres);
    }
    
    public void wypozyczKsiazke(String tytul)
    {
        boolean niema=true;
        for (int i=0; i<iloscksiazek && niema; i++)
            if (tytul.equals(spis[i].dajTytul()))
                {
                    niema=false;
                    if (spis[i].czyWyp()) System.out.println("Przykro nam, ksiazka jest juz wypozyczona.");
                        else {
                                spis[i].wypozycz();
                                System.out.println("Udalo sie wypozyczyc ksiazke: "+tytul);
                             }
                }
        if (niema) System.out.println("Przykro nam, nie mamy takiej ksiazki.");
    }
    
    public void wypiszDostepneKsiazki()
    {
       if (iloscksiazek>0)
       { 
            for (int i=0; i<iloscksiazek; i++)
                 if (spis[i].czyWyp() == false)
                    {
                        System.out.println(spis[i].dajTytul());
                        System.out.println(spis[i].dajRodzaj());
                        System.out.println(spis[i].dajOpis());
                        System.out.println();
                    }
       }
        else System.out.println("Brak ksiazek w bibliotece.");
    }
    
    public void oddajKsiazke(String tytul)
    {
        boolean niema=true;
        for (int i=0; i<iloscksiazek && niema; i++)
            if (tytul.equals(spis[i].dajTytul()))
                {
                    niema=false;
                    if (spis[i].czyWyp()) 
                        {
                            spis[i].oddaj();
                            System.out.println("Udalo ci sie zwrocic ksiazke: "+tytul);
                        }
                      else System.out.println("Ksiazka jest obecnie dostepna.");
                    }
        if (niema) System.out.println("Przykro nam, nie mamy takiej ksiazki.");
    }
    
    
    public static void main( String[] argumenty )
    {
        Biblioteka pierwsza = new Biblioteka( "Armi Krajowej 24" );
        Biblioteka druga = new Biblioteka( "Plac Grunwaldzki 6" );

        pierwsza.dodajKsiazke( new Epopeja("Pan Tadeusz","Epopeja to jest" ) );
        pierwsza.dodajKsiazke( new Kryminal("Gra o Tron","zawila fabula i cos tam" ) );
        pierwsza.dodajKsiazke( new Fantastyczna("Tozsamosc Bourne'a","komputyrnaja historyja" ) );
        pierwsza.dodajKsiazke( new Naukowa("Analiza Matematyczna","bardzo duzo matematyki" ) );
        
        System.out.println("");
        System.out.println( "Godziny otwarcia bibliotek: ");
        wypiszGodzinyOtwarcia();
        System.out.println();

        System.out.println( "Adresy bibliotek: " );
        pierwsza.wypiszAdres();
        druga.wypiszAdres();
        System.out.println();

        System.out.println( "Wypozyczanie Pana Tadeusza" );
        pierwsza.wypozyczKsiazke( "Pan Tadeusz" );

        pierwsza.wypozyczKsiazke( "Pan Tadeusz" );

        druga.wypozyczKsiazke( "Pan Tadeusz" );

        System.out.println();

        System.out.println( "Ksiazki dostepne w pierwszej bibliotece" );
        pierwsza.wypiszDostepneKsiazki();
        System.out.println();
        System.out.println( "Ksiazki dostepne w drugiej bibliotece" );
        druga.wypiszDostepneKsiazki();
        System.out.println();

        System.out.println( "Zwrot Pana Tadeusza" );
        pierwsza.oddajKsiazke( "Pan Tadeusz" );
        System.out.println();

        System.out.println( "Ksiazki dostepne w pierwszej bibliotece" );
        pierwsza.wypiszDostepneKsiazki();
    }
}