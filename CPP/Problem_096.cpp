#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static const int DIGITS = 0b1111111110; // bits 1..9

static inline int boxIndex(int r, int c) { return (r/3)*3 + (c/3); }

static inline int popcount(int x) { return __builtin_popcount((unsigned)x); }

static bool solveSudoku(int grid[9][9], int row[9], int col[9], int box[9]) {
    int bestR = -1, bestC = -1;
    int bestMask = 0;
    int bestCnt = 10;

    // MRV: pick empty cell with smallest candidate set
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (grid[r][c] == 0) {
                int b = boxIndex(r,c);
                int used = row[r] | col[c] | box[b];
                int cand = DIGITS & ~used;
                int cnt = popcount(cand);
                if (cnt == 0) return false;
                if (cnt < bestCnt) {
                    bestCnt = cnt;
                    bestMask = cand;
                    bestR = r; bestC = c;
                    if (cnt == 1) goto chosen;
                }
            }
        }
    }
chosen:
    if (bestR == -1) return true; // solved

    int r = bestR, c = bestC, b = boxIndex(r,c);

    // iterate candidate bits
    int mask = bestMask;
    while (mask) {
        int bit = mask & -mask;
        int v = __builtin_ctz((unsigned)bit); // digit 1..9

        grid[r][c] = v;
        row[r] |= bit;
        col[c] |= bit;
        box[b] |= bit;

        if (solveSudoku(grid, row, col, box)) return true;

        // undo
        row[r] ^= bit;
        col[c] ^= bit;
        box[b] ^= bit;
        grid[r][c] = 0;

        mask ^= bit;
    }
    return false;
}

int main() {
    ifstream fin("sudoku.txt");
    string line;
    long long total = 0;

    for (int puzzle = 0; puzzle < 50; puzzle++) {
        getline(fin, line); // Grid XX

        int grid[9][9] = {0};
        int row[9] = {0}, col[9] = {0}, box[9] = {0};

        for (int r = 0; r < 9; r++) {
            getline(fin, line);
            for (int c = 0; c < 9; c++) {
                int v = line[c] - '0';
                grid[r][c] = v;
                if (v != 0) {
                    int bit = 1 << v;
                    int b = boxIndex(r,c);
                    row[r] |= bit;
                    col[c] |= bit;
                    box[b] |= bit;
                }
            }
        }

        solveSudoku(grid, row, col, box);

        int val = grid[0][0]*100 + grid[0][1]*10 + grid[0][2];
        total += val;
    }

    cout << total << "\n"; // 24702
    return 0;
}
