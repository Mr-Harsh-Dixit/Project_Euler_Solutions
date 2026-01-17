def sieve(limit: int) -> bytearray:
    is_prime = bytearray(b"\x01") * (limit + 1)
    is_prime[0:2] = b"\x00\x00"
    p = 2
    while p * p <= limit:
        if is_prime[p]:
            step = p
            start = p * p
            is_prime[start::step] = b"\x00" * (((limit - start) // step) + 1)
        p += 1
    return is_prime

def solve() -> int:
    LIMIT = 2_000_000
    is_prime = sieve(LIMIT)

    primes_b = [b for b in range(2, 1001) if is_prime[b]]  # b must be prime

    best_len = 0
    best_prod = 0

    for b in primes_b:
        for a in range(-999, 1000):
            v1 = 1 + a + b
            if v1 <= 1 or not is_prime[v1]:
                continue

            n = 0
            while True:
                val = n * n + a * n + b
                if val <= 1 or val > LIMIT or not is_prime[val]:
                    break
                n += 1

            if n > best_len:
                best_len = n
                best_prod = a * b

    return best_prod

if __name__ == "__main__":
    print(solve())  # -59231
