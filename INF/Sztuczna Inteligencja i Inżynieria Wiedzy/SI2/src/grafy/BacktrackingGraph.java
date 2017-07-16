package grafy;

@SuppressWarnings("ALL")
public class BacktrackingGraph {
    public long start;
    public long end;
    private long assignments;
    private long returns;
    private long solutionsCount;

    private int graphDim;
    private int colors;
    private boolean[][] colorsMap;
    private int[][] solution;

    public BacktrackingGraph(int dim) {
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

    public boolean solve(int index) {
        boolean result = false;

        if (index >= graphDim * graphDim) {
            solutionsCount++;
            return true;
        } else {
            for (int color = 0; color < colors; color++) {
                int x = index / graphDim;
                int y = index % graphDim;
                assignments++;
                if (!isConflict(x, y, color)) {
                    solution[x][y] = color;

                    if (x - 1 >= 0) {
                        colorsMap[color][solution[x - 1][y]] = colorsMap[solution[x - 1][y]][color] = true;
                    }
                    if (y - 1 >= 0) {
                        colorsMap[color][solution[x][y - 1]] = colorsMap[solution[x][y - 1]][color] = true;
                    }

                    if (solve(index + 1)) {
                        result = true;
                    }

                    solution[x][y] = -1;
                    if (x - 1 >= 0) {
                        colorsMap[color][solution[x - 1][y]] = colorsMap[solution[x - 1][y]][color] = false;
                    }
                    if (y - 1 >= 0) {
                        colorsMap[color][solution[x][y - 1]] = colorsMap[solution[x][y - 1]][color] = false;
                    }
                }
            }

            returns++;
            return result;
        }
    }

    private boolean isConflict(int x, int y, int color) {
        boolean result = false;

        if (y - 1 >= 0) {
            int color1 = solution[x][y - 1];
            if (color == color1 || colorsMap[color][color1]) {
                result = true;
            }
        }

        if (x - 1 >= 0) {
            int color2 = solution[x - 1][y];
            if (color == color2 || colorsMap[color][color2]) {
                result = true;
            }
        }

        return result;
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
