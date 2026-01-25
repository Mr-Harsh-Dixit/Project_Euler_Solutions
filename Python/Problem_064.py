import math

def euler_64(limit: int = 10_000) -> int:
    count = 0
    for N in range(2, limit + 1):
        a0 = int(math.isqrt(N))
        if a0 * a0 == N:
            continue

        m, d, a = 0, 1, a0
        period = 0

        while True:
            m = d * a - m
            d = (N - m * m) // d
            a = (a0 + m) // d
            period += 1
            if a == 2 * a0:
                break

        if period % 2 == 1:
            count += 1

    return count

if __name__ == "__main__":
    print(euler_64())  # 1322
