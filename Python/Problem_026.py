def cycle_length(d: int) -> int:
    while d % 2 == 0:
        d //= 2
    while d % 5 == 0:
        d //= 5
    if d == 1:
        return 0

    seen = {}
    r = 1 % d
    pos = 0
    while r not in seen:
        seen[r] = pos
        r = (r * 10) % d
        pos += 1
    return pos - seen[r]


def solve(limit: int = 1000) -> int:
    best_d = 0
    best_len = 0
    for d in range(2, limit):
        clen = cycle_length(d)
        if clen > best_len:
            best_len = clen
            best_d = d
    return best_d


if __name__ == "__main__":
    print(solve())  # 983
