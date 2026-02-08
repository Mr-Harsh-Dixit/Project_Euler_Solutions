def solve(n: int = 15) -> int:
    dp = [1]  # dp[k] = numerator for P(k blues), denom tracked separately
    D = 1

    for i in range(1, n + 1):
        D *= (i + 1)
        new = [0] * (len(dp) + 1)
        for k, val in enumerate(dp):
            new[k] += val * i      # red: i/(i+1)
            new[k + 1] += val      # blue: 1/(i+1)
        dp = new

    need = n // 2 + 1  # blues > reds
    win_num = sum(dp[need:])
    return D // win_num

if __name__ == "__main__":
    print(solve(15))  # 2269
