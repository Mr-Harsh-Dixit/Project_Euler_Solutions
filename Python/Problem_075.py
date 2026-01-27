import math

def euler_75(limit: int = 1_500_000) -> int:
    cnt = [0] * (limit + 1)

    m = 2
    while 2 * m * (m + 1) <= limit:
        for n in range(1, m):
            if ((m - n) & 1) == 0:
                continue
            if math.gcd(m, n) != 1:
                continue

            p0 = 2 * m * (m + n)
            for p in range(p0, limit + 1, p0):
                cnt[p] += 1
        m += 1

    return sum(1 for p in range(1, limit + 1) if cnt[p] == 1)

if __name__ == "__main__":
    print(euler_75())  # 161667
