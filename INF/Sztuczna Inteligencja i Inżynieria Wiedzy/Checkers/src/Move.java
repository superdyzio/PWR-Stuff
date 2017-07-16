import java.awt.Point;

public class Move {
    final Point p0;
    final Point p1;
    final boolean jump;

    public int score;

    public Move() {
        p0 = null;
        p1 = null;
        jump = false;
    }

    Move(Point p0, Point p1, boolean jump) {
        this.p0 = new Point(p0);
        this.p1 = new Point(p1);
        this.jump = jump;
    }

    public String toString() {
        assert p0 != null;
        assert p1 != null;

        String s0 = (char) ('A' + p0.y) + "" + (p0.x + 1);
        String s1 = (char) ('A' + p1.y) + "" + (p1.x + 1);

        return jump ? s0 + "->" + s1 : s0 + "-" + s1;
    }

    Point getJumpedPiece() {
        assert p0 != null;
        assert p1 != null;

        int x = p1.x - Integer.signum(p1.x - p0.x);
        int y = p1.y - Integer.signum(p1.y - p0.y);

        return new Point(x, y);
    }
}
