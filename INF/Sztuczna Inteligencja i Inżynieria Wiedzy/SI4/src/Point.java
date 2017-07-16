
public class Point
{
	private int[] point; 
	private int neighbourIndex;
	private double distance;
	
	public Point(int[] point)
	{
		this.point =point;
	}
	
	public int getX()
	{
		return point[0];
	}
	public int getY()
	{
		return point[1];
	}
	
	public void setPoint(int[] point)
	{
		this.point =point;
	}
	
	public int[] getPoint()
	{
		return point;
	}
	
	public void setNeighbourIndex(int neighbourIndex)
	{
		this.neighbourIndex = neighbourIndex;
	}
	
	public int getNeighbourIndex()
	{
		return neighbourIndex;
	}
	
	public double getDistance()
	{
		return distance;
	}
	
	public void setDistance(double distance)
	{
		this.distance = distance;
	}
}
