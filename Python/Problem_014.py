def solve(limit: int = 1_000_000) -> int:
    cache = [0] * (limit + 1)
    cache[1] = 1

    best_start = 1
    best_len = 1

    for start in range(2, limit):
        n = start
        path = []

        while n != 1 and (n > limit or cache[n] == 0):
            path.append(n)
            if n % 2 == 0:
                n //= 2
            else:
                n = 3 * n + 1

        total = 1 if n == 1 else cache[n]

        # backfill
        for x in reversed(path):
            total += 1
            if x <= limit:
                cache[x] = total

        if cache[start] > best_len:
            best_len = cache[start]
            best_start = start

    return best_start


if __name__ == "__main__":
    print(solve())  # 837799
