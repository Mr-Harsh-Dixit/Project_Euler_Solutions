def ways(n: int, m: int) -> int:
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        dp[i] = dp[i - 1]
        if i >= m:
            dp[i] += dp[i - m]
    return dp[n] - 1  # exclude all-grey

def solve() -> int:
    n = 50
    return ways(n, 2) + ways(n, 3) + ways(n, 4)

if __name__ == "__main__":
    print(solve())  # 20492570929
