def euler_79(path: str = "keylog.txt") -> str:
    # Read attempts
    attempts = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            s = line.strip()
            if s:
                attempts.append(s)

    # Build graph
    nodes = set()
    graph = {str(d): set() for d in range(10)}  # digits as strings
    indeg = {str(d): 0 for d in range(10)}

    def add_edge(u: str, v: str) -> None:
        if v not in graph[u]:
            graph[u].add(v)
            indeg[v] += 1

    for s in attempts:
        a, b, c = s[0], s[1], s[2]
        nodes.update([a, b, c])
        add_edge(a, b)
        add_edge(b, c)

    # Topological sort (Kahn) with deterministic smallest-first choice
    import heapq
    heap = []
    for d in nodes:
        if indeg[d] == 0:
            heapq.heappush(heap, d)

    result = []
    while heap:
        u = heapq.heappop(heap)
        result.append(u)
        for v in sorted(graph[u]):  # sort not required, but keeps deterministic behavior
            indeg[v] -= 1
            if indeg[v] == 0:
                heapq.heappush(heap, v)

    return "".join(result)

if __name__ == "__main__":
    print(euler_79())  # 73162890 for the official file
