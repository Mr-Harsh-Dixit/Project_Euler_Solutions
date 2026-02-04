class DSU:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x: int) -> int:
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, a: int, b: int) -> bool:
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False
        if self.rank[ra] < self.rank[rb]:
            ra, rb = rb, ra
        self.parent[rb] = ra
        if self.rank[ra] == self.rank[rb]:
            self.rank[ra] += 1
        return True

def solve(path: str = "network.txt") -> int:
    rows = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            rows.append(line.strip().split(","))

    n = len(rows)
    edges = []
    total = 0

    for i in range(n):
        for j in range(i + 1, n):
            val = rows[i][j]
            if val != "-":
                w = int(val)
                total += w
                edges.append((w, i, j))

    edges.sort()
    dsu = DSU(n)

    mst = 0
    used = 0
    for w, u, v in edges:
        if dsu.union(u, v):
            mst += w
            used += 1
            if used == n - 1:
                break

    return total - mst

if __name__ == "__main__":
    print(solve("network.txt"))  # 259679 for the official file
