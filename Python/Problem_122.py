def solve(MAX_K: int = 200) -> int:
    INF = 10**9
    best = [INF] * (MAX_K + 1)
    best[1] = 0

    # quick check: are we done?
    def done():
        for k in range(1, MAX_K + 1):
            if best[k] == INF:
                return False
        return True

    # depth-limited DFS building increasing addition chains
    def dfs(chain, depth, limit):
        x = chain[-1]
        if depth < best[x]:
            best[x] = depth

        if depth == limit:
            return

        # remaining steps
        rem = limit - depth

        # generate next candidates: x + chain[i] (i from end to start)
        # descending i gives larger nxt earlier (often helps pruning)
        for i in range(len(chain) - 1, -1, -1):
            nxt = x + chain[i]
            if nxt <= x or nxt > MAX_K:
                continue

            nd = depth + 1
            if nd >= best[nxt]:
                continue

            # bound: with rem-1 steps left, max reachable is nxt * 2^(rem-1)
            # if that can't reach MAX_K, still might help smaller ks, so we do NOT prune by MAX_K reach.
            # (If you only cared about one target, you'd prune harder.)

            chain.append(nxt)
            dfs(chain, nd, limit)
            chain.pop()

    # empirical upper bound: m(200) is small (< 12), but just loop until finished
    limit = 0
    while True:
        dfs([1], 0, limit)
        if done():
            return sum(best[1:])  # include m(1)=0
        limit += 1

if __name__ == "__main__":
    print(solve(200))  # 1582
