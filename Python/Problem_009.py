def solve(S: int = 1000) -> int:
    target = S // 2  # k*m*(m+n) = S/2

    for m in range(2, 1000):  # safe upper bound
        for n in range(1, m):
            denom = m * (m + n)
            if denom > target:
                break
            if target % denom == 0:
                k = target // denom
                a = k * (m * m - n * n)
                b = k * (2 * m * n)
                c = k * (m * m + n * n)
                if a + b + c == S:
                    return a * b * c

    raise ValueError("No triplet found")

if __name__ == "__main__":
    print(solve())  # 31875000
