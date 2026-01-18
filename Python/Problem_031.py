def solve(target: int = 200) -> int:
    coins = [1, 2, 5, 10, 20, 50, 100, 200]
    dp = [0] * (target + 1)
    dp[0] = 1

    for coin in coins:
        for x in range(coin, target + 1):
            dp[x] += dp[x - coin]

    return dp[target]

if __name__ == "__main__":
    print(solve())  # 73682
