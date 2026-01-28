def isqrt(n: int) -> int:
    # Integer Newton-Raphson
    if n == 0:
        return 0
    x = 1 << ((n.bit_length() + 1) // 2)  # initial guess ~ 2^(bits/2)
    while True:
        y = (x + n // x) // 2
        if y >= x:
            return x
        x = y

def digit_sum_first_100_sqrt(n: int) -> int:
    # compute floor(sqrt(n * 10^200))
    big = n * (10 ** 200)
    x = isqrt(big)
    s = str(x)
    # For n<=100, sqrt(n) < 10, so x has 101 digits; take first 100
    s = s[:100]
    return sum(ord(ch) - 48 for ch in s)

def euler_80() -> int:
    squares = {i * i for i in range(1, 11)}
    total = 0
    for n in range(1, 101):
        if n in squares:
            continue
        total += digit_sum_first_100_sqrt(n)
    return total

if __name__ == "__main__":
    print(euler_80())  # 40886
