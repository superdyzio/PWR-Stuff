import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;


public class Reader
{
	public Point[] read(String url)
	{
		Point[] points = null;
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(url));
			int featuresAmount = Integer.parseInt(br.readLine())+5;
			int pointsAmount = Integer.parseInt(br.readLine());
			points = new Point[pointsAmount];
			
			for(int i=0; i< pointsAmount; i++)
			{
				String[] point = br.readLine().split(" ");
				points[i] = new Point(convertStringToInt(point));
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		return points;
	}
	
	public int[] convertStringToInt(String[] point)
	{
		int[] value = new int[point.length-3];
		int position = 0;
		
		for(int i=0; i<value.length; i++)
		{
			
			value[i] = (int)Double.parseDouble(point[position]);
			position++;
			if(position == 2)
			{
				position = 5;
			}
		}
		
		return value;
	}
}
