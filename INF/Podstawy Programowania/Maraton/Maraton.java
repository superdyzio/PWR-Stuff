class Maraton 
{
    public static void main( String[] args ) 
    {
        int j = 0;
        int k = 0;
        String[] ludzie = {
            "Andrzej", "Janusz", "Marta", "Alojzy", "Sylwester", "Daria", "Tomasz", "Mateusz", "Paulina", "Przemek", "Adam", "Ania", "Ola", "Sylwia", "Mariusz"
            }; 
        int[] czasy = {
            100, 101, 171, 165, 350, 289, 400, 167, 112, 800, 289, 311, 363, 422, 287   
            };
        sort(czasy,ludzie);
        for (int i = 0; i < ludzie.length; i++) 
        { 
            System.out.println(ludzie[i] + ": " + czasy[i]);
        }
        j = pierwszy(czasy);
        System.out.println("Najszybszy był " + ludzie[j] + " nr " + (j+1) + " z czasem " + czasy[j]);
        k = drugi(czasy,j);
        System.out.println("Drugi był " + ludzie[k] + " nr " + (k+1) + " z czasem " + czasy[k]);
    }
    
    public static int pierwszy (int [] tab)
    {
        int x = 0;
        int min = tab[0];
        for (int i = 1; i < tab.length; i++)
            if (tab[i] < min)
            {
                min = tab[i];
                x = i;
            }
        return x;
    }  
    
    public static int drugi (int [] tab, int p)
    {
        int [] x = new int [tab.length - 1];
        int s = 0;
        for (int i=0; i< tab.length; i++)
            if (i != p) x[i-s] = tab[i];
               else s++;
        int d=pierwszy(x);
        return d>=p?d+1:d;           
    }
    
    public static void sort(int [] czasy, String [] ludzie)
    {
        String l = "";
        int k = 0;
        for (int i = 0; i < czasy.length - 1; i++)
            for (int j = 0; j < czasy.length - 1; j++)
                if (czasy[j] > czasy[j+1])
                {
                    l=ludzie[j];
                    ludzie[j]=ludzie[j+1];
                    ludzie[j+1]=l;
                    k=czasy[j];
                    czasy[j]=czasy[j+1];
                    czasy[j+1]=k;
                }
    }
}