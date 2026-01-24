def sieve(n: int) -> list[int]:
    is_prime = bytearray(b"\x01") * (n + 1)
    is_prime[0:2] = b"\x00\x00"
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            step = i
            start = i * i
            is_prime[start:n+1:step] = b"\x00" * (((n - start) // step) + 1)
    return [i for i in range(n + 1) if is_prime[i]]

PRIMES = sieve(30000)

def is_prime(n: int) -> bool:
    if n < 2:
        return False
    for p in PRIMES:
        if p * p > n:
            break
        if n % p == 0:
            return n == p
    return True

def euler_58() -> int:
    prime_count = 0
    diag_total = 1
    k = 0

    while True:
        k += 1
        s = 2 * k + 1
        step = s - 1
        sq = s * s

        c1 = sq - step
        c2 = sq - 2 * step
        c3 = sq - 3 * step

        if is_prime(c1): prime_count += 1
        if is_prime(c2): prime_count += 1
        if is_prime(c3): prime_count += 1

        diag_total += 4

        if prime_count * 10 < diag_total:
            return s

if __name__ == "__main__":
    print(euler_58())  # 26241
