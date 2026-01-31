def euler_92(limit: int = 10_000_000) -> int:
    digit_sq = [i * i for i in range(10)]
    MAXS = 7 * 81  # 567

    fate = [0] * (MAXS + 1)
    fate[1] = 1
    fate[89] = 89

    def next_sum(n: int) -> int:
        s = 0
        while n:
            s += digit_sq[n % 10]
            n //= 10
        return s

    def resolve(s: int) -> int:
        path = []
        while fate[s] == 0:
            path.append(s)
            s = next_sum(s)
        end = fate[s]
        for v in path:
            fate[v] = end
        return end

    for s in range(1, MAXS + 1):
        if fate[s] == 0:
            resolve(s)

    cnt = 0
    for n in range(1, limit):
        s = next_sum(n)
        if fate[s] == 89:
            cnt += 1
    return cnt

if __name__ == "__main__":
    print(euler_92())  # 8581146
