import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

class Client {
    static Scanner scanner = new Scanner(System.in);
    static IssueTrackerInterface stub;

    private Client() {
    }

    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry();
            stub = (IssueTrackerInterface) registry.lookup("IssueTrackerServer");

            int action = 0;

            while (action != -1) {
                System.out.println("1- put, 2- get, 3- delete, -1: END");
                action = scanner.nextInt();

                switch (action) {
                    case 1:
                        putIssue();
                        break;
                    case 2:
                        getIssue();
                        break;
                    case 3:
                        deleteIssue();
                        break;
                    default:
                        System.out.println("Incorrect action.");
                }
            }

        } catch (Exception e) {
            System.err.println(e.toString());
            e.printStackTrace();
        }
    }

    private static void putIssue() throws RemoteException {
        System.out.print("Issue title: ");
        String title = scanner.next();
        System.out.print("Issue priority: ");
        int priority = scanner.nextInt();
        System.out.print("Project name: ");
        String projectName = scanner.next();

        int response = stub.putIssue(new Issue(title, priority), projectName);

        System.out.println("newIssueId: " + response);
    }

    private static void getIssue() throws RemoteException {
        System.out.print("Project name: ");
        String projectName = scanner.next();
        System.out.print("Issue id: ");
        int issueId = scanner.nextInt();

        Issue response = stub.get(projectName, issueId);

        System.out.println("issueData: " + (response != null ? response.toString() : "no object with given id"));
    }

    private static void deleteIssue() throws RemoteException {
        System.out.print("Project name: ");
        String projectName = scanner.next();
        System.out.print("Issue id: ");
        int issueId = scanner.nextInt();

        boolean response = stub.delete(projectName, issueId);

        System.out.println("issueDeleted: " + response);
    }
}
