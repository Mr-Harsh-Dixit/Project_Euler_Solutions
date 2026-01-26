def is_prime(x: int) -> bool:
    if x < 2:
        return False
    if x % 2 == 0:
        return x == 2
    i = 3
    while i * i <= x:
        if x % i == 0:
            return False
        i += 2
    return True

def next_prime(p: int) -> int:
    x = p + 1
    while not is_prime(x):
        x += 1
    return x

def euler_69(limit: int = 1_000_000) -> int:
    n = 1
    p = 2
    while n * p <= limit:
        n *= p
        p = next_prime(p)
    return n

if __name__ == "__main__":
    print(euler_69())  # 510510
