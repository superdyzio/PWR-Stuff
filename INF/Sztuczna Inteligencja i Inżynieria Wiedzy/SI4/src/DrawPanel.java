import java.awt.Button;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

@SuppressWarnings("LossyEncoding")
public class DrawPanel extends JPanel implements ActionListener {
    Button btn1 = new Button("Image 1");
    Button btn2 = new Button("Image 2");
    String s1, s2;
    Button btn3 = new Button("Pair");
    Button btn4 = new Button("Start");

    boolean arePaired = false;
    private String url1 = "C://cygwin//home//extract_features//1.4zeszyt.png.haraff.sift";
    private String url2 = "C://cygwin//home//extract_features//1.6zeszyt2.png.haraff.sift";
    private String image1Url;
    private String image2Url;
    private boolean isEmpty = true;

    private BufferedImage img1 = null;
    private BufferedImage img2 = null;
    private Reader fr = new Reader();
    private Point[] imageI, imageJ;
    private LinkedList<Point[]> couples;
    private LinkedList<Point[]> couples2;


    public DrawPanel() {
        this.setVisible(true);
        this.setLayout(null);
        this.setBounds(0, 0, 1600, 800);

        couples = new LinkedList<Point[]>();
        couples2 = new LinkedList<Point[]>();

        btn1.setBounds(10, 5, 100, 30);
        add(btn1);
        btn2.setBounds(110, 5, 100, 30);
        add(btn2);
        btn3.setBounds(220, 5, 100, 30);
        add(btn3);
        btn4.setBounds(330, 5, 100, 30);
        add(btn4);

        btn1.addActionListener(this);
        btn2.addActionListener(this);
        btn3.addActionListener(this);
        btn4.addActionListener(this);
        repaint();
    }

    public BufferedImage selectImage(boolean firstImage) {
        JFileChooser fc = new JFileChooser();
        fc.setCurrentDirectory(new File("D:\\Studia\\Informatyka\\Semestr 6\\Sztuczna Inteligencja i Inżynieria Wiedzy\\laboratorium\\lista4\\obrazy"));
        int returnVal = fc.showOpenDialog(this);

        BufferedImage img = null;
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            File file = fc.getSelectedFile();
            try {
                img = ImageIO.read(file);
                if (firstImage) {
                    image1Url = file.getAbsolutePath();
                    url1 = image1Url + ".haraff.sift";
                } else {
                    image2Url = file.getAbsolutePath();
                    url2 = image2Url + ".haraff.sift";
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("No image selected");
        }
        return img;
    }

    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        if (img1 != null) {
            g2d.drawImage(img1, 0, 80, null);
        }
        if (img2 != null && img1 != null) {
            g2d.drawImage(img2, img1.getWidth(), 80, null);
        }
        if (!couples.isEmpty() && couples2.isEmpty() && isEmpty) {
            for (int i = 0; i < couples.size(); i++) {
                int r = (int) (Math.random() * 255);
                int z = (int) 0;
                int b = (int) 0;

                g2d.setColor(new Color(r, z, b));
                g2d.drawLine(couples.get(i)[0].getX(), couples.get(i)[0].getY() + 80, couples.get(i)[1].getX() + img1.getWidth(), couples.get(i)[1].getY() + 80);
            }
        }
        if (!couples2.isEmpty()) {
            for (int i = 0; i < couples2.size(); i++) {
                int r = (int) (Math.random() * 255);
                int z = (int) (Math.random() * 255);
                int b = (int) (Math.random() * 255);

                g2d.setColor(new Color(r, z, b));
                g2d.drawLine(couples2.get(i)[0].getX(), couples2.get(i)[0].getY() + 80, couples2.get(i)[1].getX() + img1.getWidth(), couples2.get(i)[1].getY() + 80);
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        if (event.getSource() == btn1) {
            img1 = selectImage(true);
            imageI = fr.read(url1);
            repaint();
        } else if (event.getSource() == btn2) {
            img2 = selectImage(false);
            imageJ = fr.read(url2);
            repaint();
        } else if (event.getSource() == btn3) {
            if (imageI != null && imageJ != null) {
                couples2.clear();
                imageI = fr.read(url1);
                System.out.println("Liczba punkt�w kluczowych orbrazka I: " + imageI.length);
                imageJ = fr.read(url2);
                System.out.println("Liczba punkt�w kluczowych orbrazka J: " + imageJ.length);
                long begin = System.nanoTime();
                Neighbours neight = new Neighbours(imageI, imageJ);
                couples = neight.pairPoints();
                long end = System.nanoTime();
                System.out.println("Time needed for creating couples: " + (double) (end - begin) / (double) 1000000000);
                isEmpty = true;
                repaint();
            }
        } else if (event.getSource() == btn4) {
            imageI = fr.read(url1);
            imageJ = fr.read(url2);
            isEmpty = false;
            final Object[] options = {"Alg. sp�jno�ci", "Ransac"};
            String s = (String) JOptionPane.showInputDialog(null, "Choose...", "Algorytm", JOptionPane.PLAIN_MESSAGE, null, options, "Alg. sp�jno�ci");
            if (!s.equals("Ransac")) {
                s1 = (String) JOptionPane.showInputDialog(null, "Cardinality of neighborhood : ", " ", 1);
                s2 = (String) JOptionPane.showInputDialog(null, "Which part of is the minimum amount : ", " ", 1);
                int number = 100, number2 = 2;
                try {
                    number = Integer.parseInt(s1);
                    number2 = Integer.parseInt(s2);
                } catch (Exception e) {
                    System.out.println("Invalid number");
                    e.printStackTrace();
                }
                long begin = System.nanoTime();
                Cohesion coh = new Cohesion(couples, number2);
                couples2 = coh.neighbours(number);
                long end = System.nanoTime();
                System.out.println("Time needed for cohesion: " + (double) (end - begin) / (double) 1000000000);
                System.out.println("Got points: " + couples2.size());
                repaint();
            } else {
                System.out.println(couples.size());
                s1 = (String) JOptionPane.showInputDialog(null, "Maximum error : ", " ", 1);
                s2 = (String) JOptionPane.showInputDialog(null, "Number of iterations : ", " ", 1);
                double maxerror = 1;
                int iter = 5;
                try {
                    maxerror = Double.parseDouble(s1);
                    iter = Integer.parseInt(s2);
                } catch (Exception e) {
                    System.out.println("Invalid number");
                    e.printStackTrace();
                }
                long begin = System.nanoTime();
                Ransac ran = new Ransac(couples);

                System.out.println(iter + " " + maxerror);
                couples2 = ran.runRunsac(iter, maxerror);
                long end = System.nanoTime();
                System.out.println("Time needed for ransac: " + (double) (end - begin) / (double) 1000000000);
                System.out.println("Got points: " + couples2.size());
                repaint();
            }
        }
    }
}
