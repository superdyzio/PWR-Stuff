import java.util.List;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

class AnalizatorGieldowy
{
    public static int szukaj(List<Double> ceny, int i)
    {
        int indeks=0;
        double roznica=0;
        for (int j=0; j<i; j++)
            for (int k=j+1; k<i; k++)
                if ((ceny.get(k)-ceny.get(j))>roznica)
                    {
                        roznica=ceny.get(k)-ceny.get(j);
                        indeks=j;
                    }
        return indeks;
    }
    
    public static void main(String[] args)
    {
        int i=0;
        List< String > daty = new ArrayList < String >();
        List< Double > kursy = new ArrayList < Double >();
        try
        {
            BufferedReader wejscie = new BufferedReader(new FileReader("gielda2.csv"));
            String linia;
            while ((linia=wejscie.readLine()) != null)
            {
                StringTokenizer token = new StringTokenizer(linia,",");
                String data = token.nextToken();
                Double cenaAkcji = Double.parseDouble(token.nextToken());
                System.out.println(data+" "+cenaAkcji);
                daty.add(0,data);
                kursy.add(0,cenaAkcji);
                i++;
            }
            wejscie.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        System.out.println(szukaj(kursy,i));
    }
}