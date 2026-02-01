def euler_96(filename="sudoku.txt"):
    DIGITS = 0b1111111110  # bits 1..9

    def box_index(r, c):
        return (r // 3) * 3 + (c // 3)

    def popcount(x):
        return x.bit_count()

    def iter_bits(mask):
        # yields digit for each set bit (1..9)
        while mask:
            lsb = mask & -mask
            d = (lsb.bit_length() - 1)
            yield d
            mask ^= lsb

    def solve(grid, row, col, box):
        best_r = best_c = -1
        best_mask = 0
        best_cnt = 10

        # MRV: choose cell with fewest candidates
        for r in range(9):
            for c in range(9):
                if grid[r][c] == 0:
                    b = box_index(r, c)
                    used = row[r] | col[c] | box[b]
                    cand = DIGITS & ~used
                    cnt = popcount(cand)
                    if cnt == 0:
                        return False
                    if cnt < best_cnt:
                        best_cnt = cnt
                        best_mask = cand
                        best_r, best_c = r, c
                        if cnt == 1:
                            break
            if best_cnt == 1:
                break

        if best_r == -1:  # no empties => solved
            return True

        r, c = best_r, best_c
        b = box_index(r, c)

        for v in iter_bits(best_mask):
            bit = 1 << v
            grid[r][c] = v
            row[r] |= bit
            col[c] |= bit
            box[b] |= bit

            if solve(grid, row, col, box):
                return True

            # undo
            row[r] ^= bit
            col[c] ^= bit
            box[b] ^= bit
            grid[r][c] = 0

        return False

    total = 0
    with open(filename, "r") as f:
        lines = [line.strip() for line in f if line.strip()]

    i = 0
    for _ in range(50):
        # "Grid XX"
        i += 1
        grid = [[0]*9 for _ in range(9)]
        row = [0]*9
        col = [0]*9
        box = [0]*9

        for r in range(9):
            s = lines[i]
            i += 1
            for c in range(9):
                v = ord(s[c]) - ord('0')
                grid[r][c] = v
                if v != 0:
                    bit = 1 << v
                    b = box_index(r, c)
                    row[r] |= bit
                    col[c] |= bit
                    box[b] |= bit

        solve(grid, row, col, box)
        total += 100*grid[0][0] + 10*grid[0][1] + grid[0][2]

    return total

if __name__ == "__main__":
    print(euler_96("sudoku.txt"))  # 24702
