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

def is_square(x: int) -> bool:
    s = isqrt(x)
    return s * s == x

def solve() -> int:
    LIMIT = 100_000
    is_prime = sieve(LIMIT)
    primes = [i for i in range(2, LIMIT + 1) if is_prime[i]]

    n = 9
    while True:
        if n <= LIMIT and is_prime[n]:
            n += 2
            continue  # skip primes

        ok = False
        for p in primes:
            if p >= n:
                break
            r = n - p
            if (r & 1) == 0 and is_square(r // 2):
                ok = True
                break

        if not ok:
            return n

        n += 2

if __name__ == "__main__":
    print(solve())  # 5777
