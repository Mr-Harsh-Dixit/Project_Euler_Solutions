import java.io.*;
import java.util.*;

public class Euler96 {
    static final int DIGITS = 0b1111111110; // bits 1..9

    static int boxIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    static int popcount(int x) {
        return Integer.bitCount(x);
    }

    static boolean solve(int[][] grid, int[] row, int[] col, int[] box) {
        int bestR = -1, bestC = -1;
        int bestMask = 0;
        int bestCnt = 10;

        // MRV: pick empty cell with smallest candidate set
        outer:
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (grid[r][c] == 0) {
                    int b = boxIndex(r, c);
                    int used = row[r] | col[c] | box[b];
                    int cand = DIGITS & ~used;
                    int cnt = popcount(cand);
                    if (cnt == 0) return false;
                    if (cnt < bestCnt) {
                        bestCnt = cnt;
                        bestMask = cand;
                        bestR = r;
                        bestC = c;
                        if (cnt == 1) break outer;
                    }
                }
            }
        }

        if (bestR == -1) return true; // solved

        int r = bestR, c = bestC, b = boxIndex(r, c);

        int mask = bestMask;
        while (mask != 0) {
            int bit = mask & -mask;               // lowest set bit
            int v = Integer.numberOfTrailingZeros(bit); // digit 1..9

            grid[r][c] = v;
            row[r] |= bit;
            col[c] |= bit;
            box[b] |= bit;

            if (solve(grid, row, col, box)) return true;

            // undo
            row[r] ^= bit;
            col[c] ^= bit;
            box[b] ^= bit;
            grid[r][c] = 0;

            mask ^= bit;
        }

        return false;
    }

    public static void main(String[] args) throws Exception {
        String filename = "sudoku.txt";
        BufferedReader br = new BufferedReader(new FileReader(filename));

        long total = 0;
        for (int puzzle = 0; puzzle < 50; puzzle++) {
            String line = br.readLine(); // "Grid XX"
            if (line == null) break;

            int[][] grid = new int[9][9];
            int[] row = new int[9];
            int[] col = new int[9];
            int[] box = new int[9];

            for (int r = 0; r < 9; r++) {
                line = br.readLine();
                for (int c = 0; c < 9; c++) {
                    int v = line.charAt(c) - '0';
                    grid[r][c] = v;
                    if (v != 0) {
                        int bit = 1 << v;
                        int b = boxIndex(r, c);
                        row[r] |= bit;
                        col[c] |= bit;
                        box[b] |= bit;
                    }
                }
            }

            solve(grid, row, col, box);

            int val = grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2];
            total += val;
        }

        br.close();
        System.out.println(total); // 24702
    }
}
