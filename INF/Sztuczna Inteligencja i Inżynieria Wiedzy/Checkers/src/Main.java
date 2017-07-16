import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Main {
    public static void main(String[] args) {
        CheckersWindow window = new CheckersWindow();   // main game window
        window.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.out.println("Thank you for playing!");
                System.exit(0);
            }
        });
        window.setVisible(true);
    }
}
