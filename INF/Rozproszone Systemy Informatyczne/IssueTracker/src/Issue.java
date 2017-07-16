import java.io.Serializable;

public class Issue implements Serializable {
    private String title;
    private int priority;

    Issue(String title, int priority) {
        this.title = title;
        this.priority = priority;
    }

    @Override
    public String toString() {
        return this.title + " " + this.priority;
    }
}
