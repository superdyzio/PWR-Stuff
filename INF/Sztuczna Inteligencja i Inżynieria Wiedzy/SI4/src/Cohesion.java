import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.function.Function;
import java.util.function.ToDoubleFunction;
import java.util.function.ToIntFunction;
import java.util.function.ToLongFunction;


public class Cohesion
{
	private List<Point[]> couples;
	private int divide = 1;
	
	public Cohesion(LinkedList<Point[]> couples, int divide)
	{
		this.couples = couples;
		this.divide = divide;
	}
		
	public LinkedList<Point[]> neighbours(int number)
	{
		LinkedList<Point[]> coh = new LinkedList<Point[]>();
		boolean consist = false;
		for(int i=0; i<couples.size(); i++)
		{
			consist = checkNeighbords(couples.get(i)[0], couples.get(i)[1], number);
			if(consist)
			{
				coh.add(couples.get(i));
				consist = false;
			}
		}
		
		return coh;
	}
	
	private boolean checkNeighbords(Point point1, Point point2, int number)
	{
		ArrayList<Point> p1 = new ArrayList<Point>();
		ArrayList<Point> p2 = new ArrayList<Point>();
		int coh =0;
		for(int i=0; i<couples.size(); i++)
		{
			couples.get(i)[0].setDistance(euclidesDistance(point1, couples.get(i)[0]));
			if(couples.get(i)[0].getDistance()!=0)
			{
				p1.add(couples.get(i)[0]);
			}
			couples.get(i)[1].setDistance(euclidesDistance(point2, couples.get(i)[1]));
			if(couples.get(i)[1].getDistance()!=0)
			{
				p2.add(couples.get(i)[1]);
			}
		}
		Collections.sort(p1, new distanceComper());
		Collections.sort(p2, new distanceComper());
		for(int i=0; i<number; i++)
		{
			int key = p1.get(i).getNeighbourIndex();
			Point p = couples.get(key)[1];
			for(int j=0; j<number; j++)
			{
				if(p2.get(j) == p)
				{
					coh++;
				}
			}
		}
		return (coh >number/divide)? true : false;
	}
	
	private double euclidesDistance(Point p1, Point p2)
	{
		return Math.sqrt(Math.pow((p1.getX()-p2.getX()),2)+Math.pow((p1.getY()-p2.getY()),2));
	}
	
	private static class distanceComper implements Comparator<Point>
	{
        @Override
		public int compare(Point p1, Point p2 )
		{
			if( p1.getDistance() > p2.getDistance())  
				return 1;  
			else if( p1.getDistance() < p2.getDistance())  
				return -1;  
			else  
				return 0;  
		}

        @Override
        public Comparator<Point> reversed() {
            // TODO Auto-generated method stub
            return null;
        }

        @Override
        public Comparator<Point> thenComparing(Comparator<? super Point> other) {
            // TODO Auto-generated method stub
            return null;
        }

        @Override
        public <U> Comparator<Point> thenComparing(Function<? super Point, ? extends U> keyExtractor, Comparator<? super U> keyComparator) {
            // TODO Auto-generated method stub
            return null;
        }

        @Override
        public <U extends Comparable<? super U>> Comparator<Point> thenComparing(Function<? super Point, ? extends U> keyExtractor) {
            // TODO Auto-generated method stub
            return null;
        }

        @Override
        public Comparator<Point> thenComparingInt(ToIntFunction<? super Point> keyExtractor) {
            // TODO Auto-generated method stub
            return null;
        }

        @Override
        public Comparator<Point> thenComparingLong(ToLongFunction<? super Point> keyExtractor) {
            // TODO Auto-generated method stub
            return null;
        }

        @Override
        public Comparator<Point> thenComparingDouble(ToDoubleFunction<? super Point> keyExtractor) {
            // TODO Auto-generated method stub
            return null;
        }


	}
}
