import java.awt.Color;
import java.awt.Font;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.Timer;

// component showing game clock
public class Clock extends JPanel {
    private static final long serialVersionUID = 8988209987063047869L;
    private final JLabel label;
    private final Timer timer;
    private int time = 0;

    Clock() {
        label = new JLabel();
        add(label);
        label.setFont(new Font(Font.MONOSPACED, Font.BOLD, 16));
        timer = new Timer(1000, e -> {
            time++;
            update();
        });

        update();
    }

    private void update() {
        label.setText(String.format("%02d:%02d", time / 60, time % 60));
        label.setForeground(timer.isRunning() ? Color.RED : Color.BLACK);
    }

    void stop() {
        timer.stop();
        update();
    }

    void reset() {
        time = 0;
        update();
        stop();
    }

    void start() {
        timer.start();
        update();
    }

    @Override
    protected void finalize() throws Throwable {
        timer.stop();
    }
}
