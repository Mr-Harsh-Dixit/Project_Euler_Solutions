def sieve(n: int) -> list[int]:
    is_prime = bytearray(b"\x01") * (n + 1)
    is_prime[0:2] = b"\x00\x00"
    i = 2
    while i * i <= n:
        if is_prime[i]:
            step = i
            start = i * i
            is_prime[start:n+1:step] = b"\x00" * (((n - start) // step) + 1)
        i += 1
    return [i for i in range(n + 1) if is_prime[i]]

def euler_87(limit: int = 50_000_000) -> int:
    primes = sieve(7071)

    sq = [p * p for p in primes if p * p < limit]
    cube = [p * p * p for p in primes if p * p * p < limit]
    four = [p ** 4 for p in primes if p ** 4 < limit]

    sq.sort()
    cube.sort()
    four.sort()

    seen = bytearray(limit)  # 0/1 flags

    for f in four:
        for c in cube:
            fc = f + c
            if fc >= limit:
                break
            for s in sq:
                v = fc + s
                if v >= limit:
                    break
                seen[v] = 1

    return sum(seen)

if __name__ == "__main__":
    print(euler_87())  # 1097343
