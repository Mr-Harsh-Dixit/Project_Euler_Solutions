def euler_82(path: str = "matrix.txt") -> int:
    a = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            a.append(list(map(int, line.strip().split(","))))

    n = len(a)
    dp = [a[r][0] for r in range(n)]

    for c in range(1, n):
        dp2 = [dp[r] + a[r][c] for r in range(n)]

        # relax moving down within this column
        for r in range(1, n):
            dp2[r] = min(dp2[r], dp2[r - 1] + a[r][c])

        # relax moving up within this column
        for r in range(n - 2, -1, -1):
            dp2[r] = min(dp2[r], dp2[r + 1] + a[r][c])

        dp = dp2

    return min(dp)

if __name__ == "__main__":
    print(euler_82())  # 260324
