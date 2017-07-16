package core;

import java.util.ArrayList;

/**
 * Created by Dyzio on 13.03.2017.
 */
public class Repository {
    private String name;
    private String authorWithMostCommits;

    public Repository(String name, String authorWithMostCommits) {
        this.name = name;
        this.authorWithMostCommits = authorWithMostCommits;
    }

    public String getName() {
        return this.name;
    }

    public String getAuthorWithMostCommits() {
        return this.authorWithMostCommits;
    }
}
