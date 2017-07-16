import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.List;

class IssueTrackerServer implements IssueTrackerInterface {
    private List<Project> projectList = new ArrayList<>();

    private IssueTrackerServer() {
    }

    public static void main(String[] args) {
        IssueTrackerServer server = new IssueTrackerServer();

        server.projectList.add(new Project("project1"));
        server.projectList.add(new Project("project2"));
        server.projectList.add(new Project("project3"));

        try {
            System.setProperty("java.rmi.server.hostname", "192.168.65.1");
            LocateRegistry.createRegistry(1099);

            IssueTrackerInterface stub = (IssueTrackerInterface) UnicastRemoteObject.exportObject(server, 0);
            Registry registry = LocateRegistry.getRegistry();
            registry.bind("IssueTrackerServer", stub);

            System.out.println("Server working...");
        } catch (Exception e) {
            System.err.println(e.toString());
            e.printStackTrace();
        }
    }

    public int putIssue(Issue issue, String projectName) {
        Project project = this.getProjectByName(projectName);
        int issueId = -1;

        if (project != null) {
            issueId = project.getNewIssueId();
            project.putIssue(issueId, issue);
        }

        return issueId;
    }

    public Issue get(String projectName, int issueId) {
        Project project = this.getProjectByName(projectName);
        Issue issue = null;

        if (project != null) {
            issue = project.getIssueById(issueId);
        }

        return issue;
    }

    public boolean delete(String projectName, int issueId) {
        Project project = this.getProjectByName(projectName);

        return project.removeIssueById(issueId) != null;
    }

    private Project getProjectByName(String projectName) {
        Project project = null;
        for (Project p : this.projectList) {
            if (p.getName().equals(projectName)) {
                project = p;
            }
        }
        return project;
    }
}
