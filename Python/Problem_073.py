import math

def euler_73(limit: int = 12000) -> int:
    count = 0
    for d in range(2, limit + 1):
        n_start = d // 3 + 1
        n_end = (d - 1) // 2
        for n in range(n_start, n_end + 1):
            if math.gcd(n, d) == 1:
                count += 1
    return count

if __name__ == "__main__":
    print(euler_73())  # 7295372
