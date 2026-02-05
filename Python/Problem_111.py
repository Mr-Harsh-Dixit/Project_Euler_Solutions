import itertools

# Deterministic Miller-Rabin for 64-bit integers
def is_prime(n: int) -> bool:
    if n < 2:
        return False
    small = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
    for p in small:
        if n % p == 0:
            return n == p

    d = n - 1
    s = 0
    while d % 2 == 0:
        s += 1
        d //= 2

    def check(a: int) -> bool:
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            return True
        for _ in range(s - 1):
            x = (x * x) % n
            if x == n - 1:
                return True
        return False

    # Deterministic bases for 64-bit
    for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
        if a % n == 0:
            continue
        if not check(a):
            return False
    return True

def candidates(n: int, d: int, r: int):
    # exactly r digits are NOT d
    choices = [x for x in range(10) if x != d]
    for pos_other in itertools.combinations(range(n), r):
        pos_other = list(pos_other)
        for assignment in itertools.product(choices, repeat=r):
            arr = [d] * n
            for p, v in zip(pos_other, assignment):
                arr[p] = v

            if arr[0] == 0:
                continue
            last = arr[-1]
            if last % 2 == 0 or last == 5:
                continue

            num = 0
            for v in arr:
                num = num * 10 + v
            yield num

def solve() -> int:
    n = 10
    total = 0
    for d in range(10):
        for r in range(n + 1):
            s = 0
            cnt = 0
            for x in candidates(n, d, r):
                if is_prime(x):
                    s += x
                    cnt += 1
            if cnt > 0:
                total += s
                break
    return total

if __name__ == "__main__":
    print(solve())  # 612407567715
