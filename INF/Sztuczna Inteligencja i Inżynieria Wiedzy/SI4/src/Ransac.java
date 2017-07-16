import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

import Jama.Matrix;

public class Ransac
{
	private LinkedList<Point[]> couples = new LinkedList<Point[]>();
	
	public Ransac(LinkedList<Point[]> couples)
	{
		this.couples = couples;
	}
	
	public LinkedList<Point[]> runRunsac(int iter, double maxerror)
	{
		LinkedList<Point[]> newCouples = new LinkedList<Point[]>();
		
		Matrix model = algorithm(iter, maxerror);
		for(int i=0; i<couples.size(); i++)
		{
			if(couples.get(i)[1].getDistance() < maxerror)
			{
				newCouples.add(couples.get(i));
			}
		}
		
		return newCouples;
	}
	
	private Matrix algorithm(int iter, double maxerror)
	{
		Matrix bestmodel = null;
		double bestscore = 0;
		double error = 0;
		
		for(int i=0; i<iter; i++)
		{
			Matrix model=null;
			while(model == null)
			{
				Point[][] samples = chooseSamples2(10,180); 
				model = calculateModel(samples);
			}
			double score = 0;
			for(int j=0; j<couples.size(); j++)
			{
				error = countError(model, couples.get(j)[0], couples.get(j)[1]);
				couples.get(j)[1].setDistance(error);
				if(error < maxerror)
				{
					score++;
				}
			}
			if(score>bestscore)
			{
				bestscore = score;
				bestmodel = model;
			}
		}
		return bestmodel;
	}
	
	private Point[][] chooseSamples()
	{
		Point[][] chosen = new Point[3][2];
		Random rn = new Random();
		int position = 0;
		
		for(int i=0; i<3; i++)
		{
			position = rn.nextInt(couples.size());
			chosen[i][0] = couples.get(position)[0];
			chosen[i][1] = couples.get(position)[1];
		}
		
		return chosen;
	}
	
	private Point[][] chooseSamples2(double r, double R)
	{
		Point[][] chosen = new Point[3][2];
		Random rn = new Random();
		int position = rn.nextInt(couples.size());
		
		chosen[0][0] = couples.get(position)[0];
		chosen[0][1] = couples.get(position)[1];
		
		position = rn.nextInt(couples.size());
		while(!checkPoint(chosen[0][0], chosen[0][1], couples.get(position)[0], couples.get(position)[1], r, R))
		{
			position = rn.nextInt(couples.size());
		}
		chosen[1][0] = couples.get(position)[0];
		chosen[1][1] = couples.get(position)[1];
		
		position = rn.nextInt(couples.size());
		while(!(checkPoint(chosen[0][0], chosen[0][1], couples.get(position)[0], couples.get(position)[1], r, R) && checkPoint(chosen[1][0], chosen[1][1], couples.get(position)[0], couples.get(position)[1], r, R)))
		{
			position = rn.nextInt(couples.size());
		}
		chosen[2][0] = couples.get(position)[0];
		chosen[2][1] = couples.get(position)[1];
		
		return chosen;
	}
	
	private boolean checkPoint(Point p1, Point p2, Point p3, Point p4, double r, double R)
	{
		double d1 =Math.pow((p1.getX()-p3.getX()), 2) + Math.pow((p1.getY() - p3.getY()), 2);
		double d2 =Math.pow((p2.getX()-p4.getX()), 2) + Math.pow((p2.getY() - p4.getY()), 2);
		
		return d1 > r*r && d1 < R*R && d2 > r*r && d2 < R*R;
	}
	
	private Matrix calculateModel(Point[][] samples)
	{
		double[][] array = new double[][]
				{
					{samples[0][0].getX(),samples[0][0].getY(),1,0,0,0},
					{samples[1][0].getX(),samples[1][0].getY(),1,0,0,0},
					{samples[2][0].getX(),samples[2][0].getY(),1,0,0,0},
					{0,0,0,samples[0][0].getX(),samples[0][0].getY(),1},
					{0,0,0,samples[1][0].getX(),samples[1][0].getY(),1},
					{0,0,0,samples[2][0].getX(),samples[2][0].getY(),1},
				};
		Matrix m = new Matrix(array);
		
		try
		{
			m = m.inverse();
		}
		catch(Exception e)
		{
			return null;
		}
		
		array = new double[][]
				{
					{samples[0][1].getX()},
					{samples[1][1].getX()},
					{samples[2][1].getX()},
					{samples[0][1].getY()},
					{samples[1][1].getY()},
					{samples[2][1].getY()}
				};
		
		Matrix m2 = new Matrix(array);
		double[][] m3 = m.times(m2).getArray();
		
		array = new double[][]
				{
					{m3[0][0], m3[1][0], m3[2][0]},
					{m3[3][0], m3[4][0], m3[5][0]},
					{0, 0, 1}
				};
		
		return new Matrix(array);
	}
	
	private double countError(Matrix model, Point p1, Point p2)
	{
		double[][] mod = model.getArray();
		double error = (mod[0][0] * p1.getX() + mod[0][1] * p1.getY() + mod[0][2] - p2.getX())* (mod[0][0] * p1.getX() + mod[0][1] * p1.getY() + mod[0][2] - p2.getX())
				+ (mod [1][0]* p1.getX() + mod[1][1] * p1.getY() + mod[1][2] - p2.getY())* (mod[1][0] * p1.getX() + mod[1][1] * p1.getY() + mod[1][2] - p2.getY());
		
		return Math.sqrt(error);
	}
}
