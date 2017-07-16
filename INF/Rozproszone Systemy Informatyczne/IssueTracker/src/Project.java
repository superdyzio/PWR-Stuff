import java.util.HashMap;

class Project {
    private String name;
    private HashMap<Integer, Issue> issueMap;

    Project(String name) {
        this.name = name;
        issueMap = new HashMap<>();
    }

    String getName() {
        return this.name;
    }

    int getNewIssueId() {
        return this.issueMap.size();
    }

    void putIssue(int issueId, Issue issue) {
        this.issueMap.put(issueId, issue);
    }

    Issue getIssueById(int issueId) {
        return this.issueMap.get(issueId);
    }

    Issue removeIssueById(int issueId) {
        return this.issueMap.remove(issueId);
    }
}
