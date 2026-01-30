def euler_88(KMAX=12000):
    LIMIT = 2 * KMAX
    best = [10**18] * (KMAX + 1)

    def dfs(start, prod, s, m):
        k = m + (prod - s)
        if k <= KMAX:
            if prod < best[k]:
                best[k] = prod
        for f in range(start, LIMIT // prod + 1):
            dfs(f, prod * f, s + f, m + 1)

    dfs(2, 1, 0, 0)

    return sum(set(best[2:]))

if __name__ == "__main__":
    print(euler_88())  # 7587457
