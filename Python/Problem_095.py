def euler_95(N: int = 1_000_000) -> int:
    # sum of proper divisors
    s = [0] * (N + 1)
    for i in range(1, N // 2 + 1):
        for j in range(i * 2, N + 1, i):
            s[j] += i

    processed = [False] * (N + 1)
    best_len = 0
    best_min = 10**18

    for start in range(2, N + 1):
        if processed[start]:
            continue

        local = {}
        path = []
        cur = start

        while 1 <= cur <= N and (not processed[cur]) and (cur not in local):
            local[cur] = len(path)
            path.append(cur)
            cur = s[cur]

        if cur in local:
            idx = local[cur]
            cycle = path[idx:]
            clen = len(cycle)
            cmin = min(cycle)
            if clen > best_len or (clen == best_len and cmin < best_min):
                best_len = clen
                best_min = cmin

        for v in path:
            processed[v] = True

    return best_min

if __name__ == "__main__":
    print(euler_95())  # 14316
