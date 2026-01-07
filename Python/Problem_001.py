def sum_multiples(k: int, n: int) -> int:
    m = (n - 1) // k 
    return k * m * (m + 1) / 2

def solve(n: int = 1000) -> int:
    return int(sum_multiples(3, n) + sum_multiples(5, n) - sum_multiples(15, n))

if __name__ == "__main__":
    print(solve())  # Expected output: 233168