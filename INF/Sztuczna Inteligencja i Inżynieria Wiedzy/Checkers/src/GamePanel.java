import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.Arrays;
import java.util.List;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

class GamePanel extends JPanel {
    private static final long serialVersionUID = 5209868672877405279L;

    // board border with letters and numbers
    private static class BorderPanel extends JPanel {
        private static final long serialVersionUID = 4355351078893761543L;
        JPanel board;

        BorderPanel(JPanel board) {
            this.board = board;
            add(board);
            setLayout(null);
            board.setLocation(20, 20);
            setBackground(Color.WHITE);
            setPreferredSize(new Dimension(board.getWidth() + 40, board.getHeight() + 40));
        }

        public void paint(Graphics g) {
            super.paint(g);

            if (g instanceof Graphics2D) {
                ((Graphics2D) g).setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            }

            for (int x = 0; x < Board.width; x++) {
                g.drawString(Integer.toString(x + 1), x * 32 + 32, 16);
                g.drawString(Integer.toString(x + 1), x * 32 + 32, board.getHeight() + 32);
            }

            for (int y = 0; y < Board.height; y++) {
                g.drawString(Character.toString((char) (y + 'A')), 8, y * 32 + 32 + 8);
                g.drawString(Character.toString((char) (y + 'A')), board.getWidth() + 24, y * 32 + 32 + 8);
            }

            g.setColor(Color.BLACK);
            g.drawRect(0, 0, getWidth() - 1, getHeight() - 1);
        }
    }

    // component displaying player controller and clock
    private class PlayerInfoPanel extends JPanel implements BoardListener {
        private static final long serialVersionUID = -2691532936608582978L;
        final String playerName;
        final Clock clock;
        final int player;

        PlayerInfoPanel(final int player) {
            this.player = player;
            setLayout(new GridBagLayout());

            switch (player) {
                case 1:
                    playerName = "White";
                    break;
                case -1:
                    playerName = "Black";
                    break;
                default:
                    throw new IllegalArgumentException();
            }

            setBorder(BorderFactory.createTitledBorder(playerName + ":"));
            JComboBox playerController = new JComboBox();

            for (Player p : availablePlayers) {
                playerController.addItem(p);
            }
            playerController.addItemListener(e -> {
                if (e.getStateChange() == ItemEvent.SELECTED)
                    controller.setPlayer(player, (Player) e.getItem());
            });

            GridBagConstraints constraints = new GridBagConstraints();
            constraints.fill = GridBagConstraints.VERTICAL;
            constraints.anchor = GridBagConstraints.NORTH;
            constraints.insets = new Insets(4, 4, 4, 4);
            add(playerController, constraints);

            clock = new Clock();
            constraints.gridy = 1;
            constraints.weighty = 1.0;

            add(clock, constraints);

            controller.addBoardListener(this);

            if (controller.getBoard().turnHolder == player) {
                clock.start();
            }
        }

        @Override
        public void onMove(Board board, Move move) {
            if (board.turnHolder != player) {
                clock.start();
            } else {
                clock.stop();
            }
        }

        @Override
        public void onNewGame(Board board) {
            clock.reset();
            if (board.turnHolder == player) {
                clock.start();
            }
        }
    }

    private static final List<Player> availablePlayers = Arrays.asList(
            new HumanPlayer(),
            new RandomPlayer(),
            new MinMaxPlayer(1),
            new MinMaxPlayer(5),
            new MinMaxPlayer(9)
    );

    private final BoardView view;

    private final BoardController controller;

    GamePanel(Board board) {
        view = new BoardView(board);
        controller = new BoardController(view);

        BorderLayout borderLayout = new BorderLayout(8, 8);
        setLayout(borderLayout);

        JPanel filler = new JPanel();
        filler.setLayout(new GridBagLayout());
        GridBagConstraints constraints = new GridBagConstraints();
        constraints.fill = GridBagConstraints.CENTER;
        filler.add(new BorderPanel(view), constraints);

        add(filler, BorderLayout.CENTER);

        JComponent buttonPanel = new JPanel();

        JButton newGame = new JButton("New Game");
        newGame.addActionListener(e -> controller.newGame());
        buttonPanel.add(newGame);

        JButton quit = new JButton("Quit");
        quit.addActionListener(e -> System.exit(0));
        buttonPanel.add(quit);

        add(buttonPanel, BorderLayout.NORTH);

        JPanel rightPanel = new JPanel();
        rightPanel.setLayout(new GridLayout(0, 1));
        rightPanel.add(new PlayerInfoPanel(-1));
        rightPanel.add(new PlayerInfoPanel(1));

        add(rightPanel, BorderLayout.EAST);

        Log log = new Log();

        JScrollPane logScroll = new JScrollPane(log);
        logScroll.setBorder(BorderFactory.createTitledBorder("Log:"));
        add(logScroll, BorderLayout.SOUTH);
        controller.addBoardListener(log);
        setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));
    }
}
