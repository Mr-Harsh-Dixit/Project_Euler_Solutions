from math import gcd

def solve(limit: int = 1000) -> int:
    cnt = [0] * (limit + 1)

    m = 2
    while 2 * m * (m + 1) <= limit:  # smallest n=1 => p0=2m(m+1)
        for n in range(1, m):
            if ((m - n) & 1) == 0:
                continue
            if gcd(m, n) != 1:
                continue

            p0 = 2 * m * (m + n)
            for p in range(p0, limit + 1, p0):
                cnt[p] += 1
        m += 1

    best_p = max(range(limit + 1), key=lambda p: cnt[p])
    return best_p

if __name__ == "__main__":
    print(solve())  # 840
