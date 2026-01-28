def euler_76(n: int = 100) -> int:
    dp = [0] * (n + 1)
    dp[0] = 1

    for part in range(1, n):          # 1..99
        for s in range(part, n + 1):  # part..100
            dp[s] += dp[s - part]

    return dp[n]

if __name__ == "__main__":
    print(euler_76())  # 190569291
