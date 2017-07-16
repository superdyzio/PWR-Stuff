package server;

import core.Repository;

import java.util.ArrayList;

/**
 * Created by Dyzio on 13.03.2017.
 */
public class RepoServer {
    ArrayList<Repository> repoList;

    RepoServer() {
        this.repoList = new ArrayList<Repository>();
    }

    public String hasRepo(String repoName) {
        String result = "Nie ma takiego repozytorium.";
        for (int i = 0; i < this.repoList.size() - 1 && !result.equals("true"); i++) {
            if (this.repoList.get(i).getName().equals(repoName)) {
                result = "Repozytorium znalezione.";
            }
        }
        return result;
    }

    public String getAuthorWithMostCommits(String repoName) {
        if (this.hasRepo(repoName).equals("Nie ma takiego repozytorium.")) {
            return "Nie ma takiego repozytorium.";
        } else {
            Repository repo = this.getRepo(repoName);
            return repo != null ? repo.getAuthorWithMostCommits() : "Nie ma takiego repozytorium.";
        }
    }

    private Repository getRepo(String repoName) {
        for (int i = 0; i < this.repoList.size() - 1; i++) {
            if (this.repoList.get(i).getName().equals(repoName)) {
                return this.repoList.get(i);
            }
        }
        return null;
    }
}
