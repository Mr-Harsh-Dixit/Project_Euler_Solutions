def euler_81(path: str = "matrix.txt") -> int:
    matrix = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            matrix.append(list(map(int, line.strip().split(","))))

    n = len(matrix)
    dp = [[0] * n for _ in range(n)]

    dp[0][0] = matrix[0][0]

    for i in range(1, n):
        dp[i][0] = dp[i - 1][0] + matrix[i][0]
        dp[0][i] = dp[0][i - 1] + matrix[0][i]

    for i in range(1, n):
        for j in range(1, n):
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1])

    return dp[n - 1][n - 1]

if __name__ == "__main__":
    print(euler_81())  # 427337
