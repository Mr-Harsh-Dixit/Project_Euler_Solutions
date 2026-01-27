def euler_74(limit: int = 1_000_000) -> int:
    fact = [1] * 10
    for i in range(2, 10):
        fact[i] = fact[i - 1] * i

    MAX = 7 * fact[9]  # 2,540,160
    memo = [0] * (MAX + 1)

    def nxt(x: int) -> int:
        if x == 0:
            return fact[0]
        s = 0
        while x:
            s += fact[x % 10]
            x //= 10
        return s

    def chain_len(start: int) -> int:
        path = []
        pos = {}  # value -> index in path
        x = start

        while True:
            if x <= MAX and memo[x] != 0:
                known = memo[x]
                # fill backwards
                for v in reversed(path):
                    known += 1
                    if v <= MAX:
                        memo[v] = known
                return memo[start] if start <= MAX else len(path) + memo[x]

            if x in pos:
                loop_start = pos[x]
                loop_len = len(path) - loop_start

                # loop nodes
                for i in range(loop_start, len(path)):
                    v = path[i]
                    if v <= MAX:
                        memo[v] = loop_len

                # pre-loop nodes
                dist = loop_len
                for i in range(loop_start - 1, -1, -1):
                    dist += 1
                    v = path[i]
                    if v <= MAX:
                        memo[v] = dist

                return memo[start] if start <= MAX else len(path)

            pos[x] = len(path)
            path.append(x)
            x = nxt(x)

    count = 0
    for n in range(1, limit):
        if chain_len(n) == 60:
            count += 1
    return count

if __name__ == "__main__":
    print(euler_74())  # 402
