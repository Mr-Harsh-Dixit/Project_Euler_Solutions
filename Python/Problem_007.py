import math

def nth_prime(n: int) -> int:
    # Safe limit for 10001st prime
    limit = 200_000

    is_prime = bytearray(b"\x01") * (limit + 1)
    is_prime[0:2] = b"\x00\x00"

    for p in range(2, int(math.isqrt(limit)) + 1):
        if is_prime[p]:
            start = p * p
            step = p
            is_prime[start:limit+1:step] = b"\x00" * ((limit - start) // step + 1)

    count = 0
    for i in range(2, limit + 1):
        if is_prime[i]:
            count += 1
            if count == n:
                return i

    raise ValueError("Limit too small")

if __name__ == "__main__":
    print(nth_prime(10001))  # 104743
