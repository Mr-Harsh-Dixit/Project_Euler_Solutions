def poly(s: int, n: int) -> int:
    # s is number of sides: 3..8
    return ((s - 2) * n * n - (s - 4) * n) // 2

def generate_4digit(s: int) -> list[int]:
    out = []
    n = 1
    while True:
        v = poly(s, n)
        if v > 9999:
            break
        if 1000 <= v <= 9999:
            out.append(v)
        n += 1
    return out

def euler_61() -> int:
    types = [3, 4, 5, 6, 7, 8]

    # edges[s][prefix] -> list of numbers with that prefix
    edges = {s: {} for s in types}
    nums = {s: generate_4digit(s) for s in types}

    for s in types:
        for x in nums[s]:
            pre, suf = x // 100, x % 100
            if suf < 10:  # can't link to a valid 4-digit next number
                continue
            edges[s].setdefault(pre, []).append(x)

    def dfs(path, used, need_prefix, start_prefix):
        if len(path) == 6:
            return path if need_prefix == start_prefix else None

        for s in types:
            if s in used:
                continue
            for x in edges[s].get(need_prefix, ()):
                nxt = x % 100
                used.add(s)
                path.append(x)
                res = dfs(path, used, nxt, start_prefix)
                if res:
                    return res
                path.pop()
                used.remove(s)
        return None

    for start_s in types:
        for start in nums[start_s]:
            sp = start // 100
            ss = start % 100
            if ss < 10:
                continue
            res = dfs([start], {start_s}, ss, sp)
            if res:
                return sum(res)

    raise RuntimeError("No solution found")

if __name__ == "__main__":
    print(euler_61())  # 28684
