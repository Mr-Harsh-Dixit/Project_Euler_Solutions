def is_bouncy(n: int) -> bool:
    inc = True
    dec = True
    last = n % 10
    n //= 10

    while n > 0:
        d = n % 10
        if d < last:
            inc = False
        if d > last:
            dec = False
        last = d
        n //= 10

        if not inc and not dec:
            return True
    return False  # monotone

def solve() -> int:
    bouncy = 0
    n = 1
    while True:
        n += 1
        if n >= 100 and is_bouncy(n):
            bouncy += 1
        if bouncy * 100 == n * 99:
            return n

if __name__ == "__main__":
    print(solve())  # 1587000
