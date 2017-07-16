import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Neighbours
{
	Point[] imageI;
	Point[] imageJ;
	
	public Neighbours(Point[] imageI, Point[] imageJ)
	{
		this.imageI = imageI;
		this.imageJ = imageJ;
	}
	
	public LinkedList<Point[]> pairPoints()
	{
		double bestDistance, distance;
		int bestNeighbour;
		
		for(int i=0; i< imageI.length; i++)
		{
			bestDistance = Double.MAX_VALUE;
			bestNeighbour = 0;
			for(int j=0; j<imageJ.length; j++)
			{
				distance = euclidesDistance(imageI[i], imageJ[j]);
				if(bestDistance > distance)
				{
					bestDistance = distance;
					bestNeighbour = j;
				}
			}
			imageI[i].setNeighbourIndex(bestNeighbour);
		}
		for(int i=0; i< imageJ.length; i++)
		{
			bestDistance = Double.MAX_VALUE;
			bestNeighbour = 0;
			for(int j=0; j<imageI.length; j++)
			{
				distance = euclidesDistance(imageJ[i], imageI[j]);
				if(bestDistance > distance)
				{
					bestDistance = distance;
					bestNeighbour = j;
				}
			}
			imageJ[i].setNeighbourIndex(bestNeighbour);
		}
		
		LinkedList<Point[]> pairs = new LinkedList<Point[]>();
		
		int minLength = imageI.length;
		if(minLength > imageJ.length)
		{
			minLength = imageJ.length;
		}
		
		for(int i=0; i<minLength; i++)
		{
			int index = imageI[i].getNeighbourIndex();
			if( i == imageJ[index].getNeighbourIndex())
			{
				imageI[i].setNeighbourIndex(pairs.size());
				imageJ[index].setNeighbourIndex(pairs.size());
				pairs.add(new Point[]{imageI[i], imageJ[index]});
				
			}
		}
		
		return pairs;
	}
	
	private double euclidesDistance(Point p1, Point p2)
	{
		double value = 0;
		
		for(int i=3; i< p1.getPoint().length; i++)
		{
			value += (p1.getPoint()[i] - p2.getPoint()[i])*(p1.getPoint()[i] - p2.getPoint()[i]);
		}
		
		return Math.sqrt(value);
	}
}