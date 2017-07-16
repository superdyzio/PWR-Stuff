package hetmany;

@SuppressWarnings("ALL")
public class BacktrackingQueens {
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

    public BacktrackingQueens(int dim) {
        size = dim;

        diag_1 = new boolean[2 * size - 1];
        diag_2 = new boolean[2 * size - 1];
        column = new boolean[size];
        solution = new int[size];
    }

    public boolean solve(int row) {
        boolean result = false;

        if (row >= size) {
            solutionsCount++;
            return true;
        } else {
            for (int col = 0; col < size; col++) {
                assignments++;
                if (!(column[col] || diag_1[col - row + size - 1] || diag_2[col + row])) {
                    solution[col] = row;
                    diag_1[col - row + size - 1] = diag_2[col + row] = column[col] = true;

                    if (solve(row + 1)) {
                        result = true;
                    }

                    solution[col] = -1;
                    diag_1[col - row + size - 1] = diag_2[col + row] = column[col] = false;
                }
            }

            returns++;
            return result;
        }
    }

    public void printStats() {
        System.out.println(String.format("Liczba hetmanów: %d", size));
        System.out.println(String.format("Liczba rozwiązań: %d", solutionsCount));
        System.out.println(String.format("Liczba przypisań: %d", assignments));
        System.out.println(String.format("Liczba powrotów: %d", returns));
        System.out.println(String.format("Czas: %d\n\n", end - start));
    }
}
