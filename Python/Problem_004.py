def is_palindrome(x: int) -> bool:
    orig = x
    rev = 0
    while x > 0:
        rev = rev * 10 + (x % 10)
        x //= 10
    return rev == orig

def solve() -> int:
    best = 0

    for a in range(999, 99, -1):
        if a % 11 == 0:
            b_start, b_step = 999, 1
        else:
            b_start, b_step = 990, 11  # must hit multiples of 11

        for b in range(b_start, a - 1, -b_step):
            prod = a * b
            if prod <= best:
                break
            if is_palindrome(prod):
                best = prod

    return best

if __name__ == "__main__":
    print(solve())  # 906609
