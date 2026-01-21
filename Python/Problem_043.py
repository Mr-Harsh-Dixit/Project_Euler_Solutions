def digits3(n: int) -> tuple[int, int, int]:
    return n // 100, (n // 10) % 10, n % 10

def solve() -> int:
    primes = [17, 13, 11, 7, 5, 3, 2]  # windows from right to left
    total = 0

    def dfs(step: int, used: int, suffix: list[int]):
        # step: which prime index we’re enforcing next (0 already used for seed=17)
        # suffix: current digits from d_(8-step) ... d10 (growing left)
        nonlocal total

        if step == len(primes) - 1:
            # We have built d2..d10, now pick remaining digit as d1
            for d in range(10):
                if not (used & (1 << d)):
                    num = d
                    for x in suffix:
                        num = num * 10 + x
                    total += num
                    return

        prime = primes[step + 1]  # next constraint
        # need (newDigit, suffix[0], suffix[1]) divisible by prime
        a, b = suffix[0], suffix[1]

        for d in range(10):
            if used & (1 << d):
                continue
            triple = 100 * d + 10 * a + b
            if triple % prime == 0:
                dfs(step + 1, used | (1 << d), [d] + suffix)

    # seed with multiples of 17 for d8d9d10
    for n in range(0, 1000, 17):
        a, b, c = digits3(n)
        if a == b or b == c or a == c:
            continue
        used = (1 << a) | (1 << b) | (1 << c)
        dfs(0, used, [a, b, c])

    return total

if __name__ == "__main__":
    print(solve())  # 16695334890

