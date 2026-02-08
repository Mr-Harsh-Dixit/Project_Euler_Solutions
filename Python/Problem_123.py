import math

def sieve(limit: int):
    is_prime = bytearray(b"\x01") * (limit + 1)
    is_prime[:2] = b"\x00\x00"
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            step = i
            start = i * i
            is_prime[start:limit+1:step] = b"\x00" * (((limit - start) // step) + 1)
    return [i for i in range(limit + 1) if is_prime[i]]

def solve(threshold: int = 10**10) -> int:
    # Enough for n ~ 21035 (p_n ~ 240k). 500k is safe.
    primes = sieve(500_000)

    for n, p in enumerate(primes, start=1):
        if (n & 1) == 1:  # odd n
            if 2 * n * p > threshold:
                return n
    raise RuntimeError("Increase sieve limit")

if __name__ == "__main__":
    print(solve())  # 21035
