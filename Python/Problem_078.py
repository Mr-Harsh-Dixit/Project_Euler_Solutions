def euler_78(mod: int = 1_000_000) -> int:
    p = [1]  # p[0] = 1
    n = 1

    while True:
        total = 0
        k = 1
        while True:
            g1 = k * (3 * k - 1) // 2
            if g1 > n:
                break
            g2 = k * (3 * k + 1) // 2

            sign = 1 if (k & 1) else -1

            total += sign * p[n - g1]
            if g2 <= n:
                total += sign * p[n - g2]

            k += 1

        total %= mod
        p.append(total)

        if total == 0:
            return n
        n += 1

if __name__ == "__main__":
    print(euler_78())  # 55374
