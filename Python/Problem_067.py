def euler_67(path: str = "triangle.txt") -> int:
    tri = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if line:
                tri.append(list(map(int, line.split())))

    dp = tri[-1][:]  # copy last row
    for r in range(len(tri) - 2, -1, -1):
        for c in range(r + 1):
            dp[c] = tri[r][c] + (dp[c] if dp[c] > dp[c + 1] else dp[c + 1])
    return dp[0]

if __name__ == "__main__":
    print(euler_67())  # 7273 
