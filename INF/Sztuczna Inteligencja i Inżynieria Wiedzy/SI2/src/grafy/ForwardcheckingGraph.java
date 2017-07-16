package grafy;

import java.util.Arrays;

@SuppressWarnings("ALL")
public class ForwardcheckingGraph {
    public long start;
    public long end;
    private long assignments;
    private long returns;
    private long solutionsCount;

    private int graphDim;
    private int colors;
    private int[][] solution;
    private boolean[][] colorsMap;

    public ForwardcheckingGraph(int dim) {
        graphDim = dim;
        colors = 2 * graphDim + graphDim % 2;

        solution = new int[graphDim][graphDim];
        for (int i = 0; i < graphDim; i++) {
            for (int j = 0; j < graphDim; j++) {
                solution[i][j] = -1;
            }
        }

        colorsMap = new boolean[colors][colors];
        for (int i = 0; i < colors; i++) {
            for (int j = 0; j < colors; j++) {
                colorsMap[i][j] = i == j;
            }
        }
    }

    public void solve() {
        boolean[] domain = new boolean[colors];
        Arrays.fill(domain, Boolean.TRUE);

        solve(0, domain);
    }

    private boolean solve(int index, boolean[] domain) {
        boolean result = false;

        if (index >= graphDim * graphDim) {
            solutionsCount++;
            return true;
        } else {
            for (int c = 0; c < colors; c++) {
                if (domain[c]) {
                    int x = index / graphDim;
                    int y = index % graphDim;

                    assignments++;
                    solution[x][y] = c;
                    if (x - 1 >= 0) {
                        colorsMap[c][solution[x - 1][y]] = colorsMap[solution[x - 1][y]][c] = true;
                    }
                    if (y - 1 >= 0) {
                        colorsMap[c][solution[x][y - 1]] = colorsMap[solution[x][y - 1]][c] = true;
                    }

                    boolean[] newDomain = getNewDomain(index + 1);
                    if (newDomain != null) {
                        if (solve(index + 1, newDomain)) {
                            result = true;
                        }
                    }

                    solution[x][y] = -1;
                    if (x - 1 >= 0) {
                        colorsMap[c][solution[x - 1][y]] = colorsMap[solution[x - 1][y]][c] = false;
                    }
                    if (y - 1 >= 0) {
                        colorsMap[c][solution[x][y - 1]] = colorsMap[solution[x][y - 1]][c] = false;
                    }
                }
            }

            returns++;
            return result;
        }
    }

    private boolean[] getNewDomain(int index) {
        boolean[] domain = new boolean[colors];
        boolean result = false;
        int x = index / graphDim;
        int y = index % graphDim;

        for (int c = 0; c < colors; c++) {
            if (index >= graphDim * graphDim || !isConflict(x, y, c)) {
                domain[c] = result = true;
            }
        }

        return result ? domain : null;
    }

    private boolean isConflict(int x, int y, int color) {
        if (y - 1 >= 0) {
            int color1 = solution[x][y - 1];
            if (color == color1 || colorsMap[color][color1]) {
                return true;
            }
        }

        if (x - 1 >= 0) {
            int color2 = solution[x - 1][y];
            if (color == color2 || colorsMap[color][color2]) {
                return true;
            }
        }

        return false;
    }

    public void printStats() {
        System.out.println(String.format("Rozmiar grafu: %d", graphDim));
        System.out.println(String.format("Liczba kolorów: %d", colors));
        System.out.println(String.format("Liczba rozwiązań: %d", solutionsCount));
        System.out.println(String.format("Liczba przypisań: %d", assignments));
        System.out.println(String.format("Liczba powrotów: %d", returns));
        System.out.println(String.format("Czas: %d\n\n", end - start));
    }
}
