def solve(limit: int = 1_000_000) -> int:
    cnt = [0] * (limit + 1)

    for i in range(2, limit + 1):
        if cnt[i] == 0:  # prime
            for m in range(i, limit + 1, i):
                cnt[m] += 1

    streak = 0
    for n in range(2, limit + 1):
        if cnt[n] == 4:
            streak += 1
            if streak == 4:
                return n - 3
        else:
            streak = 0

    return -1

if __name__ == "__main__":
    print(solve())  # 134043
