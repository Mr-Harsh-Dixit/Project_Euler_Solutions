def sieve(limit: int) -> list[int]:
    is_prime = bytearray(b"\x01") * (limit + 1)
    is_prime[0:2] = b"\x00\x00"
    for i in range(2, int(limit ** 0.5) + 1):
        if is_prime[i]:
            step = i
            start = i * i
            is_prime[start:limit + 1:step] = b"\x00" * (((limit - start) // step) + 1)
    return [i for i in range(2, limit + 1) if is_prime[i]]

def digit_sig(x: int) -> tuple[int, ...]:
    cnt = [0] * 10
    while x:
        cnt[x % 10] += 1
        x //= 10
    return tuple(cnt)

def euler_70(limit: int = 10_000_000) -> int:
    primes = sieve(limit)

    best_n = 0
    best_num = 1  # ratio compare as n/phi -> compare n1*phi2 vs n2*phi1
    best_den = 0

    for i, p in enumerate(primes):
        # if p*p already exceeds limit, no more pairs
        if p * p >= limit:
            break

        for q in primes[i:]:
            n = p * q
            if n >= limit:
                break
            phi = (p - 1) * (q - 1)

            if digit_sig(n) == digit_sig(phi):
                # compare n/phi < best_num/best_den via cross-multiply
                if best_den == 0 or n * best_den < best_num * phi:
                    best_n = n
                    best_num = n
                    best_den = phi

    return best_n

if __name__ == "__main__":
    print(euler_70())  # 8319823
