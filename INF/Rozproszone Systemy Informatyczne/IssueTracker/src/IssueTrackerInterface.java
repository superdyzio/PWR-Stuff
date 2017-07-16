import java.rmi.Remote;
import java.rmi.RemoteException;

public interface IssueTrackerInterface extends Remote {
    int putIssue(Issue issue, String projectName) throws RemoteException;

    Issue get(String projectName, int issueId) throws RemoteException;

    boolean delete(String projectName, int issueId) throws RemoteException;
}
