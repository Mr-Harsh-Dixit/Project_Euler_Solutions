def largest_prime_factor(n: int) -> int:
    max_factor = 1

    while n % 2 == 0:
        max_factor = 2
        n //= 2

    i = 3
    while i * i <= n:
        while n % i == 0:
            max_factor = i
            n //= i
        i += 2

    if n > 1:
        max_factor = n

    return max_factor


if __name__ == "__main__":
    print(largest_prime_factor(600851475143))  # 6857
