sealed trait BT[+A]
case object Empty extends BT[Nothing]
case class Node[+A](elem: (A, A, A), left: BT[A], right: BT[A]) extends BT[A]

  //Z1
  def stworzSlownik(): BT[String] =
    Node(("niebo", "sky", "Himmel"), Node(("ekran", "screen", "Bildschirm"), Node(("drewno", "wood", "Holz"), Empty, Empty),
      Node(("moneta", "coin", "Munze"), Empty, Empty)), Node(("ogrod", "garden", "Garten"),
      Node(("nosorozec", "rhino", "Rhinozeros"), Empty, Empty), Empty))

  //Z2
  def szukaj(slownik: BT[String], slowo: String, jezyk:String): String =
    slownik match {
      case Empty => "Brak slowa w slowniku!"
      case Node((pol, ang, ger), l, r) => {
        if (jezyk.equals("pl")) if (pol.equals(slowo)) pol else if (slowo < pol) szukaj(l, slowo, jezyk) else szukaj(r, slowo, jezyk)
        if (jezyk.equals("en")) if (ang.equals(slowo)) ang else if (slowo < ang) szukaj(l, slowo, jezyk) else szukaj(r, slowo, jezyk)
        if (jezyk.equals("de")) if (ger.equals(slowo)) ger else if (slowo < ger) szukaj(l, slowo, jezyk) else szukaj(r, slowo, jezyk)
      }
  }


//Z3
  def dodaj(slownik: BT[String], pol: String, ang: String, ger:String): BT[String] = 
    slownik match {
      case Empty => Node((pol, ang, ger), Empty, Empty)
      case Node((pl, en, de), l, r) => {
        if (pl == pol) 
          if (en == ang)
            if (de == ger) slownik
            else if (de.length() < ger.length()) Node((pl, en, ger), l, r)
            	 else if (en.length() < ang.length()) 
            		 	if (de == ger) Node((pl, ang, de), l, r)
          				else Node((pl,ang,ger), l, r)
          else Node((pl, ang, ger), l, r)
       else if (pol < pl) Node((pl, en, de), dodaj(l, pol, ang, ger), r)
        	else Node((pl, en, de), l, dodaj(r, pol, ang, ger))
      }
      slownik
  }

  //Z4
  def inorder[A](bt: BT[A]): List[(A, A, A)] =
    {
      def inord(p: (BT[A], List[(A, A, A)])): List[(A, A, A)] = p match {
        case (Empty, labels) => labels
        case (Node(v, t1, t2), labels) => inord(t1, v :: inord(t2, labels))
      }
      inord(bt, Nil)
    }

 /*
  //Z5
  def sort(list: List[(String, String, String)], jezyk:String): List[(String, String, String)] = {

    val porz = (a: (String, String, String), b: (String, String, String),(jez:String)) => {
      jez match {
        case "pl" =>  val (s1,_,_) = a; val (s2,_,_) = b 
        case "en" =>  val (_,s1,_) = a; val (_,s2,_) = b 
        case "de" =>  val (_,_,s1) = a; val (_,_,s2) = b 
      }
      if (a < b) true else false
    }

    def insert(list: List[(String, String)], t: (String, String)): List[(String, String)] = list match {
      case Nil => List[(String, String)](t)
      case x :: r => if (porz(x, t)) x :: insert(r, t)
      else t :: x :: r
    }

    (list :\ List[(String, String)]())((h, posortowana) => insert(posortowana, h))
  }
*/