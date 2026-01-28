def sieve(limit: int) -> list[int]:
    if limit < 2:
        return []
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(limit ** 0.5) + 1):
        if is_prime[i]:
            step = i
            start = i * i
            for j in range(start, limit + 1, step):
                is_prime[j] = False
    return [i for i in range(2, limit + 1) if is_prime[i]]

def euler_77(threshold: int = 5000) -> int:
    n = 2
    while True:
        primes = sieve(n)
        ways = [0] * (n + 1)
        ways[0] = 1
        for p in primes:
            for s in range(p, n + 1):
                ways[s] += ways[s - p]
        if ways[n] > threshold:
            return n
        n += 1

if __name__ == "__main__":
    print(euler_77())  # 71
