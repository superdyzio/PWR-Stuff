package dwa;

public class Tree {
	public Node korzen;
	
	public Tree() {
		korzen = null;
	}
	
	private boolean isRed(Node x) {
		return x != null  &&  x.kolor;
	}
	
	public int find(int x) {
		Node t = search(x);
		return t != null ? t.dane : null;
	}
	
	public Node search(int x) {
		Node pom = korzen;
		while ((pom != null) && (x != pom.dane)) 
			pom = x < pom.dane ? pom.lewy : pom.prawy;
		return pom;
	}
	
	private Node rotL(Node t) { 
		Node x = t.prawy;
		t.prawy = x.lewy;
		x.lewy = t;
		x.kolor = t.kolor;
		t.kolor = true;
		return x; 
	}
    
    private Node rotR(Node t) { 
    	Node x = t.lewy;
    	t.lewy = x.prawy;
    	x.prawy = t;
    	x.kolor = t.kolor;
    	t.kolor = true;
    	return x; 
    }
    
    private void colorFlip(Node t) {
    	t.kolor = !t.kolor;
    	t.lewy.kolor = !t.lewy.kolor;
    	t.prawy.kolor = !t.prawy.kolor;
    }
    
    public void dodaj(int x) {
    	korzen = dodaj(x,korzen);
    	korzen.kolor = false;
    }
    
    protected Node dodaj(int x, Node t) {
    	if (t == null) t = new Node(x);
    	else {
    		if (isRed(t.lewy) && isRed(t.prawy))
    			colorFlip(t);
    		if (x < t.dane) 
    			t.lewy = dodaj(x,t.lewy);
    		else 	if (x > t.dane)
    					t.prawy = dodaj(x,t.prawy);
    				else throw new RuntimeException("Duplicate " + x);
    		t = fixUp(t);
    	}
    	return t;
    }
    
    private Node fixUp(Node t) {
    	if (isRed(t.prawy))
    		t = rotL(t);
        if (isRed(t.lewy) && isRed(t.lewy.lewy))
            t = rotR(t);
        if (isRed(t.lewy) && isRed(t.prawy))
            colorFlip(t);
        return t; 
    }    
    
   private Node moveRedR(Node t) {
	   colorFlip(t);
	   if (isRed(t.lewy.lewy)) { 
		   t = rotR(t); 
		   colorFlip(t); 
	   }
	   return t;
   }
     
   private Node moveRedL(Node t) {
	   colorFlip(t);
	   if (isRed(t.prawy.lewy)) {
		   t.prawy = rotR(t.prawy); 
		   t = rotL(t); 
		   colorFlip(t);
	   }
	   return t;
   }
   
   public void delete(int x) {
	   korzen = delete(x,korzen);
	   if (korzen != null) korzen.kolor = false;
   }
    
    protected Node delete(int x, Node t) {
      if (t == null) throw new RuntimeException("Not found " + x);
      else { 
    	  if (x < t.dane) {
    		  if (!isRed(t.lewy) && !isRed(t.lewy.lewy))
                            t = moveRedL(t);
                  t.lewy = delete(x,t.lewy);
    	  }
          else {
        	  if (isRed(t.lewy)) t = rotR(t);
              if (x == t.dane && t.prawy == null) return null;
              else { 
            	  if (!isRed(t.prawy) && !isRed(t.prawy.lewy))
                               t = moveRedR(t);
                  if(x > t.dane)
                	  t.prawy = delete(x,t.prawy);
                  else t.prawy = detachMin(t.prawy,t);
              }  
          }     
      }           
      return fixUp(t);
    }  
     
    protected Node detachMin(Node t, Node del) {
      if(t.lewy == null) {
    	  del.dane = t.dane; 
    	  t=null;
      }
      else { 
    	  if (!isRed(t.lewy) && !isRed(t.lewy.lewy))
               t = moveRedL(t);
          t.lewy = detachMin(t.lewy,del);
          t = fixUp(t); 
      }
      return t;
    }    
    
	public void wypisz(Node k) {
		if (k.lewy != null) wypisz(k.lewy);
		System.out.printf("%d %b\n",k.dane,k.kolor);
		if (k.prawy != null) wypisz(k.prawy);
	}
	
	public int liczbaWezlow(Node k) {
		int wynik = 0;
		if (k.lewy != null) wynik += liczbaWezlow(k.lewy);
		if (k.prawy != null) wynik += liczbaWezlow(k.prawy);
		return 1 + wynik;
	}
	
	public int liczbaWezlowW(Node k) {
		if (k.lewy == null && k.prawy == null) return 0;
		if (k.lewy == null && k.prawy != null) return 1;
		if (k.lewy != null && k.prawy == null) return 1;
		return 1 + liczbaWezlowW(k.lewy) + liczbaWezlowW(k.prawy); 
	}
	
	public int liczbaDwochSynow(Node k) {
		if (k.lewy != null && k.prawy != null) return 1 + liczbaDwochSynow(k.lewy) + liczbaDwochSynow(k.prawy);
		return 0;
	}
	
	public int iloscMniejszych() {
		return liczbaWezlow(korzen.lewy);
	}
	
	public int glebokosc(Node k, Node t) {
		if (t == null || k == null) return 0;
		if (t == k) return 1;
		if (k == t.lewy || k == t.prawy) return 2;
		return 0 + glebokosc(k,t.lewy) + glebokosc(k,t.prawy);
	}
	
	public int wysokosc(Node k) {
		if (k == null) return 0;
		if (k.lewy == null && k.prawy == null) return 1;
		else return 2 + wysokosc(k.lewy) + wysokosc(k.prawy); 
	}
	
    public String toString() 
    {return toString(korzen,0);}
    
   private String toString(Node t,int pos) {   
   String result="";
   String spaces=" ";
   if(t!=null) result=result+toString(t.prawy,pos+4)+spaces.substring(0,pos)
               +String.format("%d%s",t.dane,(t.kolor ? "/R" :"/B"))+toString(t.lewy,pos+4);
   else result=result+String.format("/n");
   return result;
   }    

}
