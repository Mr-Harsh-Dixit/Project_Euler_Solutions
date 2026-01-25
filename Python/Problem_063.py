import math

def euler_63() -> int:
    total = 0
    n = 1
    while True:
        for a in range(1, 10):
            digits = int(math.floor(n * math.log10(a))) + 1
            if digits == n:
                total += 1

        # stop when even 9^n has fewer than n digits
        if int(math.floor(n * math.log10(9))) + 1 < n:
            break
        n += 1

    return total

if __name__ == "__main__":
    print(euler_63())  # 49
