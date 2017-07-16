import grafy.*;
import hetmany.*;

import java.util.Scanner;

public class Runner {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Podaj maksymalny rozmiar grafu: ");
        int graphDim = scanner.nextInt();

        if (graphDim > 1) {
            System.out.println("\n\nGRAPH BACKTRACKING\n");
        }
        for (int i = 2; i <= graphDim; i++) {
            BacktrackingGraph solver = new BacktrackingGraph(i);

            solver.start = System.currentTimeMillis();
            solver.solve(0);
            solver.end = System.currentTimeMillis();

            solver.printStats();
        }

        if (graphDim > 1) {
            System.out.println("\n\n\nGRAPH FORWARDCHECKING\n");
        }
        for (int i = 2; i <= graphDim; i++) {
            ForwardcheckingGraph solver = new ForwardcheckingGraph(i);

            solver.start = System.currentTimeMillis();
            solver.solve();
            solver.end = System.currentTimeMillis();

            solver.printStats();
        }

        System.out.print("Podaj maksymalną liczbę hetmanów: ");
        int queens = scanner.nextInt();

        if (queens > 3) {
            System.out.println("\n\n\nQUEENS BACKTRACKING\n");
        }
        for (int i = 10; i <= queens; i++) {
            BacktrackingQueens solver = new BacktrackingQueens(i);

            solver.start = System.currentTimeMillis();
            solver.solve(0);
            solver.end = System.currentTimeMillis();

            solver.printStats();
        }

        if (queens > 3) {
            System.out.println("\n\n\nQUEENS FORWARDCHECKING\n");
        }
        for (int i = 10; i <= queens; i++) {
            ForwardcheckingQueens solver = new ForwardcheckingQueens(i);

            solver.start = System.currentTimeMillis();
            solver.solve(0, solver.setNewDomain(0));
            solver.end = System.currentTimeMillis();

            solver.printStats();
        }
    }
}
