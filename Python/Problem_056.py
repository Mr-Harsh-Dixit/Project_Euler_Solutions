def multiply_digits(digits: list[int], m: int) -> None:
    carry = 0
    for i in range(len(digits)):
        prod = digits[i] * m + carry
        digits[i] = prod % 10
        carry = prod // 10
    while carry:
        digits.append(carry % 10)
        carry //= 10

def digit_sum(digits: list[int]) -> int:
    return sum(digits)

def euler_56() -> int:
    best = 0
    for a in range(1, 100):
        for b in range(1, 100):
            digits = [1]  # represents 1
            for _ in range(b):
                multiply_digits(digits, a)
            best = max(best, digit_sum(digits))
    return best

if __name__ == "__main__":
    print(euler_56())  # 972
