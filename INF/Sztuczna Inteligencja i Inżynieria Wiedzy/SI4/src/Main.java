import java.util.List;

import javax.swing.JFrame;

public class Main
{
	private static JFrame jf= new JFrame();
	private static DrawPanel drawPanel;
	private static int x = 720;
	
	public static void main(String args[])
	{
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
		jf.setLayout(null);
		jf.setVisible(true);
		jf.setBounds(0,0, 1600, 750);
		jf.setResizable(false);
		jf.setTitle("Images Analysis");
		
		drawPanel = new DrawPanel();
		jf.add(drawPanel);
	}
}
