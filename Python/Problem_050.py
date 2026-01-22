from math import isqrt

def sieve(limit: int) -> bytearray:
    is_prime = bytearray(b"\x01") * (limit + 1)
    is_prime[0:2] = b"\x00\x00"
    p = 2
    while p * p <= limit:
        if is_prime[p]:
            start = p * p
            is_prime[start::p] = b"\x00" * (((limit - start) // p) + 1)
        p += 1
    return is_prime

def solve(limit: int = 1_000_000) -> int:
    is_prime = sieve(limit)
    primes = [i for i in range(2, limit) if is_prime[i]]

    pref = [0]
    s = 0
    for p in primes:
        s += p
        pref.append(s)

    best_len = 0
    best_prime = 0

    n = len(primes)
    for i in range(n):
        # smallest possible sum for length best_len+1 starting at i
        for j in range(i + best_len + 1, n + 1):
            val = pref[j] - pref[i]
            if val >= limit:
                break
            if is_prime[val]:
                best_len = j - i
                best_prime = val

    return best_prime

if __name__ == "__main__":
    print(solve())  # 997651
