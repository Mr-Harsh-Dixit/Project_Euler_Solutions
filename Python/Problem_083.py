import heapq

def euler_83(path: str = "matrix.txt") -> int:
    a = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            a.append(list(map(int, line.strip().split(","))))

    n = len(a)
    INF = 10**18
    dist = [[INF] * n for _ in range(n)]
    dist[0][0] = a[0][0]

    pq = [(a[0][0], 0, 0)]  # (distance, r, c)
    dirs = [(1,0), (-1,0), (0,1), (0,-1)]

    while pq:
        d, r, c = heapq.heappop(pq)
        if d != dist[r][c]:
            continue
        if r == n - 1 and c == n - 1:
            return d

        for dr, dc in dirs:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n:
                nd = d + a[nr][nc]
                if nd < dist[nr][nc]:
                    dist[nr][nc] = nd
                    heapq.heappush(pq, (nd, nr, nc))

    return dist[n - 1][n - 1]

if __name__ == "__main__":
    print(euler_83())  # 425185
