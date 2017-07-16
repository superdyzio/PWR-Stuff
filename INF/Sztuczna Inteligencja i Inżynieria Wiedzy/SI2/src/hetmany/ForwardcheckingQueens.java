package hetmany;

@SuppressWarnings("ALL")
public class ForwardcheckingQueens {
    public long start;
    public long end;
    private long assignments;
    private long returns;
    private long solutionsCount;

    private int size;
    private boolean[] diag_1;
    private boolean[] diag_2;
    private boolean[] column;
    private int[] solution;
    public int[][] domains;

    public ForwardcheckingQueens(int dim) {
        size = dim;

        diag_1 = new boolean[2 * size - 1];
        diag_2 = new boolean[2 * size - 1];
        column = new boolean[size];
        solution = new int[size];

        domains = new int[size][size];
    }

    public int setNewDomain(int row) {
        int result = 0;

        for (int col = 0; col < size; col++) {
            if (!(column[col] || diag_1[col - row + size - 1] || diag_2[col + row])) {
                domains[row][result++] = col;
            }
        }

        return result;
    }

    public boolean solve(int row, int domainSize) {
        boolean result = false;

        for (int c = 0; c < domainSize; c++) {
            int col = domains[row][c];
            assignments++;

            solution[col] = row;
            diag_1[col - row + size - 1] = diag_2[col + row] = column[col] = true;

            if (row + 1 == size) {
                solutionsCount++;
                result = true;
            } else {
                int newDomainSize = setNewDomain(row + 1);
                if (newDomainSize > 0 && solve(row + 1, newDomainSize)) {
                    result = true;
                }
            }

            diag_1[col - row + size - 1] = diag_2[col + row] = column[col] = false;
        }

        returns++;
        return result;
    }

    public void printStats() {
        System.out.println(String.format("Liczba hetmanów: %d", size));
        System.out.println(String.format("Liczba rozwiązań: %d", solutionsCount));
        System.out.println(String.format("Liczba przypisań: %d", assignments));
        System.out.println(String.format("Liczba powrotów: %d", returns));
        System.out.println(String.format("Czas: %d\n\n", end - start));
    }
}
