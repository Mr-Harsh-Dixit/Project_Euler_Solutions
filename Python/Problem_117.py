def solve(n: int = 50) -> int:
    f = [0] * (n + 1)
    f[0] = 1
    for i in range(1, n + 1):
        f[i] = f[i - 1]
        if i >= 2: f[i] += f[i - 2]
        if i >= 3: f[i] += f[i - 3]
        if i >= 4: f[i] += f[i - 4]
    return f[n]

if __name__ == "__main__":
    print(solve(50))  # 100808458960497
